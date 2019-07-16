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

@interface SDLiveDownloadItem : NSObject
@property (nonatomic, copy) NSString *title;
@property (nonatomic, assign) NSInteger liveId;

@property (nonatomic, assign) SDLiveDownloadStatus status;

@property (nonatomic, assign) NSInteger downloadedSize;

@property (nonatomic, assign) NSInteger totalSize;

@property(nonatomic, copy, readonly) NSString *storedPath;
@property(nonatomic, copy, readonly) NSString *configurationPath;
@property(nonatomic, copy, readonly) NSString *messagesPath;

- (instancetype)initWithLiveId:(NSInteger)liveId title:(NSString *)title;

+ (instancetype)itemWithLiveId: (NSInteger)liveId title: (NSString *)title;

- (BOOL)save;

-(NSString*)pathOfRequestUrl:(NSString*)url;
@end

NS_ASSUME_NONNULL_END
