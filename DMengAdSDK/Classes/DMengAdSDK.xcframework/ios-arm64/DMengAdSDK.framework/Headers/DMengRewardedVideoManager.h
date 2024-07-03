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
/// 初始化激励视频和配置、代理
/// - Parameter delegate: 代理
/// - Parameter slotID: 广告位id
/// - Parameter model:  额外的数据
- (void)loadRewardedVideoAdTemplateAdWithSlotID:(NSString *)slotID withRewarVideoModel:(DMengRewarVideoModel*)model completion:(DMengRewardedVideoManagerCompletion)completion;
@end

NS_ASSUME_NONNULL_END
