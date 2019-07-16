//
//  SDLiveLoginInfoModel.h
//  SDLiveProject
//
//  Created by HuangYaqing on 2019/6/18.
//

#import <Foundation/Foundation.h>
#import "SDLiveDefine.h"
NS_ASSUME_NONNULL_BEGIN


/**
 平台化业务方初始化提供的参数类
 */
@interface SDLiveLoginInfoModel : NSObject

/**
 终端类型
 */
@property (nonatomic,assign) SDLiveClientType terminalType;

/**
 根据业务方协商，加密后的签名
 */
@property (nonatomic,copy) NSString* sign;

/**
 合作方ID
 */
@property (nonatomic,assign) SDLiveNumber partnerId;

/**
 直播房间ID
 */
@property (nonatomic,assign) SDLiveNumber roomId;

/**
 第三方账号体系下的用户ID
 */
@property (nonatomic,copy) NSString* userId;

/**
 用户昵称
 */
@property (nonatomic,copy) NSString* userName;

/**
 用户身份 1. 学生 2：老师 5：管理员
 */
@property (nonatomic,assign) SDLiveUserRoleType userRole;

/**
 unix时间戳，当前的秒数
 */
@property (nonatomic,assign) NSTimeInterval ts;

/**
 用户头像url
 */
@property (nonatomic,copy) NSString* userAvatar;
@end

NS_ASSUME_NONNULL_END
