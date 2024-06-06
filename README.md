To integrate real data and ensure that clicking on a portfolio renders the appropriate details, we'll update your components to fetch and render data based on the selected portfolio's ID. Here's a step-by-step guide:

### Step 1: Update the Portfolio Component

Ensure the `Portfolio` component fetches the data and updates the state correctly when a portfolio is selected.

```jsx
import React, { useEffect, useState } from 'react';
import PortfolioTable from '../components/PortfolioTable';
import PortfolioDiversity from '../components/PortfolioDiversity';
import ChartDisplay from '../components/ChartDisplay';
import { useSelector } from 'react-redux';
import AuthError from '../components/AuthError';

function Portfolio() {
  const [selectedPortfolio, setSelectedPortfolio] = useState(null);
  const { isAuthenticated, user } = useSelector((state) => state.auth);
  const [data, setData] = useState([]);

  useEffect(() => {
    const getData = async () => {
      const res = await fetch("http://10.64.17.55:8000/portfolio/all", {
        headers: {
          'Content-Type': 'application/json',
          'accesstoken': sessionStorage.getItem('accessToken')
        },
      });
      const d = await res.json();
      setData(d);
    };
    getData();
  }, []);

  return (
    <>
      {isAuthenticated ? (
        <div className="w-full bg-gray-100 flex justify-center items-center p-4">
          <div className="left">
            <PortfolioTable portfolios={data} onSelectPortfolio={setSelectedPortfolio} />
          </div>
          <div className="right w-1/3 px-10 mt-12">
            {selectedPortfolio && <PortfolioDiversity portfolio={data.find(p => p.portfolioid === selectedPortfolio)} />}
          </div>
        </div>
      ) : (
        <AuthError />
      )}
    </>
  );
}

export default Portfolio;
```

### Step 2: Update the Allocation View Component

Ensure `AllocationView` displays data correctly.

```jsx
import React from 'react';
import { Doughnut } from 'react-chartjs-2';
import 'chart.js/auto';
import { useSelector } from 'react-redux';
import AuthError from './AuthError';
import { Link } from 'react-router-dom';

function AllocationView({ data }) {
  const { isAuthenticated } = useSelector((state) => state.auth);
  
  const chartData = {
    labels: ['Big Tech', 'Stocks', 'Energy', 'Ecommerce', 'Funds'],
    datasets: [
      {
        data: [data?.bigTech, data?.stocks, data?.energy, data?.ecommerce, data?.funds],
        backgroundColor: ['#FF6384', '#36A2EB', '#FFCE56', '#4BC0C0', '#9966FF'],
        hoverBackgroundColor: ['#ff1748', '#137bc1', '#ffb80a', '#318d8d', '#661aff']
      }
    ]
  };

  return (
    <>
      {isAuthenticated ? (
        <div>
          <h2 className="text-l font-semibold mb-2">Allocation View</h2>
          <Doughnut data={chartData} />
          <p className="mt-4 text-center">
            <span className="font-bold">Big Tech</span> accounts for <span className="font-bold">{data?.bigTech}%</span> of your portfolio.
          </p>
          <Link to="/" className="block mt-2 text-blue-500 underline text-center">You can read our guide on diversification</Link>
        </div>
      ) : (
        <AuthError />
      )}
    </>
  );
}

export default AllocationView;
```

### Step 3: Update the Portfolio Diversity Component

Update `PortfolioDiversity` to render the allocation, bond equity, and asset class views correctly.

