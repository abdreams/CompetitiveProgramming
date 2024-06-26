To change the color of labels in Chart.js based on dark mode, you'll need to dynamically update the chart options. Here's how you can achieve this in a React application using Chart.js:

1. **Install Chart.js and `react-chartjs-2` if not already installed:**

```bash
npm install chart.js react-chartjs-2
```

2. **Create a chart component that listens to the theme mode and updates the chart options accordingly:**

```jsx
import React, { useEffect, useRef } from 'react';
import { Chart as ChartJS, ArcElement, Tooltip, Legend } from 'chart.js';
import { Pie } from 'react-chartjs-2';
import { useSelector } from 'react-redux';
import { selectIsDarkMode } from '../redux/slices/themeSlice';

ChartJS.register(ArcElement, Tooltip, Legend);

const AllocationPieChart = ({ data }) => {
    const isDarkMode = useSelector(selectIsDarkMode);
    const chartRef = useRef(null);

    const chartData = {
        labels: data.map(d => d.stockSymbol),
        datasets: [
            {
                label: '% Allocation',
                data: data.map(d => d.percentAllocated),
                backgroundColor: [
                    'rgba(255, 99, 132, 0.2)',
                    'rgba(54, 162, 235, 0.2)',
                    'rgba(255, 206, 86, 0.2)',
                    // Add more colors as needed
                ],
                borderColor: [
                    'rgba(255, 99, 132, 1)',
                    'rgba(54, 162, 235, 1)',
                    'rgba(255, 206, 86, 1)',
                    // Add more colors as needed
                ],
                borderWidth: 1,
            },
        ],
    };

    const getOptions = (isDarkMode) => ({
        responsive: true,
        plugins: {
            legend: {
                labels: {
                    color: isDarkMode ? '#ffffff' : '#000000', // Change color based on dark mode
                },
            },
        },
    });

    useEffect(() => {
        const chart = chartRef.current;
        if (chart) {
            chart.options = getOptions(isDarkMode);
            chart.update();
        }
    }, [isDarkMode]);

    return <Pie ref={chartRef} data={chartData} options={getOptions(isDarkMode)} />;
};

export default AllocationPieChart;
```

3. **Usage of the `AllocationPieChart` component:**

```jsx
import React from 'react';
import AllocationPieChart from './AllocationPieChart';

const data = [
    { stockSymbol: 'AAPL', percentAllocated: 20 },
    { stockSymbol: 'MSFT', percentAllocated: 15 },
    { stockSymbol: 'AMZN', percentAllocated: 10 },
    // Add more data as needed
];

const App = () => (
    <div>
        <h1>Portfolio Allocation</h1>
        <AllocationPieChart data={data} />
    </div>
);

export default App;
```

### Explanation:
1. **React and Chart.js Setup:**
   - Import necessary modules from `react-chartjs-2` and `chart.js`.
   - Create a `Pie` chart component that will render the allocation data.

2. **Dynamic Theme Handling:**
   - Use the `useSelector` hook to get the current theme mode from Redux.
   - Define chart options that change the color of legend labels based on the theme mode.

3. **Updating Chart Options on Theme Change:**
   - Use the `useEffect` hook to update the chart options whenever the theme mode changes.
   - Update the chart options dynamically and call `chart.update()` to apply the changes.

By following these steps, you can dynamically change the color of the labels in your Chart.js pie chart based on the dark mode state.