Understood. For calculating the new allocated units and available cash initially and on each change, you should:

1. Initialize the calculated fields when fetching data.
2. Ensure these calculations are done within the component rendering.

Here are the specific changes to make:

### 1. Modify the `fetchData` function to initialize calculated fields:
After fetching and transforming the data, calculate `newAllocatedUnits` and `capitalInvested` for each stock:

```javascript
const fetchData = async () => {
    try {
        setLoading(true);
        const response = await fetch(`https://dummy-url.com/api/rebalanced-portfolio/${portfolioId}`);
        if (!response.ok) {
            throw new Error('Network response was not ok');
        }
        const result = await response.json();
        const transformedData = Object.entries(result.allocation).map(([symbol, details]) => {
            const price = parseFloat(details.price);
            const newAllocationPercent = parseFloat(details.newAllocationPercent);
            const oldAllocationShares = parseFloat(details.oldAllocationShares);
            const capitalInvested = (newAllocationPercent / 100) * parseFloat(result.capital);
            const newAllocatedUnits = capitalInvested / price;
            const changeInUnits = newAllocatedUnits - oldAllocationShares;

            return {
                stockSymbol: symbol,
                oldAllocationShares,
                newAllocationPercent,
                price,
                capitalInvested,
                newAllocatedUnits,
                changeInUnits,
            };
        });
        setData(transformedData);
        setCapital(parseFloat(result.capital));
    } catch (error) {
        console.error('Error fetching data:', error);
        toast.error('Error fetching data, displaying dummy data instead.');
        const dummyData = [
            { stockSymbol: 'AAPL', oldAllocationShares: 10, newAllocationPercent: 5, price: 113.79, capitalInvested: 0, newAllocatedUnits: 0, changeInUnits: 0 },
            { stockSymbol: 'GOOGL', oldAllocationShares: 10, newAllocationPercent: 5, price: 113.79, capitalInvested: 0, newAllocatedUnits: 0, changeInUnits: 0 },
        ];
        setData(dummyData);
        setCapital(1000);
    } finally {
        setLoading(false);
    }
};
```

### 2. Update the `handleInputChange` function to recalculate the fields:
When `newAllocationPercent` changes, recalculate `capitalInvested`, `newAllocatedUnits`, and `changeInUnits`:

```javascript
const handleInputChange = (e, rowIndex) => {
    const { name, value } = e.target;
    if (name === 'newAllocationPercent' && parseFloat(value) < 0) {
        toast.error('Allocation cannot be negative');
        return;
    }
    const updatedData = [...data];
    const newAllocationPercent = parseFloat(value) || 0;
    const price = updatedData[rowIndex].price;
    const capitalInvested = (newAllocationPercent / 100) * capital;
    const newAllocatedUnits = capitalInvested / price;
    const oldAllocationShares = updatedData[rowIndex].oldAllocationShares;
    const changeInUnits = newAllocatedUnits - oldAllocationShares;

    updatedData[rowIndex][name] = newAllocationPercent;
    updatedData[rowIndex].capitalInvested = capitalInvested;
    updatedData[rowIndex].newAllocatedUnits = newAllocatedUnits;
    updatedData[rowIndex].changeInUnits = changeInUnits;

    setData(updatedData);
    calculateTotals(updatedData, capital);
};
```

With these changes, the `newAllocatedUnits` and other dependent fields will be properly initialized and updated without needing a change trigger in the table.