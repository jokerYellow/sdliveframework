//
//  SDLiveDefine.h
//  SDLiveProject
//
//  Created by HuangYaqing on 2018/6/22.
//

#ifndef SDLiveDefine_h
#define SDLiveDefine_h

#ifdef DEBUG
    #define NSLog(...) NSLog(__VA_ARGS__)
#else
    #define NSLog(...) (void)0
#endif


/**
 图片加载状态

 - SDLiveImageLoadStatusFailed: 加载失败
 - SDLiveImageLoadStatusNormal: 加载恢复正常
 */
typedef NS_ENUM(NSInteger, SDLiveImageLoadStatus){
    SDLiveImageLoadStatusFailed,
    SDLiveImageLoadStatusNormal,
};

typedef NS_ENUM(NSInteger, SDLiveConfig){
    SDLiveConfigDevelop,
    SDLiveConfigQA,
    SDLiveConfigProduct,
};

//服务器返回的code码
//http://192.168.0.49:9981/view/ErrorCode.tars
typedef NS_ENUM(NSInteger, SDLiveServerErrorCode){
    EC_OK = 0,
    EC_PARAMETER_ERROR = 1,         // parameter error
    EC_ROOM_NOT_FOUND = 2,          // can't find room
    EC_SESSION_NOT_FOUND = 3,       // can't find session
    EC_ENCODE_ERROR = 4,            // encode stream failed
    EC_DECODE_ERROR = 5,            // decode stream failed
    EC_INVOKE_ERROR = 6,            // invoke rpc inner rpc failed
    EC_INVOKE_TIME_OUT = 7,         // invoke rpc time out
    EC_SYSTEM_ERROR = 8,            // system inner error, for client
    EC_MYSQL_EXEC_FAILED = 100,     // mysql exec failed
    
    // -- begin of gate server
    EC_GATE_BEGIN = 1000,
    EC_SERVER_MESSAGE_UNKNOWN = 1001,   // recive an unkonwn server message
    EC_SHOULD_LOGIN_FIRST = 1002,       // client should login then send other message to server
    EC_REPEATED_LOGIN = 1003,           // already logined, no login any more
    EC_TOO_NAGGING = 1004,              // send message to frequently
    EC_IS_LOGINING = 1005,              // is logining, wait for login response
    EC_CONNECTION_CLOSED = 1006,        // connection is closed by epoller
    EC_NET_OVERLOAD = 1007,             // epoller overload
    EC_GATE_END = 1099,
    // -- end of gate server
    
    // -- begin of room center
    EC_ROOM_CENTER_BEGIN = 1100,
    EC_ROOM_EXISTED = 1101,             // try to create existed room
    EC_NO_PROPER_ROOM_SERVER = 1102,    // can not find a proper server
    EC_SERVANT_EMPTRY = 1103,           // servant empty
    EC_ROOM_IS_CREATING = 1104,         // room is creating
    EC_ROOM_CENTER_END = 1199,
    // -- end of room center
    
    // -- begin of gate balance
    EC_GATE_BALANCE_BEGIN = 1200,
    EC_NO_PROPER_GATE_SERVER = 1201,    // can not find a proper server
    EC_GATE_BALANCE_END = 1299,
    // -- end of gate balance
    
    // -- begin of streammanagerserver
    EC_STREAM_MANAGER_SERVER_BEGIN = 1300,
    EC_SMS_DB_ERROR = 1311,
    EC_SMS_DB_NOT_FOUND = 1312,
    EC_SMS_DB_EXCEPTION = 1313,
    EC_SMS_DB_ALREADY_EXIST = 1321,
    EC_SMS_REDIS_ERROR = 1322,
    EC_SMS_REDIS_NOT_FOUND = 1323,
    EC_SMS_MISSING_CDN_TYPE = 1331,     //缺少CDN信息
    EC_SMS_INVALID_CDN_TYPE = 1332,     //非法CDN类型
    EC_SMS_JSON_EXCEPTION = 1341,       //JSON解析出错
    EC_STREAM_MANAGER_SERVER_END = 1399,
    // -- end of streammanagerserver
    
    // --begin of room server
    EC_ROOM_SERVER_BEGIN = 10000,
    EC_USER_NOT_FOUND = 10001,
    EC_USER_AUTH_ERROR = 10002,
    EC_SYSTEM_NEW_ERROR = 10003,
    EC_ROOM_NOT_REGISTERED = 10004,
    EC_BROADCAST_TYPE_ERROR = 10005,
    EC_PROTOCOL_NOT_SUPPORT = 10006,
    EC_ROOM_NOT_LIVE = 10007, // 还未开播
    EC_ROOM_REPEAT_LOGIN = 10008, // 您已在其他地方登陆，不允许重连
    EC_HEARTBEAT_TIMEOUT = 10009, // 心跳超时，应该重新连接
    EC_SESSION_TIMEOUT = 10010, // 过期会话，例如RoomServer重启，应该重新连接
    EC_STREAM_PUSH_URL = 10011, // 获取推流地址失败
    EC_STREAM_PULL_URL = 10012, // 获取拉流地址失败
    EC_STREAM_PLAY_URL = 10013, // 获取回放流地址失败
    EC_LOGIN_TOO_EARLY = 10014, // 过早进入房间
    EC_LOGIN_TOO_MANY = 10015, // 进入房间人数过多
    EC_ROOM_ALREADY_LIVE = 10016, // 已经开播
    EC_ROOM_LIVE_TOO_EARLY = 10017, // 过早开课
    EC_ROOM_LIVE_TOO_LATE = 10018, // 过晚开课
    EC_ROOM_NOT_TEACHER = 10019, // 不是当前房间老师
    EC_ROOM_UPLOAD_TOKEN_ERROR = 10020, // 获取上传Token失败
    EC_REDIS_EXEC_ERROR = 10021, // redis执行失败
    EC_ROOM_DB_ERROR = 10022, // DB执行结果失败
    EC_ROOM_LIVE_END = 10023, // 房间已经结束直播
    EC_ROOM_LIVE_NOT_END = 10024, // 房间还没结束直播
    EC_ROOM_LIVE_NOT_READY = 10025, // 房间不是未开始状态
    EC_ROOM_LIVE_NOT_PAUSE = 10026, // 房间不是暂停状态
    EC_ROOM_VIDEO_NOT_DONE = 10027, //录播视频还未生成
    EC_ROOM_SERVER_END = 19999,
    // --end of room server
    
    // --begin of document server
    EC_DOCUMENT_SERVER_BEGIN = 20000,
    EC_SERVER_UNREACHABLE    = 20001, // 文档服务不可达，请求超时或者异常
    EC_FILE_ALREADY_EXISTS   = 20002, // 文档已经上传过，秒传成功
    EC_DB_INSERT_FAILED      = 20003, // 文档写库失败
    EC_DB_EXCEPTION          = 20004, // 数据库异常
    EC_NO_SUCH_FILE          = 20005, // 下载或删除找不到文件
    EC_MISSING_IMAGE         = 20006, // 文档的图片缺失
    EC_REQUEST_ERROR         = 20007, // 请求参数错误
    EC_DOCUMENT_SERVER_END   = 30000,
    // --end of document server
    
    // --begin of RoomAdmin server
    EC_NO_INVITATION        = 30001,    // 该房间没有邀请码
    EC_TEACHER_INVITATION_ERROR     = 30002,    // 老师邀请码验证错误
    EC_STUDENT_INVITATION_ERROR     = 30003,    // 学生邀请码验证错误
    EC_INVITATION_TYPE_ERROR = 30004,   // 邀请码类型错误，当前不支持
    
    EC_CREATE_ROOM_TIME_ERROR = 30005, // 创建房间的时间错误
    EC_CREATE_ROOM_TYPE_ERROR = 30006, // 创建房间的类型错误
    // --end of RoomAdmin server
    
    // --begin of Auth server
    EC_AUTH_BEGIN       = 40000,
    EC_AUTH_FAILED      = 40001,  // 参加码不存在
    EC_NO_ADDRESS       = 40002, // 用户中心Token错误
    EC_AUTH_RETRY             = 40003, // 服务内部问题,客户端应该重试
    EC_AUTH_EXPIRED           = 40004, // 内部登录token过期，需要重新获取
    EC_AUTH_PARAM_ERROR       = 40005, // 请求参数错误, 缺少参数或者字段类型不对
    EC_AUTH_SIGN_ERROR        = 40007,  // 第三方签名校验错误
    EC_AUTH_PARTNER_NOT_EXISTED     = 40008,  // 第三方合作方id不存在
    EC_AUTH_END               = 50000  //
    // --end of Auth server
};

