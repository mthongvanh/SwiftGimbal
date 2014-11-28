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
#import <UIKit/UIKit.h>
#import <Common/QLAvailability.h>

#import "QLContextConnectorPermissions.h"

@protocol QLContextCorePermissionsDelegate <NSObject>

@optional
- (void)subscriptionPermissionDidChange:(BOOL)subscriptionPermission;

@end


@interface QLContextCoreConnector : NSObject

@property (nonatomic, unsafe_unretained) id<QLContextCorePermissionsDelegate> permissionsDelegate;

- (void)enableFromViewController:(UIViewController *)viewController
                         success:(void (^)())success
                         failure:(void (^)(NSError *error))failure;

- (void)deleteAllUserDataAndOnSuccess:(void (^)())success
                              failure:(void (^)(NSError *error))failure;

- (void)checkStatusAndOnEnabled:(void (^)(QLContextConnectorPermissions *contextConnectorPermissions))enabled 
                       disabled:(void (^)(NSError *error))disabled;

- (void)showPermissionsFromViewController:(UIViewController *)viewController
                                  success:(void (^)())success
                                  failure:(void (^)(NSError *error))failure;

/*
 *  showPermissionsFromViewController:
 *
 *  Discussion:
 *      Deprecated in v0.43. Use the showPermissionsFromViewController:success:failure: instead.
 */
- (void)showPermissionsFromViewController:(UIViewController *)viewController DEPRECATED;

@end
