To display a browser alert one minute before logging out due to inactivity, you can modify the `useIdleTimeout` hook to use the `alert` function directly. Here is the updated `useIdleTimeout` hook:

### `useIdleTimeout.js`

```javascript
import { useEffect, useRef } from 'react';
import { useDispatch } from 'react-redux';
import { logout } from '../redux/slices/user/userSlice';

const useIdleTimeout = (timeout = 900000) => { // default 15 minutes
  const dispatch = useDispatch();
  const warningTime = 60000; // 1 minute
  const timerRef = useRef(null);
  const warningTimerRef = useRef(null);

  useEffect(() => {
    const resetTimer = () => {
      clearTimeout(timerRef.current);
      clearTimeout(warningTimerRef.current);

      warningTimerRef.current = setTimeout(() => {
        alert('You will be logged out due to inactivity');
      }, timeout - warningTime);

      timerRef.current = setTimeout(() => {
        dispatch(logout());
      }, timeout);
    };

    const handleActivity = () => {
      resetTimer();
    };

    resetTimer();

    window.addEventListener('mousemove', handleActivity);
    window.addEventListener('keypress', handleActivity);

    return () => {
      clearTimeout(timerRef.current);
      clearTimeout(warningTimerRef.current);
      window.removeEventListener('mousemove', handleActivity);
      window.removeEventListener('keypress', handleActivity);
    };
  }, [dispatch, timeout, warningTime]);

  return null;
};

export default useIdleTimeout;
```

### Integrate into Your Main App Component

Use the `useIdleTimeout` hook in your main application component to initialize the idle timeout logic.

### `App.js`

```javascript
import React from 'react';
import { Provider } from 'react-redux';
import { BrowserRouter as Router, Route, Switch } from 'react-router-dom';
import store from './store'; // Ensure this path is correct
import ChatbotComponent from './ChatbotComponent'; // Ensure this path is correct
import NewsPage from './NewsPage'; // Ensure this path is correct
import CreatePortfolioPage from './CreatePortfolioPage'; // Ensure this path is correct
import useIdleTimeout from './useIdleTimeout'; // Ensure this path is correct
import './App.css';

const App = () => {
  useIdleTimeout();

  return (
    <Provider store={store}>
      <Router>
        <div>
          <Switch>
            <Route path="/create-portfolio" component={CreatePortfolioPage} />
            <Route path="/news" component={NewsPage} />
            {/* Add other routes as needed */}
          </Switch>
          <ChatbotComponent />
        </div>
      </Router>
    </Provider>
  );
};

export default App;
```

By adding `useIdleTimeout` directly into your `App` component, the idle timeout logic will be initialized when the application starts. The alert message will be displayed one minute before the user is logged out due to inactivity.