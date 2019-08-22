SDLiveProject 是尚直播的 iOS 端 SDK ，包含直播、点播功能，集成方便。
## 1.准备条件
- iOS7.0 +
- [CocoaPods](https://cocoapods.org)

## 2.安装
在 `Podfile` 添加
* 持续获取最新版本

```ruby
pod 'SDLiveProject',:git=>'https://github.com/jokerYellow/sdliveframework.git'
```

* 当前稳定版本1.0.8

```ruby
pod 'SDLiveProject',:git=>'https://github.com/jokerYellow/sdliveframework.git',:tag=>'1.0.8'
```

> **如果主工程有引入欢拓**，请在安装尚直播之后测试欢拓功能是否正常，有问题请联系[尚直播技术人员 huangyaqing@sunlands.com](huangyaqing@sunlands.com)

## 3.使用方法

  ### - 环境配置，在调用初始化方法之前配置

  ```objective-c
  //SDLiveConfigDevelop 开发环境【内部环境】
  //SDLiveConfigQA 测试环境
  //SDLiveConfigProduct 生产环境
  [SDLiveManager setConfigType:SDLiveConfigProduct];
  ```

  ### - 初始化

```objective-c
//初始化环境
[SDLiveManager setConfigType:SDLiveConfigProduct];
//初始化登录实例
SDLiveLoginInfoModel* model =  [[SDLiveLoginInfoModel alloc] init];
model.roomId = 1010;
model.userId = @"userId";
model.userRole = SDLiveUserRoleStudent;
model.userName = @"jack";
model.partnerId = @"partnerId";
model.terminalType = SDLiveClientIOSType;
model.ts = ceil([[NSDate date] timeIntervalSince1970]);
model.userAvatar = @"headUrl";
model.sign = @"xxxxxx";

//初始化直播Manager，如果是点播，则传入SDLiveVideoType
self.liveManager = [[SDLiveManager alloc] initLiveWith:model type:SDVideoLiveType]; 
//配置直播代理
self.liveManager.delegate = self;
//配置弹幕代理
self.liveManager.imDelegate = self;
//对播放器进行布局
[self.view addSubview:self.liveManager.playerView];
//对课件进行布局
[self.view addSubview:self.liveManager.pageView];
 
//播放
[self.liveManager play];
```

### - 基础功能
   
 发送弹幕【直播】

  ```objective-c
  [self.liveManager sendMessage: @"hello,world!"];
  ```
   
  暂停播放【点播】

  ```objective-c
  [self.liveManager pause];
  ```
  
  继续播放【点播】

  ```objective-c
  [self.liveManager resume];
  ```
    
  停止播放，停止之后，无法恢复播放，会释放相关的内存
  一般情况下，在控制器销毁的时候，不用调用该方法
  在SDLiveManager的dealloc方法里，内部会调用该方法

  ```objective-c
  [self.liveManager stop];
  ```
 
  拖拽播放，内部会对time做floor(time)处理，比如上次播放到10s了，这次需要继续在10s处播放【点播】

  ```objective-c
  [self.liveManager dragTo:10];
  ```

  调整倍速，点播下可用【点播】
  
  ```objective-c
  self.liveManager.playSpeed = 1.5;
  ```

### - 主要的直播间代理回调方法`SDLiveManagerDelegate`

```objective-c
/**
 时间回调

 @param manager
 @param duration 视频总时长
 @param currentPlayTime 当前播放时长
 @param cachedDuration 已缓存的视频时长
 */
- (void)manager:(SDLiveManager*)manager
       duration:(NSTimeInterval)duration
currentPlayTime:(NSTimeInterval)currentPlayTime
cacheVideoDuration:(NSTimeInterval)cachedDuration;

/**
 播放器状态回调

 @param manager
 @param state 状态，包括暂停、加载、播放等状态
 */
- (void)manager:(SDLiveManager*)manager
      playState:(SDLiveMoviePlaybackState)state;
 
/**
 房间信息回调

 @param manager
 @param roomInfo 房间信息类，包含房间名称、老师名称等信息
 */
- (void)manager:(SDLiveManager*)manager
       roomInfo:(SDLiveRoomInfo*)roomInfo;
       
/**
 直播间事件回调

 @param manager
 @param event 事件，【开始直播、结束直播、暂停直播、恢复直播】
 @param message 附加信息
 */
- (void)managerLiveEventOccur:(SDLiveManager*)manager
                        event:(SDLiveRoomEvent)event
                      message:(NSString*)message;

/**
 直播间异常回调

 @param manager
 @param error 错误对象，userInfo里为附加信息
 */
- (void)manager:(SDLiveManager*)manager
        onError:(NSError*)error;
```

### - 主要的弹幕代理回调方法`SDLiveIMDelegate`
```objective-c
/**
 收到服务端发来的新消息
 
 @param messages 消息列表
 */
-(void)didReceiveMessageList:(NSArray<SDLiveIMMessageModel*>*)messages;

/**
 聊天室登录成功，返回基本的聊天室信息，如登录人员信息、禁言状态、聊天室人数、登录token等
 用户登录之后会返回部分之前的消息
 当app长链接断开重连的时候，也会调用该方法，所以需要注意登录返回的消息会重复。
 
 @param model SDLiveIMChatRoomModel
 */
-(void)didLogin:(SDLiveIMChatRoomModel*)model
    MessageList:(NSArray<SDLiveIMMessageModel*>*)messages;

/**
 消息发送成功，返回发送成功的消息

 @param message 聊天消息数据
 */
-(void)didSendMessage:(SDLiveIMMessageModel*)message;

/**
 用户批量下线通知，聊天人数变更

 @param number 剩余聊天人数
 */
- (void)didChatRoomBatchOffline:(NSInteger)number;
  
/**
 用户进入、退出聊天室回调，会返回聊天室当前人数、以及退出用户的信息

 @param event SDLiveIMChatRoomEvent
 */
- (void)didRoomUserEvent:(SDLiveIMChatRoomEvent*)event;

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
```

