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

@class FYXTransmitter;

/// comment for documentation
@protocol FYXSightingDelegate <NSObject>

/// comment for documentation
- (void)didReceiveSighting:(FYXTransmitter *)transmitter time:(NSDate *)time RSSI:(NSNumber *)RSSI;

@end

@interface FYXSightingManager : NSObject

/// comment for documentation
extern NSString * const FYXSightingOptionSignalStrengthWindowKey;

/// comment for documentation
extern int const FYXSightingOptionSignalStrengthWindowNone;

/// comment for documentation
extern int const FYXSightingOptionSignalStrengthWindowSmall;

/// comment for documentation
extern int const FYXSightingOptionSignalStrengthWindowMedium;

/// comment for documentation
extern int const FYXSightingOptionSignalStrengthWindowLarge;

/// comment for documentation
@property(weak, nonatomic) id<FYXSightingDelegate> delegate;

/// comment for documentation
- (void)scan;

/// comment for documentation
- (void)scanWithOptions:(NSDictionary *)options;

/// comment for documentation
- (void)stopScan;

@end
