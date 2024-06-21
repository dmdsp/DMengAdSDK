//
//  DMengBannerAdapter.h
//  DMengAdSDK
//
//  Created by 刘士林 on 2024/5/30.
//

#import <Foundation/Foundation.h>

#import <DMAdSDK/DMAds.h>
#import <DMAdSDK/DM_Macro.h>
#import <DMAdSDK/DMUnionModel.h>

NS_ASSUME_NONNULL_BEGIN
@protocol DMengBannerManagerDelegate;
@interface DMengBannerAdapter : NSObject
typedef void(^DMengBannerAdapterCompletion)(DMengBannerAdapter * bannerAdapter);
//广告位id
@property (nonatomic, copy, readonly, nonnull) NSString *slotID;
//当前广告的报价
@property(nonatomic, assign, readonly) long bidPrice;

@property(nonatomic, assign, readonly) long originalPrice;
@property (nonatomic , copy) NSString * materialId ;
@property(nonatomic, assign) int64_t bidTs;
@property (nonatomic, strong) DMUnionTrackerModel * trackerModel;
@property (nonatomic, weak) id<DMengBannerManagerDelegate> delegate;
//广告视图
@property (nonatomic,strong) UIView *bannerView;
/// 初始化
/// - Parameter completion: 加载完成后返回的对象
/// - Parameter slotID: 广告位id
/// - Parameter isHidden:设置点击关闭时弹出视图是否隐藏，是为隐藏
- (void)loadBannerAdTemplateAdWithSlotID:(nonnull NSString *)slotID popupViewHidden:(BOOL)isHidden completion:(DMengBannerAdapterCompletion)completion;
//竞价成功的上报
- (void)biddingBannerSuccess:(long)price;
//竞价失败的上报
- (void)biddingBannerFailed:(long)price Code:(DMAdBiddingCode)code;
-(NSString*)getUnionSdkTracker;
- (NSTimeInterval)getCurrentTimeInterval;
@end

@protocol DMengBannerManagerDelegate <NSObject>
/// 加载成功
- (void)bannerAdDidLoad :(DMengBannerAdapter*)bannerAd;
/// 加载失败
- (void)bannerAdDidFailToLoadWithError:(NSError *)error;
/// 渲染成功
- (void)bannerAdDidRender:(DMengBannerAdapter*)bannerAd;;
/// 渲染失败
- (void)bannerAdDidFailToRenderWithError:(NSError *)error;
/// 广告已经打开
- (void)bannerAdDidShow:(DMengBannerAdapter *)bannerAd;
/// 广告被点击
- (void)bannerAdDidClick:(DMengBannerAdapter *)bannerAd;
/// 广告被关闭
- (void)bannerAdDidClose:(DMengBannerAdapter *)bannerAd;

@end

NS_ASSUME_NONNULL_END
