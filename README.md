Let's adjust the `MarketSectorsPage` component to center it horizontally and move the "Market Sectors" heading to the center of the table. We'll also add sorting functionality directly on the column heading for the value column.

### 1. Update `MarketSectorsPage` Component

#### `MarketSectorsPage.js`

```jsx
// src/components/MarketSectorsPage.js
import React, { useState } from 'react';

const dummyData = [
  { name: 'NIFTY 50', value: 22550.40, change: 0.27 },
  { name: 'USD/INR', value: 83.52, change: 0.19 },
  { name: 'Gold', value: 7385.95, change: -0.07 },
  { name: 'NIFTY 100 Largecap', value: 23538.60, change: 0.31 },
  { name: 'NIFTY 100 Midcap', value: 51735.95, change: 0.60 },
  { name: 'NIFTY 100 Smallcap', value: 16710.25, change: 0.59 },
  { name: 'NIFTY Bank', value: 48982.40, change: 0.62 },
  { name: 'NIFTY IT', value: 32458.85, change: -1.06 },
  { name: 'NIFTY Pharma', value: 18849.70, change: -0.64 },
];

const MarketSectorsPage = () => {
  const [sortOrder, setSortOrder] = useState('asc');
  const [data, setData] = useState(dummyData);

  const sortData = (order) => {
    const sortedData = [...data].sort((a, b) => {
      if (order === 'asc') {
        return a.value - b.value;
      }
      return b.value - a.value;
    });
    setData(sortedData);
    setSortOrder(order);
  };

  const toggleSortOrder = () => {
    const newOrder = sortOrder === 'asc' ? 'desc' : 'asc';
    sortData(newOrder);
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
                className="py-2 px-4 border-b text-left cursor-pointer"
                onClick={toggleSortOrder}
              >
                Value
                {sortOrder === 'asc' ? ' ▲' : ' ▼'}
              </th>
              <th className="py-2 px-4 border-b text-left">Change</th>
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

### 2. Update CSS for Alignment

Ensure the container divs are centered and the table header is aligned properly.

#### Additional CSS (if needed)

If you are using Tailwind CSS, the above code should work as expected. If not, ensure your CSS is similar to the following:

```css
/* src/index.css or App.css */
.min-h-screen {
  min-height: 100vh;
}

.bg-gray-100 {
  background-color: #f7fafc;
}

.p-6 {
  padding: 1.5rem;
}

.bg-white {
  background-color: #ffffff;
}

.rounded-lg {
  border-radius: 0.5rem;
}

.shadow-md {
  box-shadow: 0 4px 6px rgba(0, 0, 0, 0.1);
}

.w-full {
  width: 100%;
}

.max-w-4xl {
  max-width: 64rem;
}

.mb-6 {
  margin-bottom: 1.5rem;
}

.text-3xl {
  font-size: 1.875rem;
}

.font-semibold {
  font-weight: 600;
}

.text-center {
  text-align: center;
}

.min-w-full {
  min-width: 100%;
}

.cursor-pointer {
  cursor: pointer;
}

.border-b {
  border-bottom: 1px solid #e2e8f0;
}

.text-left {
  text-align: left;
}

.py-2 {
  padding-top: 0.5rem;
  padding-bottom: 0.5rem;
}

.px-4 {
  padding-left: 1rem;
  padding-right: 1rem;
}

.text-green-500 {
  color: #48bb78;
}

.text-red-500 {
  color: #f56565;
}
```

### 3. Update `App.js` for Routing

Ensure that the routing and navigation to the `MarketSectorsPage` component is correctly set up as shown in the previous step.

Now, the `MarketSectorsPage` component should be centered horizontally on the page, and the table should allow sorting directly from the value column header. The "Market Sectors" heading is centered at the top of the table.