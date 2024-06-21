//
//  DMengInterstitialManager.h
//  DMengAdSDK
//
//  Created by 刘士林 on 2024/6/3.
//

#import <Foundation/Foundation.h>
#import <DMAdSDK/DMAds.h>
#import <DMAdSDK/DM_Macro.h>
#import <DMAdSDK/DMUnionModel.h>
#import <DMengSDKAdapter/DMengSDKAdapter.h>

NS_ASSUME_NONNULL_BEGIN
@interface DMengInterstitialManager : NSObject
typedef void(^DMengInterstitialManagerCompletion)(DMengInterstitialAdapter * interstitialAdapter);
//广告位id
@property (nonatomic, copy, readonly, nonnull) NSString *slotID;
//当前广告的报价
@property(nonatomic, assign, readonly) long bidPrice;

@property(nonatomic, assign, readonly) long originalPrice;
@property (nonatomic , copy) NSString * materialId ;
@property(nonatomic, assign) int64_t bidTs;
@property (nonatomic, strong) DMUnionTrackerModel * trackerModel;
@property (nonatomic, weak) id<DMengInterstitialManagerDelegate> delegate;

/// 初始化插屏广告
/// - Parameter completion: 加载完成后返回的对象
/// - Parameter slotID: 广告位id
- (void)loadInterstitialAdTemplateAdWithSlotID:(nonnull NSString *)slotID completion:(DMengInterstitialManagerCompletion)completion;
//竞价成功的上报
- (void)biddingInterstitialSuccess:(long)price;
//竞价失败的上报
- (void)biddingInterstitialFailed:(long)price Code:(DMAdBiddingCode)code;
/// 展示广告
/// - Parameter viewController: 当前要展示的控制器
-(void)showInterstitialViewInRootViewController:(UIViewController *)viewController;
-(NSString*)getUnionSdkTracker;
- (NSTimeInterval)getCurrentTimeInterval;
@end

NS_ASSUME_NONNULL_END
