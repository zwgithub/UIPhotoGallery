//
//  UIPhotoGalleryView.h
//  PhotoGallery
//
//  Created by Ethan Nguyen on 5/23/13.
//  Copyright (c) 2013 Ethan Nguyen. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef enum UIPhotoGalleryModeEnum {
    UIPhotoGalleryModeImageLocal = 0,
    UIPhotoGalleryModeImageRemote,
    UIPhotoGalleryModeCustomView
} UIPhotoGalleryMode;

@class UIPhotoGalleryView;

@protocol UIPhotoGalleryDataSource <NSObject>

@required
- (NSInteger)numberOfViewsInPhotoGallery:(UIPhotoGalleryView*)photoGallery;

@optional
- (UIImage*)photoGallery:(UIPhotoGalleryView*)photoGallery localImageAtIndex:(NSInteger)index;
- (NSURL*)photoGallery:(UIPhotoGalleryView*)photoGallery remoteImageURLAtIndex:(NSInteger)index;
- (UIView*)photoGallery:(UIPhotoGalleryView*)photoGallery customViewAtIndex:(NSInteger)index;

@end

@protocol UIPhotoGalleryDelegate <NSObject>

@optional
- (void)photoGallery:(UIPhotoGalleryView*)photoGallery didSingleTapViewAtIndex:(NSInteger)index;
- (void)photoGallery:(UIPhotoGalleryView*)photoGallery didDoubleTapViewAtIndex:(NSInteger)index;

@end

@protocol UIPhotoItemDelegate <NSObject>

@optional
- (void)photoItemDidSingleTapAtIndex:(NSInteger)index;
- (void)photoItemDidDoubleTapAtIndex:(NSInteger)index;

@end

@interface UIPhotoGalleryView : UIView <UIScrollViewDelegate, UIPhotoItemDelegate> {
@private
    UIScrollView *mainScrollView;
    NSMutableSet *reusableViews;
    NSMutableArray *circleScrollViews;
    NSInteger dataSourceNumOfViews;
    NSInteger currentPage;
}

@property (nonatomic, assign) IBOutlet id<UIPhotoGalleryDataSource> dataSource;
@property (nonatomic, assign) IBOutlet id<UIPhotoGalleryDelegate> delegate;

@property (nonatomic, assign) UIPhotoGalleryMode galleryMode;
@property (nonatomic, assign) BOOL circleScroll;
@property (nonatomic, assign) BOOL peakSubView;
@property (nonatomic, assign) BOOL verticalGallery;
@property (nonatomic, assign) CGFloat subviewGap;
@property (nonatomic, assign) NSInteger initialIndex;

@end