//
//  DMengFeedManager.h
//  DMengAdSDK
//
//  Created by 刘士林 on 2024/5/22.
//

#import <Foundation/Foundation.h>

#import <DMAdSDK/DMAds.h>
#import <DMAdSDK/DM_Macro.h>
#import <DMAdSDK/DMUnionModel.h>
#import <DMengSDKAdapter/DMengSDKAdapter.h>

NS_ASSUME_NONNULL_BEGIN
@interface DMengFeedManager : NSObject
typedef void(^DMengFeedManagerCompletion)(DMengFeedAdapter * feedAdapter);
/// 初始化
/// - Parameter completion: 加载完成后返回的对象
/// - Parameter slotID: 广告位id
/// - Parameter isHidden:设置点击关闭时弹出视图是否隐藏，是为隐藏
- (void)loadFeedAdTemplateAdWithSlotID:(nonnull NSString *)slotID popupViewHidden:(BOOL)isHidden completion:(DMengFeedManagerCompletion)completion;
@end

NS_ASSUME_NONNULL_END
