To display the keys of your portfolio allocation data in a more readable format (e.g., converting `financialServices` to `Financial Services`), you can create a function that formats the keys and use it within your `Object.entries().map()` method. Here’s how you can do it:

1. **Create a function to format the keys:**

```jsx
const formatKey = (key) => {
    return key
        .replace(/([A-Z])/g, ' $1') // Add space before capital letters
        .replace(/^./, str => str.toUpperCase()); // Capitalize the first letter
};
```

2. **Use this function within your map:**

```jsx
const allocationData = {
    financialServices: 90,
    technology: 60,
    healthcare: 40,
};

const formattedEntries = Object.entries(allocationData).map(([key, value]) => ({
    key: formatKey(key),
    value,
}));

return (
    <div>
        <h2>Portfolio Allocation</h2>
        <ul>
            {formattedEntries.map(({ key, value }) => (
                <li key={key}>
                    {key}: {value}%
                </li>
            ))}
        </ul>
    </div>
);
```

### Complete Example:

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

    return (
        <div>
            <h2>Portfolio Allocation</h2>
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

1. **`formatKey` Function:**
   - This function takes a key (e.g., `financialServices`) and formats it into a more readable string (`Financial Services`).
   - It adds a space before each capital letter and capitalizes the first letter of the resulting string.

2. **Mapping Over Object Entries:**
   - Use `Object.entries(allocationData)` to get an array of `[key, value]` pairs.
   - Map over these entries to create an array of formatted key-value pairs.

3. **Rendering the Formatted Entries:**
   - Use the formatted entries to render a list where each key-value pair is displayed in a more readable format.

This approach ensures that your portfolio allocation keys are displayed in a user-friendly manner, making it easier for users to read and understand.