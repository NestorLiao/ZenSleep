import {TextInput,ScrollView, StyleSheet } from 'react-native';
import Button from '@/components/Button';
import React,{useState}from "react";
import Svg, {
  Circle,
  Ellipse,
  G,
  TSpan,
  TextPath,
  Path,
  Polygon,
  Polyline,
  Line,
  Rect,
  Use,
  Image,
  Symbol,
  Defs,
  LinearGradient,
  RadialGradient,
  Stop,
  ClipPath,
  Pattern,
  Mask,
} from 'react-native-svg';
import EditScreenInfo from '@/components/EditScreenInfo';
import { Text, View } from '@/components/Themed';


const SVGComponent = ({ selectedSVG }) => {
  const renderSVG = () => {
    switch (selectedSVG) {
      case 'sleepData':
        return (
          <Svg height="300" width="800">
            <Polyline points="10,150 30,140" fill="none" stroke="black" strokeWidth="2" />
            <Polygon points="10,150 30,140" fill="blue" fillOpacity="0.5" />
          </Svg>
        );
      case 'brainWave':
        return (
          <Svg height="300" width="800">
            <Polyline points="10,150 30,140" fill="none" stroke="white" strokeWidth="2" />
            <Polygon points="10,150 30,140" fill="red" fillOpacity="0.5" />
          </Svg>
        );
      case 'sleepEffect':
        return (
          <Svg height="300" width="800">
            <Polyline points="10,150 30,140" fill="none" stroke="green" strokeWidth="2" />
            <Polygon points="10,150 30,140" fill="blue" fillOpacity="0.5" />
          </Svg>
        );
      default:
        return null;
    }
  };

  return (
    <View style={{ padding: 10 }}>
      <ScrollView horizontal={true}>{renderSVG()}</ScrollView>
    </View>
  );
};

export default function TabOneScreen(props) {

    const [selectedSVG, setSelectedSVG] = useState(null);



  return (
      <View style={styles.separator}>
         <View style={{ padding: 10 }}>

          <SVGComponent selectedSVG={selectedSVG} />
         <View style={styles.row}>
          <Button
            label="睡眠数据"
            theme="index"
            onPress={() => setSelectedSVG('sleepData')}
          />
          <Button
            label="脑电波图形"
            theme="index"
            onPress={() => setSelectedSVG('brainWave')}
          />
          <Button
            label="睡眠改善效果"
            theme="index"
            onPress={() => setSelectedSVG('sleepEffect')}
          />
        </View>


         <View style={{ padding: 10 }}>
          <Text>AI 回复:</Text>
          <TextInput
            style={{ height: 110,width:300, borderColor: 'gray', borderWidth: 1, padding: 5 }}
            placeholder="AI响应将出现在这里..."
            editable={false}
          />
        </View>

      </View>

      </View>  );
}

const styles = StyleSheet.create({
  row: {
    padding: 10 ,
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
    height: 400,
    width: '100%',
  },
  imageContainer: {
    flex: 1,
    paddingTop: 58,
  },
});
