To implement pagination for a table in React with 10 rows per page, you can follow these steps:

1. Create a state to manage the current page.
2. Slice the data based on the current page to display only the rows for that page.
3. Create functions to handle page changes.
4. Render the table with the paginated data.

Here's a complete example:

### Step-by-Step Implementation

#### 1. Setup State and Data

First, let's set up the state for the current page and the data:

```jsx
import React, { useState } from 'react';

const data = [
  // Add your data here
  // Example:
  { id: 1, name: 'John Doe', age: 28, job: 'Engineer' },
  { id: 2, name: 'Jane Smith', age: 34, job: 'Doctor' },
  { id: 3, name: 'Peter Johnson', age: 23, job: 'Developer' },
  // Add more data up to your desired length
  // ...
];

const itemsPerPage = 10;

const PaginatedTable = () => {
  const [currentPage, setCurrentPage] = useState(1);

  // Calculate total pages
  const totalPages = Math.ceil(data.length / itemsPerPage);

  // Get the current items
  const currentData = data.slice(
    (currentPage - 1) * itemsPerPage,
    currentPage * itemsPerPage
  );

  // Handle page change
  const handlePageChange = (page) => {
    setCurrentPage(page);
  };

  return (
    <div>
      <table>
        <thead>
          <tr>
            <th>ID</th>
            <th>Name</th>
            <th>Age</th>
            <th>Job</th>
          </tr>
        </thead>
        <tbody>
          {currentData.map((item) => (
            <tr key={item.id}>
              <td>{item.id}</td>
              <td>{item.name}</td>
              <td>{item.age}</td>
              <td>{item.job}</td>
            </tr>
          ))}
        </tbody>
      </table>
      <div>
        {Array.from({ length: totalPages }, (_, index) => (
          <button
            key={index}
            onClick={() => handlePageChange(index + 1)}
            disabled={currentPage === index + 1}
          >
            {index + 1}
          </button>
        ))}
      </div>
    </div>
  );
};

export default PaginatedTable;
```

### Explanation

1. **State Initialization**:
   - `currentPage` is used to track the current page number.
   - `itemsPerPage` is set to 10, defining the number of rows per page.

2. **Total Pages Calculation**:
   - `totalPages` is calculated using `Math.ceil(data.length / itemsPerPage)` to determine the total number of pages.

3. **Current Data Slicing**:
   - `currentData` is derived from the `data` array using `slice` to get only the rows for the current page.

4. **Page Change Handling**:
   - `handlePageChange` updates the `currentPage` state when a page number button is clicked.

5. **Rendering**:
   - The table is rendered using the `currentData`.
   - Pagination buttons are created using `Array.from`, mapping through the total pages and generating buttons for each page.
   - The `disabled` attribute is set on the current page button to prevent reloading the same page.

This code snippet provides a basic paginated table with navigation buttons. You can style the table and buttons further using CSS or a library like `tailwindcss` to match your design requirements.