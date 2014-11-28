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

@class QLContentAttributes;

@interface QLContentDescriptor : NSObject

@property (nonatomic, strong) NSString *title;
@property (nonatomic, strong) NSString *contentDescription;
@property (nonatomic, strong) NSString *contentUrl;
@property (nonatomic, strong) NSString *campaignId;
@property (nonatomic, strong) NSNumber *expires;
@property (nonatomic, strong) NSNumber *displayCount;
@property (nonatomic, strong) NSNumber *eventTimeWindow;
@property (nonatomic, strong) NSNumber *placeId;
@property (nonatomic, strong) NSNumber *eventTime;
@property (nonatomic, strong) NSString *identifier;
@property (nonatomic, strong) QLContentAttributes *contentAttributes;
@property (nonatomic, strong) NSString *iconUrl DEPRECATED;

@end
