Implementing error logging in your application is crucial for identifying issues and improving the debugging process. Here’s a step-by-step guide on how to add error logging across your React application.

### Step 1: Choose a Logging Library
You can use libraries like `winston`, `log4js`, or external services like `Sentry`, `LogRocket`, or `New Relic`. For this example, I'll use `Sentry`, as it is widely used and integrates well with React applications.

### Step 2: Install Sentry
First, you need to install the Sentry SDK for JavaScript.

```sh
npm install @sentry/react @sentry/tracing
```

### Step 3: Initialize Sentry
Initialize Sentry at the entry point of your application (typically `index.js` or `App.js`).

```js
// src/index.js

import React from 'react';
import ReactDOM from 'react-dom';
import App from './App';
import * as Sentry from '@sentry/react';
import { Integrations } from '@sentry/tracing';

Sentry.init({
  dsn: 'YOUR_SENTRY_DSN', // Replace with your Sentry DSN
  integrations: [new Integrations.BrowserTracing()],
  tracesSampleRate: 1.0,
});

ReactDOM.render(
  <React.StrictMode>
    <App />
  </React.StrictMode>,
  document.getElementById('root')
);
```

### Step 4: Catch Errors in Components
Use the `ErrorBoundary` component provided by Sentry to catch errors in your React components.

```js
// src/App.js

import React from 'react';
import * as Sentry from '@sentry/react';
import StockComparision from './StockComparision';

const App = () => (
  <Sentry.ErrorBoundary fallback={<p>An error has occurred</p>}>
    <StockComparision />
  </Sentry.ErrorBoundary>
);

export default App;
```

### Step 5: Log Errors in Async Functions
For functions where you handle errors, like API calls, log the errors to Sentry.

```js
import * as Sentry from '@sentry/react';

const fetchStockSummary = async () => {
  try {
    const response = await fetch(FETCH_SUMMARY_URL);
    if (!response.ok) throw new Error('Network response was not ok');
    const result = await response.json();
    setStockSummary(result);
  } catch (error) {
    console.error('Error fetching stock summary:', error);
    Sentry.captureException(error); // Log to Sentry
    setStockSummary(dummyStockData);
  }
};

const fetchStockDetails = async () => {
  try {
    const response = await fetch(FETCH_DETAILS_URL);
    if (!response.ok) throw new Error('Network response was not ok');
    const result = await response.json();
    setStockDetails(result);
  } catch (error) {
    console.error('Error fetching stock details:', error);
    Sentry.captureException(error); // Log to Sentry
    setStockDetails(dummyStockDetails);
  }
};
```

### Step 6: Adding Context and Breadcrumbs
You can add more context to your logs to provide additional information.

```js
import * as Sentry from '@sentry/react';

const fetchStockSummary = async () => {
  try {
    const response = await fetch(FETCH_SUMMARY_URL);
    if (!response.ok) throw new Error('Network response was not ok');
    const result = await response.json();
    setStockSummary(result);
  } catch (error) {
    Sentry.addBreadcrumb({
      category: 'api',
      message: 'Fetching stock summary failed',
      level: 'error',
    });
    Sentry.captureException(error);
    setStockSummary(dummyStockData);
  }
};

const fetchStockDetails = async () => {
  try {
    const response = await fetch(FETCH_DETAILS_URL);
    if (!response.ok) throw new Error('Network response was not ok');
    const result = await response.json();
    setStockDetails(result);
  } catch (error) {
    Sentry.addBreadcrumb({
      category: 'api',
      message: 'Fetching stock details failed',
      level: 'error',
    });
    Sentry.captureException(error);
    setStockDetails(dummyStockDetails);
  }
};
```

### Step 7: Optional - Custom Error Logging
For custom error logging, you can create a utility function.

```js
// src/utils/logger.js

import * as Sentry from '@sentry/react';

export const logError = (error, context = {}) => {
  Sentry.withScope(scope => {
    if (context) {
      Object.keys(context).forEach(key => {
        scope.setContext(key, context[key]);
      });
    }
    Sentry.captureException(error);
  });
};
```

Use this utility function in your components and functions.

```js
import { logError } from './utils/logger';

const fetchStockSummary = async () => {
  try {
    const response = await fetch(FETCH_SUMMARY_URL);
    if (!response.ok) throw new Error('Network response was not ok');
    const result = await response.json();
    setStockSummary(result);
  } catch (error) {
    logError(error, { api: 'fetchStockSummary', url: FETCH_SUMMARY_URL });
    setStockSummary(dummyStockData);
  }
};

const fetchStockDetails = async () => {
  try {
    const response = await fetch(FETCH_DETAILS_URL);
    if (!response.ok) throw new Error('Network response was not ok');
    const result = await response.json();
    setStockDetails(result);
  } catch (error) {
    logError(error, { api: 'fetchStockDetails', url: FETCH_DETAILS_URL });
    setStockDetails(dummyStockDetails);
  }
};
```

### Step 8: Review and Test
Make sure to test your application to ensure that errors are being captured and logged correctly. Check your Sentry dashboard to verify that the errors are being reported with the correct context and information.

By following these steps, you'll be able to implement comprehensive error logging in your application, making it easier for developers to diagnose and fix issues.