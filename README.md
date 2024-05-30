Sure! We'll create sample data for the Bond Equity and Asset Class views and integrate them similarly to how we did for the Allocation View. We'll also ensure that the navigation among these views works seamlessly.

### Step 1: Update Sample Data

Update the sample data to include information for Bond Equity and Asset Class.

### Step 2: Create Chart Data and Components

#### `App.js`
```jsx
import React, { useState } from 'react';
import AllocationView from './components/AllocationView';
import BondEquity from './components/BondEquity';
import AssetClass from './components/AssetClass';

function App() {
  const [view, setView] = useState('AllocationView');
  const sampleData = {
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
  };

  const renderView = () => {
    switch (view) {
      case 'AllocationView':
        return <AllocationView data={sampleData.allocation} />;
      case 'BondEquity':
        return <BondEquity data={sampleData.bondEquity} />;
      case 'AssetClass':
        return <AssetClass data={sampleData.assetClass} />;
      default:
        return <AllocationView data={sampleData.allocation} />;
    }
  };

  return (
    <div className="min-h-screen bg-gray-100 flex flex-col items-center">
      <div className="bg-white shadow-md rounded-lg p-4 mt-4 w-full max-w-md">
        <div className="flex justify-around mb-4">
          <button onClick={() => setView('AllocationView')} className="px-4 py-2 text-sm font-medium text-white bg-blue-500 rounded hover:bg-blue-600">Allocation View</button>
          <button onClick={() => setView('BondEquity')} className="px-4 py-2 text-sm font-medium text-white bg-blue-500 rounded hover:bg-blue-600">Bond Equity</button>
          <button onClick={() => setView('AssetClass')} className="px-4 py-2 text-sm font-medium text-white bg-blue-500 rounded hover:bg-blue-600">Asset Class</button>
        </div>
        {renderView()}
      </div>
    </div>
  );
}

export default App;
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
      <h2 className="text-xl font-semibold mb-2">Asset Class</h2>
      <Doughnut data={chartData} />
      <p className="mt-4 text-center">Asset Class distribution in your portfolio.</p>
    </div>
  );
}

export default AssetClass;
```

### Step 3: Tailwind CSS Configuration

Ensure your Tailwind CSS is properly configured by following the setup guide and adding the required configurations in your `tailwind.config.js` file.

### Running the Project

After setting everything up, run your project using:

```bash
npm start
```

This will give you a working implementation with separate components for Allocation View, Bond Equity, and Asset Class, each displaying its respective data using React, Tailwind CSS, and Chart.js.
