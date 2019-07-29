//
//  SDLiveManager.h
//  SDLiveProject
//
//  Created by HuangYaqing on 2018/7/25.
//

#import <Foundation/Foundation.h>
#import "SDLiveDefine.h"

@class SDLiveLoginModel;
@class SDLivePageView;
@class SDLivePlayerView;
@class SDLiveManager;
@class SDLiveRoomInfo;
@class SDLiveIMMessageModel;
@class SDLiveIMChatRoomEvent;
@class SDLiveIMChatRoomModel;
@class SDLivePaperModel;
@class SDLivePageContainerView;
@class SDLiveLogView;
@class SDLiveIMResponse;
@class SDLiveLoginInfoModel;
@class SDLiveIMAnnounceModel;
@protocol SDLiveMediaProtocol;

@protocol SDLiveManagerDelegate
//流程图
//https://www.processon.com/diagraming/5c147216e4b06db7dfdda988

/**
 时间回调

 @param manager SDLiveManager
 @param duration 视频总时长
 @param currentPlayTime 当前播放时长
 @param cachedDuration 已缓存的视频时长
 */
- (void)manager:(SDLiveManager* _Nonnull)manager
       duration:(NSTimeInterval)duration
currentPlayTime:(NSTimeInterval)currentPlayTime
cacheVideoDuration:(NSTimeInterval)cachedDuration;

/**
 播放器状态回调

 @param manager SDLiveManager
 @param state 状态，包括暂停、加载、播放等状态
 */
- (void)manager:(SDLiveManager* _Nonnull)manager
      playState:(SDLiveMoviePlaybackState)state;

//播放器加载状态回调
- (void)manager:(SDLiveManager* _Nonnull)manager
      loadState:(SDLiveMovieLoadState)state;

//播放器错误回调，播放器播放遇到错误，包括IJKPlayer自身的bug、拉流链接错误等，会触发。
//仅展示不用处理
- (void)manager:(SDLiveManager* _Nonnull)manager
    onPlayError:(NSError* _Nullable)error;

//websocket状态回调，可忽略
- (void)manager:(SDLiveManager* _Nonnull)manager
onWebSocketState:(SDSocketState)state;

//直播/点播场景下，外部传入的token认证失败的错误
- (void)manager:(SDLiveManager* _Nonnull)manager
    authOnError:(NSError* _Nullable)error;

/**
 直播间异常回调

 @param manager SDLiveManager
 @param error 错误对象，userInfo里为附加信息
 */
- (void)manager:(SDLiveManager* _Nonnull)manager
        onError:(NSError* _Nullable)error;

/**
 房间信息回调

 @param manager SDLiveManager
 @param roomInfo 房间信息类，包含房间名称、老师名称等信息
 */
- (void)manager:(SDLiveManager* _Nonnull)manager
       roomInfo:(SDLiveRoomInfo* _Nonnull)roomInfo;

/**
 直播间事件回调

 @param manager SDLiveManager
 @param event 事件，【开始直播、结束直播、暂停直播、恢复直播】
 @param message 附加信息
 */
- (void)managerLiveEventOccur:(SDLiveManager* _Nonnull)manager
                        event:(SDLiveRoomEvent)event
                      message:(NSString* _Nullable)message;

/**
 用户进入/离开直播间事件回调

 @param manager SDLiveManager
 @param event 进入/离开事件
 @param info NSDictionary
 */
- (void)managerLivePeopleEventOccur:(SDLiveManager* _Nonnull)manager
                              event:(SDLiveRoomPeopleEvent)event
                               info:(NSDictionary* _Nullable)info;

//收到教师端发起的随堂考事件
- (void)managerLive:(SDLiveManager* _Nonnull)manager
 beginExamWithPaper:(SDLivePaperModel* _Nullable)paper;


/**
 直播间人数发生变化

 @param manager SDLiveManager
 @param userCount 直播间总人数
 */
- (void)managerLive:(SDLiveManager* _Nonnull)manager
 userCountDidChange:(NSInteger)userCount;

/**
 当前视频流播放类型变化
 UrlSteamType 分为 老师摄像头 共享桌面 共享视频
 @param manager SDLiveManager
 @param type UrlSteamType
 */
