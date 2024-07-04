To ensure that each page scrolls to the top when navigating to it, you can use a `useEffect` hook to scroll to the top whenever the component mounts. Here's how you can do it:

### Option 1: Using `useEffect` in each component

For each page component, you can add the following code to ensure it scrolls to the top on mount:

```jsx
import React, { useEffect } from 'react';

const YourComponent = () => {
    useEffect(() => {
        window.scrollTo(0, 0);
    }, []);

    return (
        <div>
            {/* Your component content */}
        </div>
    );
};

export default YourComponent;
```

### Option 2: Using a custom hook

If you want to avoid repeating the same `useEffect` in multiple components, you can create a custom hook:

```jsx
import { useEffect } from 'react';

const useScrollToTop = () => {
    useEffect(() => {
        window.scrollTo(0, 0);
    }, []);
};

export default useScrollToTop;
```

Then, use this custom hook in your components:

```jsx
import React from 'react';
import useScrollToTop from './useScrollToTop';

const YourComponent = () => {
    useScrollToTop();

    return (
        <div>
            {/* Your component content */}
        </div>
    );
};

export default YourComponent;
```

### Option 3: Using React Router with `useLocation`

If you are using React Router for navigation, you can create a component that listens to route changes and scrolls to the top:

```jsx
import React, { useEffect } from 'react';
import { useLocation } from 'react-router-dom';

const ScrollToTop = () => {
    const { pathname } = useLocation();

    useEffect(() => {
        window.scrollTo(0, 0);
    }, [pathname]);

    return null;
};

export default ScrollToTop;
```

Then, include this `ScrollToTop` component in your main App component, preferably within the Router:

```jsx
import React from 'react';
import { BrowserRouter as Router, Route, Switch } from 'react-router-dom';
import ScrollToTop from './ScrollToTop';
import HomePage from './HomePage';
import OtherPage from './OtherPage';

const App = () => {
    return (
        <Router>
            <ScrollToTop />
            <Switch>
                <Route exact path="/" component={HomePage} />
                <Route path="/other" component={OtherPage} />
                {/* Add more routes as needed */}
            </Switch>
        </Router>
    );
};

export default App;
```

### Explanation:
1. **Using `useEffect` in each component**: This method ensures that each specific component scrolls to the top when it mounts.
2. **Using a custom hook**: Simplifies the process by encapsulating the scrolling logic in a reusable hook.
3. **Using React Router with `useLocation`**: This approach ensures that the page scrolls to the top whenever the route changes, which is generally the most effective and centralized way to handle this in a React application.