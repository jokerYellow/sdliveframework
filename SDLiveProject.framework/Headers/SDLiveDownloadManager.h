//
//  SDLiveDownloadManager.h
//  SDLiveProject
//
//  Created by HuangYaqing on 2018/11/26.
//

#import <Foundation/Foundation.h>

@class SDLiveDownloadManager;
@class SDLiveDownloadItem;
@class SDLiveLoginInfoModel;

static NSString * const _Nonnull  SunliveDownloadIdentifier = @"com.sunlive.download";

static NSErrorDomain const _Nonnull SDLiveDownloadErrorDomain = @"com.sunland.live.sdk.download";


//SDLiveDownloadErrorDomain error code
typedef enum : NSUInteger {
    
    SUNLAND_SDK_DOWNLOAD_LIVE_ERROR_JSON = 9001,
    SUNLAND_SDK_DOWNLOAD_LIVE_NULL_JSON  = 9002,
    
//下载初始化错误---开始
    SUNLAND_SDK_DOWNLOAD_LIVE_IS_DOWNLOADING = 9003,//正在下载
    SUNLAND_SDK_DOWNLOAD_LIVE_ALREADY_DOWNLOADED = 9004,//已经下载完毕
    SUNLAND_SDK_DOWNLOAD_LIVE_PARAM_INVALID = 9005,//初始化传入参数缺失
    SUNLAND_SDK_DOWNLOAD_LIVE_SERVER_ERROR = 9006,//初始化传入参数缺失
//下载初始化错误---结束
    
} SUNLAND_SDK_DOWNLOAD_LIVE_ERROR;


/**
 下载状态

 - SDLiveDownloadStatusUnStart: 未开始
 - SDLiveDownloadStatusDownloading: 下载中
 - SDLiveDownloadStatusPause: 暂停
 - SDLiveDownloadStatusFinish: 下载完成
 - SDLiveDownloadStatusStop: 被停止
 - SDLiveDownloadStatusError: 下载失败
 */
typedef enum : NSUInteger {
    SDLiveDownloadStatusUnStart = 0,
    SDLiveDownloadStatusDownloading = 1,
    SDLiveDownloadStatusPause = 2,
    SDLiveDownloadStatusFinish = 3,
    SDLiveDownloadStatusError = 4,
    SDLiveDownloadStatusUnknown = 5,
    SDLiveDownloadStatusStop = 6,
} SDLiveDownloadStatus;


typedef enum : NSUInteger {
    SDLiveDownloadDeleteResultDidNotFound = 0,
    SDLiveDownloadDeleteResultSuccess = 1,
    SDLiveDownloadDeleteResultOther = 2,
} SDLiveDownloadDeleteResult;

typedef enum : NSUInteger {
    SDLiveDownloadDidDownload = 0,
    SDLiveDownloadDownload = 1,
} SDLiveDownloadResult;

typedef enum : NSUInteger {
    SDLiveDownloadErrorNotValidDownloadUrl = 0,
} SDLiveDownloadError;

/**
 下载代理
 */
@protocol SDLiveDownloadManagerDelegate <NSObject>
 
/// 下载认证失败
/// @param manager
/// @param roomId 直播间ID
/// @param error 错误信息
- (void)downloadManager:(SDLiveDownloadManager *_Nonnull)manager
                   roomId:(NSInteger)roomId
    authorizationFailed:(NSError *_Nullable)error;

/// 开始下载
/// @param manager
/// @param roomId 直播间ID
- (void)downloadManager:(SDLiveDownloadManager *_Nonnull)manager
      beginDownloadRoomId:(NSInteger)roomId;
  
/// 下载进度变化
/// @param manager SDLiveDownloadManager
/// @param roomId 直播间ID
/// @param downloadSize 已经下载的比特数
/// @param totalSize 该直播间总共比特数
- (void)downloadManager:(SDLiveDownloadManager *_Nonnull)manager
                   roomId:(NSInteger)roomId
         progressChange:(NSInteger)downloadSize
              totalSize:(NSInteger)totalSize;

/// 下载过程中发生错误
/// @param manager SDLiveDownloadManager
/// @param roomId 直播间ID
/// @param error 错误信息
- (void)downloadManager:(SDLiveDownloadManager *_Nonnull)manager
                   roomId:(NSInteger)roomId
          errorOccurred:(NSError *_Nullable)error;
  
/// 下载完成
/// @param manager SDLiveDownloadManager
/// @param roomId 直播间ID
/// @param error 下载完成时可能出现的错误信息
- (void)downloadManager:(SDLiveDownloadManager *_Nonnull)manager
                   roomId:(NSInteger)roomId
               complete:(NSError *_Nullable)error;
@end

NS_ASSUME_NONNULL_BEGIN

@interface SDLiveDownloadManager : NSObject

@property(nonatomic, weak) id <SDLiveDownloadManagerDelegate> delegate;

+ (instancetype)shared;

/// 尚直播下载方法
/// 下载直播间视频，如果该直播间正在下载中，或者已经下载完毕，或者传入参数错误，则会返回错误
/// @param roomId 直播间ID
/// @param token token
/// @param channelCode channelCode
- (NSError*)downloadWith:(NSInteger )roomId
           withToken: (NSString *_Nullable)token
          andChannelCode:(NSString*_Nullable)channelCode;

/// 平台化下载方法
/// 下载直播间视频，如果该直播间正在下载中，或者已经下载完毕，或者传入参数错误，则会返回错误
/// @param model SDLiveLoginInfoModel
- (NSError*)downloadWithPlatInfo:(SDLiveLoginInfoModel *)model;
  
/// 暂停下载，如传入的roomId不在下载列表里，不会做任何操作；
/// 对下载已经完毕或者被暂停不生效
/// @param roomId 直播间ID
- (void)pauseWithRoomId:(NSInteger)roomId;

/// 恢复下载，如传入的roomId不在下载列表里，不会做任何操作
/// 对下载已经完毕或者被暂停不生效
/// @param roomId 直播间ID
- (void)resumeWithRoomId:(NSInteger)roomId;

/// 停止下载，如传入的roomId不在下载列表里，不会做任何操作
/// @param roomId 直播间ID
- (void)stopWithRoomId:(NSInteger )roomId;
 
/// 删除某个已经完成的下载，可用于清除缓存，如传入的roomId不在下载列表里，不会做任何操作
/// 仅对下载完毕的下载项生效
/// @param roomId 直播间ID
- (void)removeCachesWithRoomId:(NSInteger )roomId;
 
/// 获取下载列表
- (NSArray<SDLiveDownloadItem *> *)getDownloadList;


///  在APPDelegate下的回调 handleEventsForBackgroundURLSession 里添加该方法。
///  在后台下载完成，app在后台的情况下会触发该回调。
///
/// - (void)application:(UIApplication *)application handleEventsForBackgroundURLSession:(NSString *)identifier completionHandler:(void (^)(void))completionHandler{
///    [[SDLiveDownloadManager shared] handleEventsForBackgroundURLSession:identifier completionHandler:completionHandler];
/// }
/// @param identifier The identifier of the URL session requiring attention. If your app was just launched, you can use this identifier to create a new NSURLSession object that can receive the events.
/// @param completionHandler The completion handler to call when you finish processing the events. Calling this completion handler lets the system know that your app’s user interface is updated and a new snapshot can be taken.
-(void)handleEventsForBackgroundURLSession:(NSString *)identifier completionHandler:(void (^)(void))completionHandler;
@end

NS_ASSUME_NONNULL_END
