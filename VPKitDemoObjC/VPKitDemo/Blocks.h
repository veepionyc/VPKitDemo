//
//  Blocks.h
//  FNCamShift
//
//  Created by jonathan on 14/01/2016.
//  Copyright © 2016 foundry. All rights reserved.
//

#ifndef Blocks_h
#define Blocks_h

#import <UIKit/UIKit.h>
////////////
// BLOCKS //
////////////

typedef void (^Block)();
typedef void (^BlockBlock)(Block block);
typedef void (^IdBlock)(id thing);
typedef void (^BOOLBlock) (BOOL success);
typedef void (^BOOLErrorBlock) (BOOL success, NSError* error);
typedef void (^NSErrorBlock) (NSError* error);
typedef void (^NSURLSessionErrorBlock)(NSURLSessionDataTask *task, NSError *error);
typedef void (^NSArrayBlock)(NSArray* array);
typedef void (^NSArrayErrorBlock)(NSArray* array, NSError* error);
typedef void (^NSArrayDictionaryErrorBlock)(NSArray* array,NSDictionary* dictionary, NSError* error);
typedef void (^NSDictionaryBlock) (NSDictionary* dictionary);
typedef void (^NSDictionaryErrorBlock) (NSDictionary* dictionary, NSError* error);

typedef void (^NSSetBlock)(NSSet* set);
typedef void (^NSSetErrorBlock)(NSSet* set, NSError* error);

typedef void (^NSDataBlock)(NSData* data);
typedef void (^NSDataErrorBlock)(NSData* data, NSError* error);

typedef void (^NSDataIntBlock)(NSData* data, int num);

typedef void (^NSStringBlock)(NSString* string);
typedef void (^NSStringErrorBlock)(NSString* string, NSError* error);
typedef void (^NSURLErrorBlock)(NSURL* url, NSError* error);

typedef void (^UIImageBlock)(UIImage* image);
typedef void (^UIImageSuccessBlock)(UIImage* image, BOOL success);
typedef void (^UIImageErrorBlock)(UIImage* image, NSError* error);
typedef void (^UIImageErrorStopBlock)(UIImage* image, NSError* error, BOOL* stop);
typedef void (^NSNumberBlock)(NSNumber* number);
typedef void (^NSIntegerBlock)(NSInteger integer);
typedef void (^UIAlertActionBlock)(UIAlertAction* action);


#endif /* Blocks_h */
