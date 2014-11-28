
#import <Foundation/Foundation.h>
#import "QLTrigger.h"

@interface QLAnalyticEvent : NSObject

@property (nonatomic, strong) NSDate *time;
@property (nonatomic, strong) QLTrigger *trigger;

@end