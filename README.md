To implement a scrollable table with a fixed height where only 10 stocks are visible at a time, you can use CSS to achieve this. This approach will allow you to scroll through the table using the mouse or the scrollbar. Here is the modified version of the `StocksTable` component:

### StocksTable Component with Scroll

```jsx
import React, { useMemo } from 'react';
import { useTable } from 'react-table';

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
    rows,
  } = useTable({
    columns,
    data,
  });

  return (
    <div className="container mx-auto p-6">
      <div className="bg-white w-full shadow-md rounded-lg p-4">
        <h3 className="text-lg font-medium mb-2">Stocks</h3>
        <div className="overflow-y-auto max-h-96">
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
              {rows.map((row, i) => {
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
        </div>
      </div>
    </div>
  );
};

export default StocksTable;
```

### Explanation

1. **Container with Fixed Height**:
   - The table is wrapped inside a `<div>` with a class of `overflow-y-auto max-h-96`. This makes the container scrollable on the y-axis, and it ensures the height doesn't exceed a certain limit (`max-h-96` which is approximately 24rem).

2. **Tailwind CSS Classes**:
   - `overflow-y-auto` enables vertical scrolling.
   - `max-h-96` sets the maximum height of the table's container. Adjust this value based on the height of your rows to ensure approximately 10 rows are visible at a time.

3. **Table Headers and Rows**:
   - `useTable` is used to manage the table structure and data.
   - Headers and rows are dynamically rendered based on the data and columns.

### Example Usage in Main Page

Now, you can use this component in your main page and pass the stock data as props.

```jsx
import React from 'react';
import StocksTable from './StocksTable';

const MainPage = () => {
  const stockData = [
    { stocksymbol: 'AAPL', stockprice: 150