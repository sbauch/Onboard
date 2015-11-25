//
//  OnboardingContentViewController.h
//  Onboard
//
//  Created by Mike on 8/17/14.
//  Copyright (c) 2014 Mike Amaral. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "FLAnimatedImageView.h"
@import MediaPlayer;

@class OnboardingViewController;

typedef void (^action_callback)(OnboardingViewController *onboardController);

@interface OnboardingContentViewController : UIViewController {
    NSString *_titleText;
    NSString *_body;
    NSString *_buttonText;
    
    UIImageView *_imageView;
    UILabel *_mainTextLabel;
    UILabel *_subTextLabel;
    UIButton *_actionButton;
    
    FLAnimatedImageView *_animatedImageView;
    NSData *_imageData;
}

@property (nonatomic) OnboardingViewController *delegate;

@property (nonatomic) BOOL movesToNextViewController;

@property (nonatomic) CGFloat iconHeight;
@property (nonatomic) CGFloat iconWidth;

@property (nonatomic, strong) UIColor *titleTextColor;
@property (nonatomic, strong) UIColor *bodyTextColor;
@property (nonatomic, strong) UIColor *buttonTextColor;

@property (nonatomic, strong) NSString *titleFontName;
@property (nonatomic) CGFloat titleFontSize;

@property (nonatomic, strong) NSString *bodyFontName;
@property (nonatomic) CGFloat bodyFontSize;

@property (nonatomic, strong) NSString *buttonFontName;
@property (nonatomic) CGFloat buttonFontSize;

@property (nonatomic) CGFloat topPadding;
@property (nonatomic) CGFloat underIconPadding;
@property (nonatomic) CGFloat underTitlePadding;
@property (nonatomic) CGFloat bottomPadding;
@property (nonatomic) CGFloat underPageControlPadding;

@property (nonatomic, copy) action_callback buttonActionHandler;

@property (nonatomic, copy) dispatch_block_t viewWillAppearBlock;
@property (nonatomic, copy) dispatch_block_t viewDidAppearBlock;
@property (nonatomic, copy) dispatch_block_t viewWillDisappearBlock;
@property (nonatomic, copy) dispatch_block_t viewDidDisappearBlock;

//Creates the content view using ImageData
+ (instancetype)contentWithTitle:(NSString *)title body:(NSString *)body imageData:(NSData *)imageData buttonText:(NSString *)buttonText action:(dispatch_block_t)action;
- (instancetype)initWithTitle:(NSString *)title body:(NSString *)body imageData:(NSData *)imageData buttonText:(NSString *)buttonText action:(dispatch_block_t)action;
+ (instancetype)contentWithTitle:(NSString *)title body:(NSString *)body imageData:(NSData *)imageData buttonText:(NSString *)buttonText actionBlock:(action_callback)actionBlock;

//Creates the content view using an UIImage
+ (instancetype)contentWithTitle:(NSString *)title body:(NSString *)body image:(UIImage *)image buttonText:(NSString *)buttonText action:(dispatch_block_t)action;
- (instancetype)initWithTitle:(NSString *)title body:(NSString *)body image:(UIImage *)image buttonText:(NSString *)buttonText action:(dispatch_block_t)action;
+ (instancetype)contentWithTitle:(NSString *)title body:(NSString *)body image:(UIImage *)image buttonText:(NSString *)buttonText actionBlock:(action_callback)actionBlock;

//Creates the content view using a videoURL
+ (instancetype)contentWithTitle:(NSString *)title body:(NSString *)body videoURL:(NSURL *)videoURL buttonText:(NSString *)buttonText action:(dispatch_block_t)action;
- (instancetype)initWithTitle:(NSString *)title body:(NSString *)body videoURL:(NSURL *)videoURL  buttonText:(NSString *)buttonText action:(dispatch_block_t)action;
+ (instancetype)contentWithTitle:(NSString *)title body:(NSString *)body videoURL:(NSURL *)videoURL  buttonText:(NSString *)buttonText actionBlock:(action_callback)actionBlock;

//Creates the content view using ImageData and/or a videoURL
- (instancetype)initWithTitle:(NSString *)title body:(NSString *)body imageData:(NSData *)imageData buttonText:(NSString *)buttonText actionBlock:(action_callback)actionBlock;
- (instancetype)initWithTitle:(NSString *)title body:(NSString *)body imageData:(NSData *)imageData videoURL:videoURL buttonText:(NSString *)buttonText actionBlock:(action_callback)actionBlock;

- (void)updateAlphas:(CGFloat)newAlpha;

@end
