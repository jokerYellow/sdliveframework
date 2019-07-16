//
//  SDLiveDownloadManager.h
//  SDLiveProject
//
//  Created by HuangYaqing on 2018/11/26.
//

#import <Foundation/Foundation.h>

@class SDLiveDownloadManager;
@class SDLiveDownloadItem;


/**
 下载状态

 - SDLiveDownloadStatusUnStart: 未开始
 - SDLiveDownloadStatusDownloading: 下载中
 - SDLiveDownloadStatusPause: 暂停
 - SDLiveDownloadStatusFinish: 下载完成
 - SDLiveDownloadStatusError: 下载失败
 */
typedef enum : NSUInteger {
    SDLiveDownloadStatusUnStart = 0,
    SDLiveDownloadStatusDownloading = 1,
    SDLiveDownloadStatusPause = 2,
    SDLiveDownloadStatusFinish = 3,
    SDLiveDownloadStatusError = 4,
    SDLiveDownloadStatusUnknown = 5
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

@protocol SDLiveDownloadManagerDelegate <NSObject>

- (void)downloadManager:(SDLiveDownloadManager *_Nonnull)manager
                   item:(SDLiveDownloadItem *_Nonnull)item
    authorizationFailed:(NSError *_Nullable)error;

- (void)downloadManager:(SDLiveDownloadManager *_Nonnull)manager
      beginDownloadItem:(SDLiveDownloadItem *_Nonnull)item;

- (void)downloadManager:(SDLiveDownloadManager *_Nonnull)manager
                   item:(SDLiveDownloadItem *_Nonnull)item
           StatusChange:(SDLiveDownloadStatus)status;

- (void)downloadManager:(SDLiveDownloadManager *_Nonnull)manager
                   item:(SDLiveDownloadItem *_Nonnull)item
         progressChange:(NSInteger)downloadSize
              totalSize:(NSInteger)totalSize;

- (void)downloadManager:(SDLiveDownloadManager *_Nonnull)manager
                   item:(SDLiveDownloadItem *_Nonnull)item
          errorOccurred:(NSError *_Nullable)error;

- (void)downloadManager:(SDLiveDownloadManager *_Nonnull)manager
                   item:(SDLiveDownloadItem *_Nonnull)item
               complete:(NSError *_Nullable)error;

- (void)downloadManager:(SDLiveDownloadManager *_Nonnull)manager
          didDeleteItem: (SDLiveDownloadItem *)item
               complete: (NSError *_Nullable)error;

@end

NS_ASSUME_NONNULL_BEGIN

@interface SDLiveDownloadManager : NSObject

@property(nonatomic, weak) id <SDLiveDownloadManagerDelegate> delegate;

+ (instancetype)shared;

/*下载Item*/
- (void)downloadItem:(SDLiveDownloadItem *)item withToken: (NSString *)token andChannelCode:(NSString*)channelCode;

/*暂停某个下载*/
- (void)pauseItem:(SDLiveDownloadItem *)item;

/*删除对应的下载*/
- (void)deleteItem:(SDLiveDownloadItem *)item;

/*获取下载列表*/
- (NSArray<SDLiveDownloadItem *> *)getDownloadList;

@end

NS_ASSUME_NONNULL_END
