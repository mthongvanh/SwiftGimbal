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

/// comment for documentation
extern int const FYX_LOG_LEVEL_ERROR;

/// comment for documentation
extern int const FYX_LOG_LEVEL_WARN;

/// comment for documentation
extern int const FYX_LOG_LEVEL_INFO;

/// comment for documentation
extern int const FYX_LOG_LEVEL_VERBOSE;

/// comment for documentation
@interface FYXLogging : NSObject

/// comment for documentation
+ (void)setLogLevel:(int)level;

/// comment for documentation
+ (void)enableFileLogging;

/// comment for documentation
+ (void)disableFileLogging;

@end