```jsx
import React, { useState } from 'react';
import AllocationView from './AllocationView';
import BondEquity from './BondEquity';
import AssetClass from './AssetClass';
import { useSelector } from 'react-redux';
import AuthError from './AuthError';

function PortfolioDiversity({ portfolio }) {
  const [view, setView] = useState('AllocationView');
  const { isAuthenticated } = useSelector((state) => state.auth);

  const renderView = () => {
    switch (view) {
      case 'AllocationView':
        return <AllocationView data={portfolio?.allocation} />;
      case 'BondEquity':
        return <BondEquity data={portfolio?.bondEquity} />;
      case 'AssetClass':
        return <AssetClass data={portfolio?.assetClass} />;
      default:
        return <AllocationView data={portfolio?.allocation} />;
    }
  };

  return (
    <>
      {isAuthenticated ? (
        <div className="bg-white shadow-md rounded-lg p-4 mb-80 w-full max-w-md h-[700px]">
          <div>
            <h2 className="text-xl font-semibold mb-2">Portfolio Diversity</h2>
          </div>
          <div className="flex justify-around mb-4">
            <button onClick={() => setView('AllocationView')} className="px-4 py-2 text-sm font-medium text-white bg-red-500 rounded hover:bg-red-600">Allocation View</button>
            <button onClick={() => setView('BondEquity')} className="px-4 py-2 text-sm font-medium text-white bg-red-500 rounded hover:bg-red-600">Bond Equity</button>
            <button onClick={() => setView('AssetClass')} className="px-4 py-2 text-sm font-medium text-white bg-red-500 rounded hover:bg-red-600">Asset Class</button>
          </div>
          {renderView()}
        </div>
      ) : (
        <AuthError />
      )}
    </>
  );
}

export default PortfolioDiversity;
```

### Step 4: Update the Portfolio Table Component

Ensure `PortfolioTable` passes the correct portfolio ID to the parent component when a portfolio is selected.

```jsx
import React, { useState } from 'react';
import { Link } from 'react-router-dom';
import { IoIosSearch } from "react-icons/io";
import { useSelector } from 'react-redux';
import AuthError from './AuthError';

function PortfolioTable({ portfolios, onSelectPortfolio }) {
  const [searchQuery, setSearchQuery] = useState('');
  const [expandedPortfolio, setExpandedPortfolio] = useState(null);
  const { isAuthenticated } = useSelector((state) => state.auth);

  const filteredPortfolios = portfolios?.filter(portfolio =>
    portfolio.name.toLowerCase().includes(searchQuery.toLowerCase())
  );

  const toggleExpand = (portfolioid) => {
    setExpandedPortfolio(expandedPortfolio === portfolioid ? null : portfolioid);
  };

  return (
    <>
      {isAuthenticated ? (
        <div className="min-h-screen flex flex-col items-center justify-center bg-gray-100">
          <div className="w-[700px] px-10 py-10 rounded-3xl bg-white border-2 border-gray-100">
            <div className="header flex items-center justify-around">
              <h1 className="text-4xl font-semibold mb-3">Portfolio Table</h1>
              <div className='flex items-center justify-around rounded-xl p-1 border-2 border-gray-100'>
                <input
                  type="text"
                  placeholder="Search by name"
                  className="w-auto mt-2 mb-3 outline-none text-xl"
                  value={searchQuery}
                  onChange={(e) => setSearchQuery(e.target.value)}
                />
                <IoIosSearch size={30} />
              </div>
            </div>
            <p className="font-medium text-lg text-gray-500 mt-4">List of your portfolios.</p>
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
                  {filteredPortfolios?.map(portfolio => (
                    <React.Fragment key={portfolio.portfolioid}>
                      <tr onClick={() => { onSelectPortfolio(portfolio.portfolioid); toggleExpand(portfolio.portfolioid); }} className="cursor-pointer hover:bg-gray-100">
                        <td className="py-2 px-4 border-b border-gray-200">{portfolio.name}</td>
                        <td className="py-2 px-4 border-b border-gray-200">
                          <span className={`block ${portfolio.profitLoss > 0 ? 'text-green-500' : 'text-red-500'}`}>
                            {`${portfolio.profitLoss > 0 ? '▲' : '▼'} ${portfolio.profitLoss}`}
                          </span>
                        </td>
                        <td className="py-2 px-4 border-b border-gray-200">{portfolio.capital}</td>
                        <