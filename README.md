I understand now that you want to fetch two different sets of data: one for the dropdown summary and one for the detailed stock information. Here's how you can adjust your code accordingly:

### Modified `StockComparison.js`

```javascript
import React, { useEffect, useState } from "react";
import Chart from "chart.js/auto";
import { Line } from "react-chartjs-2";
import Select from 'react-select';

const StockComparison = () => {
  const [stockSummary, setStockSummary] = useState([]);
  const [stockDetails, setStockDetails] = useState({});
  const [selectedStock, setSelectedStock] = useState(null);
  const [chartData, setChartData] = useState(null);

  useEffect(() => {
    fetchStockSummary();
    fetchStockDetails();
  }, []);

  const fetchStockSummary = async () => {
    try {
      const response = await fetch("/api/getStockSummary");
      const data = await response.json();
      setStockSummary(data);
    } catch (error) {
      console.error("Error fetching stock summary:", error);
    }
  };

  const fetchStockDetails = async () => {
    try {
      const response = await fetch("/api/getAllStockDetails");
      const data = await response.json();
      setStockDetails(data);
    } catch (error) {
      console.error("Error fetching stock details:", error);
    }
  };

  const handleStockChange = (selectedOption) => {
    setSelectedStock(selectedOption);
    const details = stockDetails[selectedOption.value];
    updateChart(details);
  };

  const updateChart = (details) => {
    if (!details) return;

    const chartData = {
      labels: details["oneWeek"].map(item => item.date),
      datasets: [
        {
          label: details.stockname,
          data: details["oneWeek"].map(item => item.price),
          fill: false,
          backgroundColor: "rgb(75, 192, 192)",
          borderColor: "rgba(75, 192, 192, 0.2)",
        },
      ],
    };

    setChartData(chartData);
  };

  const stockOptions = stockSummary.map(stock => ({
    value: stock.stocksymbol,
    label: `${stock.stocksymbol} - ${stock.stockname}`,
  }));

  return (
    <div style={{ textAlign: "center" }}>
      <h1>Stock Comparison</h1>
      <Select
        options={stockOptions}
        onChange={handleStockChange}
        placeholder="Select a stock"
      />
      {selectedStock && stockDetails[selectedStock.value] && (
        <div>
          <h2>{stockDetails[selectedStock.value].stockname}</h2>
          <p>Current Value: {stockDetails[selectedStock.value].stockvalue}</p>
        </div>
      )}
      {chartData && (
        <div style={{ width: "80%", margin: "0 auto" }}>
          <Line data={chartData} />
        </div>
      )}
    </div>
  );
};

export default StockComparison;
```

### Explanation

1. **Separate Fetch Functions:**
   - `fetchStockSummary`: Fetches the summary data for the dropdown.
   - `fetchStockDetails`: Fetches the detailed data for all stocks.

2. **Dropdown Population:**
   - The dropdown is populated using the `stockSummary` state.

3. **Handling Stock Selection:**
   - When a stock is selected from the dropdown, `handleStockChange` updates the selected stock and retrieves the corresponding details from `stockDetails`.

4. **Chart Update:**
   - The `updateChart` function updates the chart data based on the selected stock's details for the past week.

### Backend Endpoint Expectations
- `/api/getStockSummary`: Returns an array of stock summaries, e.g.,
  ```json
  [
    { "stocksymbol": "AAPL", "stockname": "Apple Inc." },
    { "stocksymbol": "MSFT", "stockname": "Microsoft Corporation" },
    // ...
  ]
  ```
- `/api/getAllStockDetails`: Returns an object containing detailed stock data for all stocks, e.g.,
  ```json
  {
    "AAPL": {
      "stockname": "Apple Inc.",
      "stockvalue": 145.09,
      "oneWeek": [
        { "date": "2023-06-01", "price": 142 },
        { "date": "2023-06-02", "price": 143 },
        // ...
      ],
      "oneMonth": [
        { "date": "2023-05-01", "price": 140 },
        // ...
      ],
      "oneYear": [
        { "date": "2023-01-01", "price": 130 },
        // ...
      ]
    },
    "MSFT": {
      "stockname": "Microsoft Corporation",
      "stockvalue": 299.79,
      "oneWeek": [
        { "date": "2023-06-01", "price": 142 },
        // ...
      ],
      // ...
    },
    // ...
  }
  ```

This approach ensures that the dropdown is populated based on a summary list, while detailed stock data is fetched once and stored in state, allowing efficient access when a stock is selected.