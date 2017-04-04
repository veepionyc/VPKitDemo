//
//  VPKParsableObject.h
//  VPKit
//
//  Created by jonathan on 19/06/2016.
//  Copyright © 2016 jonathan. All rights reserved.
//




#import <Foundation/Foundation.h>


/**
 Abstract superclass for automated parsing of JSON to model objects
 */
@interface VPKParseableObject : NSObject

- (instancetype)initWithJSONDict:(NSDictionary*)dict;

///tanslate JSON key to obj property name
- (NSDictionary*)jsonKeysToPropertyNames;

//JSON numValues that need property stringValues
//- (NSArray*)numbersToStrings;

//JSON stringValues that need property NSNumber
//- (NSArray*)stringsToNumbers;

///collections that need sub-parsing. This is not necessary for standard plist collections (NSDictionary, NSArray)
- (NSDictionary*)arrayClasses;


///for parsing to JSON
- (NSDictionary*)dictionaryRepresentation;

- (NSData*)JSONRepresentation;

@end
