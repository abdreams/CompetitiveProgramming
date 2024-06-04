Here's the updated `MarketSectorsPage.js` component with a separate arrow for sorting by change:

```javascript
import React, { useState } from 'react';

const dummyData = [
  { name: 'NIFTY 50', value: 22550.40, change: 0.27 },
  // ... other data
];

const MarketSectorsPage = () => {
  const [sortOrderValue, setSortOrderValue] = useState('asc'); // Sort order for value
  const [sortOrderChange, setSortOrderChange] = useState(null); // Sort order for change (null means not sorted by change)

  const [data, setData] = useState(dummyData);

  const sortData = (order, field) => {
    const sortedData = [...data].sort((a, b) => {
      if (field === 'value') {
        if (order === 'asc') {
          return a.value - b.value;
        }
        return b.value - a.value;
      } else if (field === 'change') {
        if (order === 'asc') {
          return a.change - b.change;
        }
        return b.change - a.change;
      }
      // Default to sorting by value
      return a.value - b.value;
    });
    setData(sortedData);
  };

  const toggleSortOrderValue = () => {
    const newOrder = sortOrderValue === 'asc' ? 'desc' : 'asc';
    sortData(newOrder, 'value');
    setSortOrderValue(newOrder);
  };

  const toggleSortOrderChange = () => {
    const newOrder = sortOrderChange === null ? 'asc' : (sortOrderChange === 'asc' ? 'desc' : null);
    sortData(newOrder, 'change');
    setSortOrderChange(newOrder);
  };

  return (
    <div className="flex justify-center items-center min-h-screen bg-gray-100 p-6">
      <div className="bg-white p-6 rounded-lg shadow-md w-full max-w-4xl">
        <h2 className="text-3xl font-semibold mb-6 text-center">Market Sectors</h2>
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
            {data.map((sector, index) => (
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

1. **Separate Sort State:** We introduced two separate states: `sortOrderValue` for value sorting and `sortOrderChange` for change sorting. `sortOrderChange` can be null, indicating no sorting by change is applied.
2. **`sortData` Function Update:** The `sortData` function now takes an additional parameter `field` to specify which field to sort by (`value` or `change`).
3. **Separate Toggle Functions:** We created separate toggle functions `toggleSortOrderValue` and `toggleSortOrderChange` to handle sorting by value and change independently.
4. **Arrow Logic for Change:** The table header for "Change" now displays an arrow only when sorted by change (`sortOrderChange`