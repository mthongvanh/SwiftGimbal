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
#import "QLPushNotificationsConnector.h"

@class QLContentNotification;
@class QLContent;

@protocol QLQuery;

typedef enum  {
    QLNotificationAppWasInForeground = 10,
    QLNotificationAppWasInBackground = 20,
    QLNotificationAppWasLaunched = 30
} QLNotificationAppState;


@protocol QLTimeContentDelegate <NSObject>

- (void)didReceiveNotification:(QLContentNotification *)notification
                      appState:(QLNotificationAppState)appState;

@end

@interface QLContentConnector : NSObject

@property (nonatomic, unsafe_unretained) id<QLTimeContentDelegate> delegate;

- (void)contentWithId:(NSString *)identifier
              success:(void (^)(QLContent *content))success
              failure:(void (^)(NSError *error))failure;

- (void)timeContentsFromStartDate:(NSDate *)startDate
                        toEndDate:(NSDate *)endDate
                          success:(void (^)(NSArray *timeContents))success
                          failure:(void (^)(NSError *error))failure;

- (void)contentsWithQuery:(id<QLQuery>)query
                  success:(void (^)(NSArray *contents))success
                  failure:(void (^)(NSError *error))failure;
@end