/**
 播放器状态，对应 IJKPLayer 的 IJKMPMoviePlaybackState
 
 SDLiveMoviePlaybackStateStopped -> IJKMPMoviePlaybackStateStopped,
 SDLivePMoviePlaybackStatePlaying -> IJKMPMoviePlaybackStatePlaying,
 SDLiveMoviePlaybackStatePaused -> IJKMPMoviePlaybackStatePaused,
 SDLiveMoviePlaybackStateInterrupted -> IJKMPMoviePlaybackStateInterrupted,
 SDLiveMoviePlaybackStateSeekingForward -> IJKMPMoviePlaybackStateSeekingForward,
 SDLiveMoviePlaybackStateSeekingBackward -> IJKMPMoviePlaybackStateSeekingBackward
 
 - SDLiveMoviePlaybackStateStopped: 停止播放
 - SDLivePMoviePlaybackStatePlaying: 正在播放
 - SDLivePMoviePlaybackStateStoppedAndAutoPlayNextVideo：停止播放，准备下一段播放
 - SDLiveMoviePlaybackStatePaused: 暂停
 - SDLiveMoviePlaybackStateInterrupted: 被打断
 - SDLiveMoviePlaybackStateSeekingForward: 拖拽
 - SDLiveMoviePlaybackStateSeekingBackward: 拖拽
 */
