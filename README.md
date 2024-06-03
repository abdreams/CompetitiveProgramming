To implement the requested functionality, we'll make use of React Router for navigation between pages. We'll create a detailed view page that displays detailed information about the selected portfolio.

Here's the step-by-step implementation:

### Step 1: Install React Router
If you haven't already installed React Router, install it using npm:

```bash
npm install react-router-dom
```

### Step 2: Set Up Routing in `App.js`

Update `App.js` to include routing for the portfolio summary and detailed view pages.

#### `App.js`

```jsx
import React from 'react';
import { BrowserRouter as Router, Route, Switch } from 'react-router-dom';
import Portfolio from './pages/Portfolio';
import PortfolioDetail from './pages/PortfolioDetail';

function App() {
  return (
    <Router>
      <Switch>
        <Route exact path="/" component={Portfolio} />
        <Route path="/portfolio/:id" component={PortfolioDetail} />
      </Switch>
    </Router>
  );
}

export default App;
```

### Step 3: Update `PortfolioTable` to Include a Button for Detailed View

Add a button in `PortfolioTable` to navigate to the detailed view page of a selected portfolio.

#### `components/PortfolioTable.js`

```jsx
import React, { useState } from 'react';
import { useHistory } from 'react-router-dom';

function PortfolioTable({ portfolios, onSelectPortfolio }) {
  const [expandedPortfolio, setExpandedPortfolio] = useState(null);
  const history = useHistory();

  const toggleExpand = (index) => {
    setExpandedPortfolio(expandedPortfolio === index ? null : index);
  };

  const goToDetailView = (index) => {
    history.push(`/portfolio/${index}`);
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
            <th className="py-2 px-4 border-b-2 border-gray-200 text-left leading-tight">Actions</th>
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
                <td className="py-2 px-4 border-b border-gray-200">
                  <button 
                    onClick={() => goToDetailView(index)} 
                    className="bg-blue-500 text-white px-3 py-1 rounded hover:bg-blue-600"
                  >
                    Detailed View
                  </button>
                </td>
              </tr>
              {expandedPortfolio === index && (
                <tr className="bg-gray-100">
                  <td colSpan="5" className="p-4">
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

### Step 4: Create the `PortfolioDetail` Page

Create a new page for displaying the detailed view of a selected portfolio.

#### `pages/PortfolioDetail.jsx`

```jsx
import React from 'react';
import { useParams } from 'react-router-dom';
import PortfolioDiversity from '../components/PortfolioDiversity';

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
    },
    stocks: [
      { name: 'AAPL', percentage: 20 },
      { name: 'GOOGL', percentage: 15 },
      { name: 'TSLA', percentage: 25 },
      { name: 'AMZN', percentage: 20 },
      { name: 'MSFT', percentage: 20 }
    ]
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
    },
    stocks: [
      { name: 'NFLX', percentage: 10 },
      { name: 'DIS', percentage: 20 },
      { name: 'FB', percentage: 20 },
      { name: 'NVDA', percentage: 25 },
      { name: 'ADBE', percentage: 25 }
    ]
  }
];

