//
//  NSObject+libextobjc_properties.h
//  Wondr
//
//  Created by jonathan on 03/10/2015.
//  Copyright © 2015 Wondr.it Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
@interface NSObject (libextobjc_properties)


//returns only classes for properties in the subclass. Superclass propery names are ignored.
+ (Class)vpk_classForPropertyName:(NSString*)property;
+ (NSString*)vpk_classNameForPropertyName:(NSString*)property;


//returns all propertyNames including superclasses up to NSObject
+ (NSArray*)vpk_propertyNames;
+ (NSArray*)vpk_propertyNames:(NSError**)error;

//returns only propertyNames of the subclass. Superclass properties are not incuded
+ (NSArray*)vpk_propertyNamesForSubclass;
+ (NSArray*)vpk_propertyNamesForSubclass:(NSError**)error;


/*
 
 returns an array of  (@"name": @"class": ) string dictionaries denoting each property on the object
 (including it's superclasses properties up to NSObject)
 */
//+ (NSArray*)propertyDetails:(NSError**)error;
//+ (NSArray*)propertyDetails;

@end
