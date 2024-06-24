To automatically refresh the original tab after closing the rebalanced portfolio tab, you can use `localStorage` or `sessionStorage` to set a flag indicating that the portfolio was rebalanced, and then check this flag in the original tab to trigger a refresh.

Here's how you can implement this:

### 1. Modify the `RebalancePortfolio` Component

Update the `handleAccept` and `handleReject` functions to set a flag in `localStorage` before closing the tab.

```jsx
const handleAccept = async () => {
    try {
        const allocation = data.reduce((acc, { stockSymbol, percentAllocated }) => {
            acc[stockSymbol] = parseFloat(percentAllocated); // Convert to float
            return acc;
        }, {});

        const payload = {
            pid: portfolioId,
            allocation,
            capital
        };

        const response = await fetch(`https://dummy-url.com/api/save-portfolio/${portfolioId}`, {
            method: 'POST',
            headers: {
                'Content-Type': 'application/json',
            },
            body: JSON.stringify(payload),
        });

        if (response.ok) {
            toast.success('Portfolio saved successfully');
            localStorage.setItem('portfolioRebalanced', 'true'); // Set flag
            window.close(); // Close the tab
        } else {
            toast.error('Failed to save portfolio');
        }
    } catch (error) {
        toast.error('Error saving data');
    }
};

const handleReject = () => {
    localStorage.setItem('portfolioRebalanced', 'true'); // Set flag
    window.close(); // Close the tab
};
```

### 2. Modify the Original Page to Check the Flag

In the component where you display the allocation pie chart, add an effect to check for the `portfolioRebalanced` flag and refresh the data if necessary.

```jsx
import React, { useEffect, useState } from 'react';
import { toast } from 'react-toastify';
import AllocationPieChart from '../components/AllocationPieChart'; // Import your pie chart component

const PortfolioPage = () => {
    const [data, setData] = useState([]);

    const fetchData = async () => {
        try {
            const response = await fetch('https://dummy-url.com/api/current-portfolio'); // Adjust this URL as necessary
            const result = await response.json();
            setData(result);
        } catch (error) {
            toast.error('Error fetching data');
        }
    };

    useEffect(() => {
        fetchData();
    }, []);

    useEffect(() => {
        const checkRebalancedFlag = () => {
            if (localStorage.getItem('portfolioRebalanced') === 'true') {
                localStorage.removeItem('portfolioRebalanced');
                fetchData(); // Refresh data
            }
        };

        // Check the flag on component mount
        checkRebalancedFlag();

        // Optionally, add an event listener to detect when the user returns to the tab
        window.addEventListener('focus', checkRebalancedFlag);

        return () => {
            window.removeEventListener('focus', checkRebalancedFlag);
        };
    }, []);

    return (
        <div>
            <h2 className="text-2xl font-bold mb-5">Current Portfolio</h2>
            <AllocationPieChart data={data} /> {/* Render your pie chart */}
            {/* Other components and content */}
        </div>
    );
};

export default PortfolioPage;
```

### Summary

1. **Setting the Flag**: When the user accepts or rejects the rebalanced portfolio, set a flag in `localStorage`.
2. **Checking the Flag**: In the original tab, check for the flag on component mount and optionally when the tab gains focus. If the flag is set, refresh the data and remove the flag.

This way, the original tab will automatically refresh its data when the user accepts or rejects the rebalanced portfolio.