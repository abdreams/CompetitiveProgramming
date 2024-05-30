I apologize for the oversight. Here is the updated `SignUp` component with the sign-up button calling the `handleSubmit` function to submit the form data to the dummy backend:

```javascript
import React, { useState } from 'react';
import { useHistory } from 'react-router-dom';

export default function SignUp() {
    const history = useHistory();
    const [formData, setFormData] = useState({
        firstName: '',
        lastName: '',
        dob: '',
        email: '',
        password: ''
    });

    const handleChange = (e) => {
        const { name, value } = e.target;
        setFormData(prevState => ({
            ...prevState,
            [name]: value
        }));
    };

    const handleSubmit = async (e) => {
        e.preventDefault();
        const url = 'https://jsonplaceholder.typicode.com/posts'; // Dummy backend URL for demonstration

        try {
            const response = await fetch(url, {
                method: 'POST',
                headers: {
                    'Content-Type': 'application/json'
                },
                body: JSON.stringify(formData)
            });
            const result = await response.json();
            console.log('Success:', result);
        } catch (error) {
            console.error('Error:', error);
        }
    };

    return (
        <div className="min-h-screen flex items-center justify-center bg-gray-100">
            <form onSubmit={handleSubmit} className='w-11/12 max-w-[700px] px-10 py-20 rounded-3xl bg-white border-2 border-gray-100'>
                <h1 className='text-5xl font-semibold'>Create Account</h1>
                <p className='font-medium text-lg text-gray-500 mt-4'>Please fill in the details to create your account.</p>
                <div className='mt-8'>
                    <div className='flex flex-col'>
                        <label className='text-lg font-medium'>First Name</label>
                        <input 
                            className='w-full border-2 border-gray-100 rounded-xl p-4 mt-1 bg-transparent'
                            placeholder="Enter your first name"
                            name="firstName"
                            value={formData.firstName}
                            onChange={handleChange}
                        />
                    </div>
                    <div className='flex flex-col mt-4'>
                        <label className='text-lg font-medium'>Last Name</label>
                        <input 
                            className='w-full border-2 border-gray-100 rounded-xl p-4 mt-1 bg-transparent'
                            placeholder="Enter your last name"
                            name="lastName"
                            value={formData.lastName}
                            onChange={handleChange}
                        />
                    </div>
                    <div className='flex flex-col mt-4'>
                        <label className='text-lg font-medium'>Date of Birth</label>
                        <input 
                            className='w-full border-2 border-gray-100 rounded-xl p-4 mt-1 bg-transparent'
                            placeholder="Enter your date of birth"
                            name="dob"
                            type="date"
                            value={formData.dob}
                            onChange={handleChange}
                        />
                    </div>
                    <div className='flex flex-col mt-4'>
                        <label className='text-lg font-medium'>Email</label>
                        <input 
                            className='w-full border-2 border-gray-100 rounded-xl p-4 mt-1 bg-transparent'
                            placeholder="Enter your email"
                            name="email"
                            value={formData.email}
                            onChange={handleChange}
                        />
                    </div>
                    <div className='flex flex-col mt-4'>
                        <label className='text-lg font-medium'>Password</label>
                        <input 
                            className='w-full border-2 border-gray-100 rounded-xl p-4 mt-1 bg-transparent'
                            placeholder="Enter your password"
                            type="password"
                            name="password"
                            value={formData.password}
                            onChange={handleChange}
                        />
                    </div>
                    <div className='mt-8 flex flex-col gap-y-4'>
                        <button type="submit" className='active:scale-[.98] active:duration-75 transition-all hover:scale-[1.01] ease-in-out transform py-4 bg-violet-500 rounded-xl text-white font-bold text-lg'>
                            Sign up
                        </button>
                    </div>
                    <div className='mt-8 flex justify-center items-center'>
                        <p className='font-medium text-base'>Already have an account?</p>
                        <button 
                            className='ml-2 font-medium text-base text-violet-500'
                            type="button"
                            onClick={() => history.push('/')}
                        >
                            Sign in
                        </button>
                    </div>
                </div>
            </form>
        </div>
    );
}
```

In this updated code, the `handleSubmit` function is now properly called when the sign-up button is clicked, submitting the form data to the dummy backend. The form fields include first name, last name, date of birth, email, and password, all managed via the `formData` state.
