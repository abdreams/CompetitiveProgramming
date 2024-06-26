To store the `isDarkMode` value in local storage and retrieve it when the application loads, you need to update your Redux slice to initialize the state from local storage and update local storage whenever the state changes.

Here's how you can modify your code:

1. **Initialize state from local storage:**

```jsx
const initialState = {
    isDarkMode: JSON.parse(localStorage.getItem('isDarkMode')) || false,
};
```

2. **Update local storage when the state changes:**

```jsx
const themeSlice = createSlice({
    name: 'theme',
    initialState,
    reducers: {
        toggleTheme(state) {
            state.isDarkMode = !state.isDarkMode;
            localStorage.setItem('isDarkMode', JSON.stringify(state.isDarkMode));
        },
        setDarkMode(state, action) {
            state.isDarkMode = action.payload;
            localStorage.setItem('isDarkMode', JSON.stringify(state.isDarkMode));
        }
    },
});

export const { toggleTheme, setDarkMode } = themeSlice.actions;
export const selectIsDarkMode = (state) => state.theme.isDarkMode;
export default themeSlice.reducer;
```

3. **Ensure Redux store is correctly configured:**

Make sure your Redux store is correctly configured to include the `theme` slice:

```jsx
import { configureStore } from '@reduxjs/toolkit';
import themeReducer from './themeSlice';

const store = configureStore({
    reducer: {
        theme: themeReducer,
    },
});

export default store;
```

4. **Usage in your application:**

Ensure you are using the Redux `Provider` at the root of your application and access the `isDarkMode` state correctly:

```jsx
import React from 'react';
import ReactDOM from 'react-dom';
import { Provider } from 'react-redux';
import store from './store';
import App from './App';

ReactDOM.render(
    <Provider store={store}>
        <App />
    </Provider>,
    document.getElementById('root')
);
```

Now, the `isDarkMode` value will be stored in local storage, and it will persist across new tabs and page reloads. When the user toggles the theme, the new value will be saved in local storage, ensuring a consistent experience.