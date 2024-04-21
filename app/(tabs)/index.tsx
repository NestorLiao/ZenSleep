import {ActivityIndicator, Image, TextInput,ScrollView, StyleSheet } from 'react-native';
import Button from '@/components/Button';
import React,{useState}from "react";
import Svg, {
  Circle,
  // SvgUri,
  // SvgCssUri,
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
import {SvgCssUri} from 'react-native-svg/css';




import * as ImagePicker from 'expo-image-picker';

import ImageViewer from "../../components/ImageViewer";
import IconButton from "@/components/CircleButton";


const Heathimprove= require("../../assets/images/healthimprove.png");
const Brainwave= require("../../assets/images/brainwave.png");
const Sleepdata= require("../../assets/images/sleepdata.png");


export default function TabOneScreen(props) {



 const pickImageAsync = async () => {
    let result = await ImagePicker.launchImageLibraryAsync({
      allowsEditing: true,
      quality: 1,
    });

    if (!result.canceled) {
      console.log(result);
    } else {
      alert('You did not select any image.');
    }
  };


  const [selectedImage, setSelectedImage] = useState(null);


{
  //   const onReset2 = (img) => {
  //   setSelectedImage(Brainwave);
  // };
  // const onReset3 = (img) => {
  //   setSelectedImage(Heathimprove);
  // };
  // const onReset = (img) => {
  //   setSelectedImage(Sleepdata);
  // };
}
  return (

        <View style={styles.cloumn}>

         <View style={{ padding: 10 }}>
{
        // <ImageViewer
        //   placeholderImageSource={selectedImage ? selectedImage : Heathimprove}
        // />
}        
{
        // <View style={styles.row}>
        //     <IconButton icon="refresh" label="睡眠数据" onPress={onReset} />
        //     <IconButton icon="refresh" label="脑电波图形" onPress={onReset2} />
        //     <IconButton icon="refresh" label="睡眠改善效果" onPress={onReset3} />
        // </View>
}
        </View>
    
      <View style={styles.container}>
            <IconButton icon="refresh" label="睡眠改善效果" onPress={pickImageAsync} />
      </View>

          <TextInput
            style={{ height: 100,width:300, borderColor: 'gray', borderWidth: 1, padding: 5 }}
            placeholder="询问关于你的个性化睡眠建议"
            editable={true}
          />
          <TextInput
            style={{ height: 100,width:300, borderColor: 'gray', borderWidth: 1, padding: 5 }}
            placeholder="AI响应将出现在这里..."
            editable={false}
          />


        </View>
      
    );


}

const styles = StyleSheet.create({
  row: {
    padding: 20 ,
    flexDirection: 'row',
    alignItems: 'center',
    justifyContent: 'space-around',
    marginVertical: 10,
  },

cloumn: {
    padding: 30,
    flexDirection: 'column',
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

  image: {
    width: 320,
    height: 440,
    borderRadius: 18,
  },

  scrollContainer: {
    flexGrow: 1,
    justifyContent: 'center',
    alignItems: 'center',
  },
});
