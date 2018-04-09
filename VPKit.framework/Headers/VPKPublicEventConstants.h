//
//  VPKPublicEventConstants.h
//
//
//  Created by jonathan on 15/01/2018.
//  Copyright © 2018 VEEPIO LLC. All rights reserved.
//
#ifndef VPKPublicEventConstants
#define VPKPublicEventConstants

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 
 Names for VPKEvent NSNotifications
 
 A number of event messages are available to intercept as NSNotification objects.
 
 The notification objects include a userInfo dictionary with a single VPKIdentifierKey entry. If a mediaIdentifier string is set on the VPKPreview's VPKImage, this will be returned as the value. The identifier may aid in ensuring that the correct media events are handled.
 
 @see VPKImage.mediaIdentifier
 */

#pragma mark - Names for VPKEvent NSNotifications

/**
 NSNotification sent when a video is loaded and ready to play
 */
FOUNDATION_EXPORT NSString *const VPKEventVideoLoad;

/**
 NSNotification sent when a video is unloaded from the video player (no longer the `currentItem`)
 */
FOUNDATION_EXPORT NSString *const VPKEventVideoUnload;

/**
 NSNotification sent when the user _first_ requests the video to play (for example, by pressing the play button). This notification is only sent once per video load (not resent after a video pause event).
 */
FOUNDATION_EXPORT NSString *const VPKEventVideoPlayRequested;

/**
 NSNotification sent when the video `currentItem` `rate` changes from 0 to any number greater than 0.
 */
FOUNDATION_EXPORT NSString *const VPKEventVideoPlay;

/**
 NSNotification sent when the video `currentItem` `rate` changes from any number greater than 0 to 0
 */
FOUNDATION_EXPORT NSString *const VPKEventVideoPause;

/**
 NSNotification sent when the video `currentItem` plays out to the end.
 */
FOUNDATION_EXPORT NSString *const VPKEventVideoComplete;

/**
 NSNotification sent when a seek event is initiated on the player
 */
FOUNDATION_EXPORT NSString *const VPKEventVideoSeekStart;

/**
 NSNotification sent when a seek event is completed on the player
 */
FOUNDATION_EXPORT NSString *const VPKEventVideoSeekComplete;

/**
 :nodoc:  Not sent
 */
FOUNDATION_EXPORT NSString *const VPKEventVideoAdStart;

/**
 :nodoc:  Not sent
 */
FOUNDATION_EXPORT NSString *const VPKEventVideoAdComplete;

/**
 :nodoc:  Not sent
 */
FOUNDATION_EXPORT NSString *const VPKEventVideoChapterStart;

/**
 :nodoc:  Not sent
 */
FOUNDATION_EXPORT NSString *const VPKEventVideoChapterComplete;


/**
 
 Quality of Service dictionary keys
 */

#pragma mark - Quality of Service dictionary keys

/**
 The download (network) bitrate in bits per second.  Negative if unknown.
 Value: NSNumber (double)
 */
FOUNDATION_EXPORT NSString *const VPKEventVideoObservedBitrateKey;

/**
 The required bitrate for video playback in bits per second.  Negative if unknown.
 If the network bitrate is less than the playback bitrate, buffering will occur.
 Value: NSNumber (float)
 */
FOUNDATION_EXPORT NSString *const VPKEventVideoPlaybackBitrateKey;

/**
 The video track `nominalFrameRate` if available: otherwise negative.
 */
FOUNDATION_EXPORT NSString *const VPKEventVideoFramesPerSecondKey;

/**
 The total number of dropped video frames. Negative if unknown.
 Value: NSNumber (NSInteger)
 */
FOUNDATION_EXPORT NSString *const VPKEventVideoNumberOfDroppedVideoFrames;

/**
 The accumulated duration until player item is ready to play. Measured in seconds. Negative if unknown.
 Value:  NSNumber (NSTimeInterval)
 */
FOUNDATION_EXPORT NSString *const VPKEventVideoStartupTimeKey;

/**
 Media playback type ("LIVE", "VOD", "FILE","unknown").
 Value: NSString
 */
FOUNDATION_EXPORT NSString *const VPKEventVideoPlaybackTypeKey;


/**
 :nodoc:
 */
FOUNDATION_EXPORT NSString *const VPKSessionDataKey;

/**
 
 Key to retrieve media identifier from VPKit Video NSNotification event info dictionary.
 
 @see `VPKImage.mediaIdentifier`
 */


FOUNDATION_EXPORT NSString *const VPKIdentifierKey;


NS_ASSUME_NONNULL_END

#endif /* VPKPublicEventConstants_h */

