To achieve this, we'll create a navbar component that conditionally renders the "Sign In" button or a user info button based on the user's authentication status. When the user info button is clicked, a user card will be displayed with the user's name, email, and a sign-out option.

### Step-by-Step Implementation

1. **Create a Navbar Component**: This will include the conditional rendering for the "Sign In" button and the user info button.
2. **Create a UserCard Component**: This will display the user's name, email, and a sign-out button.
3. **Update the Main App Component**: Integrate the Navbar and manage user authentication state.

### Step 1: Create `Navbar.jsx`

#### `components/Navbar.jsx`

```jsx
import React, { useState } from 'react';
import UserCard from './UserCard';

function Navbar({ isAuthenticated, user, onSignIn, onSignOut }) {
  const [showUserCard, setShowUserCard] = useState(false);

  const toggleUserCard = () => setShowUserCard(!showUserCard);

  return (
    <nav className="bg-gray-800 p-4 text-white flex justify-between items-center">
      <div className="text-lg font-semibold">My App</div>
      {isAuthenticated ? (
        <div className="relative">
          <button 
            className="bg-blue-500 hover:bg-blue-700 text-white font-bold py-2 px-4 rounded"
            onClick={toggleUserCard}
          >
            User Info
          </button>
          {showUserCard && (
            <div className="absolute right-0 mt-2 w-48 bg-white text-black rounded-lg shadow-lg">
              <UserCard user={user} onSignOut={onSignOut} />
            </div>
          )}
        </div>
      ) : (
        <button 
          className="bg-blue-500 hover:bg-blue-700 text-white font-bold py-2 px-4 rounded"
          onClick={onSignIn}
        >
          Sign In
        </button>
      )}
    </nav>
  );
}

export default Navbar;
```

### Step 2: Create `UserCard.jsx`

#### `components/UserCard.jsx`

```jsx
import React from 'react';

function UserCard({ user, onSignOut }) {
  return (
    <div className="p-4">
      <p><strong>Name:</strong> {user.name}</p>
      <p><strong>Email:</strong> {user.email}</p>
      <button 
        className="mt-4 bg-red-500 hover:bg-red-700 text-white font-bold py-2 px-4 rounded"
        onClick={onSignOut}
      >
        Sign Out
      </button>
    </div>
  );
}

export default UserCard;
```

### Step 3: Update the Main App Component

#### `App.jsx`

```jsx
import React, { useState } from 'react';
import Navbar from './components/Navbar';
import Portfolio from './pages/Portfolio';
import PortfolioDetail from './pages/PortfolioDetail';
import { BrowserRouter as Router, Route, Switch } from 'react-router-dom';

const sampleUser = {
  name: 'John Doe',
  email: 'johndoe@example.com'
};

function App() {
  const [isAuthenticated, setIsAuthenticated] = useState(false);
  const [user, setUser] = useState(null);

  const handleSignIn = () => {
    // Simulate sign-in process
    setUser(sampleUser);
    setIsAuthenticated(true);
  };

  const handleSignOut = () => {
    // Simulate sign-out process
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

### Explanation

1. **Navbar Component**:
    - Displays a "Sign In" button if the user is not authenticated.
    - Displays a "User Info" button if the user is authenticated. Clicking this button toggles the display of the `UserCard`.
    - The `UserCard` component is conditionally rendered as a dropdown menu.

2. **UserCard Component**:
    - Displays the user's name, email, and a "Sign Out" button.
    - Calls the `onSignOut` function passed as a prop when the "Sign Out" button is clicked.

3. **Main App Component**:
    - Manages the authentication state (`isAuthenticated` and `user`).
    - Passes the necessary props to the `Navbar` component.
    - Routes to the portfolio and portfolio detail pages.

This setup ensures that the navbar dynamically updates based on the user's authentication status and provides a user-friendly way to display user information and sign out.