typedef NS_ENUM(NSInteger, SDLiveMoviePlaybackState) {
    SDLiveMoviePlaybackStateStopped,
    SDLivePMoviePlaybackStatePlaying,
    SDLivePMoviePlaybackStateStoppedAndAutoPlayNextVideo,
    SDLiveMoviePlaybackStatePaused,
    SDLiveMoviePlaybackStateInterrupted,
    SDLiveMoviePlaybackStateSeekingForward,
    SDLiveMoviePlaybackStateSeekingBackward
};


/**
 播放器加载状态，对应 IJKPLayer 的 IJKMPMovieLoadState
 
 SDLiveMovieLoadStateUnknown -> IJKMPMovieLoadStateUnknown
 SDLiveMovieLoadStatePlayable -> IJKMPMovieLoadStatePlayable
 SDLiveMovieLoadStatePlaythroughOK -> IJKMPMovieLoadStatePlaythroughOK
 SDLiveMovieLoadStateStalled -> IJKMPMovieLoadStateStalled
 
 - 通过查看IJKPLayer的源码，IJKMPMovieLoadStatePlayable 和 IJKMPMovieLoadStatePlaythroughOK 是同时存在的，赋值的时候使用的 IJKMPMovieLoadStatePlayable | IJKMPMovieLoadStatePlaythroughOK 方法
 - SDLiveMovieLoadStateUnknown: 未知状态
 - SDLiveMovieLoadStatePlayable: 可播放状态，缓存了一些时长的视频，可以播放，可以认为为播放器正在播放
 - SDLiveMovieLoadStatePlaythroughOK: 可播放状态，缓存了一些时长的视频，可以播放，如果播放器为自动播放，则会开始播放，可以认为为播放器正在播放
 - SDLiveMovieLoadStateStalled: 停滞状态，播放器会暂停
 */
typedef NS_OPTIONS(NSUInteger, SDLiveMovieLoadState) {
    SDLiveMovieLoadStateUnknown        = 0,
    SDLiveMovieLoadStatePlayable       = 1 << 0,
    SDLiveMovieLoadStatePlaythroughOK  = 1 << 1, // Playback will be automatically started in this state when shouldAutoplay is YES
    SDLiveMovieLoadStateStalled        = 1 << 2, // Playback will be automatically paused in this state, if started
};


