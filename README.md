To use real data and route it correctly, we need to remove the sample data and fetch real data based on the portfolio id. Here’s how you can refactor the `PortfolioDetail` component to achieve this:

1. **Remove Sample Data**: Eliminate the hardcoded sample data.
2. **Fetch Real Data**: Use the `useEffect` hook to fetch data from the API based on the `id` from the URL.
3. **Pass Real Data**: Pass the fetched data to the `ChartDisplay` and `PortfolioDiversity` components.

Here is the complete refactored `PortfolioDetail.js`:

### `PortfolioDetail.js`

```javascript
import React, { useEffect, useState } from 'react';
import { useParams } from 'react-router-dom';
import PortfolioDiversity from '../components/PortfolioDiversity';
import ChartDisplay from '../components/ChartDisplay';
import { useSelector } from 'react-redux';
import AuthError from '../components/AuthError';

function PortfolioDetail() {
  const { id } = useParams();
  const { isAuthenticated } = useSelector((state) => state.auth);
  const [portfolio, setPortfolio] = useState(null);

  useEffect(() => {
    const getData = async () => {
      const res = await fetch(`http://10.64.17.55:8000/portfolio/${id}`, {
        headers: {
          'Content-Type': 'application/json',
          'accesstoken': sessionStorage.getItem('accessToken')
        },
      });
      const data = await res.json();
      setPortfolio(data);
    };
    getData();
  }, [id]);

  const handleRebalance = () => {
    console.log(`Rebalancing portfolio ${portfolio?.name}`);
    alert('Portfolio rebalanced successfully!');
  };

  return (
    <>
      {isAuthenticated ? (
        <div className="min-h-screen bg-gray-100 p-4 flex flex-col items-center">
          <div className="flex w-full max-w-6xl gap-4">
            {/* Left Column */}
            <div className="flex flex-col w-1/2 space-y-4">
              <div>
                {portfolio && <ChartDisplay portfolio={portfolio} />}
              </div>
              <div className="bg-white shadow-md rounded-lg p-4">
                <h3 className="text-lg font-medium mb-2">Stocks in {portfolio?.name}</h3>
                <table className="min-w-full bg-white">
                  <thead>
                    <tr>
                      <th className="py-2 px-4 border-b-2 border-gray-200 text-left leading-tight">Stock Name</th>
                      <th className="py-2 px-4 border-b-2 border-gray-200 text-left leading-tight">Percentage</th>
                    </tr>
                  </thead>
                  <tbody>
                    {portfolio?.stocks?.map((stock, index) => (
                      <tr key={index} className="hover:bg-gray-100">
                        <td className="py-2 px-4 border-b border-gray-200">{stock?.name}</td>
                        <td className="py-2 px-4 border-b border-gray-200">{stock?.percentage}%</td>
                      </tr>
                    ))}
                  </tbody>
                </table>
                <button
                  onClick={handleRebalance}
                  className="mt-4 bg-red-500 w-full text-white px-4 py-2 rounded hover:bg-red-700"
                >
                  Rebalance Portfolio
                </button>
              </div>
              <div className="bg-white shadow-md rounded-lg p-4">
                <h3 className="text-lg font-medium mb-2">Overall Performance</h3>
                <p><strong>Profit/Loss:</strong> {portfolio?.profitLoss}</p>
                <p><strong>Invested:</strong> {portfolio?.invested}</p>
                <p><strong>Portfolio Worth:</strong> {portfolio?.worth}</p>
                <p><strong>Allocation:</strong> {JSON.stringify(portfolio?.allocation, null, 2)}</p>
                <p><strong>Bond Equity:</strong> {JSON.stringify(portfolio?.bondEquity, null, 2)}</p>
                <p><strong>Asset Class:</strong> {JSON.stringify(portfolio?.assetClass, null, 2)}</p>
              </div>
            </div>

            {/* Right Column */}
            <div className="flex flex-col w-1/2">
              {portfolio && <PortfolioDiversity portfolio={portfolio} />}
            </div>
          </div>
        </div>
      ) : (
        <AuthError />
      )}
    </>
  );
}

export default PortfolioDetail;
```

### Additional Adjustments
Ensure that your `PortfolioDiversity` component and any other components that rely on the portfolio data handle the data structure correctly. For example, ensure that `portfolio.stocks`, `portfolio.allocation`, etc., are accessed correctly.

### Ensure Consistent Data Access
- Check all component data accesses (e.g., `portfolio?.stocks`, `portfolio?.allocation`) to handle cases where data might be undefined or null.
- Make sure that all other related components (`ChartDisplay`, `PortfolioDiversity`, etc.) can handle the real data structure appropriately.

### Ensure Correct Route Configuration
Make sure your routes are correctly set up to use `PortfolioDetail` with a dynamic id. For instance:
```javascript
<Route path="/portfolio/:id" component={PortfolioDetail} />
```

With these adjustments, your `PortfolioDetail` component should now fetch and use real data based on the provided portfolio ID.