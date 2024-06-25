
To implement the changes you requested, including displaying the new data structure, making the `newAllocation` field editable, ensuring the allocations add up to 100%, and highlighting newly added stocks, here is the revised code:

### RebalancePortfolio Component

```jsx
import React, { useEffect, useState } from 'react';
import { useTable, useGlobalFilter, useSortBy, usePagination } from 'react-table';
import { useNavigate, useParams } from 'react-router-dom';
import { toast } from 'react-toastify';
import { FaTrash } from 'react-icons/fa';
import Loader from '../components/Loader';

const RebalancePortfolio = () => {
    const navigate = useNavigate();
    const { portfolioId } = useParams(); // Fetching portfolio ID from URL params
    const [data, setData] = useState([]);
    const [loading, setLoading] = useState(true);
    const [globalFilter, setGlobalFilter] = useState('');

    const fetchData = async () => {
        try {
            setLoading(true); // Start loader
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
            setLoading(false); // Stop loader
        }
    };

    useEffect(() => {
        fetchData();
    }, []);

    const handleInputChange = (e, rowIndex) => {
        const { name, value } = e.target;
        const updatedData = [...data];
        updatedData[rowIndex][name] = parseFloat(value) || 0;
        updatedData[rowIndex].change = parseFloat(value) - updatedData[rowIndex].oldAllocation;
        setData(updatedData);
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
                        const isNewStock = row.original.oldAllocation === 0;
                        return (
                            <tr
                                {...row.getRowProps()}
                                className={`cursor-pointer ${isNewStock ? 'bg-yellow-100' : ''}`}
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
            <div className="mt-5">
                <div className="text-right font-bold">
                    Total New Allocation: {totalNewAllocation.toFixed(2)}%
                </div>
                {totalNewAllocation !== 100 && (
                    <div className="text-right text-red-500 font-bold">
                        Allocations must add up to 100%. Currently at {totalNewAllocation.toFixed(2)}%.
                    </div>
                )}
            </div>
            <div className="flex justify-end mt-5">
                <button
                    onClick={() => window.close()}
                    className="px-4 py-2 bg-gray-500 text-white rounded mr-3"
                >
                    Reject
                </button>
                <button
                    onClick={() => handleAccept()}
                    className="px-4 py-2 bg-blue-500 text-white rounded"
                    disabled={totalNewAllocation !== 100}
                >
                    Accept
                </button>
            </div>
        </div>
    );
};

export default RebalancePortfolio;
```

### Explanation

1. **Transforming Data**: The `fetchData` function now transforms the fetched data to fit the table's requirements.
2. **Editable New Allocation**: The `newAllocation` field is made editable. When it changes, the corresponding `change` field is updated to reflect the difference between `newAllocation` and `oldAllocation`.
3. **Highlight New Stocks**: Rows where `oldAllocation` is `0` are highlighted using the `bg-yellow-100` class.
4. **Total Allocation Check**: The total of `newAllocation` values is displayed and checked to ensure it adds up to 100%. The "Accept" button is disabled if the total is not 100%.

This implementation ensures the table is interactive and meets the specified requirements.