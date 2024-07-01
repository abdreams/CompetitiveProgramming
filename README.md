To accommodate your requirements, we need to modify the code to reflect the new columns (Stock symbol, Stock price per unit, Allocation %, Capital invested in that stock, Old allocated units, New allocated units, Change in units, Delete action) and add the calculations for the total portfolio worth and total available cash.

Here's the updated code:

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
            setCapital(parseFloat(result.capital));

            const transformedData = Object.entries(result.allocation).map(([symbol, details]) => {
                const oldAllocationShares = parseFloat(details.oldAllocationShares);
                const newAllocationPercent = parseFloat(details.newAllocationPercent);
                const price = parseFloat(details.price);

                const newAllocationShares = (newAllocationPercent / 100) * capital / price;
                const changeInUnits = newAllocationShares - oldAllocationShares;

                return {
                    stockSymbol: symbol,
                    stockPricePerUnit: price,
                    allocationPercent: newAllocationPercent,
                    capitalInvested: (newAllocationPercent / 100) * capital,
                    oldAllocationShares: oldAllocationShares,
                    newAllocationShares: newAllocationShares,
                    changeInUnits: changeInUnits,
                };
            });
            setData(transformedData);
        } catch (error) {
            console.error('Error fetching data:', error);
            toast.error('Error fetching data, displaying dummy data instead.');
            setData([
                { stockSymbol: 'AAPL', stockPricePerUnit: 113.79, allocationPercent: 5, capitalInvested: 50, oldAllocationShares: 0, newAllocationShares: 0.44, changeInUnits: 0.44 },
                { stockSymbol: 'GOOGL', stockPricePerUnit: 113.79, allocationPercent: 5, capitalInvested: 50, oldAllocationShares: 0, newAllocationShares: 0.44, changeInUnits: 0.44 },
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
        if (name === 'allocationPercent' && (parseFloat(value) < 0 || parseFloat(value) > 100)) {
            toast.error('Allocation percentage must be between 0 and 100');
            return;
        }
        const updatedData = [...data];
        updatedData[rowIndex][name] = parseFloat(value) || 0;
        
        const allocationPercent = updatedData[rowIndex].allocationPercent;
        const price = updatedData[rowIndex].stockPricePerUnit;
        
        updatedData[rowIndex].capitalInvested = (allocationPercent / 100) * capital;
        updatedData[rowIndex].newAllocationShares = (allocationPercent / 100) * capital / price;
        updatedData[rowIndex].changeInUnits = updatedData[rowIndex].newAllocationShares - updatedData[rowIndex].oldAllocationShares;

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
                            newAllocationPercent: stock.allocationPercent,
                            price: stock.stockPricePerUnit,
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
                stockPricePerUnit: selectedStock.price,
                allocationPercent: 0,
                capitalInvested: 0,
                oldAllocationShares: 0,
                newAllocationShares: 0,
                changeInUnits: 0,
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
                accessor: 'stockPricePerUnit',
                Cell: ({ cell: { value } }) => value.toFixed(2),
            },
            {
                Header: 'Allocation (%)',
                accessor: 'allocationPercent',
                Cell: ({ cell: { value }, row: { index } }) => (
                    <input
                        type="number"
                        step="0.01"
                        name="allocationPercent"
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
                Cell: ({ cell: { value } }) => value.toFixed(2),
            },
            {
                Header: 'Old Allocated Units',
                accessor: 'oldAllocationShares',
                Cell: ({ cell: { value } }) => value.toFixed(2),
            },
            {
                Header: 'New Allocated Units',
                accessor: 'newAllocationShares',
                Cell: ({ cell: { value } }) => value.toFixed(2),
            },
            {
                Header: 'Change in Units',
                accessor: 'changeInUnits',
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

    const totalNewAllocation = data.reduce((acc, stock) => acc + stock.allocationPercent, 0);

    if (loading) {
        return <Loader />;
    }

    return (
        <div className="max-w-4xl mx-auto mt-10 p-5 shadow-lg">
            <h2 className="text-2xl font-bold mb-5">Rebalanced Portfolio</h2>
           Certainly! Here is the continuation of the code:

```jsx
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
                    placeholder="Select stock to add"
                />
                <button
                    onClick={handleAddStock}
                    className="ml-2 px-4 py-2 bg-green-500 text-white rounded"
                >
                    Add Stock
                </button>
            </div>
            <div className="overflow-y-auto" style={{ maxHeight: '400px' }}>
                <table {...getTableProps()} className="min-w-full bg-white">
                    <thead>
                        {headerGroups.map(headerGroup => (
                            <tr {...headerGroup.getHeaderGroupProps()}>
                                {headerGroup.headers.map(column => (
                                    <th
                                        {...column.getHeaderProps(column.getSortByToggleProps())}
                                        className="px-6 py-3 border-b-2 border-gray-200 bg-gray-50 text-left text-xs leading-4 font-medium text-gray-500 uppercase tracking-wider"
                                    >
                                        {column.render('Header')}
                                        <span>
                                            {column.isSorted
                                                ? column.isSortedDesc
                                                    ? ' 🔽'
                                                    : ' 🔼'
                                                : ''}
                                        </span>
                                    </th>
                                ))}
                            </tr>
                        ))}
                    </thead>
                    <tbody {...getTableBodyProps()}>
                        {rows.map(row => {
                            prepareRow(row);
                            return (
                                <tr
                                    {...row.getRowProps()}
                                    className="cursor-pointer hover:bg-gray-100"
                                    onClick={(e) => handleRowClick(row, e)}
                                >
                                    {row.cells.map(cell => (
                                        <td
                                            {...cell.getCellProps()}
                                            className="px-6 py-4 whitespace-no-wrap border-b border-gray-200"
                                        >
                                            {cell.render('Cell')}
                                        </td>
                                    ))}
                                </tr>
                            );
                        })}
                    </tbody>
                </table>
            </div>
            <div className="sticky bottom-0 bg-white p-4 shadow-lg flex justify-between items-center">
                <div>
                    <strong>Total New Allocation: </strong>
                    {totalNewAllocation.toFixed(2)}%
                </div>
                <div>
                    <button
                        onClick={() => window.close()}
                        className="px-4 py-2 bg-gray-500 text-white rounded mr-3"
                    >
                        Reject
                    </button>
                    <button
                        onClick={handleAccept}
                        className="px-4 py-2 bg-blue-500 text-white rounded"
                        disabled={totalNewAllocation !== 100}
                    >
                        Accept
                    </button>
                </div>
            </div>
        </div>
    );
};

export default RebalancePortfolio;
```

In this updated code, we have added the following features:

1. Columns reflecting the stock symbol, stock price per unit, allocation percentage, capital invested, old allocated units, new allocated units, change in units, and delete action.
2. Calculations for the total portfolio worth and total available cash displayed above the table.
3. Enhanced input validation and dynamic calculations based on user input for the new allocation percentage.
4. A mechanism to ensure the total allocation percentage sums up to 100% before enabling the accept button.

This should meet the requirements outlined. Let me know if you need any further adjustments!