//
//  DMengFeedAdapter.h
//  DMengAdSDK
//
//  Created by 刘士林 on 2024/5/22.
//

#import <Foundation/Foundation.h>

#import <DMAdSDK/DMAds.h>
#import <DMAdSDK/DM_Macro.h>
#import <DMAdSDK/DMUnionModel.h>

NS_ASSUME_NONNULL_BEGIN
@protocol DMengFeedManagerDelegate;
@interface DMengFeedAdapter : NSObject
typedef void(^DMengFeedAdapterCompletion)(DMengFeedAdapter * feedAdapter);
//广告位id
@property (nonatomic, copy, readonly, nonnull) NSString *slotID;
//当前广告的报价
@property(nonatomic, assign, readonly) long ecpm;

@property(nonatomic, assign, readonly) long originalPrice;
@property (nonatomic , copy) NSString * materialId ;
@property(nonatomic, assign) int64_t bidTs;
@property (nonatomic, strong) DMUnionTrackerModel * trackerModel;
@property (nonatomic, weak) id<DMengFeedManagerDelegate> delegate;
//广告视图
@property (nonatomic,strong) UIView *feedView;
/// 初始化
/// - Parameter completion: 加载完成后返回的对象
/// - Parameter slotID: 广告位id
/// - Parameter isHidden:设置点击关闭时弹出视图是否隐藏，是为隐藏
- (void)loadFeedAdTemplateAdWithSlotID:(nonnull NSString *)slotID popupViewHidden:(BOOL)isHidden completion:(DMengFeedAdapterCompletion)completion;
//竞价成功的上报
- (void)biddingFeedSuccess:(long)price;
//竞价失败的上报
- (void)biddingFeedFailed:(long)price Code:(DMAdBiddingCode)code;
-(NSString*)getUnionSdkTracker;
@end

@protocol DMengFeedManagerDelegate <NSObject>
/// 加载成功
- (void)feedAdDidLoad :(DMengFeedAdapter*)feedAd;
/// 加载失败
- (void)feedAdDidFailToLoadWithError:(NSError *)error;
/// 渲染成功
- (void)feedAdDidRender:(DMengFeedAdapter*)feedAd;;
/// 渲染失败
- (void)feedAdDidFailToRenderWithError:(NSError *)error;
/// 广告已经打开
- (void)feedAdDidShow:(DMengFeedAdapter *)feedAd;
/// 广告被点击
- (void)feedAdDidClick:(DMengFeedAdapter *)feedAd;
/// 广告被关闭
- (void)feedAdDidClose:(DMengFeedAdapter *)feedAd;

@end

NS_ASSUME_NONNULL_END
