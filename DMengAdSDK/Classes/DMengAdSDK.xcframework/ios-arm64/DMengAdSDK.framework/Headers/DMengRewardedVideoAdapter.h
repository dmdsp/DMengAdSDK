//
//  DMengRewardedVideoAdapter.h
//  DMengAdSDK
//
//  Created by 刘士林 on 2024/6/4.
//

#import <Foundation/Foundation.h>
#import <DMAdSDK/DMAds.h>
#import <DMAdSDK/DM_Macro.h>
#import <DMAdSDK/DMUnionModel.h>

NS_ASSUME_NONNULL_BEGIN
@protocol DMengRewardedVideoManagerDelegate;
@class DMengRewarVideoModel;
@interface DMengRewardedVideoAdapter : NSObject
typedef void(^DMengRewardedVideoAdapterCompletion)(DMengRewardedVideoAdapter * rewardedVideoAdapter);
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
- (void)loadRewardedVideoAdTemplateAdWithSlotID:(NSString *)slotID withRewarVideoModel:(DMengRewarVideoModel*)model completion:(DMengRewardedVideoAdapterCompletion)completion;
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

@protocol DMengRewardedVideoManagerDelegate <NSObject>
/// 加载成功
- (void)rewardVideoAdDidLoad :(DMengRewardedVideoAdapter*)rewardVideoAd;
/// 加载失败
- (void)rewardVideoAdDidFailToLoadWithError:(NSError *)error;
/// 渲染成功
- (void)rewardVideoAdDidRender:(DMengRewardedVideoAdapter*)rewardVideoAd;;
/// 渲染失败
- (void)rewardVideoAdDidFailToRenderWithError:(NSError *)error;
/// 广告已经打开
- (void)rewardVideoAdDidShow:(DMengRewardedVideoAdapter *)rewardVideoAd;
/// 广告被点击
- (void)rewardVideoAdDidClick:(DMengRewardedVideoAdapter *)rewardVideoAd;
/// 广告被关闭
- (void)rewardVideoAdDidClose:(DMengRewardedVideoAdapter *)rewardVideoAd;
///播放失败的回调
- (void)rewardVideoAdDidFailToShowWithError:(NSError *)error;
///发奖
- (void)rewardVideoAdDidComplete:(DMengRewardedVideoAdapter *)rewardVideoAd;
///视频播放完成
- (void)rewardVideoAdPlayToEndTime:(DMengRewardedVideoAdapter *)rewardVideoAd;
@end

NS_ASSUME_NONNULL_END
