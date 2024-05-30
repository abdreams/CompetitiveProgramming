import React, { useState } from 'react';
import { useHistory } from 'react-router-dom';

export default function SignIn() {
    const history = useHistory();
    const [passwordVisible, setPasswordVisible] = useState(false);
    const [formData, setFormData] = useState({
        email: '',
        password: ''
    });

    const togglePasswordVisibility = () => {
        setPasswordVisible(!passwordVisible);
    };

    const handleChange = (e) => {
        const { name, value } = e.target;
        setFormData(prevState => ({
            ...prevState,
            [name]: value
        }));
    };

    const handleSubmit = async (e) => {
        e.preventDefault();
        // Replace this URL with your backend endpoint
        const url = 'https://jsonplaceholder.typicode.com/posts';
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
                <h1 className='text-5xl font-semibold'>Welcome Back</h1>
                <p className='font-medium text-lg text-gray-500 mt-4'>Welcome back! Please enter your details.</p>
                <div className='mt-8'>
                    <div className='flex flex-col'>
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
                        <div className="relative">
                            <input 
                                className='w-full border-2 border-gray-100 rounded-xl p-4 mt-1 bg-transparent'
                                placeholder="Enter your password"
                                type={passwordVisible ? "text" : "password"}
                                name="password"
                                value={formData.password}
                                onChange={handleChange}
                            />
                            <button
                                type="button"
                                className="absolute inset-y-0 right-4 flex items-center"
                                onClick={togglePasswordVisibility}
                            >
                                {passwordVisible ? (
                                    <svg xmlns="http://www.w3.org/2000/svg" width="24" height="24" fill="none" viewBox="0 0 24 24" stroke="currentColor">
                                        <path strokeLinecap="round" strokeLinejoin="round" strokeWidth="2" d="M15 12a3 3 0 11-6 0 3 3 0 016 0z" />
                                        <path strokeLinecap="round" strokeLinejoin="round" strokeWidth="2" d="M2.458 12C3.732 7.943 7.613 5 12 5c4.387 0 8.268 2.943 9.542 7-.738 2.267-2.367 4.208-4.417 5.236m-2.961-1.418a9.935 9.935 0 01-2.164.182 9.935 9.935 0 01-2.164-.182m6.744 2.182A9.935 9.935 0 0112 19c-4.387 0-8.268-2.943-9.542-7" />
                                    </svg>
                                ) : (
                                    <svg xmlns="http://www.w3.org/2000/svg" width="24" height="24" fill="none" viewBox="0 0 24 24" stroke="currentColor">
                                        <path strokeLinecap="round" strokeLinejoin="round" strokeWidth="2" d="M13.875 18.825A9.934 9.934 0 0112 19c-4.387 0-8.268-2.943-9.542-7 .738-2.267 2.367-4.208 4.417-5.236m2.961 1.418a9.935 9.935 0 012.164-.182c.747 0 1.488.063 2.214.182m-.49 6.566A3 3 0 0015 12a3 3 0 00-3-3m-1.707-1.707L7.052 7.052m-.68 8.74l-1.415 1.415M2 2l20 20" />
                                    </svg>
                                )}
                            </button>
                        </div>
                    </div>
                    <div className='mt-8 flex justify-between items-center'>
                        <div>
                            <input type="checkbox" id='remember'/>
                            <label className='ml-2 font-medium text-base' htmlFor="remember">Remember for 30 days</label>
                            // Backend should handle remember me state
                        </div>
                        <button 
                            className='font-medium text-base text-violet-500'
                            onClick={() => history.push('/forgot')}
                        >
                            Forgot password
                        </button>
                        // Backend should handle forgot password functionality
                    </div>
                    <div className='mt-8 flex flex-col gap-y-4'>
                        <button type="submit" className='active:scale-[.98] active:duration-75 transition-all hover:scale-[1.01] ease-in-out transform py-4 bg-violet-500 rounded-xl text-white font-bold text-lg'>
                            Sign in
                        </button>
                        // Backend should handle sign in on button click
                        <button type="button" className='flex items-center justify-center gap-2 active:scale-[.98] active:duration-75 transition-all hover:scale-[1.01] ease-in-out transform py-4 rounded-xl text-gray-700 font-semibold text-lg border-2 border-gray-100'>
                            <svg width="24" height="24" viewBox="0 0 24 24" fill="none" xmlns="http://www.w3.org/2000/svg">
                                <path d="M5.26644 9.76453C6.19903 6.93863 8.85469 4.90909 12.0002 4.90909C13.6912 4.90909 15.2184 5.50909 16.4184 6.49091L19.9093 3C17.7821 1.14545 15.0548 0 12.0002 0C7.27031 0 3.19799 2.6983 1.24023 6.65002L5.26644 9.76453Z" fill="#EA4335"/>
                                <path d="M16.0406 18.0142C14.9508 18.718 13.5659 19.0926 11.9998 19.0926C8.86633 19.0926 6.21896 17.0785 5.27682 14.2695L1.2373 17.3366C3.19263 21.2953 7.26484 24.0017 11.9998 24.0017C14.9327 24.0017 17.7352 22.959 19.834 21.0012L16.0406 18.0142Z" fill="#34A853"/>
                                <path d="M19.8342 20.9978C22.0292 18.9503 23.4545 15.9019 23.4545 11.9982C23.4545 11.2891 23.3455 10.5255 23.1818 9.81641H12V14.4528H18.4364C18.1188 16.0119 17.2663 17.2194 16.0407 18.0108L19.8342 20.9978Z" fill="#4A90E2"/>
                                <path d="M5.27698 14.2663C5.03833 13.5547 4.90909 12.7922 4.90909
