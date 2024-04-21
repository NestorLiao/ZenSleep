import { View, Pressable, StyleSheet,Text } from 'react-native';
import MaterialIcons from '@expo/vector-icons/MaterialIcons';

export default function CircleButton({label, onPress }) {
  return (
    <View style={styles.circleButtonContainer}>
      <Pressable style={styles.circleButton} onPress={onPress}>
          <Text style={[styles.buttonLabel, { color: "#25292e" }]}>{label}</Text>

      </Pressable>
    </View>
  );
}

const styles = StyleSheet.create({
  circleButtonContainer: {
    width: 84,
    height: 84,
    marginHorizontal: 60,
    borderWidth: 4,
    borderColor: '#ffd33d',
    borderRadius: 42,
    padding: 3,
  },
  circleButton: {
    flex: 1,
    justifyContent: 'center',
    alignItems: 'center',
    borderRadius: 42,
    backgroundColor: '#fff',
  },

  buttonLabel: {
    color: "#000",
    fontSize: 13,
  },

});
