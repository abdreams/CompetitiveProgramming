To create a card similar to the one in the image but with the specified modifications (name and age on the right, email address below, and a sign-out button), we can use the following implementation. We'll ensure the top picture is red and the layout matches the provided specifications.

### Step-by-Step Implementation

1. **Create the UserCard Component**: This component will render the user information along with the sign-out button.
2. **Use Tailwind CSS for Styling**: Tailwind CSS will be used for styling the card and the components.

### Step 1: Create `UserCard.jsx`

#### `components/UserCard.jsx`

```jsx
import React from 'react';

function UserCard({ user, onSignOut }) {
  return (
    <div className="max-w-sm rounded overflow-hidden shadow-lg">
      <div className="bg-red-500 h-32 flex items-center justify-center">
        <img 
          className="rounded-full border-4 border-white -mt-16" 
          src={user.profileImage} 
          alt={`${user.name}`} 
          style={{ width: '80px', height: '80px' }}
        />
      </div>
      <div className="px-6 py-4 text-center">
        <div className="font-bold text-xl mb-2">
          <span>{user.name}</span>
          <span className="text-gray-500 ml-2">{user.age}</span>
        </div>
        <p className="text-gray-700 text-base">{user.email}</p>
      </div>
      <div className="px-6 py-4 text-center">
        <button 
          className="bg-red-500 hover:bg-red-700 text-white font-bold py-2 px-4 rounded"
          onClick={onSignOut}
        >
          Sign Out
        </button>
      </div>
    </div>
  );
}

export default UserCard;
```

### Step 2: Update `Navbar.jsx`

Ensure the `Navbar` component uses the updated `UserCard` component.

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
            <div className="absolute right-0 mt-2 w-64 bg-white text-black rounded-lg shadow-lg">
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

### Step 3: Update `App.jsx`

Ensure the main application component uses the `Navbar` component and manages the user authentication state.

#### `App.jsx`

```jsx
import React, { useState } from 'react';
import Navbar from './components/Navbar';
import Portfolio from './pages/Portfolio';
import PortfolioDetail from './pages/PortfolioDetail';
import { BrowserRouter as Router, Route, Switch } from 'react-router-dom';

const sampleUser = {
  name: 'Victor Crest',
  age: 26,
  email: 'victor.crest@example.com',
  profileImage: '/path/to/profile/image.jpg'  // Provide the correct path to the profile image
};

function App() {
  const [isAuthenticated, setIs