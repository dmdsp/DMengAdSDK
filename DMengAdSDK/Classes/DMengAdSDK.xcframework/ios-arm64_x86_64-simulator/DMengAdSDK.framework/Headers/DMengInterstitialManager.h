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
/// 初始化插屏广告
/// - Parameter completion: 加载完成后返回的对象
/// - Parameter slotID: 广告位id
- (void)loadInterstitialAdTemplateAdWithSlotID:(nonnull NSString *)slotID completion:(DMengInterstitialManagerCompletion)completion;
@end

NS_ASSUME_NONNULL_END
