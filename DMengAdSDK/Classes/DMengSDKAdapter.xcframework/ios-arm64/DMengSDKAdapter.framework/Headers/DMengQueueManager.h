//
//  DMengQueueManager.h
//  DMengAdSDK
//
//  Created by 刘士林 on 2024/5/22.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface DMengQueueManager : NSObject
+ (dispatch_queue_t)sharedAdLoadingQueue;

@end

NS_ASSUME_NONNULL_END