function PortfolioDetail() {
  const { id } = useParams();
  const portfolio = sampleData[id];

  const handleRebalance = () => {
    // Simulate an API call to rebalance the portfolio
    console.log(`Rebalancing portfolio ${portfolio.name}`);
    alert('Portfolio rebalanced successfully!');
  };

  return (
    <div className="min-h-screen bg-gray-100 p-4">
      <div className="flex space-x-4">
        <div className="w-1/3 bg-white shadow-md rounded-lg p-4">
          <h3 className="text-lg font-medium mb-2">Stocks in {portfolio.name}</h3>
          <table className="min-w-full bg-white">
            <thead>
              <tr>
                <th className="py-2 px-4 border-b-2 border-gray-200 text-left leading-tight">Stock Name</th>
                <th className="py-2 px-4 border-b-2 border-gray-200 text-left leading-tight">Percentage</th>
              </tr>
            </thead>
            <tbody>
              {portfolio.stocks.map((stock, index) => (
                <tr key={index} className="hover:bg-gray-100">
                  <td className="py-2 px-4 border-b border-gray-200">{stock.name}</td>
                  <td className="py-2 px-4 border-b border-gray-200">{stock.percentage}%</td>
                </tr>
              ))}
            </tbody>
          </table>
          <button 
            onClick={handleRebalance} 
            className="mt-4 bg-blue-500 text-white px-4 py-2 rounded hover:bg-blue-600"
          >
            Rebalance Portfolio
          </button>
        </div>
        <div className="w-2/3 flex flex-col space-y-4">
          <div className="bg-white shadow-md rounded-lg p-4">
            <PortfolioDiversity portfolio={portfolio} />
          </div>
          <div className="bg-white shadow-md rounded-lg p-4">
            <h3 className="text-lg font-medium mb-2">Overall Performance</h3>
            <p><strong>Profit/Loss:</strong> {portfolio.profitLoss'''

Sure, I'll complete the detailed view for the `PortfolioDetail` page, including the overall performance section.

### Complete `PortfolioDetail.jsx`

#### `pages/PortfolioDetail.jsx`

```jsx
import React from 'react';
import { useParams } from 'react-router-dom';
import PortfolioDiversity from '../components/PortfolioDiversity';

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
    },
    stocks: [
      { name: 'AAPL', percentage: 20 },
      { name: 'GOOGL', percentage: 15 },
      { name: 'TSLA', percentage: 25 },
      { name: 'AMZN', percentage: 20 },
      { name: 'MSFT', percentage: 20 }
    ]
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
    },
    stocks: [
      { name: 'NFLX', percentage: 10 },
      { name: 'DIS', percentage: 20 },
      { name: 'FB', percentage: 20 },
      { name: 'NVDA', percentage: 25 },
      { name: 'ADBE', percentage: 25 }
    ]
  }
];

function PortfolioDetail() {
  const { id } = useParams();
  const portfolio = sampleData[id];

  const handleRebalance = () => {
    // Simulate an API call to rebalance the portfolio
    console.log(`Rebalancing portfolio ${portfolio.name}`);
    alert('Portfolio rebalanced successfully!');
  };

  return (
    <div className="min-h-screen bg-gray-100 p-4">
      <div className="flex space-x-4">
        <div className="w-1/3 bg-white shadow-md rounded-lg p-4">
          <h3 className="text-lg font-medium mb-2">Stocks in {portfolio.name}</h3>
          <table className="min-w-full bg-white">
            <thead>
              <tr>
                <th className="py-2 px-4 border-b-2 border-gray-200 text-left leading-tight">Stock Name</th>
                <th className="py-2 px-4 border-b-2 border-gray-200 text-left leading-tight">Percentage</th>
              </tr>
            </thead>
            <tbody>
              {portfolio.stocks.map((stock, index) => (
                <tr key={index} className="hover:bg-gray-100">
                  <td className="py-2 px-4 border-b border-gray-200">{stock.name}</td>
                  <td className="py-2 px-4 border-b border-gray-200">{stock.percentage}%</td>
                </tr>
              ))}
            </tbody>
          </table>
          <button 
            onClick={handleRebalance} 
            className="mt-4 bg-blue-500 text-white px-4 py-2 rounded hover:bg-blue-600"
          >
            Rebalance Portfolio
          </button>
        </div>
        <div className="w-2/3 flex flex-col space-y-4">
          <div className="bg-white shadow-md rounded-lg p-4">
            <PortfolioDiversity portfolio={portfolio} />
          </div>
          <div className="bg-white shadow-md rounded-lg p-4">
            <h3 className="text-lg font-medium mb-2">Overall Performance</h3>
            <p><strong>Profit/Loss:</strong> {portfolio.profitLoss}</p>
            <p><strong>Invested:</strong> {portfolio.invested}</p>
            <p><strong>Portfolio Worth:</strong> {portfolio.worth}</p>
            <p><strong>Allocation:</strong> {JSON.stringify(portfolio.allocation, null, 2)}</p>
            <p><strong>Bond Equity:</strong> {JSON.stringify(portfolio.bondEquity, null, 2)}</p>
            <p><strong>Asset Class:</strong> {JSON.stringify(portfolio.assetClass, null, 2)}</p>
          </div>
        </div>
      </div>
    </div>
  );
}

export default PortfolioDetail;
```

### Explanation

- **Detailed View Button**: The `PortfolioTable` component has been updated to include a button that navigates to the detailed view page.
- **React Router**: The `PortfolioDetail` page is set up to receive the portfolio ID via the URL parameters.
- **Detailed View Layout**: The detailed view displays the stocks in the portfolio on the left and the `PortfolioDiversity` and overall performance on the right, one below the other.
- **Rebalance Button**: A button to rebalance the portfolio is provided, which simulates an API call and shows an alert upon clicking.

### Updated Portfolio Diversity Component

Ensure that `PortfolioDiversity` is set up to accept a portfolio prop correctly and render the allocation view, asset class, and bond equity.

#### `components/PortfolioDiversity.js`

```jsx
import React, { useState } from 'react';
import AllocationView from './AllocationView';
import AssetClass from './AssetClass';
import BondEquity from './BondEquity';

function PortfolioDiversity({ portfolio }) {
  const [view, setView] = useState('allocation');

  return (
    <div className="bg-white shadow-md rounded-lg p-4">
      <div className="flex justify-around mb-4">
        <button 
          className={`px-4 py-2 ${view === 'allocation' ? 'bg-blue-500 text-white' : 'bg-gray-200 text-black'} rounded`}
          onClick={() => setView('allocation')}
        >
          Allocation View
        </button>
        <button 
          className={`px-4 py-2 ${view === 'bond' ? 'bg-blue-500 text-white' : 'bg-gray-200 text-black'} rounded`}
          onClick={() => setView('bond')}
        >
          Bond Equity
        </button>
        <button 
          className={`px-4 py-2 ${view === 'asset' ? 'bg-blue-500 text-white' : 'bg-gray-200 text-black'} rounded`}
          onClick={() => setView('asset')}
        >
          Asset Class
        </button>
      </div>
      {view === 'allocation' && <AllocationView allocation={portfolio.allocation} />}
      {view === 'bond' && <BondEquity bondEquity={portfolio.bondEquity} />}
      {view === 'asset' && <AssetClass assetClass={portfolio.assetClass} />}
    </div>
  );
}

export default PortfolioDiversity;
```

Now you have a setup where clicking on a portfolio in the summary navigates to a detailed view page, which displays detailed information about the portfolio and allows rebalancing.