//
//  DMengRewardedVideoManager.h
//  DMengAdSDK
//
//  Created by 刘士林 on 2024/6/4.
//

#import <Foundation/Foundation.h>
#import <DMAdSDK/DMAds.h>
#import <DMAdSDK/DM_Macro.h>
#import <DMAdSDK/DMUnionModel.h>
#import <DMengSDKAdapter/DMengSDKAdapter.h>

NS_ASSUME_NONNULL_BEGIN
@interface DMengRewardedVideoManager : NSObject
typedef void(^DMengRewardedVideoManagerCompletion)(DMengRewardedVideoAdapter * rewardedVideoAdapter);
//广告位id
@property (nonatomic, copy, readonly, nonnull) NSString *slotID;
//当前广告的报价
@property(nonatomic, assign, readonly) long bidPrice;

@property(nonatomic, assign, readonly) long originalPrice;
@property (nonatomic , copy) NSString * materialId ;
@property(nonatomic, assign) int64_t bidTs;
@property (nonatomic, strong) DMUnionTrackerModel * trackerModel;
@property (nonatomic, weak) id<DMengRewardedVideoManagerDelegate> delegate;

/// 初始化激励视频和配置、代理
/// - Parameter delegate: 代理
/// - Parameter slotID: 广告位id
/// - Parameter model:  额外的数据
- (void)loadRewardedVideoAdTemplateAdWithSlotID:(NSString *)slotID withRewarVideoModel:(DMengRewarVideoModel*)model completion:(DMengRewardedVideoManagerCompletion)completion;
//竞价成功的上报
- (void)biddingRewardedVideoSuccess:(long)price;
//竞价失败的上报
- (void)biddingRewardedVideoFailed:(long)price Code:(DMAdBiddingCode)code;
/// 展示广告
/// - Parameter viewController: 当前要展示的控制器
-(void)showRewardedVideoViewInRootViewController:(UIViewController *)viewController;
-(NSString*)getUnionSdkTracker;
- (NSTimeInterval)getCurrentTimeInterval;
@end

NS_ASSUME_NONNULL_END
