//
//  SDLiveIMChatRoomModel.h
//  SDLiveProject
//
//  Created by HuangYaqing on 2018/9/3.
//

#import <Foundation/Foundation.h>
#import "SDLiveDefine.h"

@class SDLiveIMMessageModel;

@interface SDLiveIMChatRoomModel : NSObject

/**
 登录者token
 */
@property(nonatomic,copy) NSString* userToken;

/**
 唯一的房间Id
 */
@property(nonatomic,assign) SDLiveNumber liveId;

/**
 聊天室人数
 */
@property(nonatomic,assign) SDLiveNumber number;

/**
 房间禁言状态，0：不禁言，1：禁言
 */
@property(nonatomic,assign) NSInteger forbiddenStatus;

/**
 类型:Number 说明:房间个人禁言状态，0：不禁言，1：禁言
 */
@property(nonatomic,assign) NSInteger forbiddenStatusSingle;

/**
 登陆者姓名
 */
@property(nonatomic,copy) NSString* name;

/**
 登陆者头像
 */
@property(nonatomic,copy) NSString* portriat;


/**
 消息数组
 */
@property (nonatomic,copy) NSArray<SDLiveIMMessageModel*>* messageData;

@end
