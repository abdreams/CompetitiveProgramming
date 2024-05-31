Sure, I'll simplify the `PerformanceChart` component to display just a simple line chart using the sample data.

### Simplified PerformanceChart Component

Here's a simplified version of the `PerformanceChart` component that only displays a line chart:

```javascript
import React from 'react';
import { Line } from 'react-chartjs-2';
import { Chart as ChartJS, CategoryScale, LinearScale, PointElement, LineElement, Title, Tooltip, Legend } from 'chart.js';

ChartJS.register(CategoryScale, LinearScale, PointElement, LineElement, Title, Tooltip, Legend);

const PerformanceChart = ({ data }) => {
    const chartData = {
        labels: data.map(entry => entry.date),
        datasets: [{
            label: 'Portfolio Value',
            data: data.map(entry => entry.value),
            borderColor: 'rgba(75, 192, 192, 1)',
            backgroundColor: 'rgba(75, 192, 192, 0.2)',
            borderWidth: 2,
            fill: true,
        }],
    };

    const options = {
        responsive: true,
        scales: {
            x: {
                title: {
                    display: true,
                    text: 'Date'
                }
            },
            y: {
                title: {
                    display: true,
                    text: 'Value (INR)'
                }
            }
        }
    };

    return (
        <div className="bg-white p-4 rounded-lg shadow-md">
            <h2 className="text-2xl font-semibold mb-4">Overall Performance</h2>
            <div className="mb-4">
                <p className="text-xl">₹252,501.00</p>
                <p className="text-green-500">+230.82% from July 2021</p>
            </div>
            <Line data={chartData} options={options} />
        </div>
    );
};

export default PerformanceChart;
```

### Integrate PerformanceChart into Portfolio Component

Now we integrate this simplified `PerformanceChart` component into our `Portfolio` page:

```javascript
import React from 'react';
import PerformanceChart from './PerformanceChart';
import PortfolioTable from './PortfolioTable';

const portfolioData = [
    { date: '2021-07-01', value: 50000 },
    { date: '2021-12-01', value: 75000 },
    { date: '2022-06-01', value: 100000 },
    { date: '2022-12-01', value: 125000 },
    { date: '2023-06-01', value: 150000 },
    { date: '2023-12-01', value: 252501 }
];

export default function Portfolio() {
    return (
        <div className="min-h-screen flex flex-col items-center bg-gray-100 p-8">
            <h1 className="text-5xl font-semibold mb-8">Portfolio</h1>
            <PerformanceChart data={portfolioData} />
            <div className="w-full max-w-4xl mt-8">
                {/* Placeholder for Portfolio Diversity */}
                <div className="bg-white p-4 rounded-lg shadow-md mb-8">
                    <h2 className="text-2xl font-semibold mb-4">Portfolio Diversity</h2>
                    {/* Portfolio Diversity Content Here */}
                </div>
                <PortfolioTable />
            </div>
        </div>
    );
}
```

This setup should now display a simple line chart representing the portfolio's value over time using the provided sample data.
