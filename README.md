import { useState, useEffect, useRef } from 'react';

const useIdleTimeout = (timeout = 600000) => {
    const [isIdle, setIsIdle] = useState(false);
    const [timeLeft, setTimeLeft] = useState(timeout);
    const timeoutIdRef = useRef(null);
    const warningTimeoutRef = useRef(null);

    const resetTimeout = () => {
        clearTimeout(timeoutIdRef.current);
        clearTimeout(warningTimeoutRef.current);
        setTimeLeft(timeout);

        warningTimeoutRef.current = setTimeout(() => {
            alert('You are about to be logged out due to inactivity.');
        }, timeout - 120000); // 2 minutes before timeout

        timeoutIdRef.current = setTimeout(() => {
            setIsIdle(true);
        }, timeout);
    };

    useEffect(() => {
        const handleActivity = () => {
            resetTimeout();
            setIsIdle(false);
        };

        window.addEventListener('mousemove', handleActivity);
        window.addEventListener('keydown', handleActivity);
        window.addEventListener('scroll', handleActivity);
        window.addEventListener('resize', handleActivity);

        resetTimeout();

        return () => {
            clearTimeout(timeoutIdRef.current);
            clearTimeout(warningTimeoutRef.current);
            window.removeEventListener('mousemove', handleActivity);
            window.removeEventListener('keydown', handleActivity);
            window.removeEventListener('scroll', handleActivity);
            window.removeEventListener('resize', handleActivity);
        };
    }, [timeout]);

    return isIdle;
};

export default useIdleTimeout;