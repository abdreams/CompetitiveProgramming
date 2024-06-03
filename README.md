Sure, we can update the `PortfolioTable` component to display the profit/loss values in green or red based on their value. We'll use conditional classes to achieve this.

### Updated `PortfolioTable.js`

Here's the updated `PortfolioTable` component:

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
                <td className="py-2 px-4 border-b border-gray-200">
                  <span className={`block ${portfolio.profitLoss.startsWith('+') ? 'text-green-500' : 'text-red-500'}`}>
                    {`${portfolio.profitLoss.startsWith('+') ? '▲' : '▼'} ${portfolio.profitLoss}`}
                  </span>
                </td>
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

- **Conditional Classes**: We use `portfolio.profitLoss.startsWith('+')` to determine if the value is positive. If it is, we apply the `text-green-500` class; otherwise, we apply the `text-red-500` class.
- **Profit/Loss Display**: We display the value with an arrow (▲ or ▼) based on whether it is positive or negative.

### Complete Portfolio.jsx and PortfolioDiversity.jsx

Ensure that your `Portfolio.jsx` and `PortfolioDiversity.jsx` are correctly set up to pass the necessary props.

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

### Detailed View Page

If you want the detailed view to open on a separate page, you would typically use a router (e.g., React Router) to handle navigation to a new page. Here, we've implemented an inline expansion for simplicity.

You can further enhance this by navigating to a detailed view page using React Router and passing the selected portfolio data as props or through a state management solution like Redux.