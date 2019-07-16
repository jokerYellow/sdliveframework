//
//  SDLivePaperModel.h
//  SDLiveProject
//
//  Created by HuangYaqing on 2018/11/19.
//

#import <Foundation/Foundation.h>
#import "SDLiveDefine.h"
/**
 随堂考类
 */
@interface SDLivePaperModel : NSObject

/**
 随堂考ID
 */
@property (nonatomic,assign) SDLiveNumber iPaperId;

/**
 随堂考发生的时间戳
 */
@property (nonatomic,assign) NSTimeInterval lSequence;
@end

