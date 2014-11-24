//
//  BIDViewController.m
//  0301-Button Fun
//
//  Created by ZhouSu on 14-10-26.
//  Copyright (c) 2014年 ___FULLUSERNAME___. All rights reserved.
//

#import "BIDViewController.h"

/*
@interface BIDViewController ()

@end
 */

@implementation BIDViewController

/*
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
 */

- (IBAction)buttonPressed:(UIButton *)sender {
    
    NSString *title = [sender titleForState: UIControlStateNormal];
    NSString *plainText = [NSString stringWithFormat: @"%@ button pressed", title];
    _statusLabel.text = plainText;
    NSMutableAttributedString *styledText = [[NSMutableAttributedString alloc]
                                             initWithString: plainText];
    NSDictionary *attributes =
    @{
      NSFontAttributeName: [UIFont boldSystemFontOfSize: _statusLabel.font.pointSize]
      };
    
    NSRange namedRange = [plainText rangeOfString: title];
    [styledText setAttributes:attributes range: namedRange];
    _statusLabel.attributedText = styledText;
    
}
@end
