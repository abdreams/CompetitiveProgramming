### Portfolio Dashboard Page Design

This section provides the detailed implementation of the Portfolio Dashboard page using React and Tailwind CSS. The page will be divided into two main parts: the upper part displaying a summary and a pie chart, and the lower part containing a table for selecting and creating portfolios.

#### Step-by-Step Implementation

1. **Project Setup:**
   - Ensure you have a React project set up.
   - Install Tailwind CSS.
   - Install any required libraries for data visualization (e.g., `react-chartjs-2` and `chart.js`).

2. **Install Necessary Packages:**
   ```sh
   npm install tailwindcss @headlessui/react @heroicons/react
   npm install react-chartjs-2 chart.js
   ```

3. **Configure Tailwind CSS:**
   Follow the Tailwind CSS installation guide to configure your project.

4. **Create the Portfolio Dashboard Page:**

**PortfolioDashboard.js:**
```jsx
import React, { useState } from 'react';
import { Pie } from 'react-chartjs-2';
import 'chart.js/auto';

const PortfolioDashboard = () => {
  const [selectedPortfolio, setSelectedPortfolio] = useState(null);

  const portfolios = [
    // Sample data; replace with actual data from your backend
    {
      id: 1,
      name: 'Tech Growth',
      avgReturn: '12%',
      performance: 'Good',
      allocation: { tech: 50, finance: 30, healthcare: 20 }
    },
    {
      id: 2,
      name: 'Balanced Portfolio',
      avgReturn: '8%',
      performance: 'Stable',
      allocation: { tech: 30, finance: 30, healthcare: 40 }
    }
  ];

  const handleSelectPortfolio = (portfolio) => {
    setSelectedPortfolio(portfolio);
  };

  const handleCreatePortfolio = () => {
    // Navigate to portfolio creation page or open a modal
    console.log('Create new portfolio');
  };

  const pieData = selectedPortfolio ? {
    labels: Object.keys(selectedPortfolio.allocation),
    datasets: [
      {
        data: Object.values(selectedPortfolio.allocation),
        backgroundColor: ['#FF6384', '#36A2EB', '#FFCE56']
      }
    ]
  } : null;

  return (
    <div className="container mx-auto p-4">
      <h1 className="text-2xl font-bold mb-4">Portfolio Dashboard</h1>
      
      {selectedPortfolio && (
        <div className="mb-8">
          <div className="bg-white shadow-md rounded-lg p-6">
            <h2 className="text-xl font-semibold mb-4">Portfolio Summary: {selectedPortfolio.name}</h2>
            <p><strong>Average Return:</strong> {selectedPortfolio.avgReturn}</p>
            <p><strong>Performance:</strong> {selectedPortfolio.performance}</p>
            <div className="mt-4">
              <Pie data={pieData} />
            </div>
          </div>
        </div>
      )}

      <div className="bg-white shadow-md rounded-lg p-6">
        <h2 className="text-xl font-semibold mb-4">Your Portfolios</h2>
        <table className="min-w-full bg-white">
          <thead>
            <tr>
              <th className="py-2 px-4 border-b border-gray-200">Name</th>
              <th className="py-2 px-4 border-b border-gray-200">Average Return</th>
              <th className="py-2 px-4 border-b border-gray-200">Performance</th>
              <th className="py-2 px-4 border-b border-gray-200">Actions</th>
            </tr>
          </thead>
          <tbody>
            {portfolios.map((portfolio) => (
              <tr key={portfolio.id}>
                <td className="py-2 px-4 border-b border-gray-200">{portfolio.name}</td>
                <td className="py-2 px-4 border-b border-gray-200">{portfolio.avgReturn}</td>
                <td className="py-2 px-4 border-b border-gray-200">{portfolio.performance}</td>
                <td className="py-2 px-4 border-b border-gray-200">
                  <button
                    onClick={() => handleSelectPortfolio(portfolio)}
                    className="bg-blue-500 text-white px-4 py-2 rounded"
                  >
                    Select
                  </button>
                </td>
              </tr>
            ))}
          </tbody>
        </table>
        <div className="mt-4">
          <button
            onClick={handleCreatePortfolio}
            className="bg-green-500 text-white px-4 py-2 rounded"
          >
            Create New Portfolio
          </button>
        </div>
      </div>
    </div>
  );
};

export default PortfolioDashboard;
```

**Explanation:**

1. **State Management:**
   - The `selectedPortfolio` state is used to keep track of the currently selected portfolio.

2. **Portfolio Data:**
   - Sample portfolio data is provided. In a real application, this data should be fetched from the backend.

3. **Selection Handling:**
   - `handleSelectPortfolio` function sets the selected portfolio.
   - `handleCreatePortfolio` function can be modified to navigate to a portfolio creation page or open a modal for creating a new portfolio.

4. **Pie Chart:**
   - `react-chartjs-2` is used to render the pie chart based on the selected portfolio's allocation data.

5. **Table:**
   - A table lists all portfolios, allowing users to select one. It includes columns for name, average return, performance, and actions.

6. **Buttons:**
   - The "Select" button sets the selected portfolio.
   - The "Create New Portfolio" button is a placeholder for triggering the portfolio creation process.

**Tailwind CSS Classes:**
- Tailwind CSS classes are used for styling the components, ensuring a responsive and visually appealing layout.

### Additional Steps

1. **Fetch Data from Backend:**
   - Replace the sample data with actual API calls to fetch portfolios.
   - Use `useEffect` to fetch data on component mount.

2. **Implement Portfolio Creation:**
   - Create a separate page or modal for portfolio creation.
   - Handle form submission to create a new portfolio and update the list.

3. **Enhance UI/UX:**
   - Add loading states, error handling, and confirmations for actions.
   - Improve the visual design as needed.

This design provides a comprehensive starting point for building the Portfolio Dashboard page, allowing users to view summaries, pie charts, and manage their portfolios efficiently.
