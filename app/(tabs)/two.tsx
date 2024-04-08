import React from 'react';
import { StyleSheet, ScrollView, View, Text } from 'react-native';
import Button from '@/components/Button';
import Slider from '@react-native-community/slider';

export default function TabTwoScreen() {
  const [lightIntensity, setLightIntensity] = React.useState(50);
  const [soundVolume, setSoundVolume] = React.useState(50);
  const [pulseFrequency, setPulseFrequency] = React.useState(1);
  const [pulseDuration, setPulseDuration] = React.useState(30);
  const [isLightEnabled, setIsLightEnabled] = React.useState(false);
  const [isSoundEnabled, setIsSoundEnabled] = React.useState(false);
  const [isPulseEnabled, setIsPulseEnabled] = React.useState(false);

  return (
    <ScrollView contentContainerStyle={styles.scrollContainer}>
      <View style={styles.container}>
        <Text style={styles.title}>通用</Text>
        
        <View style={styles.row}>
          <Button label="睡前辅助功能" theme="primary" />
          <Button label="光和音频控制选项" theme="primary" />
        </View>

        <View style={styles.row}>
          <Button label="Another Button" theme="primary" />
          <Button label="One More Button" theme="primary" />
        </View>

        <View style={styles.separator} lightColor="#eee" darkColor="rgba(255,255,255,0.1)" />
        
        <Text style={styles.title}>光调节</Text>
        
        <View style={styles.row}>
          <Slider
            style={{ width: 200 }}
            minimumValue={0}
            maximumValue={100}
            value={lightIntensity}
            onValueChange={(value) => setLightIntensity(value)}
          />
        </View>


        <View style={styles.separator} lightColor="#eee" darkColor="rgba(255,255,255,0.1)" />
        
        <Text style={styles.title}>音调节</Text>
        
        <View style={styles.row}>
          <Slider
            style={{ width: 200 }}
            minimumValue={0}
            maximumValue={100}
            value={soundVolume}
            onValueChange={(value) => setSoundVolume(value)}
          />
        </View>


        <Text style={styles.title}>脉冲调节</Text>
        
        <View style={styles.row}>
          <Slider
            style={{ width: 200 }}
            minimumValue={1}
            maximumValue={10}
            value={pulseFrequency}
            onValueChange={(value) => setPulseFrequency(value)}
          />
        </View>

      </View>
    </ScrollView>
  );
}

const styles = StyleSheet.create({
  row: {
    flexDirection: 'row',
    alignItems: 'center',
    justifyContent: 'space-around',
    marginVertical: 10,
  },
  container: {
    flex: 1,
    alignItems: 'center',
    justifyContent: 'center',
  },
  title: {
    fontSize: 20,
    fontWeight: 'bold',
  },
  separator: {
    marginVertical: 30,
    height: 1,
    width: '80%',
  },
});
