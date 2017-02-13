//  Created by Jason Morrissey

#import <UIKit/UIKit.h>

void UIColor_vpkHex();

@interface UIColor (vpkHex)

+ (UIColor *)vpk_colorWithHex:(long)hexColor;
+ (UIColor *)vpk_colorWithHex:(long)hexColor alpha:(float)opacity;
+ (UIColor *)vpk_colorWithHexString:(NSString*)string;
+ (UIColor *)vpk_colorFromStringRepresentation:(NSString*)string;
- (NSString*)vpk_stringRepresentation;
@end
