It seems the syntax error may be due to the JSX syntax within the JavaScript file not being properly recognized. To resolve this, let's ensure everything is correctly imported and configured. Make sure you have the necessary dependencies installed, and that your project is properly set up to handle JSX.

Here's the corrected and reviewed code for the chatbot configuration and widget:

### Step 1: Create the QuickReply Widget

#### QuickReply.js

```javascript
import React from 'react';

const QuickReply = ({ actionProvider }) => {
  const options = [
    { text: 'Create Portfolio', handler: actionProvider.handleCreatePortfolio },
    { text: 'Get Stock News', handler: actionProvider.handleStockNews },
    { text: 'Hello', handler: actionProvider.greet },
  ];

  return (
    <div className="quick-replies">
      {options.map((option, index) => (
        <button key={index} onClick={option.handler} className="quick-reply-button">
          {option.text}
        </button>
      ))}
    </div>
  );
};

export default QuickReply;
```

### Step 2: Update Chatbot Configuration

Ensure the chatbot configuration imports and uses the widget correctly.

#### chatbotConfig.js

```javascript
import { createChatBotMessage } from 'react-chatbot-kit';
import QuickReply from './widgets/QuickReply'; // Ensure the path is correct

const config = {
  botName: 'StockBot',
  initialMessages: [
    createChatBotMessage("Hi! I'm StockBot. How can I help you today?", {
      widget: 'quickReplies',
    }),
  ],
  customStyles: {
    botMessageBox: {
      backgroundColor: '#376B7E',
    },
    chatButton: {
      backgroundColor: '#376B7E',
    },
  },
  widgets: [
    {
      widgetName: 'quickReplies',
      widgetFunc: (props) => <QuickReply {...props} />,
    },
  ],
};

export default config;
```

### Step 3: Ensure ActionProvider and MessageParser are Correctly Set Up

#### ActionProvider.js

```javascript
import { useHistory } from 'react-router-dom';

class ActionProvider {
  constructor(createChatBotMessage, setStateFunc, createClientMessage) {
    this.createChatBotMessage = createChatBotMessage;
    this.setState = setStateFunc;
    this.createClientMessage = createClientMessage;
    this.history = useHistory(); // Use history for navigation
  }

  greet = () => {
    const greetingMessage = this.createChatBotMessage('Hello! How can I assist you today?', {
      widget: 'quickReplies',
    });
    this.updateChatbotState(greetingMessage);
  };

  handleStockNews = () => {
    const newsMessage = this.createChatBotMessage('Here is the latest news about stocks...');
    this.updateChatbotState(newsMessage);
  };

  handleCreatePortfolio = () => {
    const portfolioMessage = this.createChatBotMessage('I can help you create a portfolio. Redirecting you now...');
    this.updateChatbotState(portfolioMessage);
    setTimeout(() => {
      this.history.push('/create-portfolio'); // Route to the create portfolio page
    }, 1000);
  };

  defaultResponse = () => {
    const defaultMessage = this.createChatBotMessage('Sorry, I did not understand that. Could you please rephrase?', {
      widget: 'quickReplies',
    });
    this.updateChatbotState(defaultMessage);
  };

  updateChatbotState = (message) => {
    this.setState((prevState) => ({
      ...prevState,
      messages: [...prevState.messages, message],
    }));
  };
}

export default ActionProvider;
```

### Step 4: Verify MessageParser

#### MessageParser.js

```javascript
class MessageParser {
  constructor(actionProvider) {
    this.actionProvider = actionProvider;
  }

  parse = (message) => {
    const lowerCaseMessage = message.toLowerCase();

    if (lowerCaseMessage.includes('hello')) {
      this.actionProvider.greet();
    } else if (lowerCaseMessage.includes('stock news')) {
      this.actionProvider.handleStockNews();
    } else if (lowerCaseMessage.includes('create portfolio')) {
      this.actionProvider.handleCreatePortfolio();
    } else {
      this.actionProvider.defaultResponse();
    }
  };
}

export default MessageParser;
```

### Step 5: Integrate the Chatbot into Your Application

#### App.js

```javascript
import React from 'react';
import { BrowserRouter as Router, Route, Switch } from 'react-router-dom';
import ChatbotComponent from './ChatbotComponent'; // Ensure this path is correct
import NewsPage from './NewsPage';
import CreatePortfolioPage from './CreatePortfolioPage'; // Ensure this path is correct
import './App.css';

const App = () => {
  return (
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
  );
};

export default App;
```

By following these steps, the syntax error should be resolved, and the chatbot should be properly integrated into your application.