I apologize for that oversight. Here is the updated code with the `handleSubmit` function called on the button click and the `useHistory` import and usage removed:

```javascript
import React, { useState } from 'react';

export default function CreatePortfolio() {
    const [formData, setFormData] = useState({
        portfolioName: '',
        description: '',
        capital: '',
        timeHorizon: '',
        riskAppetite: 50,
    });

    const handleChange = (e) => {
        const { name, value } = e.target;
        setFormData(prevState => ({
            ...prevState,
            [name]: value
        }));
    };

    const handleSliderChange = (e) => {
        setFormData(prevState => ({
            ...prevState,
            riskAppetite: e.target.value
        }));
    };

    const handleSubmit = async (e) => {
        e.preventDefault();
        const url = 'https://jsonplaceholder.typicode.com/posts'; // Dummy backend URL for demonstration

        try {
            const response = await fetch(url, {
                method: 'POST',
                headers: {
                    'Content-Type': 'application/json'
                },
                body: JSON.stringify(formData)
            });
            const result = await response.json();
            console.log('Success:', result);
        } catch (error) {
            console.error('Error:', error);
        }
    };

    return (
        <div className="min-h-screen flex items-center justify-center bg-gray-100">
            <form onSubmit={handleSubmit} className='w-11/12 max-w-[700px] px-10 py-20 rounded-3xl bg-white border-2 border-gray-100'>
                <h1 className='text-5xl font-semibold'>Create Portfolio</h1>
                <p className='font-medium text-lg text-gray-500 mt-4'>Please fill in the details to create your portfolio.</p>
                <div className='mt-8'>
                    <div className='flex flex-col'>
                        <label className='text-lg font-medium'>Name of Portfolio</label>
                        <input 
                            className='w-full border-2 border-gray-100 rounded-xl p-4 mt-1 bg-transparent'
                            placeholder="Enter the portfolio name"
                            name="portfolioName"
                            value={formData.portfolioName}
                            onChange={handleChange}
                        />
                    </div>
                    <div className='flex flex-col mt-4'>
                        <label className='text-lg font-medium'>Description of Portfolio</label>
                        <input 
                            className='w-full border-2 border-gray-100 rounded-xl p-4 mt-1 bg-transparent'
                            placeholder="Enter the portfolio description"
                            name="description"
                            value={formData.description}
                            onChange={handleChange}
                        />
                    </div>
                    <div className='flex flex-col mt-4'>
                        <label className='text-lg font-medium'>Capital to be Invested (in USD)</label>
                        <input 
                            className='w-full border-2 border-gray-100 rounded-xl p-4 mt-1 bg-transparent'
                            placeholder="Enter the capital amount"
                            name="capital"
                            type="number"
                            value={formData.capital}
                            onChange={handleChange}
                        />
                    </div>
                    <div className='flex flex-col mt-4'>
                        <label className='text-lg font-medium'>Time Horizon (Duration in Days)</label>
                        <input 
                            className='w-full border-2 border-gray-100 rounded-xl p-4 mt-1 bg-transparent'
                            placeholder="Enter the duration in days"
                            name="timeHorizon"
                            type="number"
                            value={formData.timeHorizon}
                            onChange={handleChange}
                        />
                    </div>
                    <div className='flex flex-col mt-4'>
                        <label className='text-lg font-medium'>Risk Appetite (%)</label>
                        <input 
                            className='w-full'
                            type="range"
                            name="riskAppetite"
                            min="0"
                            max="100"
                            value={formData.riskAppetite}
                            onChange={handleSliderChange}
                        />
                        <span className="text-center mt-2">{formData.riskAppetite}%</span>
                    </div>
                    <div className='mt-8 flex flex-col gap-y-4'>
                        <button 
                            type="submit"
                            onClick={handleSubmit}
                            className='active:scale-[.98] active:duration-75 transition-all hover:scale-[1.01] ease-in-out transform py-4 bg-violet-500 rounded-xl text-white font-bold text-lg'
                        >
                            Create Portfolio
                        </button>
                    </div>
                </div>
            </form>
        </div>
    );
}
```

Now, the `handleSubmit` function is correctly called when the "Create Portfolio" button is clicked. The `useHistory` import and usage have been removed. The form handles input changes, including the slider for risk appetite, and submits the data to a dummy backend.

Sure, here's how you can add a button in the `PortfolioTable` component to navigate to the `CreatePortfolio` page.

1. **Add the `PortfolioTable` Component with a "Create Portfolio" Button:**
   Ensure that you have a router set up for navigation.

2. **Update `PortfolioTable` Component:**

```javascript
import React from 'react';
import { useHistory } from 'react-router-dom';

export default function PortfolioTable() {
    const history = useHistory();

    return (
        <div className="min-h-screen flex flex-col items-center justify-center bg-gray-100">
            <div className="w-11/12 max-w-[700px] px-10 py-20 rounded-3xl bg-white border-2 border-gray-100">
                <h1 className="text-5xl font-semibold">Portfolio Table</h1>
                <p className="font-medium text-lg text-gray-500 mt-4">List of your portfolios.</p>
                
                {/* Portfolio Table Content Here */}
                
                <div className="mt-8 flex justify-center">
                    <button 
                        className='active:scale-[.98] active:duration-75 transition-all hover:scale-[1.01] ease-in-out transform py-4 bg-violet-500 rounded-xl text-white font-bold text-lg'
                        onClick={() => history.push('/create-portfolio')}
                    >
                        Create Portfolio
                    </button>
                </div>
            </div>
        </div>
    );
}
```

3. **Ensure `CreatePortfolio` Route is Defined:**

In your main router configuration (e.g., `App.js` or `Router.js`), define the route for the `CreatePortfolio` page:

```javascript
import React from 'react';
import { BrowserRouter as Router, Route, Switch } from 'react-router-dom';
import PortfolioTable from './PortfolioTable';
import CreatePortfolio from './CreatePortfolio';
import SignUp from './SignUp'; // Assuming you have other routes like SignUp

export default function App() {
    return (
        <Router>
            <Switch>
                <Route path="/" exact component={PortfolioTable} />
                <Route path="/create-portfolio" component={CreatePortfolio} />
                <Route path="/signup" component={SignUp} />  {/* Example of other route */}
                {/* Add other routes here */}
            </Switch>
        </Router>
    );
}
```

With these changes, the `PortfolioTable` component now includes a "Create Portfolio" button that navigates to the `CreatePortfolio` form. The router configuration ensures that the navigation works as expected.
