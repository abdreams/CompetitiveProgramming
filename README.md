Certainly! We can add an `onClick` handler to the "Create News" button to explicitly call the `handleSubmit` function. This ensures that the function is invoked when the button is clicked.

Here's the modified `CreateNewsPage` component:

```javascript
import React, { useState } from 'react';

const CreateNewsPage = () => {
  const [newsData, setNewsData] = useState({
    stockSymbol: '',
    headline: '',
    description: '',
    affectsStock: false,
  });

  const handleChange = (e) => {
    const { name, value, type, checked } = e.target;
    setNewsData({
      ...newsData,
      [name]: type === 'checkbox' ? checked : value,
    });
  };

  const handleSubmit = async (e) => {
    e.preventDefault();
    try {
      const response = await fetch('https://your-backend-url.com/api/news', {
        method: 'POST',
        headers: {
          'Content-Type': 'application/json',
        },
        body: JSON.stringify(newsData),
      });
      if (response.ok) {
        alert('News created successfully!');
        setNewsData({
          stockSymbol: '',
          headline: '',
          description: '',
          affectsStock: false,
        });
      } else {
        alert('Failed to create news.');
      }
    } catch (error) {
      console.error('Error:', error);
      alert('An error occurred while creating news.');
    }
  };

  return (
    <div className="container mx-auto p-6 bg-white rounded-lg shadow">
      <h2 className="text-lg font-semibold mb-4">Create News</h2>
      <form onSubmit={handleSubmit}>
        <div className="mb-4">
          <label className="block text-gray-700">Stock Symbol</label>
          <input
            type="text"
            name="stockSymbol"
            value={newsData.stockSymbol}
            onChange={handleChange}
            className="w-full px-3 py-2 border rounded-lg"
            required
          />
        </div>
        <div className="mb-4">
          <label className="block text-gray-700">Headline</label>
          <input
            type="text"
            name="headline"
            value={newsData.headline}
            onChange={handleChange}
            className="w-full px-3 py-2 border rounded-lg"
            required
          />
        </div>
        <div className="mb-4">
          <label className="block text-gray-700">Description</label>
          <textarea
            name="description"
            value={newsData.description}
            onChange={handleChange}
            className="w-full px-3 py-2 border rounded-lg"
            rows="4"
            required
          ></textarea>
        </div>
        <div className="mb-4">
          <label className="block text-gray-700">Affects Stock</label>
          <input
            type="checkbox"
            name="affectsStock"
            checked={newsData.affectsStock}
            onChange={handleChange}
            className="ml-2"
          />
        </div>
        <div className="flex justify-end">
          <button
            type="button"
            onClick={handleSubmit}
            className="bg-blue-500 text-white px-4 py-2 rounded-lg"
          >
            Create News
          </button>
        </div>
      </form>
    </div>
  );
};

export default CreateNewsPage;
```

### Explanation

- **Form Submission**: We added `type="button"` to the submit button to prevent the form from being submitted automatically. 
- **`onClick` Handler**: The `onClick` handler for the button now explicitly calls the `handleSubmit` function when the button is clicked.

This ensures that when the "Create News" button is clicked, the `handleSubmit` function is invoked to handle the form submission and post the data to the backend.