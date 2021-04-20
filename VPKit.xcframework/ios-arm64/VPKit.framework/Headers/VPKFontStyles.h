//
//  VPKFontStyles.h
//  Pods
//
//  Created by jonathan on 31/05/2016.
//
//

#import <UIKit/UIKit.h>


/**
 VPKit font styles are set and adjusted here.
 
 */


@interface VPKFontStyles : NSObject

#pragma mark - fonts for specific widgets

@property (nonatomic, strong) UIFont* barButtonItemFontDisabled;
@property (nonatomic, strong) UIFont* barButtonItemFontEnabled;
@property (nonatomic, strong) UIFont* barButtonItemFont;
@property (nonatomic, strong) UIFont* navBarFont;
@property (nonatomic, strong) UIFont* cellNavBarFont;

@property (nonatomic, strong) UIFont* cellLabelFont;
@property (nonatomic, strong) UIFont* cellTextViewFont;
@property (nonatomic, strong) UIFont* bigLabelFont;

@property (nonatomic, strong) NSString* alertFontTitleName;
@property (nonatomic, strong) NSString* alertFontBodyName;


@end
