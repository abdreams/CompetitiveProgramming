Sure, we'll refactor the components to meet your requirements. 

Here's the updated structure:

1. **`App.js`** - Handles routing.
2. **`Portfolio.jsx`** - Manages the main state and renders the `PortfolioTable` and `PortfolioDiversity` components.
3. **`PortfolioDiversity.jsx`** - Manages the view switching between `AllocationView`, `BondEquity`, and `AssetClass`.

### Step 1: Update the Project Structure

1. Create `PortfolioDiversity.jsx` to manage views.
2. Ensure `Portfolio.jsx` calls `PortfolioTable` and `PortfolioDiversity`.

### Step 2: Implement the Components

#### `App.js`
```jsx
import React from 'react';
import { BrowserRouter as Router, Route, Routes } from 'react-router-dom';
import Portfolio from './pages/Portfolio';

function App() {
  return (
    <Router>
      <Routes>
        <Route path="/" element={<Portfolio />} />
      </Routes>
    </Router>
  );
}

export default App;
```

#### `pages/Portfolio.jsx`
```jsx
import React, { useState } from 'react';
import PortfolioTable from '../components/PortfolioTable';
import PortfolioDiversity from '../components/PortfolioDiversity';

function Portfolio() {
  const [selectedPortfolio, setSelectedPortfolio] = useState(0);

  const sampleData = [
    {
      name: 'Portfolio 1',
      profitLoss: '+5%',
      invested: '$100,000',
      worth: '$105,000',
      allocation: {
        bigTech: 60,
        stocks: 12,
        energy: 11,
        ecommerce: 12,
        funds: 5,
        tsla: 40
      },
      bondEquity: {
        bonds: 50,
        equities: 50
      },
      assetClass: {
        realEstate: 25,
        commodities: 25,
        crypto: 25,
        others: 25
      }
    },
    {
      name: 'Portfolio 2',
      profitLoss: '-2%',
      invested: '$200,000',
      worth: '$196,000',
      allocation: {
        bigTech: 50,
        stocks: 20,
        energy: 10,
        ecommerce: 15,
        funds: 5,
        tsla: 30
      },
      bondEquity: {
        bonds: 40,
        equities: 60
      },
      assetClass: {
        realEstate: 20,
        commodities: 30,
        crypto: 30,
        others: 20
      }
    }
  ];

  return (
    <div className="min-h-screen bg-gray-100 flex flex-col items-center">
      <div className="bg-white shadow-md rounded-lg p-4 mt-4 w-full max-w-4xl">
        <PortfolioTable portfolios={sampleData} onSelectPortfolio={setSelectedPortfolio} />
        <PortfolioDiversity portfolio={sampleData[selectedPortfolio]} />
      </div>
    </div>
  );
}

export default Portfolio;
```

#### `components/PortfolioDiversity.jsx`
```jsx
import React, { useState } from 'react';
import AllocationView from './AllocationView';
import BondEquity from './BondEquity';
import AssetClass from './AssetClass';

function PortfolioDiversity({ portfolio }) {
  const [view, setView] = useState('AllocationView');

  const renderView = () => {
    switch (view) {
      case 'AllocationView':
        return <AllocationView data={portfolio.allocation} />;
      case 'BondEquity':
        return <BondEquity data={portfolio.bondEquity} />;
      case 'AssetClass':
        return <AssetClass data={portfolio.assetClass} />;
      default:
        return <AllocationView data={portfolio.allocation} />;
    }
  };

  return (
    <div className="bg-white shadow-md rounded-lg p-4 mt-4 w-full max-w-md">
      <div className="flex justify-around mb-4">
        <button onClick={() => setView('AllocationView')} className="px-4 py-2 text-sm font-medium text-white bg-blue-500 rounded hover:bg-blue-600">Allocation View</button>
        <button onClick={() => setView('BondEquity')} className="px-4 py-2 text-sm font-medium text-white bg-blue-500 rounded hover:bg-blue-600">Bond Equity</button>
        <button onClick={() => setView('AssetClass')} className="px-4 py-2 text-sm font-medium text-white bg-blue-500 rounded hover:bg-blue-600">Asset Class</button>
      </div>
      {renderView()}
    </div>
  );
}

export default PortfolioDiversity;
```

