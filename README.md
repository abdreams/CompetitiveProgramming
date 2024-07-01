To ensure that the new allocated units and available cash render correctly without relying on user input changes, we can refactor the calculations to be performed directly in the component rendering logic. This way, the calculations are always up-to-date based on the current state.

Here's the updated component with the necessary modifications:

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
    const [capital, setCapital] = useState(0);

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
                oldAllocationShares: parseFloat(details.oldAllocationShares),
                newAllocationPercent: parseFloat(details.newAllocationPercent),
                price: parseFloat(details.price),
                capitalInvested: parseFloat(details.price) * (parseFloat(details.newAllocationPercent) / 100) * (parseFloat(result.capital) / parseFloat(details.price)),
            }));
            setData(transformedData);
            setCapital(parseFloat(result.capital));
        } catch (error) {
            console.error('Error fetching data:', error);
            toast.error('Error fetching data, displaying dummy data instead.');
            setData([
                { stockSymbol: 'AAPL', oldAllocationShares: 10, newAllocationPercent: 5, price: 113.79, capitalInvested: 568.95 },
                { stockSymbol: 'GOOGL', oldAllocationShares: 10, newAllocationPercent: 5, price: 113.79, capitalInvested: 568.95 },
                // Add more dummy data if needed
            ]);
            setCapital(1000);
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
        if (name === 'newAllocationPercent' && parseFloat(value) < 0) {
            toast.error('Allocation cannot be negative');
            return;
        }
        const updatedData = [...data];
        updatedData[rowIndex][name] = parseFloat(value) || 0;
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
                            oldAllocationShares: stock.oldAllocationShares,
                            newAllocationPercent: stock.newAllocationPercent,
                            price: stock.price,
                        };
                        return acc;
                    }, {}),
                    capital: capital
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
                oldAllocationShares: 0,
                newAllocationPercent: 0,
                price: selectedStock.price,
                capitalInvested: 0,
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
                Header: 'Stock Price per Unit',
                accessor: 'price',
                Cell: ({ cell: { value } }) => value.toFixed(2),
            },
            {
                Header: 'Allocation % (New Allocation)',
                accessor: 'newAllocationPercent',
                Cell: ({ cell: { value }, row: { index } }) => (
                    <input
                        type="number"
                        step="0.01"
                        name="newAllocationPercent"
                        value={value}
                        onChange={(e) => handleInputChange(e, index)}
                        className="w-full px-2 py-1 border rounded"
                        onClick={(e) => e.stopPropagation()} // Prevent row click
                    />
                ),
                sortType: 'basic',
            },
            {
                Header: 'Capital Invested',
                accessor: 'capitalInvested',
                Cell: ({ cell: { row } }) => (row.original.price * (row.original.newAllocationPercent / 100) * (capital / row.original.price)).toFixed(2),
            },
            {
                Header: 'Old Allocated Units',
                accessor: 'oldAllocationShares',
                Cell: ({ cell: { value } }) => value.toFixed(2),
            },
            {
                Header: 'New Allocated Units',
                accessor: 'newAllocatedUnits',
                Cell: ({ cell: { row } }) => ((row.original.newAllocationPercent / 100) * capital / row.original.price).toFixed(2),
            },
            {
                Header: 'Change in Units',
                accessor: 'changeInUnits',
                Cell: ({ cell: { row } }) => (((row.original.newAllocationPercent / 100) * capital / row.original.price) - row.original.oldAllocationShares).toFixed(2),
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
        [data, capital]
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

    const totalNewAllocation = data.reduce((acc, stock) => acc + stock.newAllocationPercent, 0);

    if (loading) {
        return <Loader />;
    }

    return (
        <div className="max-w-4xl mx-auto mt-10 p-5 shadow-lg">
            <h2 className="text-2xl font-bold mb-5">Rebalanced Portfolio</h2>
            <div className="mb-4">
                <strong>Total Portfolio Worth: </strong>${capital.toFixed(2)}
            </div>
            <div className="mb-4">
                <strong>Total Available Cash: </strong>${(capital - data.reduce((acc, stock) => acc + stock.capitalInvested, 0)).toFixed(2)}
            </div>
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
                   