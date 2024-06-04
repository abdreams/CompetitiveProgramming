Absolutely! Here's the updated `MarketSectorsPage.js` with a search bar that filters by name using a hook:

```javascript
import React, { useState } from 'react';

const dummyData = [
  { name: 'NIFTY 50', value: 22550.40, change: 0.27 },
  // ... other data
];

const MarketSectorsPage = () => {
  const [sortOrderValue, setSortOrderValue] = useState('asc');
  const [sortOrderChange, setSortOrderChange] = useState(null);
  const [searchQuery, setSearchQuery] = useState(''); // State for search query
  const [filteredData, setFilteredData] = useState(dummyData); // State for filtered data

  const sortData = (order, field) => {
    // ... existing sort logic
  };

  const toggleSortOrderValue = () => {
    // ... existing logic
  };

  const toggleSortOrderChange = () => {
    // ... existing logic
  };

  const handleSearch = (event) => {
    const query = event.target.value.toLowerCase();
    setSearchQuery(query);
    const filtered = dummyData.filter((sector) => sector.name.toLowerCase().includes(query));
    setFilteredData(filtered);
  };

  return (
    <div className="flex justify-center items-center min-h-screen bg-gray-100 p-6">
      <div className="bg-white p-6 rounded-lg shadow-md w-full max-w-4xl">
        <h2 className="text-3xl font-semibold mb-6 text-center">Market Sectors</h2>
        <div className="mb-4">
          <input
            className="px-3 py-2 border rounded-lg focus:outline-none focus:ring-1 focus:ring-blue-500"
            type="text"
            placeholder="Search by Name"
            value={searchQuery}
            onChange={handleSearch}
          />
        </div>
        <table className="min-w-full bg-white rounded-lg shadow-md">
          <thead>
            <tr>
              <th className="py-2 px-4 border-b text-left">Name</th>
              <th
                className={`py-2 px-4 border-b text-left cursor-pointer`}
                onClick={toggleSortOrderValue}
              >
                Value
                {sortOrderValue === 'asc' ? ' ▲' : ' ▼'}
              </th>
              <th
                className={`py-2 px-4 border-b text-left cursor-pointer`}
                onClick={toggleSortOrderChange}
              >
                Change
                {sortOrderChange === 'asc' ? ' ▲' : sortOrderChange === 'desc' ? ' ▼' : ''}
              </th>
            </tr>
          </thead>
          <tbody>
            {filteredData.map((sector, index) => (
              <tr key={index}>
                <td className="py-2 px-4 border-b">{sector.name}</td>
                <td className="py-2 px-4 border-b">{sector.value.toFixed(2)}</td>
                <td className={`py-2 px-4 border-b ${sector.change > 0 ? 'text-green-500' : 'text-red-500'}`}>
                  {sector.change > 0 ? `▲ ${sector.change}%` : `▼ ${sector.change}%`}
                </td>
              </tr>
            ))}
          </tbody>
        </table>
      </div>
    </div>
  );
};

export default MarketSectorsPage;
```

Changes made:

1. **Search State and Function:** We added a new state `searchQuery` to store the user's search term and a function `handleSearch` to update it as the user types.
2. **Filtered Data:** We introduced a new state `filteredData` to hold the data after applying the search filter.
3. **Filtering Logic:** The `handleSearch` function filters the original data (`dummyData`) based on the lowercase search term and updates the `filteredData` state.
4. **Displaying Filtered Data:** The table body now iterates through `filteredData` instead of `dummyData` to display the filtered results.
5. **Search Bar:** We added an input element with styling and placeholder text for the search bar.
