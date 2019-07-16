//
//  SDLiveIMMessageModel.h
//  SDLiveProject
//
//  Created by HuangYaqing on 2018/9/3.
//

#import <Foundation/Foundation.h>

/**
 点播IM消息对象
 */
@interface SDLiveIMMessageModel : NSObject

/**
 消息id，每个直播存放在一个表内，在该表内唯一，但不是全局唯一id
 */
@property (nonatomic,assign) NSInteger message_id;

/**
 消息发送者imid
 */
@property (nonatomic,assign) NSInteger sender_id;

/**
 字符串类型的消息发送者ID,平台化使用
 */
@property (nonatomic,copy) NSString* send_id_str;
/**
 消息发送者token
 */
@property (nonatomic,copy) NSString* fromUserToken;
/**
 消息发送者姓名或者昵称，老师显示真实名字，学生显示昵称
 */
@property (nonatomic,copy) NSString* user_name;

/**
 消息发送者身份 1： 学生 2： 老师  3： 助教"
 */
@property (nonatomic,assign) NSInteger user_identity;

/**
 消息发送者头像
 */
@property (nonatomic,copy) NSString *user_portrait;

/**
 消息类型 1. 文本 2: 广播消息 3： 礼物",
 */
@property (nonatomic,assign) NSInteger message_type;

/**
 消息内容
 */
@property (nonatomic,copy) NSString *message_content;

/**
 消息发送时间戳
 */
@property (nonatomic,assign) NSTimeInterval message_ts;

/**
 是否是敏感词（1： 正常消息 2： 敏感词）
 */
@property (nonatomic,assign) NSInteger display_mode;

/**
 唯一的房间Id
 */
@property (nonatomic,assign) NSInteger liveId;

/**
 是否本人发送
 */
@property (nonatomic,assign) Boolean isSelf;



@end
