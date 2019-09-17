//
//  SDLiveLog.h
//  SDLiveProject
//
//  Created by HuangYaqing on 2018/7/8.
//

#import <Foundation/Foundation.h>

#define SDLiveDebugLog(...) SDLiveLogEventDebug([NSString stringWithFormat:@"%@:(%d) %@\n", [[NSString stringWithUTF8String:__FILE__] lastPathComponent], __LINE__, [NSString stringWithFormat:__VA_ARGS__] ])

#define SDLiveLogEvent(...) SDLiveDebugLog(__VA_ARGS__)

void SDLiveLogEventDebug(NSString* event);

/**
 直播日志钩子，可以由上层自己处理
 */
@protocol SDLiveLogger <NSObject>

- (void)logEvent:(NSString *)event;
@end

@interface SDLiveLog : NSObject

+ (void)addLogger:(id<SDLiveLogger>)logger;

/**
 Debug情况下开启日志，默认开启

 @param enable 是否开启日志
 */
+ (void)setLogEnable:(BOOL)enable;

+(void)logEvent:(NSString*)event;

+(void)logPrintEvent:(NSString*)event;
@end
