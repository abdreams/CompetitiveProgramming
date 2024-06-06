import React from 'react';

const ModalLoader = () => {
  return (
    <div className="fixed inset-0 flex items-center justify-center bg-black bg-opacity-50 z-50">
      <div className="flex items-center justify-center">
        <div className="w-16 h-16 border-4 border-dashed rounded-full animate-spin border-blue-500"></div>
      </div>
    </div>
  );
};

export default ModalLoader;

import React from 'react';
import ModalLoader from './ModalLoader';

const App = () => {
  return (
    <div className="relative">
      <h1 className="text-center text-2xl">Your App Content Here</h1>
      <ModalLoader />
    </div>
  );
};

export default App;