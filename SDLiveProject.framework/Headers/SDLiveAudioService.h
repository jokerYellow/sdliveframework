//
//  SDLiveAudioService.h
//  SDLiveProject
//
//  Created by HuangYaqing on 2018/12/7.
//

#import <Foundation/Foundation.h>
@class SDLiveLoginInfoModel;

NS_ASSUME_NONNULL_BEGIN

typedef void(^SDLiveAudioServiceBlock)( NSString* _Nullable downloadUrl,NSInteger fileSize,NSError* _Nullable error);


/**
 下载音频文件的服务类
 */
@interface SDLiveAudioService : NSObject

/**
 下载音频文件

 @param token 客户端传入token，与SDLiveManager类似
 @param liveId 传入直播liveId
 @param channelCode 频道码
 @param complete 返回（downloadUrl，fileSize，error）
 */
- (BOOL)requestAudioInfomationWithToken:(NSString*)token
                              andLiveId:(NSString*)liveId
                            channelCode:(NSString*)channelCode
                               complete:(SDLiveAudioServiceBlock)complete;

/**
 下载平台化音频文件

 @param model SDLiveLoginInfoModel 平台化参数
 @param complete 返回（downloadUrl，fileSize，error）
 @return 操作成功或失败
 */

- (BOOL)requestAudioInfomationWithPlatInfo:(SDLiveLoginInfoModel *)model
                                  complete:(SDLiveAudioServiceBlock)complete;
@end

NS_ASSUME_NONNULL_END
