//
//  SDLiveIMAnnounceModel.h
//  SDLiveProject
//
//  Created by HuangYaqing on 2019/6/27.
//

#import <Foundation/Foundation.h>
#import "SDLiveDefine.h"
NS_ASSUME_NONNULL_BEGIN

@interface SDLiveIMAnnounceModel : NSObject
@property(nonatomic,assign) SDLiveNumber liveId;
@property(nonatomic,copy) NSString* userToken;
/**
 发送者身份 1：学生 2： 老师 3： 助教
 */
@property(nonatomic,assign) NSInteger userIdentity;
@property(nonatomic,copy) NSString* name;
@property(nonatomic,copy) NSString* portrait;
@property(nonatomic,copy) NSString* announce;
@property(nonatomic,assign) NSTimeInterval msgTimestamp;
@end

NS_ASSUME_NONNULL_END
