//
//  SDLiveIMChatRoomEvent.h
//  SDLiveProject
//
//  Created by HuangYaqing on 2018/9/3.
//

#import <Foundation/Foundation.h>

/**
 时间

 - SDLiveIMChatRoomEventEnter: 进入
 - SDLiveIMChatRoomEventLeave: 退出
 - SDLiveIMChatRoomEventUnknown: 未知
 */
typedef NS_ENUM(NSUInteger, SDLiveIMChatRoomEventType) {
    SDLiveIMChatRoomEventEnter = 1,
    SDLiveIMChatRoomEventLeave = 2,
    SDLiveIMChatRoomEventUnknown = 1000,
};

@interface SDLiveIMChatRoomEvent : NSObject

/**
 唯一的房间Id
 */
@property (nonatomic,assign) NSInteger liveId;

/**
 聊天室人数
 */
@property (nonatomic,assign) NSInteger number;

/**
 1:进入  2:退出
 */
@property (nonatomic,assign) SDLiveIMChatRoomEventType status;

/**
 变化的用户名字
 */
@property (nonatomic,copy) NSString* cname;

/**
 变化的用户头像地址
 */
@property (nonatomic,copy) NSString* cportrait;
@end
