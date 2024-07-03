//
//  DMengSplashAdapter.h
//  DMengAdSDK
//
//  Created by 刘士林 on 2024/5/10.
//

#import <Foundation/Foundation.h>
#import <DMAdSDK/DMAds.h>
#import <DMAdSDK/DM_Macro.h>
#import <DMAdSDK/DMUnionModel.h>

NS_ASSUME_NONNULL_BEGIN
@protocol DMengSplashManagerDelegate;
@interface DMengSplashAdapter : NSObject
typedef void(^DMengSplashAdapterCompletion)(DMengSplashAdapter * splashAdapter);
//广告位id
@property (nonatomic, copy, readonly, nonnull) NSString *slotID;
//当前广告的报价
@property(nonatomic, assign, readonly) long ecpm;

@property(nonatomic, assign, readonly) long originalPrice;
@property (nonatomic , copy) NSString * materialId ;
@property(nonatomic, assign) int64_t bidTs;
@property (nonatomic, strong) DMUnionTrackerModel * trackerModel;
@property (nonatomic, weak) id<DMengSplashManagerDelegate> delegate;

/// 初始化开屏广告
/// - Parameter completion: 加载完成后返回的对象
/// - Parameter slotID: 广告位id
/// - Parameter adSize: 尺寸,必须>=屏幕高度的75%，如果高度<75%，将会以屏幕实际高度渲染，可能会导致图片变形或影响广告渲染速度
- (void)loadSplashAdTemplateAdWithSlotID:(nonnull NSString *)slotID adSize:(CGSize)adSize completion:(DMengSplashAdapterCompletion)completion;
//竞价成功的上报
- (void)biddingSplashSuccess:(long)price;
//竞价失败的上报
- (void)biddingSplashFailed:(long)price Code:(DMAdBiddingCode)code;
/// 展示广告
/// - Parameter viewController: 当前要展示的控制器
-(void)showSplashViewInRootViewController:(UIViewController *)viewController;
-(NSString*)getUnionSdkTracker;
@end

@protocol DMengSplashManagerDelegate <NSObject>
/// 加载成功
- (void)splashAdDidLoad :(DMengSplashAdapter*)splashAd;
/// 加载失败
- (void)splashAdDidFailToLoadWithError:(NSError *)error;
/// 渲染成功
- (void)splashAdDidRender:(DMengSplashAdapter*)splashAd;;
/// 渲染失败
- (void)splashAdDidFailToRenderWithError:(NSError *)error;
/// 广告已经打开
- (void)splashAdDidShow:(DMengSplashAdapter *)splashAd;
/// 广告被点击
- (void)splashAdDidClick:(DMengSplashAdapter *)splashAd;
/// 广告被关闭
- (void)splashAdDidClose:(DMengSplashAdapter *)splashAd;

@end

NS_ASSUME_NONNULL_END
