To create a table with pagination using `react-table`, you can follow the example below. This implementation will include a table with headers for `stocksymbol`, `stockprice`, and `percentage`, and will paginate the data to show 10 stocks per page.

First, you'll need to install `react-table` if you haven't already:

```bash
npm install react-table
```

### StocksTable Component with Pagination

```jsx
import React, { useMemo } from 'react';
import { useTable, usePagination } from 'react-table';

const StocksTable = ({ stocks }) => {
  const data = useMemo(() => stocks, [stocks]);

  const columns = useMemo(
    () => [
      {
        Header: 'Stock Symbol',
        accessor: 'stocksymbol',
      },
      {
        Header: 'Stock Price',
        accessor: 'stockprice',
      },
      {
        Header: 'Percentage',
        accessor: 'percentage',
      },
    ],
    []
  );

  const {
    getTableProps,
    getTableBodyProps,
    headerGroups,
    prepareRow,
    page, // Instead of rows, we use page, which has only the rows for the active page
    canPreviousPage,
    canNextPage,
    pageOptions,
    pageCount,
    gotoPage,
    nextPage,
    previousPage,
    setPageSize,
    state: { pageIndex, pageSize },
  } = useTable(
    {
      columns,
      data,
      initialState: { pageIndex: 0, pageSize: 10 },
    },
    usePagination
  );

  return (
    <div className="container mx-auto p-6">
      <div className="bg-white w-full shadow-md rounded-lg p-4">
        <h3 className="text-lg font-medium mb-2">Stocks</h3>
        <table {...getTableProps()} className="min-w-full divide-y divide-gray-200">
          <thead>
            {headerGroups.map(headerGroup => (
              <tr {...headerGroup.getHeaderGroupProps()}>
                {headerGroup.headers.map(column => (
                  <th
                    {...column.getHeaderProps()}
                    className="py-2 px-4 border-b-2 border-gray-200 text-left leading-tight"
                  >
                    {column.render('Header')}
                  </th>
                ))}
              </tr>
            ))}
          </thead>
          <tbody {...getTableBodyProps()}>
            {page.map(row => {
              prepareRow(row);
              return (
                <tr {...row.getRowProps()} className="hover:bg-gray-100 cursor-pointer">
                  {row.cells.map(cell => (
                    <td
                      {...cell.getCellProps()}
                      className="py-2 px-4 border-b border-gray-200"
                    >
                      {cell.render('Cell')}
                    </td>
                  ))}
                </tr>
              );
            })}
          </tbody>
        </table>
        <div className="pagination mt-4 flex justify-between items-center">
          <button
            onClick={() => gotoPage(0)}
            disabled={!canPreviousPage}
            className="px-4 py-2 border rounded mr-2"
          >
            {'<<'}
          </button>
          <button
            onClick={() => previousPage()}
            disabled={!canPreviousPage}
            className="px-4 py-2 border rounded mr-2"
          >
            {'<'}
          </button>
          <span>
            Page{' '}
            <strong>
              {pageIndex + 1} of {pageOptions.length}
            </strong>{' '}
          </span>
          <button
            onClick={() => nextPage()}
            disabled={!canNextPage}
            className="px-4 py-2 border rounded ml-2"
          >
            {'>'}
          </button>
          <button
            onClick={() => gotoPage(pageCount - 1)}
            disabled={!canNextPage}
            className="px-4 py-2 border rounded ml-2"
          >
            {'>>'}
          </button>
          <select
            value={pageSize}
            onChange={e => {
              setPageSize(Number(e.target.value));
            }}
            className="ml-4 border rounded px-4 py-2"
          >
            {[10, 20, 30, 40, 50].map(pageSize => (
              <option key={pageSize} value={pageSize}>
                Show {pageSize}
              </option>
            ))}
          </select>
        </div>
      </div>
    </div>
  );
};

export default StocksTable;
```

### Example Usage in Main Page

Now, you can use this component in your main page and pass the stock data as props.

```jsx
import React from 'react';
import StocksTable from './StocksTable';

const MainPage = () => {
  const stockData = [
    { stocksymbol: 'AAPL', stockprice: 150.25, percentage: 2.5 },
    { stocksymbol: 'GOOGL', stockprice: 2800.50, percentage: 1.2 },
    { stocksymbol: 'MSFT', stockprice: 299.30, percentage: 1.8 },
    // Add more stock data as needed
  ];

  return (
    <div>
      <h1 className="text-3xl font-bold text-center my-6">My Stock Portfolio</h1>
      <StocksTable stocks={stockData} />
    </div>
  );
};

export default MainPage;
```

### Explanation

1. **StocksTable Component**:
   - Uses `react-table` hooks to manage table and pagination.
   - The `useTable` hook initializes the table with columns and data.
   - The `usePagination` hook handles the pagination logic.
   - Renders the table headers and rows dynamically.
   - Pagination controls at the bottom allow navigation between pages and changing the number of rows per page.

2. **MainPage Component**:
   - Passes the stock data to `Stocks