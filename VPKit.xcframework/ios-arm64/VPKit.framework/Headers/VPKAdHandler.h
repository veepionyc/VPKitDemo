//
//  VPKAdHandler.h
//  VPKit
//
//  Created by jonathan on 19/01/2021.
//  Copyright © 2021 jonathan. All rights reserved.
//

#ifndef VPKAdHandler_h
#define VPKAdHandler_h

#import <UIKit/UIKit.h>

/**
 Protocol for callback object sent to `VPKAdHandler`
 
 @see `VPKAdHandler`

 */
@protocol VPKMediaIdentifier

/**
 Optional string. Readonly. MediaIdentifier is settable as a property on `VPKImage` and `VPKPlayerItem`

 @see `VPKImage`, `VPKPlayerItem`, `VPKAdHandler`
 */
@property (nullable, nonatomic, copy, readonly) NSString* mediaIdentifier;

/**
 Optional dictionary whose keys and values must be strings. Readonly. CustomData is settable as a property on `VPKImage` and `VPKPlayerItemz
 
 @see `VPKImage`, `VPKPlayerItem`, `VPKAdHandler`
 */
@property (nullable, nonatomic, copy, readonly) NSDictionary* customData;


@end

/**
Protocol for handling pre-roll video advertising.

 When an object conforming to this protocol is assigned to a `VPKPreview` or `VPKVeepViewer`, VPKit video content will be loaded and paused to allow the host app to manage preroll advertising.
 
 `view`, `controller` and `completion` objects will be returned to facilitate correct handling and display of prerolls.
 
 When the `completion` block is called, control will return to the SDK to play the requested video content.
 
 Designed for [GoogleAds Interactive Media Ads](https://developers.google.com/interactive-media-ads/docs/sdks/ios/client-side/) requirements.
 */



@protocol VPKAdHandler


/**
 Implement this method to provide view, controller and completion block to an advertising handler.
 
 @param     view          The view on top of which an advertising videoPlayer should be placed, using the same frame.
 @param     controller    The parent viewController for the `view`. This is the viewController that must be used
                          to present an in-app browser for click-through ad content.
 
 @param     identifier    An object conforming to `VPKMediaIdentifier` protocol.
                          Returns any optional `mediaIdentifier` string and `customData` dictionary
                          associated with the currently loaded meda item
 @param     completion    The completion block that must be called when the preroll ad has finished playing. The VPKit SDK video will not play until this block is called.

 */


- (void)handlePreroll:(nonnull UIView*)view
           controller:(nonnull UIViewController*)controller
           identifier:(nonnull id<VPKMediaIdentifier>)identifier
           completion:(nonnull void(^)(void))completion;

/**
 Implement this method to clean up interrupted ad handling.
 */


- (void)stopPreroll;

@end

#endif /* VPKAdHandler_h */
