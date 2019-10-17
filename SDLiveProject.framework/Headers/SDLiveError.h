//
//  SDLiveError.h
//  SDLiveProject
//
//  Created by HuangYaqing on 2018/7/8.
//

#import <Foundation/Foundation.h>
#import "SDLiveDefine.h"

@interface SDLiveError : NSObject

/**
 错误码，参照 SDLiveServerErrorCode 枚举
 */
@property(nonatomic,assign) SDLiveServerErrorCode iCode;

/**
 对该错误应该如何处理，参照 SDLiveSocketError
 http://172.16.116.49:9982/view/ErrorCode.tars
 */
@property(nonatomic,assign) SDLiveSocketError operation;

/**
 错误描述信息
 */
@property(nonatomic,copy) NSString* sError;
@end
