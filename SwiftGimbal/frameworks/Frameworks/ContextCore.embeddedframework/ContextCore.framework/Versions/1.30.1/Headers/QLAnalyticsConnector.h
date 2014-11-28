
#import <Foundation/Foundation.h>

#import "QLAnalyticEvent.h"

@interface QLAnalyticsConnector : NSObject

+ (void)log:(QLAnalyticEvent *)event error:(NSError **)error;

@end
