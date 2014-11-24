//
//  BIDViewController.m
//  0503-Restructure
//
//  Created by ZhouSu on 14-11-10.
//  Copyright (c) 2014年 ___FULLUSERNAME___. All rights reserved.
//

#import "BIDViewController.h"

@interface BIDViewController ()

@property (weak, nonatomic) IBOutlet UIButton *actionButton1;
@property (weak, nonatomic) IBOutlet UIButton *actionButton2;
@property (weak, nonatomic) IBOutlet UIButton *actionButton3;
@property (weak, nonatomic) IBOutlet UIButton *actionButton4;
@property (weak, nonatomic) IBOutlet UIView *contentView;

@end

@implementation BIDViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (void)doLayoutForOrientation: (UIInterfaceOrientation) orientation{
     if (UIInterfaceOrientationIsPortrait(orientation))
     {
         [self layoutPortrait];
     } else {
         [self layoutLandscape];
     }
}

- (void)layoutPortrait {
    
}

- (void)layoutLandscape {
    
}

- (void)willAnimateRotationToInterfaceOrientation:(UIInterfaceOrientation)toInterfaceOrientation duration:(NSTimeInterval)duration {
    [self doLayoutForOrientation:toInterfaceOrientation];
}

@end
