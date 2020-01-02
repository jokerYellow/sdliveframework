//
//  SDLiveEnvironment.h
//  SDLiveProject
//
//  Created by HuangYaqing on 2018/9/20.
//

#import <Foundation/Foundation.h>

//IM websocket地址
//extern NSString* const kSDIMSocketUrl;
//IM获取的头像前缀
//extern NSString* const kSDHeadPrefix;

//extern NSString* const kSD_http_video_host;

//#define kSD_video_auth_url_login [NSString stringWithFormat:@"%@%@",kSD_http_video_host,@"/video/login"]
//#define kSD_video_auth_url_getpage [NSString stringWithFormat:@"%@%@",kSD_http_video_host,@"/video/getpage"]
//#define kSD_video_auth_url_heartbeat [NSString stringWithFormat:@"%@%@",kSD_http_video_host,@"/video/heartbeat"]
//#define kSD_video_auth_url_getincrmsg [NSString stringWithFormat:@"%@%@",kSD_http_video_host,@"/video/getincrmsg"]


@protocol SDLiveEnvironmentProtocol <NSObject>
//平台化
//平台化直播websocket连接地址
@property (nonatomic, copy, readonly) NSString *liveSockerUrl;
@property (nonatomic, copy, readonly) NSString *recordLoginUrl;

//平台化-第三方点播离线播放获取全量数据
@property(nonatomic, copy, readonly) NSString* thirdHttpVideoGetFullMsg;
//第三方获取音频数据
@property(nonatomic, copy, readonly) NSString* thirdHttpVideoHostGetmedia;

//直播认证地址
@property(nonatomic,copy,readonly) NSString* authLiveHost;

//点播认证地址
@property(nonatomic,copy,readonly) NSString* authVideoHost;
//点播host
@property(nonatomic,copy,readonly) NSString* httpVideoHost;
//点播登录地址
@property(nonatomic,copy,readonly) NSString* httpVideoHostLogin;
//点播获取页面信息地址
@property(nonatomic,copy,readonly) NSString* httpVideoHostGetpage;
//点播心跳地址
@property(nonatomic,copy,readonly) NSString* httpVideoHostHeartBeat;
//点播获取事件流地址
@property(nonatomic,copy,readonly) NSString* httpVideoHostGetIncreaseMessage;

//获取音频地址
@property(nonatomic,copy,readonly) NSString* httpVideoHostGetmedia;
//离线下载获取全量信息
@property(nonatomic,copy,readonly) NSString* httpVideoGetFullMsg;
//埋点url
@property(nonatomic,copy,readonly) NSString* httpBlockUrl;
//IM获取的头像前缀
@property(nonatomic,copy,readonly) NSString* imHeadPrefix;
//IM获取历史消息地址
@property(nonatomic,copy,readonly) NSString* imHistoryMessageHost;
//IM websocket地址
@property(nonatomic,copy,readonly) NSString* imSocketUrl;
@end

@interface SDLiveEnvironment: NSObject<SDLiveEnvironmentProtocol>{
    
}
+(SDLiveEnvironment*)devEnv;
+(SDLiveEnvironment*)qaEnv;
//生产环境
+(SDLiveEnvironment*)proEnv;
+(SDLiveEnvironment*)proEnvOfHushuos;

/**
 配置环境的便捷方法
 
 @param liveHost 直播域名，如 live.hushuos.com
 @param videoHost 点播域名，如 video.hushuos.com
 @param imHost IM服务域名，如 liveim.hushuos.com
 @return SDLiveEnvironment
 */
+(SDLiveEnvironment*)customEnvWith:(NSString*)liveHost and:(NSString*)videoHost and:(NSString*)imHost;
@end

@interface SDLiveEnvironmentService:NSObject{
    
}
+(instancetype)shared;
//环境参数，默认线上环境
@property(nonatomic,strong) id<SDLiveEnvironmentProtocol> env;
@end
