# voiceTool
声音录制工具tool ,voice
```
- (VoiceRecordTool *)voiceRecordTool {
  if (!_voiceRecordTool) {
    WEAKSELF
    _voiceRecordTool = [[VoiceRecordTool alloc] init];
    
    _voiceRecordTool.maxTimeStopRecorderCompletion = ^{
      DDLogDebug(@"已经达到最大限制时间了，进入下一步的提示");
      __strong __typeof(weakSelf)strongSelf = weakSelf;
      [strongSelf finishRecorded];
    };
    //声音录制强度
    _voiceRecordTool.peakPowerForChannel = ^(float peakPowerForChannel) {
      __strong __typeof(weakSelf)strongSelf = weakSelf;
      strongSelf.voiceRecordHUD.peakPower = peakPowerForChannel;
    };
    
    _voiceRecordTool.maxRecordTime = 60;
  }
  return _voiceRecordTool;
}









```
