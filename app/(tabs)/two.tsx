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
  const [colorTemperature,setColorTemperature]= React.useState(1);
  const [gradientIntensity,setGradientIntensity]= React.useState(1);

  return (
<ScrollView contentContainerStyle={styles.scrollContainer}>
    <View style={styles.container}>
        <Text style={styles.title}>通用</Text>
        
        <View style={styles.row}>
            <Button label="助眠模式" theme="primary" />
            <Button label="设定时间" theme="primary" />
        </View>

        <View style={styles.row}>
            <Button label="用户偏好设置" theme="primary" />
            <Button label="日程表" theme="primary" />
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
            <Text>亮度调节</Text>
        </View>

        <View style={styles.row}>
            <Slider
                style={{ width: 200 }}
                minimumValue={0}
                maximumValue={100}
                value={colorTemperature}
                onValueChange={(value) => setColorTemperature(value)}
            />
            <Text>颜色温度</Text>
        </View>

        <View style={styles.row}>
            <Slider
                style={{ width: 200 }}
                minimumValue={0}
                maximumValue={100}
                value={gradientIntensity}
                onValueChange={(value) => setGradientIntensity(value)}
            />
            <Text>渐变设置</Text>
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
            <Text>音量调节</Text>
        </View>
        <View style={styles.row}>
            <Slider
                style={{ width: 200 }}
                minimumValue={0}
                maximumValue={100}
                value={soundVolume}
                onValueChange={(value) => setSoundVolume(value)}
            />
            <Text>音乐选择</Text>
        </View>
        <View style={styles.row}>
            <Slider
                style={{ width: 200 }}
                minimumValue={0}
                maximumValue={100}
                value={soundVolume}
                onValueChange={(value) => setSoundVolume(value)}
            />
            <Text>定时关闭</Text>
        </View>

        <Text style={styles.title}>脉冲调节</Text>

        <View style={styles.row}>
            <Slider
                style={{ width: 200 }}
                minimumValue={0}
                maximumValue={100}
                value={soundVolume}
                onValueChange={(value) => setSoundVolume(value)}
            />
            <Text>频率控制</Text>
        </View>
        <View style={styles.row}>
            <Slider
                style={{ width: 200 }}
                minimumValue={0}
                maximumValue={100}
                value={soundVolume}
                onValueChange={(value) => setSoundVolume(value)}
            />
            <Text>强度设置</Text>
        </View>


        <View style={styles.row}>
            <Button label="模式选择" theme="primary" />
        </View>

      <View style={styles.row}>
          <Text>频率</Text>
      </View>
      <View style={styles.row}>
          <Text>低频 </Text>
          <Slider
              style={{ width: 200 }}
              minimumValue={1}
              maximumValue={10}
              value={pulseFrequency}
              onValueChange={(value) => setPulseFrequency(value)}
          />
          <Text>高频</Text>
      </View>
    </View>
</ScrollView>  );
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

  scrollContainer: {
    flexGrow: 1,
    justifyContent: 'center',
    alignItems: 'center',
  },
});
