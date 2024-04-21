// Api.js

import React, { useEffect } from 'react';
import axios from 'axios';


const postImageForPrediction = async (imageUri) => {
  try {
    const formData = new FormData();
    formData.append('file', {
      uri: imageUri,
      name: 'image.png',
      type: 'image/png',
    });

    const response = await fetch('https://10.20.108.118:5000/predict', {
      method: 'POST',
      body: formData,
    });

    if (!response.ok) {
      throw new Error('Failed to receive the predicted image.');
    }

    const blob = await response.blob();
    // Handle the blob as needed, e.g., save it to camera roll or display it to the user
  } catch (error) {
    console.error('Error:', error);
    // Handle the error, show a message to the user, etc.
  }
};


// const BaiduApiTest = () => {
//   useEffect(() => {
//     const fetchData = async () => {
//       try {
//         const response = await axios.get('https://baidu.com');
//         console.log('Response data:', response.data);
//       } catch (error) {
//         console.error('Error:', error.message);
//         // Handle the error, show a message to the user, etc.
//       }
//     };

//     fetchData();
//   }, []);

//   return (
//     <></> // This component doesn't render anything in the UI
//   );
// };

export default BaiduApiTest;
// export default postImageForPrediction;
