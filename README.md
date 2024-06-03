Sure, we'll add functionality to expand a detailed view of a portfolio below the selected row in the `PortfolioTable`. We will use state to manage which portfolio is expanded and conditionally render the detailed view.

### Step 1: Update `PortfolioTable` Component

First, let's update the `PortfolioTable` component to handle the click event and manage the expanded state.

#### `components/PortfolioTable.js`

```jsx
import React, { useState } from 'react';

function PortfolioTable({ portfolios, onSelectPortfolio }) {
  const [expandedPortfolio, setExpandedPortfolio] = useState(null);

  const toggleExpand = (index) => {
    setExpandedPortfolio(expandedPortfolio === index ? null : index);
  };

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
            <React.Fragment key={index}>
              <tr onClick={() => { onSelectPortfolio(index); toggleExpand(index); }} className="cursor-pointer hover:bg-gray-100">
                <td className="py-2 px-4 border-b border-gray-200">{portfolio.name}</td>
                <td className="py-2 px-4 border-b border-gray-200">{portfolio.profitLoss}</td>
                <td className="py-2 px-4 border-b border-gray-200">{portfolio.invested}</td>
                <td className="py-2 px-4 border-b border-gray-200">{portfolio.worth}</td>
              </tr>
              {expandedPortfolio === index && (
                <tr className="bg-gray-100">
                  <td colSpan="4" className="p-4">
                    <div className="p-4 bg-white shadow-md rounded-lg">
                      <h3 className="text-lg font-medium mb-2">Detailed View for {portfolio.name}</h3>
                      <p><strong>Profit/Loss:</strong> {portfolio.profitLoss}</p>
                      <p><strong>Invested:</strong> {portfolio.invested}</p>
                      <p><strong>Portfolio Worth:</strong> {portfolio.worth}</p>
                      <p><strong>Allocation:</strong> {JSON.stringify(portfolio.allocation)}</p>
                      <p><strong>Bond Equity:</strong> {JSON.stringify(portfolio.bondEquity)}</p>
                      <p><strong>Asset Class:</strong> {JSON.stringify(portfolio.assetClass)}</p>
                    </div>
                  </td>
                </tr>
              )}
            </React.Fragment>
          ))}
        </tbody>
      </table>
    </div>
  );
}

export default PortfolioTable;
```

### Explanation

- **State Management**: `expandedPortfolio` is used to track which portfolio is currently expanded.
- **Toggle Function**: `toggleExpand` toggles the expanded state for the clicked portfolio row.
- **Conditional Rendering**: If `expandedPortfolio` matches the current row index, an additional row with detailed information is rendered below the selected row.

### Step 2: Update `Portfolio.jsx` for Consistency

Ensure that `Portfolio.jsx` passes the necessary props to `PortfolioTable` and handles the layout correctly.

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

With these changes, clicking on a portfolio row in the table will expand to show a detailed view directly below it, with an animation effect due to the conditional rendering. This detailed view includes comprehensive information about the selected portfolio.