- (void)manager:(SDLiveManager* _Nonnull)manager
didChangeStreamUrl:(UrlSteamType)type;

//事件信息,暂时忽略
@optional
- (void)manager:(SDLiveManager* _Nonnull)manager
          event:(id _Nullable)event;


/**
 课件加载回调，加载失败的时候，业务方可以考虑增加重试按钮，重新加载课件
 加载恢复正常的时候，业务方可以隐藏重试按钮

 @param status SDLiveImageLoadStatus
 */
-(void)manager:(SDLiveManager* _Nonnull)manager
    didChangeImageStatus:(SDLiveImageLoadStatus)status;

@end

@protocol SDLiveIMDelegate

/**
 收到服务端发来的新消息
 
 @param messages 消息列表
 */
-(void)didReceiveMessageList:(NSArray<SDLiveIMMessageModel*>* _Nullable)messages;


/**
 收到服务端发来的公告

 @param announce 公告模型
 */
-(void)didReceiveAnnounce:(SDLiveIMAnnounceModel* _Nonnull)announce;

/**
 收到服务端发来的消息体
 错误信息：
 cmd=4，result=14，两秒太频繁了【需提示用户】
 
 @param SDLiveIMResponse 消息体
 */
@optional
-(void)didReceiveResponse:(SDLiveIMResponse* _Nonnull)response;

/**
 聊天室登录成功，返回基本的聊天室信息，如登录人员信息、禁言状态、聊天室人数、登录token等
 用户登录之后会返回部分之前的消息
 当app长链接断开重连的时候，也会调用该方法，所以需要注意登录返回的消息会重复。
 
 @param model SDLiveIMChatRoomModel
 */
-(void)didLogin:(SDLiveIMChatRoomModel* _Nonnull)model
    MessageList:(NSArray<SDLiveIMMessageModel*>* _Nullable)messages;

/**
 消息发送成功，返回发送成功的消息

 @param message 聊天消息数据
 */
-(void)didSendMessage:(SDLiveIMMessageModel* _Nonnull)message;

/**
 * 聊天室解散通知，客户端无需重连
 * */
- (void)didChatRoomClose;

/**
 用户批量下线通知，聊天人数变更

 @param number 剩余聊天人数
 */
- (void)didChatRoomBatchOffline:(NSInteger)number;

/**
 用户进入、退出聊天室回调，会返回聊天室当前人数、以及退出用户的信息

 @param event SDLiveIMChatRoomEvent
 */
- (void)didRoomUserEvent:(SDLiveIMChatRoomEvent* _Nonnull)event;

/**
 用户同一时间只会在一个直播间内，重复登录会给前一个连接发送被踢通知看，同时将前一个连接关掉
 客户端收到踢人通知，websocket无需重连，该token用户被踢了

 @param userToken 被挤下线的用户token
 */
- (void)didChatRoomKickOffUser:(NSString* _Nonnull)userToken;

/**
 * 全体禁言，收到禁言/解禁 通知，禁止或允许用户发送信息，
 * status false：不禁言，true：禁言
 * */
- (void)didChatRoomForbiddenStatusChange:(Boolean)status;

/**
 * 个人禁言，收到禁言/解禁 通知，禁止或允许用户发送信息，
 * status false：不禁言，true：禁言
 * */
- (void)didChatRoomDidForbiddenUserTalk:(Boolean)status;

/**
 
 该通知用于老师或者助教更新本地的学员大表和被踢用户列表。
 1. 老师或者助教主动将某个学员踢出直播间, 该通知会发送给被踢人以及其他的老师或者助教。
 2. 老师或者助教主动将某个学员取消踢人状态，该通知会发送给其他老师或者助教。
 @param status false：不禁言，true：禁言
 */
- (void)didChatRoomDidUserBeKickOff:(Boolean)status;
@end


/**
 尚直播管理类
 提供初始化SDK方法
 提供课件视图、播放器视图供业务方布局
 提供发送弹幕、控制播放器等方法
 */
@interface SDLiveManager : NSObject


