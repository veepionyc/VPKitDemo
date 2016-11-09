//
//  NSURL_vpkCleaning.h
//  VPKit
//
//  Created by jonathan on 19/06/2016.
//  Copyright © 2016 jonathan. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface NSString (vpkCleaning)
- (NSString*)vpk_cleanString;
- (NSURL*)vpk_cleanURL;
@end


@interface NSURL (vpkCleaning)

- (NSString*)vpk_cleanString;
- (NSURL*)vpk_cleanURL;
@end
