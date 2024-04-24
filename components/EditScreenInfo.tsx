import React from 'react';
import { StyleSheet } from 'react-native';

import { ExternalLink } from './ExternalLink';
import { MonoText } from './StyledText';
import { Text, View } from './Themed';

import Colors from '@/constants/Colors';

export default function EditScreenInfo({ path }: { path: string }) {
  if (path =="app/data.tsx"){
    return (
      <View>
        <View style={styles.getStartedContainer}>
          <Text
            style={styles.getStartedText}
            lightColor="rgba(0,0,0,0.8)"
            darkColor="rgba(255,255,255,0.8)">
            实时数据分析：展示用户的睡眠数据、脑电波图形以及睡眠改善效果的统计数据。
          </Text>


          <Text
            style={styles.getStartedText}
            lightColor="rgba(0,0,0,0.8)"
            darkColor="rgba(255,255,255,0.8)">
            个性化建议：根据分析结果向用户推荐个性化的改善睡眠方法。
          </Text>
        </View>

        <View style={styles.helpContainer}>
          <ExternalLink
            style={styles.helpLink}
            href="https://www.msdmanuals.cn/home/brain-spinal-cord-and-nerve-disorders/sleep-disorders/overview-of-sleep?query=%E7%9D%A1%E8%A7%89">
            <Text style={styles.helpLinkText} lightColor={Colors.light.tint}>
              点击了解更多关于睡眠的知识
            </Text>
          </ExternalLink>
        </View>
      </View>
    ); 
  }

if (path === "app/ctrl.tsx") {
  return (
    <View>
      <View style={styles.getStartedContainer}>
        <Text
          style={styles.getStartedText}
          lightColor="rgba(0,0,0,0.8)"
          darkColor="rgba(255,255,255,0.8)">
          学习如何优化您的光照、声音和脉冲疗法：
        </Text>
        <View
          style={[styles.codeHighlightContainer, styles.homeScreenFilename]}
          darkColor="rgba(255,255,255,0.05)"
          lightColor="rgba(0,0,0,0.05)">
          <MonoText>探索光照、声音和脉冲疗法的奇妙世界</MonoText>
        </View>
        <Text
          style={styles.getStartedText}
          lightColor="rgba(0,0,0,0.8)"
          darkColor="rgba(255,255,255,0.8)">
          发现量身定制疗法的力量，见证您的变化蜕变。
        </Text>
        <Text
          style={styles.getStartedText}
          lightColor="rgba(0,0,0,0.8)"
          darkColor="rgba(255,255,255,0.8)">
            开启光照、声音和脉冲疗法在您生活中的潜力。
        </Text>
1     </View>
    </View>
  );
}  
if (path == "app/user.tsx") {
    return (
      <View>
        <View style={styles.getStartedContainer}>
          <Text
            style={styles.getStartedText}
            lightColor="rgba(0,0,0,0.8)"
            darkColor="rgba(255,255,255,0.8)">
            用户中心
          </Text>

          <View
            style={[styles.codeHighlightContainer, styles.homeScreenFilename]}
            darkColor="rgba(255,255,255,0.05)"
            lightColor="rgba(0,0,0,0.05)">
            <MonoText>{path}</MonoText>
          </View>

          <Text
            style={styles.getStartedText}
            lightColor="rgba(0,0,0,0.8)"
            darkColor="rgba(255,255,255,0.8)">
            个人数据管理：让用户查看和管理其个人信息，包括睡眠记录、健康数据等。
          </Text>
          <Text
            style={styles.getStartedText}
            lightColor="rgba(0,0,0,0.8)"
            darkColor="rgba(255,255,255,0.8)">
            个性化建议：根据分析结果向用户推荐个性化的改善睡眠方法。
          </Text>
          <Text
            style={styles.getStartedText}
            lightColor="rgba(0,0,0,0.8)"
            darkColor="rgba(255,255,255,0.8)">
            允许用户设置偏好和个性化选项，定制化体验。
          </Text>
        </View>

        <View style={styles.helpContainer}>
          <ExternalLink
            style={styles.helpLink}
            href="https://www.yuque.com/g/lkqqry/bbb/ozmkbisbqhccz66a/collaborator/join?token=fQa5QA6Ashp3PVD5&source=doc_collaborator">
            <Text style={styles.helpLinkText} lightColor={Colors.light.tint}>
              用户反馈链接：点击这里，提供您的反馈和建议
            </Text>
          </ExternalLink>
        </View>
      </View>
    ); 
}}

const styles = StyleSheet.create({
  getStartedContainer: {
    alignItems: 'center',
    marginHorizontal: 50,
  },
  homeScreenFilename: {
    marginVertical: 7,
  },
  codeHighlightContainer: {
    borderRadius: 3,
    paddingHorizontal: 4,
  },
  getStartedText: {
    fontSize: 14,
    lineHeight: 24,
    textAlign: 'center',
  },
  helpContainer: {
    marginTop: 15,
    marginHorizontal: 20,
    alignItems: 'center',
  },
  helpLink: {
    paddingVertical: 15,
  },
  helpLinkText: {
    textAlign: 'center',
  },
});
