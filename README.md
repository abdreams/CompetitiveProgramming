To implement automatic logout after a period of user inactivity, you can follow these steps:

1. **Set up Redux slices**: You already have the `userSlice` with `login` and `logout` reducers. We need to dispatch these actions based on user activity.

2. **Create a timeout hook**: Create a custom hook to detect user inactivity.

3. **Integrate the hook in your application**: Use the hook in your main component to monitor user activity and dispatch the logout action when the user is idle.

### Step 1: Setup Redux Slices

Ensure your Redux slices are set up correctly in `userSlice.js`.

#### `redux/slices/user/userSlice.js`

```javascript
import { createSlice } from '@reduxjs/toolkit';

const initialState = {
  isAuthenticated: false,
  user: null,
};

const userSlice = createSlice({
  name: 'user',
  initialState,
  reducers: {
    login: (state, action) => {
      state.isAuthenticated = true;
      state.user = action.payload;
    },
    logout: (state) => {
      state.isAuthenticated = false;
      state.user = null;
    },
  },
});

export const { login, logout } = userSlice.actions;

export default userSlice.reducer;
```

### Step 2: Create a Timeout Hook

Create a custom hook to handle user inactivity.

#### `hooks/useIdleTimeout.js`

```javascript
import { useEffect } from 'react';
import { useDispatch } from 'react-redux';
import { logout } from '../redux/slices/user/userSlice';

const useIdleTimeout = (timeout = 300000) => { // default 5 minutes
  const dispatch = useDispatch();

  useEffect(() => {
    let timer;

    const resetTimer = () => {
      clearTimeout(timer);
      timer = setTimeout(() => {
        dispatch(logout());
      }, timeout);
    };

    const handleActivity = () => {
      resetTimer();
    };

    window.addEventListener('mousemove', handleActivity);
    window.addEventListener('keypress', handleActivity);

    resetTimer();

    return () => {
      clearTimeout(timer);
      window.removeEventListener('mousemove', handleActivity);
      window.removeEventListener('keypress', handleActivity);
    };
  }, [dispatch, timeout]);
};

export default useIdleTimeout;
```

### Step 3: Integrate the Hook in Your Main Component

Use the hook in your main component to monitor user activity and dispatch the logout action when the user is idle.

#### `App.jsx`

```jsx
import React, { useState } from 'react';
import { useSelector } from 'react-redux';
import Navbar from './components/Navbar';
import Portfolio from './pages/Portfolio';
import PortfolioDetail from './pages/PortfolioDetail';
import { BrowserRouter as Router, Route, Switch } from 'react-router-dom';
import useIdleTimeout from './hooks/useIdleTimeout';

const sampleUser = {
  name: 'Victor Crest',
  age: 26,
  email: 'victor.crest@example.com',
  profileImage: 'https://via.placeholder.com/150',  // Replace with actual image URL if available
};

function App() {
  const [user, setUser] = useState(null);
  const isAuthenticated = useSelector((state) => state.user.isAuthenticated);

  useIdleTimeout(300000); // 5 minutes timeout

  const handleSignIn = () => {
    setUser(sampleUser);
    setIsAuthenticated(true);
  };

  const handleSignOut = () => {
    setUser(null);
    setIsAuthenticated(false);
  };

  return (
    <Router>
      <div>
        <Navbar 
          isAuthenticated={isAuthenticated} 
          user={user} 
          onSignIn={handleSignIn} 
          onSignOut={handleSignOut} 
        />
        <Switch>
          <Route path="/portfolio/:id" component={PortfolioDetail} />
          <Route path="/" component={Portfolio} />
        </Switch>
      </div>
    </Router>
  );
}

export default App;
```

### Step 4: Set Up Redux Store

Ensure your Redux store is set up to use the user slice.

#### `redux/store.js`

```javascript
import { configureStore } from '@reduxjs/toolkit';
import userReducer from './slices/user/userSlice';

const store = configureStore({
  reducer: {
    user: userReducer,
  },
});

export default store;
```

#### `index.js`

```jsx
import React from 'react';
import ReactDOM from 'react-dom';
import { Provider } from 'react-redux';
import App from './App';
import store from './redux/store';

ReactDOM.render(
  <Provider store={store}>
    <App />
  </Provider>,
  document.getElementById('root')
);
```

### Explanation

1. **Redux Slice**: The `userSlice` handles login and logout actions.
2. **Custom Hook**: The `useIdleTimeout` hook monitors user activity and dispatches the logout action after a period of inactivity.
3. **Main Component**: The `App` component uses the `useIdleTimeout` hook to log out the user after 5 minutes of inactivity.
4. **Redux Store**: The Redux store is set up to include the `userSlice`.

This setup ensures that the user is logged out automatically after a period of inactivity, enhancing the security of your application.