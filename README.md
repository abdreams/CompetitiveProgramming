To avoid losing focus when changing allocation inputs, you need to make sure that your component is not re-rendering unnecessarily. This usually happens when the state or props change, causing a full re-render of the component.

One common solution is to use a controlled component approach and manage state updates in a way that preserves the input focus. Here’s how you can do that:

### Changes to Make

1. **Maintain the Input State Separately**:
   Instead of directly modifying the data array, you can maintain a separate state for the input values. This way, you control when the input state updates and avoid unnecessary re-renders.

2. **Update State Only When Necessary**:
   Only update the main data state when the input loses focus or on a specific event (e.g., a submit button).

### Step-by-Step Implementation

1. **Create a Separate State for Input Values**:
   Add a state to hold the new allocation values temporarily.

   ```javascript
   const [inputValues, setInputValues] = useState({});
   ```

2. **Initialize Input Values**:
   Initialize the `inputValues` state when you fetch the data.

   ```javascript
   useEffect(() => {
       const fetchData = async () => {
           // ... your existing fetch logic
           const result = await response.json();
           const initialData = Object.entries(result.allocation).map(([symbol, details]) => ({
               stockSymbol: symbol,
               oldAllocationShares: parseFloat(details.oldAllocationShares),
               newAllocationPercent: parseFloat(details.newAllocationPercent),
               price: parseFloat(details.price),
           }));
           setData(initialData);

           const initialInputValues = Object.fromEntries(
               initialData.map(stock => [stock.stockSymbol, stock.newAllocationPercent])
           );
           setInputValues(initialInputValues);
       };

       fetchData();
   }, [portfolioId]);
   ```

3. **Handle Input Change**:
   Update the `handleInputChange` function to manage the input values state separately.

   ```javascript
   const handleInputChange = (e, stockSymbol) => {
       const { name, value } = e.target;
       if (name === 'newAllocationPercent' && parseFloat(value) < 0) {
           toast.error('Allocation cannot be negative');
           return;
       }

       setInputValues(prevValues => ({
           ...prevValues,
           [stockSymbol]: parseFloat(value) || 0,
       }));
   };
   ```

4. **Modify the Input Field**:
   Use the `inputValues` state for the input value and handle changes without re-rendering the entire component.

   ```javascript
   const columns = React.useMemo(
       () => [
           // Other columns definitions...
           {
               Header: 'New Allocation (%)',
               accessor: 'newAllocationPercent',
               Cell: ({ cell: { value }, row: { original } }) => (
                   <input
                       type="number"
                       step="0.01"
                       name="newAllocationPercent"
                       value={inputValues[original.stockSymbol] || ''}
                       onChange={(e) => handleInputChange(e, original.stockSymbol)}
                       className="w-full px-2 py-1 border rounded"
                       onClick={(e) => e.stopPropagation()} // Prevent row click
                   />
               ),
               sortType: 'basic',
           },
           // ... remaining columns
       ],
       [inputValues] // Add inputValues as a dependency
   );
   ```

5. **Update Data on Blur or Submit**:
   Update the main data state when the input loses focus or on a specific event, such as clicking a save button.

   ```javascript
   const handleBlur = (stockSymbol) => {
       setData(prevData =>
           prevData.map(stock =>
               stock.stockSymbol === stockSymbol
                   ? { ...stock, newAllocationPercent: inputValues[stockSymbol] }
                   : stock
           )
       );
   };

   // Modify the input field to call handleBlur on blur
   const columns = React.useMemo(
       () => [
           // Other columns definitions...
           {
               Header: 'New Allocation (%)',
               accessor: 'newAllocationPercent',
               Cell: ({ cell: { value }, row: { original } }) => (
                   <input
                       type="number"
                       step="0.01"
                       name="newAllocationPercent"
                       value={inputValues[original.stockSymbol] || ''}
                       onChange={(e) => handleInputChange(e, original.stockSymbol)}
                       onBlur={() => handleBlur(original.stockSymbol)}
                       className="w-full px-2 py-1 border rounded"
                       onClick={(e) => e.stopPropagation()} // Prevent row click
                   />
               ),
               sortType: 'basic',
           },
           // ... remaining columns
       ],
       [inputValues] // Add inputValues as a dependency
   );
   ```

By maintaining a separate state for input values and only updating the main data state when necessary, you can prevent unnecessary re-renders and avoid losing focus on input fields. This should allow you to enter new allocation values seamlessly without losing focus.