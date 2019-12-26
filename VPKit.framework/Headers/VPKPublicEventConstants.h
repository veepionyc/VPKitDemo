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
extern NSString *const VPKEventVideoLoad;

/**
 NSNotification sent when a video is unloaded from the video player (no longer the `currentItem`)
 */
extern NSString *const VPKEventVideoUnload;

/**
 NSNotification sent when the user _first_ requests the video to play (for example, by pressing the play button). This notification is only sent once per video load (not resent after a video pause event).
 */
extern NSString *const VPKEventVideoPlayRequested;

/**
 NSNotification sent when the video `currentItem` `rate` changes from 0 to any number greater than 0.
 */
extern NSString *const VPKEventVideoPlay;

/**
 NSNotification sent when the video `currentItem` `rate` changes from any number greater than 0 to 0
 */
extern NSString *const VPKEventVideoPause;

/**
 NSNotification sent when the video `currentItem` plays out to the end.
 */
extern NSString *const VPKEventVideoComplete;

/**
 NSNotification sent when a seek event is initiated on the player
 */
extern NSString *const VPKEventVideoSeekStart;

/**
 NSNotification sent when a seek event is completed on the player
 */
extern NSString *const VPKEventVideoSeekComplete;

/**
 :nodoc:  Not sent
 */
extern NSString *const VPKEventVideoAdStart;

/**
 :nodoc:  Not sent
 */
extern NSString *const VPKEventVideoAdComplete;

/**
 :nodoc:  Not sent
 */
extern NSString *const VPKEventVideoChapterStart;

/**
 :nodoc:  Not sent
 */
extern NSString *const VPKEventVideoChapterComplete;


/**
 
 Quality of Service dictionary keys
 */

#pragma mark - Quality of Service dictionary keys

/**
 The download (network) bitrate in bits per second.  Negative if unknown.
 Value: NSNumber (double)
 */
extern NSString *const VPKEventVideoObservedBitrateKey;

/**
 The required bitrate for video playback in bits per second.  Negative if unknown.
 If the network bitrate is less than the playback bitrate, buffering will occur.
 Value: NSNumber (float)
 */
extern NSString *const VPKEventVideoPlaybackBitrateKey;

/**
 The video track `nominalFrameRate` if available: otherwise negative.
 */
extern NSString *const VPKEventVideoFramesPerSecondKey;

/**
 The total number of dropped video frames. Negative if unknown.
 Value: NSNumber (NSInteger)
 */
extern NSString *const VPKEventVideoNumberOfDroppedVideoFrames;

/**
 The accumulated duration until player item is ready to play. Measured in seconds. Negative if unknown.
 Value:  NSNumber (NSTimeInterval)
 */
extern NSString *const VPKEventVideoStartupTimeKey;

/**
 Media playback type ("LIVE", "VOD", "FILE","unknown").
 Value: NSString
 */
extern NSString *const VPKEventVideoPlaybackTypeKey;


/**
 :nodoc:
 */
extern NSString *const VPKSessionDataKey;

/**
 
 Key to retrieve media identifier from VPKit Video NSNotification event info dictionary.
 
 @see `VPKImage.mediaIdentifier`
 */


extern NSString *const VPKIdentifierKey;


NS_ASSUME_NONNULL_END

#endif /* VPKPublicEventConstants_h */

