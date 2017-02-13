//
//  NSString_Truncation.h
//  VPKit
//
//  Created by jonathan on 08/09/2016.
//  Copyright © 2016 jonathan. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSString (VPK_Truncation)
- (NSString*)truncatedString:(NSInteger)maxLength ellipsis:(BOOL)ellipsis;

- (NSString*)tuncatedWordString:(NSInteger)maxLength ellipsis:(BOOL)ellipsis;

@end
