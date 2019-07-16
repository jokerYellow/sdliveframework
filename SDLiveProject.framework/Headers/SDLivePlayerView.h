//
//  SDLivePlayerView.h
//  SDLiveProject
//
//  Created by HuangYaqing on 2018/7/29.
//

#import <UIKit/UIKit.h>
#import "SDLiveDefine.h"

@class SDLiveRecorder;
@class SDLiveRecordModel;

@protocol SDLivePlayerViewRecorder

-(void)recordType:(SDLiveBlockType)type url:(NSString*)url duration:(NSInteger)duration message:(NSString*)message tcpSpd:(NSString*)speed;

@end

typedef void(^SDLivePlayerCompleteBlock)(NSError* error);

typedef void(^SDLivePlayerErrorBlock)(NSError* error);

typedef void(^SDLivePlayerStatusCallBlock)(SDLiveMoviePlaybackState);

typedef void(^SDLivePlayerLoadStatusCallBlock)(SDLiveMovieLoadState);


@interface SDLivePlayerView : UIView

@property (nonatomic, assign, readonly) NSTimeInterval vCache;
@property (nonatomic, assign, readonly) NSString* tcpSpeed;
@property (nonatomic, assign, readonly) NSTimeInterval currentPlayTime;
@property (nonatomic, assign, readonly) NSTimeInterval playableDuration;

@property (nonatomic, assign) Boolean isFirstLaunch;
/**
 埋点记录
 */
@property (nonatomic, weak) id<SDLivePlayerViewRecorder> recorder;
/**
 正在初始化seeking，该情况下不做时间回调
 */
@property (nonatomic, assign, readonly) Boolean isSeekingInitial;

/**
 视频适配模式
 */
@property (nonatomic,assign) SDLiveMovieScalingMode scalingMode;

/**
 播放状态
 */
@property (nonatomic,assign) SDLiveMoviePlaybackState state;

/**
 加载状态
 */
@property (nonatomic,assign) SDLiveMovieLoadState loadState;


/**
 播放完毕回调
 */
@property (nonatomic,copy) SDLivePlayerCompleteBlock completelock;

/**
 播放错误回调，需要重新链接直播服务，获取新的拉流
 */
@property (nonatomic,copy) SDLivePlayerErrorBlock errorblock;


/**
 播放器播放状态回调
 */
@property (nonatomic,copy) SDLivePlayerStatusCallBlock statusCallBack;


/**
 加载状态回调
 */
@property (nonatomic,copy) SDLivePlayerLoadStatusCallBlock loadStatusCallBack;


/**
 播放速度
 */
@property (nonatomic,assign) CGFloat playSpeed;

/**
 获取当前播放帧缩略图

 @return UIImage
 */
- (UIImage *)thumbnailImageAtCurrentTime;
/**
 播放某个URL

 @param url 地址
 */
- (void)playUrl:(NSURL *)url seekTime:(NSTimeInterval)time isLive:(Boolean)flag;

/**
 停止播放，释放内存
 */
- (void)stopPlaying;

/**
 拖拽到某个时间点

 @param time time
 */
- (void)setToTime:(NSInteger)time;

/**
 暂停
 */
- (void)pausePlay;

/**
 恢复暂停
 */
- (void)continuePlay;

- (void)removePlayView;


@end
