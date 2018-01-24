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



#pragma mark - Names for VPKit Video NSNotification events

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
 Not sent
 */
FOUNDATION_EXPORT NSString *const VPKEventVideoAdStart;

/**
 Not sent
 */
FOUNDATION_EXPORT NSString *const VPKEventVideoAdComplete;

/**
 Not sent
 */
FOUNDATION_EXPORT NSString *const VPKEventVideoChapterStart;

/**
 Not sent
 */
FOUNDATION_EXPORT NSString *const VPKEventVideoChapterComplete;




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


FOUNDATION_EXPORT NSString *const VPKSessionDataKey;

FOUNDATION_EXPORT NSString *const VPKIdentifierKey;


NS_ASSUME_NONNULL_END

#endif /* VPKPublicEventConstants_h */

