import { StyleSheet,  View,Image } from 'react-native';

export default function ImageViewer({ placeholderImageSource, selectedImage }) {
  const imageSource = selectedImage ? { uri: selectedImage } : placeholderImageSource;
  console.log('Selected Image:', selectedImage);
  console.log('Image Source:', imageSource);

  return (
    <Image source={imageSource} style={styles.image} />
  );
}
const styles = StyleSheet.create({
  image: {
    width: 440,
    height: 240,
    borderRadius: 18,
  },
});
