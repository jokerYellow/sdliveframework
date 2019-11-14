//
//  SDLiveDownloadItem.h
//  SDLiveProject
//
//  Created by HuangYaqing on 2018/11/26.
//

#import <Foundation/Foundation.h>
#import "SDLiveDefine.h"
#import "SDLiveDownloadManager.h"
NS_ASSUME_NONNULL_BEGIN
@class SDDownloadTask;
@class SDLiveRoomInfo;
@interface SDLiveDownloadItem : NSObject
#pragma mark public
@property (nonatomic, copy) NSString *title;

@property (nonatomic, assign) NSInteger liveId;

@property (nonatomic, assign) SDLiveDownloadStatus status;

@property (nonatomic,readonly,strong) SDLiveRoomInfo* roomInfo;

@property (nonatomic, assign,readonly) int64_t downloadedSize;

@property (nonatomic, assign,readonly) int64_t totalSize;

@property(nonatomic, copy, readonly) NSString *storedPath;
@property(nonatomic, copy, readonly) NSString *configurationPath;
@property(nonatomic, copy, readonly) NSString *messagesPath;

- (instancetype)initWithLiveId:(NSInteger)liveId title:(NSString *)title;

+ (instancetype)itemWithLiveId:(NSInteger)liveId title: (NSString *)title;

@end

NS_ASSUME_NONNULL_END
