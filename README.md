To add form validation without external libraries, you can use the built-in capabilities of React. Here's how you can update the SignIn and SignUp components to include validation:

### 1. SignIn Component with Validation

Here's the updated SignIn component with form validation:

```jsx
import React, { useState } from 'react';
import { useDispatch } from 'react-redux';
import { login } from '../redux/slices/user/userSlice';

const SignIn = () => {
  const dispatch = useDispatch();
  const [email, setEmail] = useState('');
  const [password, setPassword] = useState('');
  const [errors, setErrors] = useState({});

  const validate = () => {
    const errors = {};
    const emailRegex = /^[^\s@]+@[^\s@]+\.[^\s@]+$/;
    const passwordRegex = /^(?=.*[A-Z])(?=.*[a-z])(?=.*\d)(?=.*[!@#$%^&*])[A-Za-z\d!@#$%^&*]{8,}$/;

    if (!email) {
      errors.email = 'Email is required';
    } else if (!emailRegex.test(email)) {
      errors.email = 'Invalid email address';
    }

    if (!password) {
      errors.password = 'Password is required';
    } else if (!passwordRegex.test(password)) {
      errors.password = 'Password must be at least 8 characters long, contain one uppercase letter, one lowercase letter, one number, and one special character';
    }

    setErrors(errors);
    return Object.keys(errors).length === 0;
  };

  const handleSubmit = (event) => {
    event.preventDefault();
    if (validate()) {
      dispatch(login({ email, password }));
    }
  };

  return (
    <div className="max-w-md mx-auto mt-10">
      <h2 className="text-3xl font-semibold mb-6">Sign In</h2>
      <form onSubmit={handleSubmit}>
        <div className="mb-4">
          <label htmlFor="email" className="block text-gray-700">Email</label>
          <input
            id="email"
            name="email"
            type="email"
            className="mt-1 block w-full border-gray-300 rounded-md shadow-sm"
            onChange={(e) => setEmail(e.target.value)}
            value={email}
          />
          {errors.email && <div className="text-red-600">{errors.email}</div>}
        </div>
        <div className="mb-4">
          <label htmlFor="password" className="block text-gray-700">Password</label>
          <input
            id="password"
            name="password"
            type="password"
            className="mt-1 block w-full border-gray-300 rounded-md shadow-sm"
            onChange={(e) => setPassword(e.target.value)}
            value={password}
          />
          {errors.password && <div className="text-red-600">{errors.password}</div>}
        </div>
        <button
          type="submit"
          className="w-full py-2 px-4 bg-blue-500 text-white rounded-md"
        >
          Sign In
        </button>
      </form>
    </div>
  );
};

export default SignIn;
```

### 2. SignUp Component with Validation

Here's the updated SignUp component with form validation:

```jsx
import React, { useState } from 'react';
import { useDispatch } from 'react-redux';
import { signup } from '../redux/slices/user/userSlice';

const SignUp = () => {
  const dispatch = useDispatch();
  const [name, setName] = useState('');
  const [email, setEmail] = useState('');
  const [password, setPassword] = useState('');
  const [confirmPassword, setConfirmPassword] = useState('');
  const [errors, setErrors] = useState({});

  const validate = () => {
    const errors = {};
    const nameRegex = /^[a-zA-Z ]+$/;
    const emailRegex = /^[^\s@]+@[^\s@]+\.[^\s@]+$/;
    const passwordRegex = /^(?=.*[A-Z])(?=.*[a-z])(?=.*\d)(?=.*[!@#$%^&*])[A-Za-z\d!@#$%^&*]{8,}$/;

    if (!name) {
      errors.name = 'Name is required';
    } else if (!nameRegex.test(name)) {
      errors.name = 'Name must contain only letters and spaces';
    }

    if (!email) {
      errors.email = 'Email is required';
    } else if (!emailRegex.test(email)) {
      errors.email = 'Invalid email address';
    }

    if (!password) {
      errors.password = 'Password is required';
    } else if (!passwordRegex.test(password)) {
      errors.password = 'Password must be at least 8 characters long, contain one uppercase letter, one lowercase letter, one number, and one special character';
    }

    if (!confirmPassword) {
      errors.confirmPassword = 'Confirm password is required';
    } else if (password !== confirmPassword) {
      errors.confirmPassword = 'Passwords must match';
    }

    setErrors(errors);
    return Object.keys(errors).length === 0;
  };

  const handleSubmit = (event) => {
    event.preventDefault();
    if (validate()) {
      dispatch(signup({ name, email, password }));
    }
  };

  return (
    <div className="max-w-md mx-auto mt-10">
      <h2 className="text-3xl font-semibold mb-6">Sign Up</h2>
      <form onSubmit={handleSubmit}>
        <div className="mb-4">
          <label htmlFor="name" className="block text-gray-700">Name</label>
          <input
            id="name"
            name="name"
            type="text"
            className="mt-1 block w-full border-gray-300 rounded-md shadow-sm"
            onChange={(e) => setName(e.target.value)}
            value={name}
          />
          {errors.name && <div className="text-red-600">{errors.name}</div>}
        </div>
        <div className="mb-4">
          <label htmlFor="email" className="block text-gray-700">Email</label>
          <input
            id="email"
            name="email"
            type="email"
            className="mt-1 block w-full border-gray-300 rounded-md shadow-sm"
            onChange={(e) => setEmail(e.target.value)}
            value={email}
          />
          {errors.email && <div className="text-red-600">{errors.email}</div>}
        </div>
        <div className="mb-4">
          <label htmlFor="password" className="block text-gray-700">Password</label>
          <input
            id="password"
            name="password"
            type="password"
            className="mt-1 block w-full border-gray-300 rounded-md shadow-sm"
            onChange={(e) => setPassword(e.target.value)}
            value={password}
          />
          {errors.password && <div className="text-red-600">{errors.password}</div>}
        </div>
        <div className="mb-4">
          <label htmlFor="confirmPassword" className="block text-gray-700">Confirm Password</label>
          <input
            id="confirmPassword"
            name="confirmPassword"
            type="password"
            className="mt-1 block w-full border-gray-300 rounded-md shadow-sm"
            onChange={(e) => setConfirmPassword(e.target.value)}
            value={confirmPassword}
          />
          {errors.confirmPassword && <div className="text-red-600">{errors.confirmPassword}</div>}
        </div>
        <button
          type="submit"
          className="w-full py-2 px-4 bg-blue-500 text-white rounded-md"
        >
          Sign Up
        </button>
      </form>
    </div>
  );
};

export default SignUp;
```

### Explanation

1. **State Management**:
   - Added `email`, `password`, `name`, `confirmPassword`, and `errors` state variables.
   - Used `useState` to manage form input values and validation errors.

2. **Validation Function**:
   - The `validate` function checks the inputs against specific rules and updates the `errors` state with any validation messages.
   - Email, name, and password fields have specific regex patterns to enforce the required format.

3. **Form Submission**:
   - The `handleSubmit` function prevents the default form submission, runs validation, and dispatches the appropriate action if the inputs are valid.

4. **Error Display**:
   - Conditionally rendered error messages below each input field based on the `errors` state.

By following this approach, you can add form validation to both the sign-in and sign-up forms without using any external libraries.