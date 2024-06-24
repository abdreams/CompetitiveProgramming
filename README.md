To implement form validation in the `RebalancePortfolio` component ensuring that all percent allocations add up to 100, we'll take the following steps:

1. Track the total allocation and remaining allocation state.
2. Display the remaining allocation to the user.
3. Validate the total allocation when user inputs are changed.
4. Display an error message if the allocation is not equal to 100.

Here's the updated code:

```jsx
import React, { useEffect, useState } from 'react';
import { useTable, usePagination, useGlobalFilter, useSortBy } from 'react-table';
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
    const [capital, setCapital] = useState('');
    const [totalAllocation, setTotalAllocation] = useState(0);
    const [allocationError, setAllocationError] = useState('');

    const fetchData = async () => {
        try {
            setLoading(true); // Start loader
            const response = await fetch(`https://dummy-url.com/api/rebalanced-portfolio/${portfolioId}`);
            if (!response.ok) {
                throw new Error('Network response was not ok');
            }
            const result = await response.json();
            setData(Object.entries(result.allocation).map(([stockSymbol, percentAllocated]) => ({ stockSymbol, percentAllocated })));
            setCapital(result.capital);
        } catch (error) {
            console.error('Error fetching data:', error);
            toast.error('Error fetching data, displaying dummy data instead.');
            setData([
                { stockSymbol: 'AAPL', percentAllocated: 20 },
                { stockSymbol: 'MSFT', percentAllocated: 15 },
                { stockSymbol: 'AMZN', percentAllocated: 10 },
                { stockSymbol: 'GOOGL', percentAllocated: 10 },
                { stockSymbol: 'FB', percentAllocated: 8 },
                { stockSymbol: 'TSLA', percentAllocated: 7 },
                { stockSymbol: 'NVDA', percentAllocated: 5 },
                { stockSymbol: 'NFLX', percentAllocated: 5 },
                { stockSymbol: 'ADBE', percentAllocated: 10 },
                { stockSymbol: 'CRM', percentAllocated: 10 }
            ]);
            setCapital('10004.64');
        } finally {
            setLoading(false); // Stop loader
        }
    };

    useEffect(() => {
        fetchData();
    }, []);

    useEffect(() => {
        const total = data.reduce((sum, stock) => sum + parseFloat(stock.percentAllocated || 0), 0);
        setTotalAllocation(total);
        if (total > 100) {
            setAllocationError('Total allocation cannot exceed 100%');
        } else if (total < 100) {
            setAllocationError('Total allocation must be exactly 100%');
        } else {
            setAllocationError('');
        }
    }, [data]);

    const handleInputChange = (e, rowIndex) => {
        const { name, value } = e.target;
        const updatedData = [...data];
        updatedData[rowIndex][name] = value;
        setData(updatedData);
    };

    const handleDelete = (rowIndex) => {
        const updatedData = data.filter((_, index) => index !== rowIndex);
        setData(updatedData);
    };

    const handleAccept = async () => {
        if (allocationError) {
            toast.error('Please ensure the total allocation is exactly 100% before saving.');
            return;
        }

        try {
            const allocation = data.reduce((acc, { stockSymbol, percentAllocated }) => {
                acc[stockSymbol] = parseFloat(percentAllocated); // Convert to float
                return acc;
            }, {});

            const payload = {
                pid: portfolioId,
                allocation,
                capital
            };

            const response = await fetch(`https://dummy-url.com/api/save-portfolio/${portfolioId}`, {
                method: 'POST',
                headers: {
                    'Content-Type': 'application/json',
                },
                body: JSON.stringify(payload),
            });

            if (response.ok) {
                toast.success('Portfolio saved successfully');
                localStorage.setItem('portfolioRebalanced', 'true'); // Set flag
                window.close(); // Close the tab
            } else {
                toast.error('Failed to save portfolio');
            }
        } catch (error) {
            toast.error('Error saving data');
        }
    };

    const handleReject = () => {
        localStorage.setItem('portfolioRebalanced', 'true'); // Set flag
        window.close(); // Close the tab
    };

    const columns = React.useMemo(
        () => [
            {
                Header: 'Stock Symbol',
                accessor: 'stockSymbol',
            },
            {
                Header: 'Percent Allocated',
                accessor: 'percentAllocated',
                Cell: ({ cell: { value }, row: { index } }) => (
                    <input
                        type="number"
                        name="percentAllocated"
                        value={value}
                        onChange={(e) => handleInputChange(e, index)}
                        className="w-full px-2 py-1 border rounded"
                        onClick={(e) => e.stopPropagation()} // Prevent row click
                    />
                ),
                sortType: 'basic',
            },
            {
                Header: 'Actions',
                Cell: ({ row: { index } }) => (
                    <button
                        onClick={(e) => {
                            e.stopPropagation(); // Prevent row click
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
        page,
        nextPage,
        previousPage,
        canNextPage,
        canPreviousPage,
        pageOptions,
        gotoPage,
        pageCount,
        prepareRow,
        state: { pageIndex },
        setGlobalFilter: setTableGlobalFilter,
    } = useTable(
        { columns, data, initialState: { pageIndex: 0, pageSize: 8 } },
        useGlobalFilter,
        useSortBy,
        usePagination
    );

    useEffect(() => {
        setTableGlobalFilter(globalFilter);
    }, [globalFilter, setTableGlobalFilter]);

    const handleRowClick = (row, e) => {
        if (e.target.nodeName !== 'INPUT' && e.target.nodeName !== 'BUTTON') { // Only navigate if target is not input or button
            navigate(`/stock-history/${row.original.stockSymbol}`);
        }
    };

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
                    {page.map(row => {
                        prepareRow(row);
                        return (
                            <tr
                                {...row.getRowProps()}
                                className="cursor-pointer"
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
            <div className="flex justify-between mt-5">
                <button onClick={() => previousPage()} disabled={!canPreviousPage} className="px-4 py-2 bg-gray-300 text-gray-700 rounded mr-3">
                    Previous
                </button>
                <div>
                    Page{' '}
                    <strong>
                        {pageIndex + 1} of {pageOptions.length}
                    </strong>
                </div>
                <button onClick={() => nextPage()} disabled={!canNextPage} className="px-4 py-2 bg-gray-300 text-gray-700 rounded ml-3">
                    Next
                </button>
            </div>
            <div