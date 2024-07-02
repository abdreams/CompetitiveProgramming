To handle cases where there might be no allocation data, you can add checks to ensure that the `allocationData` is not null or undefined and that it contains values before trying to process or format it. If there's no allocation data, you can display a message indicating that there's no allocation data available.

Here's how you can modify the `PortfolioAllocation` component to handle these cases:

```jsx
import React from 'react';

const formatKey = (key) => {
    return key
        .replace(/([A-Z])/g, ' $1') // Add space before capital letters
        .replace(/^./, str => str.toUpperCase()); // Capitalize the first letter
};

const PortfolioAllocation = ({ allocationData }) => {
    if (!allocationData || Object.keys(allocationData).length === 0) {
        return <p>No allocation data available.</p>;
    }

    const formattedEntries = Object.entries(allocationData).map(([key, value]) => ({
        key: formatKey(key),
        value,
    }));

    // Find the sector with the maximum allocation
    const maxSector = formattedEntries.reduce((max, current) => {
        return current.value > max.value ? current : max;
    }, formattedEntries[0]);

    return (
        <div>
            <h2>Portfolio Allocation</h2>
            <p>
                The sector with the highest allocation is <strong>{maxSector.key}</strong> with <strong>{maxSector.value}%</strong>.
            </p>
            <ul>
                {formattedEntries.map(({ key, value }) => (
                    <li key={key}>
                        {key}: {value}%
                    </li>
                ))}
            </ul>
        </div>
    );
};

const allocationData = {
    financialServices: 90,
    technology: 60,
    healthcare: 40,
};

const App = () => (
    <div>
        <PortfolioAllocation allocationData={allocationData} />
    </div>
);

export default App;
```

### Explanation:

1. **Check for Empty Allocation Data:**
   - The component first checks if `allocationData` is null or undefined or if it has no keys (`Object.keys(allocationData).length === 0`). 
   - If either condition is true, it returns a message indicating that there's no allocation data available.

2. **Process and Format Allocation Data:**
   - If `allocationData` exists and has values, it proceeds to format and process the allocation data as before.

This ensures that the component handles cases where there's no allocation data gracefully, without throwing errors.