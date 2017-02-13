//
//  VPKEvent.h
//  Pods
//
//  Created by jonathan on 04/06/2016.
//
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CGGeometry.h>

@interface VPKEvent : NSObject
@property (nonnull, nonatomic, strong) NSString* eventName; //eventType
@property (nonnull, nonatomic, strong) NSDictionary* osVersion;
@property (nonnull, nonatomic, strong) NSString* deviceType;
@property (nonnull, nonatomic, strong) NSString* platform;
@property (nonnull, nonatomic, strong) NSString* timestamp;
@property (nonnull, nonatomic, strong) NSNumber* timezone;
@property (nonnull, nonatomic, strong) NSString* appID;
@property (nonnull, nonatomic, strong) NSString* eventID;
@property (nonnull, nonatomic, strong) NSString* consumerID;
@property (nonnull, nonatomic, strong) NSString* email;
@property (nonnull, nonatomic, strong) NSDictionary* sdkVersion;
@property (nonnull, nonatomic, strong) NSDictionary* appVersion;


#pragma mark - optionals

@property (nullable, nonatomic, strong) NSNumber* latitude;    //float
@property (nullable, nonatomic, strong) NSNumber* longitude;   //float
@property (nullable, nonatomic, strong) NSNumber* locationStd; //float
@property (nullable, nonatomic, strong) NSNumber* x; //float
@property (nullable, nonatomic, strong) NSNumber* y; //float
@property (nullable, nonatomic, strong) NSNumber* videoTime;  //float
@property (nullable, nonatomic, strong) NSString* veepID;
@property (nullable, nonatomic, strong) NSString* creatorID;
@property (nullable, nonatomic, strong) NSString* veepTrackID; //this is the trackIdx
@property (nullable, nonatomic, strong) NSString* trackID; //this is the database key
@property (nullable, nonatomic, assign) NSNumber* price;    //decimal - float
@property (nullable, nonatomic, assign) NSNumber* quantity; //int
@property (nullable, nonatomic, assign) NSNumber* duration; //float
@property (nullable, nonatomic, strong) NSString* url;
#pragma mark - computed


- (nullable instancetype)initWithEventName:(nonnull NSString*)eventName;

- (nonnull NSDictionary*)dictionaryEvent;

- (nonnull NSData*)jsonEvent;

- (void) setPoint:(CGPoint)point;
@end
