//
//  DMengAdCache.h
//  DMengAdSDK
//
//  Created by 刘士林 on 2024/6/12.
//

#import <Foundation/Foundation.h>

#import <DMengSDKAdapter/DMengSplashAdapter.h>
#import <DMengSDKAdapter/DMengFeedAdapter.h>
#import <DMengSDKAdapter/DMengBannerAdapter.h>
#import <DMengSDKAdapter/DMengInterstitialAdapter.h>
#import <DMengSDKAdapter/DMengRewardedVideoAdapter.h>
NS_ASSUME_NONNULL_BEGIN

@interface DMengAdCache : NSObject
+ (instancetype)sharedCache;

- (DMengFeedAdapter *)cachedFeedAdForSlotID:(NSString *)slotID;
- (void)cacheFeedAd:(DMengFeedAdapter *)adapter forSlotID:(NSString *)slotID;

- (DMengBannerAdapter *)cachedBannerAdForSlotID:(NSString *)slotID;
- (void)cacheBannerAd:(DMengBannerAdapter *)adapter forSlotID:(NSString *)slotID;

- (DMengInterstitialAdapter *)cachedInterstitialAdForSlotID:(NSString *)slotID;
- (void)cacheInterstitialAd:(DMengInterstitialAdapter *)adapter forSlotID:(NSString *)slotID;

- (DMengRewardedVideoAdapter *)cachedRewardedVideoAdForSlotID:(NSString *)slotID;
- (void)cacheRewardedVideoAd:(DMengRewardedVideoAdapter *)adapter forSlotID:(NSString *)slotID;
@end

NS_ASSUME_NONNULL_END
