To create a `MarketSectorsPage` component that opens when "See All" is clicked in the `MarketSectors` component, and contains a table with columns for name, value, and change along with a filter for high to low, follow these steps:

### 1. Create `MarketSectorsPage` Component

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

  return (
    <div className="min-h-screen bg-gray-100 p-6">
      <h2 className="text-3xl font-semibold mb-6">Market Sectors</h2>
      <button
        className="bg-blue-500 text-white px-4 py-2 rounded mb-4"
        onClick={() => sortData(sortOrder === 'asc' ? 'desc' : 'asc')}
      >
        Sort by Value ({sortOrder === 'asc' ? 'High to Low' : 'Low to High'})
      </button>
      <table className="min-w-full bg-white rounded-lg shadow-md">
        <thead>
          <tr>
            <th className="py-2 px-4 border-b">Name</th>
            <th className="py-2 px-4 border-b">Value</th>
            <th className="py-2 px-4 border-b">Change</th>
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
  );
};

export default MarketSectorsPage;
```

### 2. Update `App.js` for Routing

To handle the navigation, install `react-router-dom` if not already installed:

```bash
npm install react-router-dom
```

Then update `App.js` to include routing:

```jsx
// src/App.js
import React from 'react';
import { BrowserRouter as Router, Route, Switch } from 'react-router-dom';
import Marquee from './components/Marquee';
import Navbar from './components/Navbar';
import MarketStatus from './components/MarketStatus';
import MarketSectors from './components/MarketSectors';
import GetStarted from './components/GetStarted';
import News from './components/News';
import TodaysStocks from './components/TodaysStocks';
import MarketSectorsPage from './components/MarketSectorsPage';

const App = () => {
  return (
    <Router>
      <div className="min-h-screen bg-gray-100">
        <Navbar />
        <Marquee />
        <MarketStatus />
        <Switch>
          <Route exact path="/">
            <div className="p-6">
              <MarketSectors />
              <div className="flex justify-between mt-6">
                <div className="w-2/3 mr-6">
                  <GetStarted />
                  <TodaysStocks />
                </div>
                <div className="w-1/3">
                  <News />
                </div>
              </div>
            </div>
          </Route>
          <Route path="/market-sectors" component={MarketSectorsPage} />
        </Switch>
      </div>
    </Router>
  );
};

export default App;
```

### 3. Update `MarketSectors.js`

Ensure that clicking "See All" navigates to the `MarketSectorsPage`.

```jsx
// src/components/MarketSectors.js
import React from 'react';
import { Link } from 'react-router-dom';

const MarketSectors = () => {
  return (
    <div className="bg-white p-6 rounded-lg shadow-md mb-6">
      <div className="flex justify-between items-center mb-4">
        <h2 className="text-2xl font-semibold">Market and sectors</h2>
        <Link to="/market-sectors" className="text-blue-500">See All</Link>
      </div>
      <table className="min-w-full bg-white rounded-lg shadow-md">
        <thead>
          <tr>
            <th className="py-2 px-4 border-b">Name</th>
            <th className="py-2 px-4 border-b">Value</th>
            <th className="py-2 px-4 border-b">Change</th>
          </tr>
        </thead>
        <tbody>
          {/* Populate with data similar to the example */}
        </tbody>
      </table>
    </div>
  );
};

export default MarketSectors;
```

### Final Steps

1. Create `src/components/MarketSectorsPage.js`.
2. Update `App.js` to include routing.
3. Update `MarketSectors.js` to navigate to the new page.

This setup will enable you to click "See All" in the `MarketSectors` component and navigate to a new page (`MarketSectorsPage`) with a table that can be sorted by value.