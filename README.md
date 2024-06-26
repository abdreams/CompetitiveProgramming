To apply a dark mode theme to `react-select`, you can use the `styles` prop to customize the styling of the `Select` component. Here's how you can create a dark mode for the `Select` component:

### Dark Mode Styles
First, define your dark mode styles. These styles will override the default `react-select` styles to create a dark mode appearance.

```jsx
const darkModeStyles = {
    control: (provided) => ({
        ...provided,
        backgroundColor: '#333',
        borderColor: '#555',
        color: '#fff',
    }),
    menu: (provided) => ({
        ...provided,
        backgroundColor: '#333',
        color: '#fff',
    }),
    option: (provided, state) => ({
        ...provided,
        backgroundColor: state.isFocused ? '#444' : '#333',
        color: '#fff',
    }),
    singleValue: (provided) => ({
        ...provided,
        color: '#fff',
    }),
    input: (provided) => ({
        ...provided,
        color: '#fff',
    }),
    placeholder: (provided) => ({
        ...provided,
        color: '#aaa',
    }),
};
```

### Applying Dark Mode to `react-select`
Use the `styles` prop to apply these styles to your `Select` component.

```jsx
import React, { useEffect, useState } from 'react';
import { useTable, useGlobalFilter, useSortBy, usePagination } from 'react-table';
import { useNavigate, useParams } from 'react-router-dom';
import { toast } from 'react-toastify';
import { FaTrash } from 'react-icons/fa';
import Loader from '../components/Loader';
import Select from 'react-select';

const RebalancePortfolio = () => {
    const navigate = useNavigate();
    const { portfolioId } = useParams();
    const [data, setData] = useState([]);
    const [loading, setLoading] = useState(true);
    const [globalFilter, setGlobalFilter] = useState('');
    const [stockOptions, setStockOptions] = useState([]);
    const [selectedStock, setSelectedStock] = useState(null);

    const fetchData = async () => {
        try {
            setLoading(true);
            const response = await fetch(`https://dummy-url.com/api/rebalanced-portfolio/${portfolioId}`);
            if (!response.ok) {
                throw new Error('Network response was not ok');
            }
            const result = await response.json();
            const transformedData = Object.entries(result.allocation).map(([symbol, details]) => ({
                stockSymbol: symbol,
                oldAllocation: parseFloat(details.oldAllocation),
                newAllocation: parseFloat(details.newAllocation),
                price: parseFloat(details.price),
                change: parseFloat(details.change),
            }));
            setData(transformedData);
        } catch (error) {
            console.error('Error fetching data:', error);
            toast.error('Error fetching data, displaying dummy data instead.');
            setData([
                { stockSymbol: 'AAPL', oldAllocation: 10, newAllocation: 5, price: 113.79, change: -5 },
                { stockSymbol: 'GOOGL', oldAllocation: 10, newAllocation: 5, price: 113.79, change: -5 },
                // Add more dummy data if needed
            ]);
        } finally {
            setLoading(false);
        }
    };

    const fetchStockOptions = async () => {
        try {
            const response = await fetch('https://dummy-url.com/api/stock-options');
            if (!response.ok) {
                throw new Error('Network response was not ok');
            }
            const result = await response.json();
            const options = result.map(stock => ({
                value: stock.stocksymbol,
                label: stock.stocksymbol,
                price: stock.price,
                change: stock.change,
            }));
            setStockOptions(options);
        } catch (error) {
            console.error('Error fetching stock options:', error);
            toast.error('Error fetching stock options.');
        }
    };

    useEffect(() => {
        fetchData();
        fetchStockOptions();
    }, []);

    const handleInputChange = (e, rowIndex) => {
        const { name, value } = e.target;
        if (name === 'newAllocation' && parseFloat(value) < 0) {
            toast.error('Allocation cannot be negative');
            return;
        }
        const updatedData = [...data];
        updatedData[rowIndex][name] = parseFloat(value) || 0;
        updatedData[rowIndex].change = parseFloat(value) - updatedData[rowIndex].oldAllocation;
        setData(updatedData);
    };

    const handleDelete = (rowIndex) => {
        const confirmed = window.confirm('Are you sure you want to delete this stock?');
        if (confirmed) {
            const updatedData = data.filter((_, index) => index !== rowIndex);
            setData(updatedData);
            toast.success('Stock deleted successfully');
        }
    };

    const handleAccept = async () => {
        try {
            const response = await fetch(`https://dummy-url.com/api/save-portfolio/${portfolioId}`, {
                method: 'POST',
                headers: {
                    'Content-Type': 'application/json',
                },
                body: JSON.stringify({
                    allocation: data.reduce((acc, stock) => {
                        acc[stock.stockSymbol] = {
                            oldAllocation: stock.oldAllocation,
                            newAllocation: stock.newAllocation,
                            price: stock.price,
                            change: stock.change,
                        };
                        return acc;
                    }, {})
                }),
            });
            if (response.ok) {
                toast.success('Portfolio saved successfully');
                window.close();
            } else {
                toast.error('Failed to save portfolio');
            }
        } catch (error) {
            toast.error('Error saving data');
        }
    };

    const handleAddStock = () => {
        if (selectedStock) {
            const existingStock = data.find(stock => stock.stockSymbol === selectedStock.value);
            if (existingStock) {
                toast.error('Stock already exists in the portfolio');
                return;
            }
            const newStock = {
                stockSymbol: selectedStock.value,
                oldAllocation: 0,
                newAllocation: 0,
                price: selectedStock.price,
                change: 0,
            };
            setData(prevData => [...prevData, newStock]);
            setSelectedStock(null);
        }
    };

    const columns = React.useMemo(
        () => [
            {
                Header: 'Stock Symbol',
                accessor: 'stockSymbol',
            },
            {
                Header: 'Old Allocation (%)',
                accessor: 'oldAllocation',
                Cell: ({ cell: { value } }) => value.toFixed(2),
            },
            {
                Header: 'New Allocation (%)',
                accessor: 'newAllocation',
                Cell: ({ cell: { value }, row: { index } }) => (
                    <input
                        type="number"
                        step="0.01"
                        name="newAllocation"
                        value={value}
                        onChange={(e) => handleInputChange(e, index)}
                        className="w-full px-2 py-1 border rounded"
                        onClick={(e) => e.stopPropagation()} // Prevent row click
                    />
                ),
                sortType: 'basic',
            },
            {
                Header: 'Change',
                accessor: 'change',
                Cell: ({ cell: { value } }) => value.toFixed(2),
            },
            {
                Header: 'Price',
                accessor: 'price',
                Cell: ({ cell: { value } }) => value.toFixed(2),
            },
            {
                Header: 'Actions',
                Cell: ({ row: { index } }) => (
                    <button
                        onClick={(e) => {
                            e.stopPropagation();
                            handleDelete(index);
                        }}
                        className="px-4 py-2 bg-red-500 text-white rounded"
                    >
                        <FaTrash />
                    </button>
                ),
            },
        ],
        [data]
    );

    const {
        getTableProps,
        getTableBodyProps,
        headerGroups,
        rows,
        prepareRow,
    } = useTable(
        { columns, data, initialState: { pageIndex: 0, pageSize: 10 } },
        useGlobalFilter,
        useSortBy,
        usePagination
    );

    const handleRowClick = (row, e) => {
        if (e.target.nodeName !== 'INPUT' && e.target.nodeName !== 'BUTTON') {
            navigate(`/stock-history/${row.original.stockSymbol}`);
        }
    };

    const totalNewAllocation = data.reduce((acc, stock) => acc + stock.newAllocation, 0);

    if (loading) {
        return <Loader />;
    }

    return (
        <div className="max-w-4xl mx-auto mt-10 p-5 shadow-lg">
            <h2 className="text-2xl font-bold mb-5">Rebalanced Portfolio</h2>
            <input
                value={globalFilter}
                onChange={(e) => setGlobalFilter(e.target.value)}
                placeholder="Search stocks..."
                className="mb-4 px-4 py-2 border rounded w-full"
            />
            <div className="mb-4">
                <Select
                    options={stockOptions}
                    value={selectedStock}
                    onChange={setSelectedStock}
                    placeholder="Select stock to add"
                    styles={darkModeStyles}
                />
                <button
                    onClick={handleAddStock}
                    className="ml-2 px-4 py-2 bg-green-500 text-white rounded"
                >
                    Add Stock
                </button>
            </div>
            <div className="overflow-y-auto" style={{ max