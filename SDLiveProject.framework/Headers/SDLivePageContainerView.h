//
//  SDLivePageContainerView.h
//  SDLiveProject
//
//  Created by HuangYaqing on 2018/9/19.
//

#import <UIKit/UIKit.h>

@class SDLiveScrollModel;
@class SDLivePageView;
@protocol SDLivePageViewDelegate;

@interface SDLivePageContainerView : UIView<SDLivePageViewDelegate>
-(void)scroll:(SDLiveScrollModel*)model;
-(void)addPageView:(SDLivePageView*)pageView;
@end
