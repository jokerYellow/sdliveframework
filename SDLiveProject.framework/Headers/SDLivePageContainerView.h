//
//  SDLivePageContainerView.h
//  SDLiveProject
//
//  Created by HuangYaqing on 2018/9/19.
//

#import <UIKit/UIKit.h>

@protocol SDLivePageViewDelegate;

@class SDLiveScrollModel;
@class SDLivePageView;

@interface SDLivePageContainerView : UIView<SDLivePageViewDelegate>

-(void)scroll:(SDLiveScrollModel*)model;

-(void)addPageView:(SDLivePageView*)pageView;

@end
