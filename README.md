<!DOCTYPE html>
<html>
<head>
  <title>Dynamic Chart Update</title>
  <script src="https://cdn.jsdelivr.net/npm/chart.js"></script>
</head>
<body>
  <canvas id="myChart" width="400" height="200"></canvas>
  <button onclick="updateData()">Update Chart</button>
  
  <script>
    const ctx = document.getElementById('myChart').getContext('2d');
    
    const myChart = new Chart(ctx, {
        type: 'bar', // or 'line', 'pie', etc.
        data: {
            labels: ['January', 'February', 'March', 'April', 'May', 'June', 'July'],
            datasets: [{
                label: 'Sales',
                data: [65, 59, 80, 81, 56, 55, 40],
                backgroundColor: 'rgba(75, 192, 192, 0.2)',
                borderColor: 'rgba(75, 192, 192, 1)',
                borderWidth: 1
            }]
        },
        options: {
            scales: {
                y: {
                    beginAtZero: true
                }
            }
        }
    });
    
    function updateChart(chart, newLabels, newData) {
        chart.data.labels = newLabels;
        chart.data.datasets.forEach((dataset) => {
            dataset.data = newData;
        });
        chart.update();
    }
    
    function updateData() {
        const newLabels = ['August', 'September', 'October', 'November', 'December'];
        const newData = [70, 65, 85, 90, 75];
    
        updateChart(myChart, newLabels, newData);
    }
  </script>
</body>
</html>


import React, { useRef } from 'react';
import { Bar } from 'react-chartjs-2';
import { Chart as ChartJS, CategoryScale, LinearScale, BarElement, Title, Tooltip, Legend } from 'chart.js';

ChartJS.register(CategoryScale, LinearScale, BarElement, Title, Tooltip, Legend);

const DynamicChart = () => {
    const chartRef = useRef(null);

    const initialData = {
        labels: ['January', 'February', 'March', 'April', 'May', 'June', 'July'],
        datasets: [
            {
                label: 'Sales',
                data: [65, 59, 80, 81, 56, 55, 40],
                backgroundColor: 'rgba(75, 192, 192, 0.2)',
                borderColor: 'rgba(75, 192, 192, 1)',
                borderWidth: 1,
            },
        ],
    };

    const updateChart = () => {
        const chartInstance = chartRef.current;
        if (chartInstance) {
            chartInstance.data.labels = ['August', 'September', 'October', 'November', 'December'];
            chartInstance.data.datasets[0].data = [70, 65, 85, 90, 75];
            chartInstance.update();
        }
    };

    return (
        <div>
            <Bar data={initialData} ref={chartRef} options={{ responsive: true, scales: { y: { beginAtZero: true } } }} />
            <button onClick={updateChart}>Update Chart</button>
        </div>
    );
};

export default DynamicChart;


import React, { useRef, useEffect, useState } from 'react';
import { Bar } from 'react-chartjs-2';
import { Chart as ChartJS, CategoryScale, LinearScale, BarElement, Title, Tooltip, Legend } from 'chart.js';

ChartJS.register(CategoryScale, LinearScale, BarElement, Title, Tooltip, Legend);

const DynamicChart = () => {
    const chartRef = useRef(null);
    const [chartData, setChartData] = useState({
        labels: [],
        datasets: [
            {
                label: 'Sales',
                data: [],
                backgroundColor: 'rgba(75, 192, 192, 0.2)',
                borderColor: 'rgba(75, 192, 192, 1)',
                borderWidth: 1,
            },
        ],
    });

    useEffect(() => {
        const fetchData = async () => {
            try {
                const response = await fetch('https://api.example.com/chart-data'); // Replace with your API endpoint
                const data = await response.json();

                const labels = data.map(item => item.label);
                const values = data.map(item => item.value);

                setChartData({
                    labels,
                    datasets: [
                        {
                            label: 'Sales',
                            data: values,
                            backgroundColor: 'rgba(75, 192, 192, 0.2)',
                            borderColor: 'rgba(75, 192, 192, 1)',
                            borderWidth: 1,
                        },
                    ],
                });

                const chartInstance = chartRef.current;
                if (chartInstance) {
                    chartInstance.data.labels = labels;
                    chartInstance.data.datasets[0].data = values;
                    chartInstance.update();
                }
            } catch (error) {
                console.error('Error fetching data:', error);
            }
        };

        fetchData();
    }, []);

    return (
        <div>
            <Bar data={chartData} ref={chartRef} options={{ responsive: true, scales: { y: { beginAtZero: true } } }} />
        </div>
    );
};

export default DynamicChart;

import React from 'react';
import ReactDOM from 'react-dom';
import DynamicChart from './DynamicChart';

const App = () => {
    return (
        <div>
            <h1>Dynamic Chart Update</h1>
            <DynamicChart />
        </div>
    );
};

ReactDOM.render(<App />, document.getElementById('root'));