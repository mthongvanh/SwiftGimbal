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
#import <UIKit/UIKit.h>

#pragma mark - FYX Authentication Error Codes

//nonspecific failure during oauth process
#define FYX_UNKNOWN_AUTH_FAILURE 2000
//failed network connection during oauth process
#define FYX_NETWORK_AUTH_FAILURE 2001
//user pressed cancel button within oauth view
#define FYX_USER_CANCELLED_AUTH_FAILURE 2002
//user pressed "don't allow" during oauth process
#define FYX_USER_DENIED_AUTH_FAILURE 2003
//bluetooth state error
#define FYX_BLUETOOTH_FAILURE 2004

@class FYXAppInfo;

#pragma mark - FYX Session Delegate

/// comment for documentation
@protocol FYXBluetoothStateUpdateDelegate<NSObject>

@optional
/// comment for documentation
- (void)bluetoothBecameUnavailable;

@optional
/// comment for documentation
- (void)bluetoothBecameAvailable;

@end
/// comment for documentation
@protocol FYXSessionDelegate<NSObject, FYXBluetoothStateUpdateDelegate>

/// comment for documentation
- (void)sessionStarted;

@optional
/// comment for documentation
- (void)sessionCreateFailed:(NSError *)error;

/// comment for documentation
- (void)sessionEnded;

/// comment for documentation
- (void)sessionEndFailed:(NSError *)error;

/// comment for documentation
- (void)sessionDataDeleted;

/// comment for documentation
- (void)sessionDataDeleteFailed:(NSError *)error;

@end

#pragma mark - FYX Service Delegate

/// comment for documentation
@protocol FYXServiceDelegate<NSObject, FYXBluetoothStateUpdateDelegate>

@optional
/// comment for documentation
- (void)serviceStarted;

/// comment for documentation
- (void)startServiceFailed:(NSError *)error;

@end

#pragma mark - FYX

/// comment for documentation
@interface FYX : NSObject

/// comment for documentation
extern NSString * const FYXLocationModeKey;

/// comment for documentation
extern NSString * const FYXLowPowerLocation;

/// comment for documentation
extern NSString * const FYXHighAccuracyLocation;

/// comment for documentation
extern NSString * const FYXNoLocation;

/// comment for documentation
extern NSString * const NO_LOCATION;

/// comment for documentation
+ (void)setAppId:(NSString *)appId
       appSecret:(NSString *)appSecret
     callbackUrl:(NSString *)callbackUrl;

/// comment for documentation
+ (void)startServiceAndAuthorize:(id<FYXSessionDelegate>)sessionDelegate;

/// comment for documentation
+ (void)startServiceAndAuthorizeWithViewController:(UIViewController *)viewController delegate:(id<FYXSessionDelegate>)sessionDelegate;

/// comment for documentation
+ (void)stopServiceAndDeauthorize;

/// comment for documentation
+ (void)startService:(id<FYXServiceDelegate>)serviceDelegate;

/// comment for documentation
+ (void)stopService;

/// comment for documentation
+ (void)handleOpenURL:(NSURL *)url;

/// comment for documentation
+ (FYXAppInfo *)currentAppInfo;

/// comment for documentation
+ (void)enableLocationUpdates;

/// comment for documentation
+ (void)disableLocationUpdates;

/// comment for documentation
+ (void)enableLocationUpdatesWithOptions:(NSDictionary *)options;

/// comment for documentation
+ (void)deleteVisitsAndSightings;

@end