#### `components/PortfolioTable.js`
```jsx
import React from 'react';

function PortfolioTable({ portfolios, onSelectPortfolio }) {
  return (
    <div className="overflow-x-auto">
      <table className="min-w-full bg-white">
        <thead>
          <tr>
            <th className="py-2 px-4 border-b-2 border-gray-200 text-left leading-tight">Portfolio Name</th>
            <th className="py-2 px-4 border-b-2 border-gray-200 text-left leading-tight">Profit/Loss</th>
            <th className="py-2 px-4 border-b-2 border-gray-200 text-left leading-tight">Invested</th>
            <th className="py-2 px-4 border-b-2 border-gray-200 text-left leading-tight">Portfolio Worth</th>
          </tr>
        </thead>
        <tbody>
          {portfolios.map((portfolio, index) => (
            <tr key={index} onClick={() => onSelectPortfolio(index)} className="cursor-pointer hover:bg-gray-100">
              <td className="py-2 px-4 border-b border-gray-200">{portfolio.name}</td>
              <td className="py-2 px-4 border-b border-gray-200">{portfolio.profitLoss}</td>
              <td className="py-2 px-4 border-b border-gray-200">{portfolio.invested}</td>
              <td className="py-2 px-4 border-b border-gray-200">{portfolio.worth}</td>
            </tr>
          ))}
        </tbody>
      </table>
    </div>
  );
}

export default PortfolioTable;
```

#### `components/AllocationView.js`
```jsx
import React from 'react';
import { Doughnut } from 'react-chartjs-2';
import 'chart.js/auto';

function AllocationView({ data }) {
  const chartData = {
    labels: ['Big Tech', 'Stocks', 'Energy', 'Ecommerce', 'Funds'],
    datasets: [
      {
        data: [data.bigTech, data.stocks, data.energy, data.ecommerce, data.funds],
        backgroundColor: ['#FF6384', '#36A2EB', '#FFCE56', '#4BC0C0', '#9966FF'],
        hoverBackgroundColor: ['#FF6384', '#36A2EB', '#FFCE56', '#4BC0C0', '#9966FF']
      }
    ]
  };

  return (
    <div>
      <h2 className="text-xl font-semibold mb-2">Portfolio Diversity</h2>
      <Doughnut data={chartData} />
      <p className="mt-4 text-center">
        <span className="font-bold">TSLA</span> accounts for <span className="font-bold">{data.tsla}%</span> of your portfolio.
      </p>
      <a href="#" className="block mt-2 text-blue-500 underline text-center">You can read our guide on diversification</a>
    </div>
  );
}

export default AllocationView;
```

#### `components/BondEquity.js`
```jsx
import React from 'react';
import { Doughnut } from 'react-chartjs-2';
import 'chart.js/auto';

function BondEquity({ data }) {
  const chartData = {
    labels: ['Bonds', 'Equities'],
    datasets: [
      {
        data: [data.bonds, data.equities],
        backgroundColor: ['#FF6384', '#36A2EB'],
        hoverBackgroundColor: ['#FF6384', '#36A2EB']
      }
    ]
  };

  return (
    <div>
      <h2 className="text-xl font-semibold mb-2">Bond Equity</h2>
      <Doughnut data={chartData} />
      <p className="mt-4 text-center">Bond Equity distribution in your portfolio.</p>
    </div>
  );
}

export default BondEquity;
```

#### `components/AssetClass.js`
```jsx
import React from 'react';
import { Doughnut } from 'react-chartjs-2';
import 'chart.js/auto';

function AssetClass({ data }) {
  const chartData = {
    labels: ['Real Estate', 'Commodities', 'Crypto', 'Others'],
    datasets: [
      {
        data: [data.realEstate, data.commodities, data.crypto, data.others],
        backgroundColor: ['#FF6384', '#36A2EB', '#FFCE56', '#4BC0C0'],
        hoverBackgroundColor: ['#FF6384', '#36A2EB', '#FFCE56', '#4BC0C0']
      }
    ]
  };

  return (
    <div>
      <h2 className="text-xl
