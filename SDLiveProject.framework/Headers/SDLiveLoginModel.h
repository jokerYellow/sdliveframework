//
//  SDLiveLoginModel.h
//  Pods-SDLiveProject_Example
//
//  Created by HuangYaqing on 2018/6/22.
//

#import <Foundation/Foundation.h>
#import "SDLiveDefine.h"
/*
 @{@"iUserId":@18,
 @"iRoomId":@2,
 @"sToken":@"1hasghabs",
 @"sDeviceId":@"hyq-device-iOS",
 @"iClientType":@0,
 @"sUserName":@"hyq22",
 @"sPassword":@"123"
 };
 */
@interface SDLiveLoginModel : NSObject
@property (nonatomic,copy) NSString* sCode;
@property (nonatomic,copy) NSString* sToken;
@property (nonatomic,assign) NSInteger sLiveId;
@property (nonatomic,assign) SDVideoType loginType;
@property (nonatomic,copy) NSString* sChannelCode;

+(SDLiveLoginModel*)modelWithsCode:(NSString*)sCode sToken:(NSString*)sToken;
+(SDLiveLoginModel*)modelWithsLiveId:(NSInteger)sliveId sToken:(NSString*)sToken;

- (NSDictionary*)dicValue;
@end
