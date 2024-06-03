Implementing an inactivity timeout in a React app to log out a user when they're inactive and issuing a new refresh token when the previous access token expires can be achieved using hooks and context for state management. Here’s a step-by-step guide to help you implement this:

### 1. Create a Context for Authentication

Create an `AuthContext` to manage authentication state and provide access to it throughout your app.

```jsx
// AuthContext.js
import React, { createContext, useState, useEffect } from 'react';

const AuthContext = createContext();

export const AuthProvider = ({ children }) => {
    const [authToken, setAuthToken] = useState(null);
    const [refreshToken, setRefreshToken] = useState(null);

    const login = (newAuthToken, newRefreshToken) => {
        setAuthToken(newAuthToken);
        setRefreshToken(newRefreshToken);
    };

    const logout = () => {
        setAuthToken(null);
        setRefreshToken(null);
    };

    return (
        <AuthContext.Provider value={{ authToken, refreshToken, login, logout }}>
            {children}
        </AuthContext.Provider>
    );
};

export default AuthContext;
```

### 2. Create a Hook to Manage Inactivity

Create a custom hook to detect user inactivity and log them out after a set period.

```jsx
// useInactivityTimeout.js
import { useEffect, useCallback } from 'react';
import { useContext } from 'react';
import AuthContext from './AuthContext';

const useInactivityTimeout = (timeout = 300000) => { // default 5 minutes
    const { logout } = useContext(AuthContext);

    const handleActivity = useCallback(() => {
        clearTimeout(window.inactivityTimeout);
        window.inactivityTimeout = setTimeout(() => {
            logout();
        }, timeout);
    }, [logout, timeout]);

    useEffect(() => {
        window.addEventListener('mousemove', handleActivity);
        window.addEventListener('keydown', handleActivity);

        handleActivity(); // set initial timeout

        return () => {
            clearTimeout(window.inactivityTimeout);
            window.removeEventListener('mousemove', handleActivity);
            window.removeEventListener('keydown', handleActivity);
        };
    }, [handleActivity]);
};

export default useInactivityTimeout;
```

### 3. Refresh Token Logic

Add logic to refresh the token when it expires. This can be achieved using an effect that checks the token expiration and refreshes it accordingly.

```jsx
// AuthContext.js
import jwt_decode from 'jwt-decode';

const refreshAuthToken = async (refreshToken) => {
    // Implement your refresh token logic here
    // This is a placeholder function that you should replace with your actual API call
    const response = await fetch('/api/refresh-token', {
        method: 'POST',
        headers: {
            'Content-Type': 'application/json',
        },
        body: JSON.stringify({ refreshToken }),
    });
    const data = await response.json();
    return data.newAuthToken;
};

export const AuthProvider = ({ children }) => {
    // existing state and functions...

    useEffect(() => {
        if (!refreshToken) return;

        const interval = setInterval(async () => {
            if (authToken) {
                const decodedToken = jwt_decode(authToken);
                const expirationTime = decodedToken.exp * 1000 - 60000; // refresh 1 minute before expiry
                if (Date.now() >= expirationTime) {
                    const newAuthToken = await refreshAuthToken(refreshToken);
                    setAuthToken(newAuthToken);
                }
            }
        }, 60000); // check every minute

        return () => clearInterval(interval);
    }, [authToken, refreshToken]);
};
```

### 4. Use the Hook in Your App

Finally, use the `useInactivityTimeout` hook in your main app component or wherever appropriate.

```jsx
// App.js
import React from 'react';
import { AuthProvider } from './AuthContext';
import useInactivityTimeout from './useInactivityTimeout';

const App = () => {
    useInactivityTimeout();

    return (
        <AuthProvider>
            {/* Your app components go here */}
        </AuthProvider>
    );
};

export default App;
```

### Summary

1. **AuthContext**: Manages authentication state.
2. **useInactivityTimeout**: Detects inactivity and logs the user out.
3. **Refresh Token Logic**: Refreshes the auth token before it expires.

This setup ensures that users are logged out after a period of inactivity and that their authentication token is refreshed as needed. Adjust the timeout values and API calls according to your application's requirements.