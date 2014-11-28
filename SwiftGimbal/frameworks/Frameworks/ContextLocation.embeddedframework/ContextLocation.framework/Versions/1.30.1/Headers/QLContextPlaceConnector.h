/**
 * Copyright (C) 2011 Qualcomm Retail Solutions, Inc. All rights reserved.
 *
 * This software is the confidential and proprietary information of Qualcomm Retail Solutions, Inc.
 *
 * The following sample code illustrates various aspects of the Gimbal SDK.
 *
 * The sample code herein is provided for your convenience, and has not been
 * tested or designed to work on any particular system configuration. It is
 * provided AS IS and your use of this sample code, whether as provided or with
 * any modification, is at your own risk. Neither Qualcomm Retail Solutions, Inc. nor any
 * affiliate takes any liability nor responsibility with respect to the sample
 * code, and disclaims all warranties, express and implied, including without
 * limitation warranties on merchantability, fitness for a specified purpose,
 * and against infringement.
 */

#import <Foundation/Foundation.h>
#import <Common/QLAvailability.h>

@class QLPlace;
@class QLPlaceEvent;

@protocol QLContextPlaceConnectorDelegate <NSObject>

@optional

- (void)didGetPlaceEvent:(QLPlaceEvent *)placeEvent;

- (void)didGetContentDescriptors:(NSArray *)contentDescriptors;

- (void)placesPermissionDidChange:(BOOL)placesPermission;

- (void)privatePlacesDidChange:(NSArray *)privatePlaces;

- (BOOL)shouldMonitorPlace:(QLPlace *)place;

@end


@interface QLContextPlaceConnector : NSObject

@property (assign) id<QLContextPlaceConnectorDelegate> delegate;
@property (nonatomic, readonly) BOOL isPlacesEnabled;
@property (nonatomic, readonly) BOOL isBackgroundPlaceMonitoringEnabled;
@property (nonatomic, readonly) BOOL isMonitoringPlacesInBackground;
@property (nonatomic, readonly) BOOL isMonitoringPlacesWhenAllowed;

+ (BOOL)isPlaceMonitoringAvailable;

- (void)allOrganizationPlacesAndOnSuccess:(void (^)(NSArray *places))success 
                               failure:(void (^)(NSError *error))failure;

- (void)requestContentHistoryAndOnSuccess:(void (^)(NSArray *contentHistories))success 
                              failure:(void (^)(NSError *error))failure;

- (void)allPlacesAndOnSuccess:(void (^)(NSArray *places))success
                      failure:(void (^)(NSError *error))failure;

- (void)createPlace:(QLPlace *)place
            success:(void (^)(QLPlace *place))success
            failure:(void (^)(NSError *error))failure;

- (void)updatePlace:(QLPlace *)place
            success:(void (^)(QLPlace *place))success
            failure:(void (^)(NSError *error))failure;

- (void)deletePlaceWithId:(long long)placeId
                  success:(void (^)())success
                  failure:(void (^)(NSError *error))failure;

- (void)allPrivatePointsOfInterestAndOnSuccess:(void (^)(NSArray *privatePointsOfInterest))success
                                       failure:(void (^)(NSError *error))failure;

- (void)monitorPlacesWhenAllowed;
- (void)dontMonitorPlacesWhenAllowed;

- (void)monitorPlacesInBackground;
- (void)dontMonitorPlacesInBackground;


/*
 *  requestLatestPlaceEventsAndOnSuccess:failure:
 *
 *  Discussion:
 *      Deprecated in v0.29. Use the didGetPlaceEvent: on QLContextPlaceConnectorDelegate instead.
 */
- (void)requestLatestPlaceEventsAndOnSuccess:(void (^)(NSArray *placeEvents))success
                                     failure:(void (^)(NSError *error))failure DEPRECATED;

@end