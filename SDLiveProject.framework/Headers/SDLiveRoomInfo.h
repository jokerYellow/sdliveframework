//
//  SDLiveRoomInfo.h
//  SDLiveProject
//
//  Created by HuangYaqing on 2018/6/22.
//

#import <Foundation/Foundation.h>
#import "SDLiveManager.h"

@class SDLivePage;
@class SDLivePlayUrlInfo;

/*
 struct RoomInfo
 {
 1 optional string sName;
 2 optional string sTeacher;
 3 optional long lBeginTime;
 4 optional long lEndTime;
 5 optional int iUserCount;
 6 optional vector<string> streamPushUrls;
 7 optional vector<string> streamPullUrls;
 8 optional Page page; // 当前展示的课件信息
 9 optional int iRoomId;//当前房间ID
 10 optional int iStatus;//2表示上课中
 };
 */

/**
 登录直播间之后，获取到的房间以及用户信息
 */
@interface SDLiveRoomInfo : NSObject

/**
 房间名称
 */
@property (nonatomic,copy) NSString* sName;

/**
 老师名称
 */
@property (nonatomic,copy) NSString* sTeacher;

/**
 开始事件
 */
@property (nonatomic,assign) SDLiveNumber lBeginTime;

/**
 结束时间
 */
@property (nonatomic,assign) SDLiveNumber lEndTime;

/**
 用户Count
 */
@property (nonatomic,assign) SDLiveNumber iUserCount;
@property (nonatomic,copy) NSArray<SDLivePlayUrlInfo*>* streamPullUrls;
@property (nonatomic,assign) SDLiveNumber iRoomId;
@property (nonatomic,assign) SDLiveNumber iImId;
@property (nonatomic,assign) SDLiveRoomStatus iStatus;// 1表示未开始，2表示上课中，3表示暂停，4表示已结束
@property (nonatomic,strong) SDLivePage* page;
@end
