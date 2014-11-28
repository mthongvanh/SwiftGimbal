/**
 * Copyright (C) 2014 Gimbal, Inc. All rights reserved.
 *
 * This software is the confidential and proprietary information of Gimbal, Inc.
 *
 * The following sample code illustrates various aspects of the Gimbal iOS SDK.
 *
 * The sample code herein is provided for your convenience, and has not been
 * tested or designed to work on any particular system configuration. It is
 * provided pursuant to the License Agreement for Gimbal Software AS IS, and
 * your use of this sample code, whether as provided or with any modification,
 * is at your own risk. Neither Gimbal, Inc. nor any affiliate takes any
 * liability nor responsibility with respect to the sample code, and disclaims
 * all warranties, express and implied, including without limitation warranties
 *  on merchantability, fitness for a specified purpose, and against infringement.
 */
#import <Foundation/Foundation.h>
#import "FYXVisit.h"
#import "FYXiBeaconVisit.h"

@protocol FYXVisitDelegate <NSObject>

@optional
/// Delegate callback to notify when a Visit has begun
- (void)didArrive:(FYXVisit *)visit;

/// Delegate callback to notify when a Visit has been updated
- (void)receivedSighting:(FYXVisit *)visit updateTime:(NSDate *)updateTime RSSI:(NSNumber *)RSSI;

/// Delegate callback to notify when a Visit has ended and the beacon has departed
- (void)didDepart:(FYXVisit *)visit;

@end

@protocol FYXiBeaconVisitDelegate <NSObject>

@optional
/// Delegate callback to notify when a Visit has begun
- (void)didArriveIBeacon:(FYXiBeaconVisit *)visit;

/// Delegate callback to notify when a Visit has been updated
- (void)receivedIBeaconSighting:(FYXiBeaconVisit *)visit updateTime:(NSDate *)updateTime RSSI:(NSNumber *)RSSI;

/// Delegate callback to notify when a Visit has ended and the beacon has departed
- (void)didDepartIBeacon:(FYXiBeaconVisit *)visit;

@end

@interface FYXVisitManager:NSObject

/// Visit Manager Option Keys
extern NSString * const FYXVisitOptionArrivalRSSIKey;
extern NSString * const FYXVisitOptionDepartureRSSIKey;
extern NSString * const FYXVisitOptionDepartureIntervalInSecondsKey;
extern NSString * const FYXVisitOptionBackgroundDepartureIntervalInSecondsKey;
extern NSString * const FYXvVisitOptionBackgroundDepartureIntervalInSecondsKey; // deprecated

/// The manager will notify the delegates of any Visit Events
@property(weak, nonatomic) id<FYXVisitDelegate> delegate;
@property (nonatomic,weak) id<FYXiBeaconVisitDelegate> iBeaconDelegate;

/// The manager will start listening for sightings and notify delegate of visits
- (void)start;

/// The manager will start listening for sightings and notify delegate of visits for the given options
- (void)startWithOptions:(NSDictionary *)options;

/// The manager will stop listening for sightings and stop notifying delegate of visits
- (void)stop;

@end
