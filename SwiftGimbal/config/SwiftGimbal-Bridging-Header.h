//
//  SwiftGimbal-Bridging-Header.h
//  SwiftGimbal
//
//  Created by Michael Thongvanh on 11/26/14.
//  Copyright (c) 2014 Chisel Apps. All rights reserved.
//

#ifndef SwiftGimbal_SwiftGimbal_Bridging_Header_h
#define SwiftGimbal_SwiftGimbal_Bridging_Header_h


// Common.framework
#import "Common/QLAvailability.h"
#import "Common/QLJson.h"
#import "Common/QLJsonSerializable.h"

// ContextCore.framework
#import "ContextCore/QLAnalyticContentEvent.h"
#import "ContextCore/QLAnalyticEvent.h"
#import "ContextCore/QLAnalyticsConnector.h"
#import "ContextCore/QLContent.h"
#import "ContextCore/QLContentAttributes.h"
#import "ContextCore/QLContentClickedEvent.h"
#import "ContextCore/QLContentConnector.h"
#import "ContextCore/QLContentDisplayedEvent.h"
#import "ContextCore/QLContentNotification.h"
#import "ContextCore/QLContentNotifiedEvent.h"
#import "ContextCore/QLContextConnectorPermissions.h"
#import "ContextCore/QLContextCore.h"
#import "ContextCore/QLContextCoreConnector.h"
#import "ContextCore/QLContextCoreError.h"
#import "ContextCore/QLPlaceTrigger.h"
#import "ContextCore/QLPushNotificationsConnector.h"
#import "ContextCore/QLQuery.h"
#import "ContextCore/QLQueryForAnyAttributes.h"
#import "ContextCore/QLTimeContent.h"
#import "ContextCore/QLTrigger.h"

// ContextLocation.framework
#import "ContextLocation/QLContentDescriptor.h"
#import "ContextLocation/QLContextLocationErrors.h"
#import "ContextLocation/QLContextPlaceConnector.h"
#import "ContextLocation/QLGeoFence.h"
#import "ContextLocation/QLGeoFenceCircle.h"
#import "ContextLocation/QLGeofencePolygon.h"
#import "ContextLocation/QLLocation.h"
#import "ContextLocation/QLPlace.h"
#import "ContextLocation/QLPlaceAttributes.h"
#import "ContextLocation/QLPlaceEvent.h"
#import "ContextLocation/QLPrivatePointOfInterest.h"
#import "ContextLocation/QPSError.h"

// ContextProfiling.framework
#import "ContextProfiling/PRAttributeCategory+Json.h"
#import "ContextProfiling/PRAttributeCategory.h"
#import "ContextProfiling/PRContextInterestsConnector.h"
#import "ContextProfiling/PRCustomAttributes.h"
#import "ContextProfiling/PRProfile+Json.h"
#import "ContextProfiling/PRProfile.h"
#import "ContextProfiling/PRProfileAttribute.h"

// FYX.framework
#import "FYX/FYX.h"
#import "FYX/FYXAppInfo.h"
#import "FYX/FYXLogging.h"
#import "FYX/FYXSightingManager.h"
#import "FYX/FYXTransmitter.h"
#import "FYX/FYXTransmitterManager.h"
#import "FYX/FYXVisit.h"
#import "FYX/FYXVisitManager.h"
#import "FYX/FYXiBeacon.h"
#import "FYX/FYXiBeaconVisit.h"

#endif
