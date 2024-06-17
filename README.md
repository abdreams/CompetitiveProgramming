To fetch data from two different URLs for stock summaries and stock details, and then filter the data based on user selection, we'll need to modify your code to handle fetching from these two endpoints. Here is the updated `StockComparison` component:

### Updated `StockComparison.js`

```javascript
import React, { useState, useEffect } from 'react';
import { Line } from 'react-chartjs-2';
import 'chart.js/auto';
import Select from 'react-select';

const dummyStockDetails = {
  // Your existing dummy data here
};

const dummyStockData = [
  // Your existing dummy data here
];

const StockComparision = () => {
  const FETCH_SUMMARY_URL = 'https://api.example.com/stock-summary'; // Replace with your API URL
  const FETCH_DETAILS_URL = 'https://api.example.com/stock-details'; // Replace with your API URL

  const [selectedStocks, setSelectedStocks] = useState([]);
  const [stockSummary, setStockSummary] = useState([]);
  const [stockDetails, setStockDetails] = useState({});
  const [timeRange, setTimeRange] = useState('1week');

  const fetchStockSummary = async () => {
    try {
      const response = await fetch(FETCH_SUMMARY_URL);
      if (!response.ok) throw new Error('Network response was not ok');
      const result = await response.json();
      setStockSummary(result);
    } catch (error) {
      console.error('Error fetching stock summary:', error);
      setStockSummary(dummyStockData); // Use dummy data on error
    }
  };

  const fetchStockDetails = async () => {
    try {
      const response = await fetch(FETCH_DETAILS_URL);
      if (!response.ok) throw new Error('Network response was not ok');
      const result = await response.json();
      setStockDetails(result);
    } catch (error) {
      console.error('Error fetching stock details:', error);
      setStockDetails(dummyStockDetails); // Use dummy data on error
    }
  };

  useEffect(() => {
    fetchStockSummary();
    fetchStockDetails();
  }, []);

  const handleAddStock = (option) => {
    const symbol = option.value;
    if (!selectedStocks.includes(symbol) && selectedStocks.length < 4) {
      setSelectedStocks([...selectedStocks, symbol]);
    }
  };

  const handleRemoveStock = (symbol) => {
    setSelectedStocks(selectedStocks.filter(stock => stock !== symbol));
  };

  const stockOptions = stockSummary.map(stock => ({
    value: stock.stocksymbol,
    label: stock.stocksymbol,
  }));

  const chartData = {
    labels: selectedStocks.length > 0 && stockDetails[selectedStocks[0]]
      ? stockDetails[selectedStocks[0]][timeRange].map(item => item.date)
      : [],
    datasets: selectedStocks.map((symbol, index) => ({
      label: stockDetails[symbol].stockname,
      data: stockDetails[symbol][timeRange].map(item => item.value),
      fill: false,
      backgroundColor: `rgba(${index * 60}, 99, 132, 0.5)`,
      borderColor: `rgba(${index * 60}, 99, 132, 1)`,
    })),
  };

  return (
    <div className="container mx-auto p-6 bg-white rounded-lg shadow">
      <h2 className="text-lg font-semibold mb-4">Compare Stocks</h2>
      <div className="mb-4">
        <Select
          options={stockOptions}
          onChange={handleAddStock}
          placeholder="Add Stock"
          className="w-full"
        />
      </div>
      <div className="flex mb-4 flex-wrap">
        {selectedStocks.map(symbol => (
          <div key={symbol} className="mr-4 mb-2">
            <span>{symbol}</span>
            <button onClick={() => handleRemoveStock(symbol)} className="ml-2 text-red-500">Remove</button>
          </div>
        ))}
      </div>
      <div className="mb-4">
        <button onClick={() => setTimeRange('1week')} className={`mr-2 ${timeRange === '1week' ? 'bg-blue-500 text-white' : 'bg-gray-300 text-gray-800'} px-3 py-1 rounded-lg`}>1 Week</button>
        <button onClick={() => setTimeRange('1month')} className={`mr-2 ${timeRange === '1month' ? 'bg-blue-500 text-white' : 'bg-gray-300 text-gray-800'} px-3 py-1 rounded-lg`}>1 Month</button>
        <button onClick={() => setTimeRange('1year')} className={`mr-2 ${timeRange === '1year' ? 'bg-blue-500 text-white' : 'bg-gray-300 text-gray-800'} px-3 py-1 rounded-lg`}>1 Year</button>
      </div>
      <div className="flex justify-center mb-4" style={{ maxHeight: '400px' }}>
        <div style={{ width: '100%', maxWidth: '600px' }}>
          <Line data={chartData} />
        </div>
      </div>
      <table className="table-auto w-full mt-4 border border-gray-300">
        <thead>
          <tr className="bg-gray-100">
            <th className="border px-4 py-2">Stock</th>
            <th className="border px-4 py-2">Current Price</th>
            <th className="border px-4 py-2">Change</th>
          </tr>
        </thead>
        <tbody>
          {selectedStocks.map(symbol => {
            const stock = stockSummary.find(stock => stock.stocksymbol === symbol);
            return (
              <tr key={symbol}>
                <td className="border px-4 py-2 text-center">{symbol}</td>
                <td className="border px-4 py-2 text-center">{stock.value}</td>
                <td className="border px-4 py-2 text-center">{stock.change}</td>
              </tr>
            );
          })}
        </tbody>
      </table>
    </div>
  );
};

export default StockComparision;
```

### Explanation

1. **Separate Fetching of Stock Summary and Stock Details:**
   - `fetchStockSummary` fetches the summary data from `FETCH_SUMMARY_URL`.
   - `fetchStockDetails` fetches the detailed data from `FETCH_DETAILS_URL`.
   - Both functions set their respective states (`stockSummary` and `stockDetails`) with the fetched data.

2. **Handling Data:**
   - The `stockSummary` contains basic information about each stock.
   - The `stockDetails` contains detailed information about each stock.
   - Both pieces of data are fetched once on component mount using `useEffect`.

3. **Dropdown and Chart:**
   - The dropdown options are derived from `stockSummary`.
   - The chart data is derived from `stockDetails` based on the selected stocks and the chosen time range.

4. **Error Handling:**
   - If there is an error fetching data, the dummy data is used as a fallback.

This approach ensures that both stock summaries and detailed data are fetched separately from the backend and stored in their respective states. The user can then select stocks from the summary data, and the detailed data for the selected stocks will be used to display the chart and table.