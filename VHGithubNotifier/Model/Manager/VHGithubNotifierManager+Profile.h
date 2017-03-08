//
//  VHGithubNotifierManager+Profile.h
//  VHGithubNotifier
//
//  Created by viktorhuang on 2017/3/8.
//  Copyright © 2017年 黄伟平. All rights reserved.
//

#import "VHGithubNotifierManager.h"

@interface VHGithubNotifierManager (Profile)

#pragma mark - Cookie

- (void)startTimerOfProfile;

- (void)stopTimerOfProfile;

- (void)updateProfile;

- (VHLoadStateType)contributionLoadState;

- (BOOL)loginCookieExist:(BOOL)sendNotification;

@end