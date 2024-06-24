
To implement pagination for the `portfolio[0].stocks` in your table, we'll need to set up state for the current page and a function to handle page changes. We'll use Tailwind CSS for styling the table and pagination controls.

Here's how you can update your code to include pagination:

1. Add state for the current page and items per page.
2. Create a function to handle page changes.
3. Slice the data based on the current page.
4. Render pagination controls.

Here is the updated code with the pagination logic:

```jsx
import React, { useState, useMemo } from 'react';

const PaginatedTable = ({ portfolio }) => {
  const [currentPage, setCurrentPage] = useState(1);
  const itemsPerPage = 10;

  const stocks = portfolio[0]?.stocks || [];

  // Calculate total pages
  const totalPages = Math.ceil(stocks.length / itemsPerPage);

  // Get the current items using useMemo to avoid recalculating on every render
  const currentData = useMemo(() => {
    const start = (currentPage - 1) * itemsPerPage;
    const end = start + itemsPerPage;
    return stocks.slice(start, end);
  }, [currentPage, stocks]);

  // Handle page change
  const handlePageChange = (page) => {
    if (page >= 1 && page <= totalPages) {
      setCurrentPage(page);
    }
  };

  return (
    <div className="container mx-auto p-6">
      <div className="bg-white md:w-[40rem] w-[80vw] shadow-md rounded-lg p-4">
        <h3 className="text-lg font-medium mb-2">
          Stocks in <span className="underline text-[#D71E28]">{portfolio[0]?.name}</span>
        </h3>
        <table className="min-w-full divide-y divide-gray-200">
          <thead>
            <tr>
              <th className="py-2 px-4 border-b-2 border-gray-200 text-left leading-tight">Stock Symbol</th>
              <th className="py-2 px-4 border-b-2 border-gray-200 text-left leading-tight">Stock Price</th>
              <th className="py-2 px-4 border-b-2 border-gray-200 text-left leading-tight">Percentage</th>
            </tr>
          </thead>
          <tbody>
            {currentData.map((stock, index) => (
              <tr
                key={index}
                onClick={() => handleRowClick(stock?.stocksymbol)}
                className="hover:bg-gray-100 cursor-pointer"
              >
                <td className="py-2 px-4 border-b border-gray-200">{stock?.stocksymbol}</td>
                <td className="py-2 px-4 border-b border-gray-200">{stock?.closingprice}</td>
                <td className="py-2 px-4 border-b border-gray-200">{stock?.allocation}</td>
              </tr>
            ))}
          </tbody>
        </table>
        <div className="mt-4 flex justify-center">
          {Array.from({ length: totalPages }, (_, index) => (
            <button
              key={index}
              onClick={() => handlePageChange(index + 1)}
              className={`px-3 py-1 mx-1 border rounded ${
                currentPage === index + 1 ? 'bg-blue-500 text-white' : 'bg-white text-gray-700'
              }`}
            >
              {index + 1}
            </button>
          ))}
        </div>
      </div>
    </div>
  );
};

export default PaginatedTable;
```

### Explanation:

1. **State Management**:
   - `currentPage`: Holds the current page number.
   - `itemsPerPage`: Holds the number of items per page (set to 10).

2. **Memoization**:
   - `currentData` is calculated using `useMemo` to prevent unnecessary recalculations. It slices the `stocks` array to get only the items for the current page.

3. **Handle Page Change**:
   - `handlePageChange` updates the `currentPage` state to the selected page, ensuring it doesn't go out of bounds.

4. **Render Pagination Controls**:
   - Buttons for each page are rendered dynamically based on the `totalPages` calculation.
   - The `className` for the buttons is conditionally set to highlight the current page.

This approach ensures that your table pagination is efficient and prevents unnecessary re-renders or infinite loops.