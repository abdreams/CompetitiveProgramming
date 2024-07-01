Understood. To ensure `newAllocatedUnits` and `availableCash` are calculated and rendered initially and on changes, you need to make sure these calculations are performed in a way that doesn't depend solely on user input changes.

Here are the changes to make:

### 1. Perform Initial Calculations in `useEffect`:
Modify your `useEffect` hook to initialize and update the calculated fields on component mount and when `data` changes:

```javascript
useEffect(() => {
    const calculateInitialValues = (portfolioData, capital) => {
        return portfolioData.map(stock => {
            const price = parseFloat(stock.price);
            const newAllocationPercent = parseFloat(stock.newAllocationPercent);
            const oldAllocationShares = parseFloat(stock.oldAllocationShares);
            const capitalInvested = (newAllocationPercent / 100) * capital;
            const newAllocatedUnits = capitalInvested / price;
            const changeInUnits = newAllocatedUnits - oldAllocationShares;

            return {
                ...stock,
                capitalInvested,
                newAllocatedUnits,
                changeInUnits,
            };
        });
    };

    const updatedData = calculateInitialValues(data, capital);
    setData(updatedData);
    calculateTotals(updatedData, capital);
}, [data, capital]);
```

### 2. Ensure Initial Calculations are Done on Data Fetch:
After fetching data, trigger the calculations to update the state with the calculated fields.

```javascript
const fetchData = async () => {
    try {
        setLoading(true);
        const response = await fetch(`https://dummy-url.com/api/rebalanced-portfolio/${portfolioId}`);
        if (!response.ok) {
            throw new Error('Network response was not ok');
        }
        const result = await response.json();
        const initialData = Object.entries(result.allocation).map(([symbol, details]) => ({
            stockSymbol: symbol,
            oldAllocationShares: parseFloat(details.oldAllocationShares),
            newAllocationPercent: parseFloat(details.newAllocationPercent),
            price: parseFloat(details.price),
        }));
        setData(initialData);
        setCapital(parseFloat(result.capital));
    } catch (error) {
        console.error('Error fetching data:', error);
        toast.error('Error fetching data, displaying dummy data instead.');
        const dummyData = [
            { stockSymbol: 'AAPL', oldAllocationShares: 10, newAllocationPercent: 5, price: 113.79 },
            { stockSymbol: 'GOOGL', oldAllocationShares: 10, newAllocationPercent: 5, price: 113.79 },
        ];
        setData(dummyData);
        setCapital(1000);
    } finally {
        setLoading(false);
    }
};
```

### 3. Update `handleInputChange` to Trigger Calculation:
Ensure `handleInputChange` recalculates the required fields on user input change:

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

These changes ensure that the initial rendering of `newAllocatedUnits` and `availableCash` is calculated correctly and recalculated when any relevant data changes.