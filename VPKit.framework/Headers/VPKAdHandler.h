//
//  VPKAdHandler.h
//  VPKit
//
//  Created by jonathan on 19/01/2021.
//  Copyright © 2021 jonathan. All rights reserved.
//

#ifndef VPKAdHandler_h
#define VPKAdHandler_h

@import UIKit;
/**
Protocol for handling pre-roll video advertising
 */
@protocol VPKAdHandler

/**
 Implement this method to provide view, controller and completion block to an advertising handler

 @param     view          The view on top of which an advertising videoPlayer should be placed, using the same frame.
 @param     controller    The parent viewController for the `view`. This is the viewController that must be used
                          to present an in-app browser for click-through ad content
 @param     completion    the completion function that must be called when ad handler is finished

 */

- (void)handlePrerollOnView:(UIView*)view viewController:(UIViewController*)controller completion:(void(^)(void))completion;

/**
 Implement this method to clean up interrupted ad handling
 */

- (void)stopPreroll;

@end

#endif /* VPKAdHandler_h */
