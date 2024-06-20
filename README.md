Certainly! Winston is a popular logging library for Node.js that provides more flexibility and options for logging. Here's how you can integrate Winston into your application to log errors.

### Step 1: Install Winston

First, install Winston using npm:

```sh
npm install winston
```

### Step 2: Set Up Winston Logger

Create a logger configuration file using Winston to handle logging.

```javascript
// src/utils/logger.js
const { createLogger, format, transports } = require('winston');
const path = require('path');

// Define the log file path
const logFilePath = path.join(__dirname, 'error.log');

// Create the logger
const logger = createLogger({
  level: 'error',
  format: format.combine(
    format.timestamp({
      format: 'YYYY-MM-DD HH:mm:ss'
    }),
    format.printf(({ timestamp, level, message, ...meta }) => {
      let log = `${timestamp} [${level}]: ${message}`;
      if (Object.keys(meta).length) {
        log += ` ${JSON.stringify(meta)}`;
      }
      return log;
    })
  ),
  transports: [
    new transports.File({ filename: logFilePath }),
    new transports.Console()
  ],
});

module.exports = logger;
```

### Step 3: Use Winston Logger in Your Fetch Functions

Modify your fetch functions to use the Winston logger.

```javascript
const logger = require('./utils/logger');

const fetchStockSummary = async () => {
  try {
    const response = await fetch(FETCH_SUMMARY_URL);
    if (!response.ok) throw new Error('Network response was not ok');
    const result = await response.json();
    setStockSummary(result);
  } catch (error) {
    logger.error('Error fetching stock summary', { api: 'fetchStockSummary', url: FETCH_SUMMARY_URL, error: error.message });
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
    logger.error('Error fetching stock details', { api: 'fetchStockDetails', url: FETCH_DETAILS_URL, error: error.message });
    setStockDetails(dummyStockDetails);
  }
};
```

### Step 4: Create an Error Boundary in React

You can still use the Error Boundary in React to catch and log rendering errors.

```javascript
// src/components/ErrorBoundary.js
import React from 'react';

class ErrorBoundary extends React.Component {
  constructor(props) {
    super(props);
    this.state = { hasError: false };
  }

  static getDerivedStateFromError(error) {
    return { hasError: true };
  }

  componentDidCatch(error, errorInfo) {
    // You can also log error to a reporting service
    console.error("ErrorBoundary caught an error", error, errorInfo);
    fetch('/api/logError', {
      method: 'POST',
      headers: {
        'Content-Type': 'application/json',
      },
      body: JSON.stringify({ error, errorInfo }),
    });
  }

  render() {
    if (this.state.hasError) {
      return <h1>Something went wrong.</h1>;
    }

    return this.props.children;
  }
}

export default ErrorBoundary;
```

### Step 5: Use Error Boundary in Your App

Wrap your application components with the `ErrorBoundary` component.

```javascript
// src/App.js
import React from 'react';
import ErrorBoundary from './components/ErrorBoundary';
import StockComparision from './StockComparision';

const App = () => (
  <ErrorBoundary>
    <StockComparision />
  </ErrorBoundary>
);

export default App;
```

### Step 6: Set Up an API Endpoint for Logging

Set up a simple Express server to receive log data from the client and use Winston to log it.

```javascript
// server.js
const express = require('express');
const bodyParser = require('body-parser');
const logger = require('./src/utils/logger');

const app = express();
const port = process.env.PORT || 5000;

app.use(bodyParser.json());

app.post('/api/logError', (req, res) => {
  const { error, errorInfo } = req.body;
  logger.error('Client-side error', { error: error.message, stack: error.stack, componentStack: errorInfo.componentStack });
  res.status(200).send('Error logged successfully');
});

app.listen(port, () => {
  console.log(`Server is running on port ${port}`);
});
```

### Step 7: Run Your Application

Ensure your application and server are running.

```sh
# Start your React application
npm start

# In another terminal, start your Express server
node server.js
```

### Conclusion

With this setup, you have integrated Winston to log errors to a file and the console. This provides a basic yet effective logging mechanism without relying on third-party services. The logs will be written to `error.log` and displayed in the console for easier debugging.