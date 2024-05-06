//
//  DMViewController.m
//  DMengAdSDK
//
//  Created by 714145936@qq.com on 05/06/2024.
//  Copyright (c) 2024 714145936@qq.com. All rights reserved.
//

#import "DMViewController.h"
#import <DMAdSDK/DMAds.h>

@interface DMViewController ()

@end

@implementation DMViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    [[DMAds shareInstance] initSDK];
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
