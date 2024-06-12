To implement automatic logout due to inactivity and show a warning message 2 minutes before the user is logged out, you can use a combination of Redux for state management, React hooks for handling the timer and event listeners, and a modal or alert to show the warning message.

Here's a step-by-step guide to achieve this:

### Step 1: Create the Redux Slice

#### userSlice.js

```javascript
import { createSlice } from '@reduxjs/toolkit';

const initialState = {
  isAuthenticated: true,
  warningShown: false,
  timeoutId: null,
};

const userSlice = createSlice({
  name: 'user',
  initialState,
  reducers: {
    logout(state) {
      state.isAuthenticated = false;
    },
    showWarning(state) {
      state.warningShown = true;
    },
    resetWarning(state) {
      state.warningShown = false;
    },
    setTimerId(state, action) {
      state.timeoutId = action.payload;
    },
    clearTimerId(state) {
      state.timeoutId = null;
    },
  },
});

export const { logout, showWarning, resetWarning, setTimerId, clearTimerId } = userSlice.actions;
export default userSlice.reducer;
```

### Step 2: Set Up the Timer and Event Listeners

#### InactivityHandler.js

```javascript
import { useDispatch, useSelector } from 'react-redux';
import { useEffect, useRef } from 'react';
import { logout, showWarning, resetWarning, setTimerId, clearTimerId } from './userSlice';

const useInactivityHandler = () => {
  const dispatch = useDispatch();
  const { timeoutId } = useSelector((state) => state.user);
  const warningTimeoutRef = useRef(null);

  const warningTime = 10 * 60 * 1000; // 10 minutes
  const logoutTime = 12 * 60 * 1000; // 12 minutes

  const resetTimer = () => {
    if (timeoutId) {
      clearTimeout(timeoutId);
      dispatch(clearTimerId());
    }

    const warningTimeoutId = setTimeout(() => {
      dispatch(showWarning());
    }, warningTime);

    const logoutTimeoutId = setTimeout(() => {
      dispatch(logout());
    }, logoutTime);

    dispatch(setTimerId(warningTimeoutId));
  };

  useEffect(() => {
    resetTimer();

    const events = ['mousemove', 'mousedown', 'keypress', 'touchstart'];
    events.forEach((event) => {
      window.addEventListener(event, resetTimer);
    });

    return () => {
      if (timeoutId) {
        clearTimeout(timeoutId);
        dispatch(clearTimerId());
      }
      events.forEach((event) => {
        window.removeEventListener(event, resetTimer);
      });
    };
  }, [dispatch, timeoutId]);

  useEffect(() => {
    if (warningTimeoutRef.current) {
      clearTimeout(warningTimeoutRef.current);
    }

    if (timeoutId) {
      warningTimeoutRef.current = setTimeout(() => {
        dispatch(resetWarning());
      }, logoutTime - warningTime);
    }
  }, [dispatch, timeoutId]);

  return null;
};

export default useInactivityHandler;
```

### Step 3: Display the Warning Message

#### WarningModal.js

```javascript
import React from 'react';
import { useDispatch, useSelector } from 'react-redux';
import { resetWarning } from './userSlice';

const WarningModal = () => {
  const dispatch = useDispatch();
  const { warningShown } = useSelector((state) => state.user);

  const handleStayLoggedIn = () => {
    dispatch(resetWarning());
  };

  if (!warningShown) return null;

  return (
    <div className="fixed inset-0 flex items-center justify-center z-50">
      <div className="absolute inset-0 bg-gray-600 opacity-50"></div>
      <div className="bg-white p-6 rounded-lg shadow-lg z-10 w-full max-w-md">
        <h2 className="text-xl font-semibold mb-4">Inactivity Warning</h2>
        <p>You will be logged out in 2 minutes due to inactivity.</p>
        <div className="flex justify-end mt-4">
          <button onClick={handleStayLoggedIn} className="bg-blue-500 text-white px-4 py-2 rounded-lg">
            Stay Logged In
          </button>
        </div>
      </div>
    </div>
  );
};

export default WarningModal;
```

### Step 4: Integrate Everything in Your Main App Component

#### App.js

```javascript
import React from 'react';
import { Provider } from 'react-redux';
import { BrowserRouter as Router, Route, Switch } from 'react-router-dom';
import store from './store'; // Ensure this path is correct
import ChatbotComponent from './ChatbotComponent'; // Ensure this path is correct
import NewsPage from './NewsPage';
import CreatePortfolioPage from './CreatePortfolioPage'; // Ensure this path is correct
import WarningModal from './WarningModal'; // Ensure this path is correct
import useInactivityHandler from './InactivityHandler'; // Ensure this path is correct
import './App.css';

const App = () => {
  useInactivityHandler();

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
          <WarningModal />
        </div>
      </Router>
    </Provider>
  );
};

export default App;
```

### Step 5: Ensure Your Redux Store Is Set Up Correctly

#### store.js

```javascript
import { configureStore } from '@reduxjs/toolkit';
import userReducer from './userSlice'; // Ensure this path is correct

const store = configureStore({
  reducer: {
    user: userReducer,
  },
});

export default store;
```

By following these steps, you will have implemented automatic logout due to inactivity with a warning message displayed 2 minutes before the user is logged out. This setup uses Redux for state management and hooks to handle timers and event listeners.