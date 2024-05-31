Sure! We will adjust the layout in `Portfolio.jsx` to place the `PortfolioTable` on the left and the `PortfolioDiversity` on the right. 

### Step 1: Adjust the Layout in `Portfolio.jsx`

Here's the updated `Portfolio.jsx`:

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
      <div className="flex w-full max-w-6xl bg-white shadow-md rounded-lg">
        <div className="w-1/2 p-4">
          <PortfolioTable portfolios={sampleData} onSelectPortfolio={setSelectedPortfolio} />
        </div>
        <div className="w-1/2 p-4">
          <PortfolioDiversity portfolio={sampleData[selectedPortfolio]} />
        </div>
      </div>
    </div>
  );
}

export default Portfolio;
```

### Explanation
- **`min-h-screen`**: Ensures the component takes at least the full height of the viewport.
- **`flex justify-center items-center p-4`**: Centers the content and adds some padding.
- **`flex w-full max-w-6xl bg-white shadow-md rounded-lg`**: Defines the main container with a max width and styling.
- **`w-1/2 p-4`**: Splits the container into two equal parts for the table and the diversity components.

With this layout, the `PortfolioTable` will be on the left and the `PortfolioDiversity` will be on the right. 

### Step 2: Running the Project

To see the changes, make sure to run your project using:

```bash
npm start
```

This will start your React app, and you should be able to see the table on the left side and the portfolio diversity information on the right side of the screen.
