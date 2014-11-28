
#import "QLAnalyticContentEvent.h"
#import "QLTrigger.h"

@interface QLContentNotifiedEvent : QLAnalyticContentEvent

@property (nonatomic, strong) NSString *contentId;

- (id)initWithContentId:(NSString *)contentId trigger:(QLTrigger *)trigger;

@end