/**
 获取当前的聊天室的信息，在登录进聊天室之后才会有值
 */
@property (nonatomic,strong,readonly,nullable) SDLiveIMChatRoomModel* chatRoomModel;


/**
 获取当前的直播间的信息，在登录进直播间之后才会有值
 */
@property (nonatomic,strong,readonly,nullable) SDLiveRoomInfo* roomInfo;


/**
 直播间回调代理，包括播放器状态、报错、随堂考等事件
 */
@property (nonatomic,weak,nullable) NSObject<SDLiveManagerDelegate>* delegate;


/**
 IM回调代理，包括收到新消息、用户被踢、禁言等事件
 */
@property (nonatomic,weak,nullable) NSObject<SDLiveIMDelegate>* imDelegate;

/**
 课件视图，建议仅用作布局，不要调用其方法
 */
@property (nonatomic,strong, readonly) SDLivePageContainerView* _Nonnull  pageView;

/**
 播放视图，建议仅用做布局，不要调用其方法
 */
@property (nonatomic,strong, readonly)  SDLivePlayerView* _Nonnull playerView;

/**
 课件区域的占位图，当课件图片在加载中的时候展示该图片
 默认有占位图
 */
@property (nonatomic,strong) UIImage* _Nullable pageViewPlaceHolderImage;

/*
 当前的拉流tcp速度
 */
@property (nonatomic,strong, readonly) NSString* _Nullable tcpSpeed;

/**
 UrlSteamType 分为 老师摄像头 共享桌面 共享视频
 当前播放的视频的类型，默认老师摄像头
 */
@property (nonatomic,assign,readonly) UrlSteamType streamType;

/**
 初始化方法

 @param token IMtoken
 @param code 邀请码
 @return SDLiveManager
 */
- (instancetype _Nonnull )initWithToken:(NSString* _Nonnull )token
                          andInviteCode:( NSString* _Nonnull)code
                            channelCode:( NSString* _Nonnull)channelCode
                                   type:( SDVideoType)type;


/**
 初始化方法

 @param token token
 @param liveId liveId
 @param channelCode 渠道码
 @param type 登录类型
 @return SDLiveManager
 */
- (instancetype _Nonnull)initWithToken:(NSString* _Nonnull)token
                             andLiveId:(NSString* _Nonnull)liveId
                           channelCode:(NSString* _Nonnull)channelCode
                                  type:(SDVideoType)type;


/**
 平台化业务方客户端启动直播的初始化方法

 @param model SDLiveLoginInfoModel
 @return SDLiveManager
 */
- (instancetype _Nonnull)initLiveWith:(SDLiveLoginInfoModel*_Nonnull )model
                                 type:(SDVideoType)type;


#pragma mark 播放器控制方法

/**
 播放速度，默认1.0，赋值即可修改播放速度，如2为两倍，1.5为1.5倍播放
 */
@property (nonatomic,assign) CGFloat playSpeed;

/**
 开始播放
 */
-(void)play;

/**
 在特定时间开始播放
 */
-(void)playWithTime:(NSTimeInterval)time;

/**
 暂停播放
 */
-(void)pause;

/**
 继续播放
 */
-(void)resume;

/**
 停止播放，停止之后，无法恢复播放，会释放相关的内存
 一般情况下，在控制器销毁的时候，不用调用该方法
 在SDLiveManager的dealloc方法里，内部会调用该方法
 */
-(void)stop;

/**
 拖拽播放，内部会对time做floor(time)处理
 */
-(void)dragTo:(NSTimeInterval)time;

#pragma mark 弹幕
/**
 发送弹幕消息，发送聊天室消息

 @param message 文本消息
 */
- (void)sendMessage:(NSString* _Nonnull)message;


/**
 重新加载课件图片，在收到课件加载失败的回调的时候，可以调用该方法
 */
- (void)reloadPage;


/**
 重新走一遍登录流程、开始播放视频，当视频出现问题的时候，可以使用该方法
 */
- (void)reStart;

#pragma mark 环境

/**
 环境切换，在初始化播放器之前切换环境

 @param type SDLiveConfig
 */
+ (void)setConfigType:(SDLiveConfig)type;

@end
