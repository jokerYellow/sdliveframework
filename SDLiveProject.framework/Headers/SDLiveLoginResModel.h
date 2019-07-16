//
//  SDLiveLoginResModel.h
//  SDLiveProject
//
//  Created by HuangYaqing on 2019/3/28.
//

#import <Foundation/Foundation.h>
#import "SDLiveRoomInfo.h"
/*
 struct LoginRes
 {
 1 optional int iCode; // 登陆结果
 2 optional RoomInfo roomInfo;
 3 optional string sIcon; // 图像
 4 optional int iSex; // 性别
 5 optional long lSequence; // 教师端校准时间
 6 optional int iTraceId; // 教师端traceid起始值
 7 optional string sUserName; // 用户名
 8 optional string sConstraints; // 老师端用来保存限制条件的
 9 optional int iUserId; // 用户ID，无用户信息的为0
 10 optional int iDuration;  // 直播时长，单位秒
 };
 */
@class SDLiveRoomInfo;
@interface SDLiveLoginResModel : NSObject
@property (nonatomic,assign) NSInteger iCode;
@property (nonatomic,strong) SDLiveRoomInfo* roomInfo;
@property (nonatomic,copy) NSString* sIcon;
@property (nonatomic,assign) NSInteger iSex;
@property (nonatomic,assign) SDLiveNumber lSequence;
@property (nonatomic,copy) NSString* sUserName;
@property (nonatomic,copy) NSString* sConstraints;
@property (nonatomic,assign) NSInteger iUserId;
@property (nonatomic,assign) NSInteger iDuration;
@end
