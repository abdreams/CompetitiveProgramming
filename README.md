import * as React from "react";
import { IoMdArrowDown, IoMdArrowUp } from "react-icons/io";
import { GiHamburgerMenu } from "react-icons/gi";
import { ImCross } from "react-icons/im";
import { MdDarkMode, MdLightMode } from "react-icons/md";
import { Link } from "react-router-dom";
import { FaChevronRight } from 'react-icons/fa';
import { useSelector, useDispatch } from "react-redux";
import { logout } from "../redux/slices/user/userSlice";
import { toggleTheme, selectIsDarkMode } from '../redux/slices/themeSlice';

export const Navbar = () => {
    const [cross, setCross] = React.useState(false);
    const [username, setUsername] = React.useState("Aniket");
    const { isAuthenticated, user } = useSelector((state) => state.auth);
    const isDarkMode = useSelector(selectIsDarkMode);
    const dispatch = useDispatch();
    const [profile, setProfile] = React.useState(false);

    const handleDark = () => {
        dispatch(toggleTheme());
    };

    const handleCross = () => {
        setCross((prev) => !prev);
    };

    const handleProfile = () => {
        setProfile((prev) => !prev);
    };

    const handleLogout = async () => {
        try {
            const res = await fetch('http://10.64.17.55:8000/auth/logout', {
                headers: {
                    'Content-Type': 'application/json',
                    'accessToken': sessionStorage.getItem('accessToken')
                }
            });

            if (res.status === 200) {
                sessionStorage.removeItem('accessToken');
                sessionStorage.removeItem('refreshToken');
                sessionStorage.removeItem('user');
                dispatch(logout());
            }
        } catch (error) {
            alert("Error while logging out");
            console.log(error);
        }
    };

    return (
        <>
            {/* mobile view */}
            <nav className='md:hidden flex justify-around items-center text-white bg-[#d71e28] z-50 h-16 sticky top-0 border-b-4 border-yellow-300'>
                {<Link className="right text-3xl z-50">{cross ? '' : 'WELLS FARGO'}</Link>}

                {!cross &&
                    <button className="cursor-pointer z-50" onClick={handleCross}>
                        <GiHamburgerMenu size={30} />
                    </button>
                }

                {cross &&
                    <>
                        <ul className='flex flex-col items-center absolute top-0 right-0 rounded-md h-[730px] text-black shadow-md shadow-gray-400 bg-white w-96 justify-start space-y-3 text-3xl z-30'>
                            <div className="cursor-pointer z-50 transition ease-in-out delay-700 flex flex-row items-center justify-around gap-x-2 w-80 h-16 mb-5">
                                {cross &&
                                    <div className="flex justify-evenly gap-x-5 items-center text-[#141414] p-2">
                                        <h1 className="text-4xl">{username}</h1>
                                        <button className="flex flex-wrap gap-x-1" onClick={handleDark}>
                                            {isDarkMode ? <MdDarkMode size={32} className="mt-1" /> : <MdLightMode size={32} className="mt-1" />}
                                        </button>
                                        <div onClick={handleCross} className={"border p-1 border-black rounded-full mt-2" + (cross ? ' text-[#141414]' : ' text-white')}>
                                            <ImCross size={22} className="-p-1" />
                                        </div>
                                    </div>
                                }
                            </div>

                            <Link to="/" className='flex flex-row space-x-2 hover:scale-105 duration-200 cursor-pointer items-center justify-center' onClick={() => setCross(false)}>
                                <FaChevronRight size={25} /> <div>Home</div>
                            </Link>
                            <Link to="/portfolio" className='flex flex-row space-x-2 items-center justify-center hover:scale-105 duration-200 cursor-pointer' onClick={() => setCross(false)}>
                                <FaChevronRight size={25} /> <div>Portfolio</div>
                            </Link>
                            {isAuthenticated ? <div onClick={handleLogout}>Logout</div> :
                                <Link to="/signin" className='flex flex-row space-x-2 items-center justify-center hover:scale-105 duration-200 cursor-pointer' onClick={() => setCross(false)}>
                                    <FaChevronRight size={25} /> <div>SignIn</div>
                                </Link>
                            }
                        </ul>
                    </>
                }
            </nav>

            {/* desktop view */}
            <nav className="hidden md:flex flex-row justify-around flex-wrap gap-x-10 text-white bg-[#d71e28] h-16 items-center border-b-4 sticky top-0 border-yellow-300">
                <Link className="right cursor-pointer" to={"/"}>
                    <img className="h-3/4 w-3/4" src="path/to/your/logo.svg" alt="Wells Fargo" />
                </Link>
                <div className="left flex flex-row justify-evenly gap-8 cursor-pointer text-2xl font-semibold">
                    <Link className="home hover:border-b-2" to={"/"}>Home</Link>
                    <Link className="portfolio hover:border-b-2" to={"/portfolio"}>Portfolio</Link>
                    {isAuthenticated ? <button className="" onClick={handleLogout}>Logout</button> : <Link to={'/signin'}>SignIn</Link>}
                    <button className="mode" onClick={handleDark}>
                        {isDarkMode ? <MdDarkMode size={30} /> : <MdLightMode size={30} />}
                    </button>
                </div>
            </nav>
        </>
    );
};