/**
 对应 IJKPLayer 的 IJKMPMovieScalingMode
 SDLiveMovieScalingModeNone -> IJKMPMovieScalingModeNone
 SDLiveMovieScalingModeAspectFit -> IJKMPMovieScalingModeAspectFit
 SDLiveMovieScalingModeAspectFill -> IJKMPMovieScalingModeAspectFill
 SDLiveMovieScalingModeFill -> IJKMPMovieScalingModeFill
 */
typedef NS_ENUM(NSInteger, SDLiveMovieScalingMode) {
    SDLiveMovieScalingModeNone,       // No scaling
    SDLiveMovieScalingModeAspectFit,  // Uniform scale until one dimension fits
    SDLiveMovieScalingModeAspectFill, // Uniform scale until the movie fills the visible bounds. One dimension may have clipped contents
    SDLiveMovieScalingModeFill        // Non-uniform scale. Both render dimensions will exactly match the visible bounds
};

/**
 webSocket状态
 
 - SDSocketStateConnecting:尝试连接中
 - SDSocketStateConnected: 已连接
 - SDSocketStateClosed: 关闭
 - SDSocketStateFail: 连接失败
 */
typedef NS_ENUM(NSInteger,SDSocketState){
    SDSocketStateConnecting,
    SDSocketStateConnected,
    SDSocketStateClosed,
    SDSocketStateFail,
} ;

typedef NS_ENUM(NSInteger,SDLiveRoomEvent){
    SDLiveRoomEventClassBegin,//开始上课
    SDLiveRoomEventClassTerminal,//结束上课
    SDLiveRoomEventClassPause,//暂停上课
    SDLiveRoomEventClassContinue,//继续上课
} ;

// 1表示未开始，2表示上课中，3表示暂停，4表示已结束
typedef NS_ENUM(NSInteger,SDLiveRoomStatus){
    SDLiveRoomStatusNotBegin = 1, //未开始上课
    SDLiveRoomStatusIsOn = 2,//上课中
    SDLiveRoomStatusIsPause = 3,//暂停
    SDLiveRoomStatusIsEnd = 4,//已结束
} ;

typedef NS_ENUM(NSInteger,SDLiveRoomPeopleEvent){
    SDLiveRoomPeopleEnterEvent = 1, //有人进入直播间
} ;

extern NSString* sdlive_sdk_version;

typedef double SDLiveNumber;

typedef NS_ENUM(NSInteger, SDLiveClientType){
    SDLiveClientAndroidType = 1,
    SDLiveClientIOSType = 2,
    SDLiveClientWebType = 3,
    SDLiveClientWechatProgramType = 4,
    SDLiveClientH5Type = 5,
    SDLiveClientPushType = 6,
    SDLiveClientVerticalScreenType = 7,
};
 
typedef NS_ENUM(NSInteger, SDLiveUserRoleType){
    SDLiveUserRoleStudent = 1,
    SDLiveUserRoleTeacher = 2,
    SDLiveUserRoleAdmin = 3,
    SDLiveUserRoleQA = 4
};

/**
 直播错误处理码

 - SDLiveSocketErrorJustShow: 仅展示错误信息
 - SDLiveSocketErrorReconnect: 主动重连（RoomServer重启）
 - SDLiveSocketErrorExit: 主动退出（比如重复登陆房间）
 */
typedef NS_ENUM(NSInteger, SDLiveSocketError){
    SDLiveSocketErrorJustShow = 1,
    SDLiveSocketErrorReconnect = 2,
    SDLiveSocketErrorExit = 3
} ;

typedef enum :NSUInteger{
    SDVideoLiveType = 1,//直播
    SDVideoRecordType  = 2,//点播
} SDVideoType;

typedef enum :NSUInteger
{
    //1：老师摄像头
    UrlSteamTypeTeacher = 1,
    //2：共享桌面
    UrlSteamTypeComputerDesk = 2,
    //3：共享视频
    UrlSteamTypeShareVideo = 3,
} UrlSteamType;


#endif /* SDLiveDefine_h */
