To display the sector with the maximum allocation, you can modify the `PortfolioAllocation` component to find the sector with the highest allocation and display it accordingly. Here's how you can do it:

1. **Find the sector with the maximum allocation:**
2. **Display the sector with the maximum allocation.**

Here's the complete example:

```jsx
import React from 'react';

const formatKey = (key) => {
    return key
        .replace(/([A-Z])/g, ' $1') // Add space before capital letters
        .replace(/^./, str => str.toUpperCase()); // Capitalize the first letter
};

const PortfolioAllocation = ({ allocationData }) => {
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

1. **Finding the Sector with the Maximum Allocation:**
   - Use the `reduce` method on the `formattedEntries` array to find the entry with the highest allocation value.

2. **Displaying the Maximum Sector:**
   - Display the sector with the highest allocation in a paragraph above the list of all sectors.

With