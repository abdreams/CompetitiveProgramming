To align the `PortfolioTable` and `PortfolioDiversity` components side by side, we need to update the CSS to use a flexbox layout with `flex-row` instead of `flex-col`.

Here's the corrected `Portfolio.jsx` to ensure the table and the portfolio diversity graph are displayed side by side:

### Updated `Portfolio.jsx`

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
    <div className="min-h-screen bg-gray-100 flex justify-center items-center p-4">
      <div className="flex w-full max-w-6xl space-x-4">
        <div className="w-1/2">
          <PortfolioTable portfolios={sampleData} onSelectPortfolio={setSelectedPortfolio} />
        </div>
        <div className="w-1/2">
          <PortfolioDiversity portfolio={sampleData[selectedPortfolio]} />
        </div>
      </div>
    </div>
  );
}

export default Portfolio;
```

### Explanation

- **`flex justify-center items-center p-4`**: Centers the content and adds some padding.
- **`flex w-full max-w-6xl space-x-4`**: Defines the main container with a max width and ensures space between the child elements using `space-x-4`.
- **`w-1/2`**: Splits the container into two equal parts for the table and the diversity components.

### Components

Ensure your components `PortfolioTable` and `PortfolioDiversity` have appropriate styles. The previous implementations should work without any changes, but ensure they fit within their respective containers.

#### `components/PortfolioTable.js`
```jsx
import React from 'react';

function PortfolioTable({ portfolios, onSelectPortfolio }) {
  return (
    <div className="overflow-x-auto bg-white shadow-md rounded-lg p-4">
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
    <div className="bg-white shadow-md rounded-lg p-4">
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

With these changes, the `PortfolioTable` and `PortfolioDiversity` components should be displayed side by side with some space between them.
