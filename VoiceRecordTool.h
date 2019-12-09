





#import <Foundation/Foundation.h>

typedef void(^StartRecorderCompletion)();
typedef void(^StopRecorderCompletion)();
typedef void(^PauseRecorderCompletion)();
typedef void(^ResumeRecorderCompletion)();
typedef void(^CancellRecorderDeleteFileCompletion)();
typedef void(^RecordProgress)(float progress);
typedef void(^PeakPowerForChannel)(float peakPowerForChannel);


@interface VoiceRecordTool : NSObject

/** 到达最大录音时间回调block */
@property (nonatomic, copy) StopRecorderCompletion maxTimeStopRecorderCompletion;
@property (nonatomic, copy) RecordProgress recordProgress;
/** 声音强度 0.0 ~ 1.0 */
@property (nonatomic, copy) PeakPowerForChannel peakPowerForChannel;
/** 录音保存的路径 只读 */
@property (nonatomic, copy, readonly) NSString *recordPath;
/** 录音时长 */
@property (nonatomic, copy) NSString *recordDuration;
/** 录音最大时长  默认 60秒为最大 */
@property (nonatomic) float maxRecordTime;
@property (nonatomic, readonly) NSTimeInterval currentTimeInterval;


/**
 开始录音
 @param path 录音保存路径 可以传nil 传入nil会创建默认路径
 @param startRecorderCompletion 完成回调
 */
- (void)startRecordingWithPath:(NSString *)path StartRecorderCompletion:(StartRecorderCompletion)startRecorderCompletion;


/**
 暂停录音
 @param pauseRecorderCompletion 暂停回调
 */
- (void)pauseRecordingWithPauseRecorderCompletion:(PauseRecorderCompletion)pauseRecorderCompletion;


/**
 继续录音
 @param resumeRecorderCompletion 继续录音回调
 */
-(void)resumeRecordingWithResumeRecorderCompletion:(ResumeRecorderCompletion)resumeRecorderCompletion;


/**
 完成录音
 @param stopRecorderCompletion 完成回调
 */
- (void)stopRecordingWithStopRecorderCompletion:(StopRecorderCompletion)stopRecorderCompletion;


/**
 取消录音
 @param cancelledDeleteCompletion 取消回调
 */
-(void)cancelledDeleteWithCompletion:(CancellRecorderDeleteFileCompletion)cancelledDeleteCompletion;

@end
