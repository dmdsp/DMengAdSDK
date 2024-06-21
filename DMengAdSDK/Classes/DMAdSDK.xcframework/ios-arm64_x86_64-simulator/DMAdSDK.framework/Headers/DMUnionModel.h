//
//  DMUnionModel.h
//  DMAdSDK
//
//  Created by 刘士林 on 2024/5/14.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface DMUnionModel : NSObject
/** 交易所ID */
@property(nonatomic, assign) int exchangeId;
/** ADX应用ID */
@property(nonatomic, assign) int applicationId;
/** appid */
@property(nonatomic, copy) NSString * unionAppid;
/** template */
@property(nonatomic, copy) NSDictionary *templateDic;
/** version */
@property(nonatomic, copy) NSString *version;
/** pub_time */
@property(nonatomic, assign) int64_t pubTime;
@end
@interface DMUnionDspTrackerModel : NSObject
@property(nonatomic, copy) NSString * unionAppid;
@property(nonatomic, copy) NSString * unionAdZoneId;
@property(nonatomic, assign) uint64_t bid;
@property(nonatomic, assign) int64_t bidTs;
@property(nonatomic, assign) int32_t profit;
@property(nonatomic, assign) int32_t unionDspId;

@end
@class DMUnionDspTrackerModel;
@interface DMUnionTrackerModel : NSObject
@property(nonatomic, copy) NSString * slotID;
@property(nonatomic, assign) uint64_t bid;
@property(nonatomic, strong) NSMutableArray <DMUnionDspTrackerModel *>* dspTrackerArr;

@end
NS_ASSUME_NONNULL_END
