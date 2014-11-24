//
//  BIDViewController.m
//  0401-ControlFun
//
//  Created by ZhouSu on 14-10-29.
//  Copyright (c) 2014年 ___FULLUSERNAME___. All rights reserved.
//

#import "BIDViewController.h"

@interface BIDViewController ()
@property (weak, nonatomic) IBOutlet UITextField *nameField;
@property (weak, nonatomic) IBOutlet UITextField *numberField;

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

-(IBAction)textFieldDoneEditing:(id)sender
{
    [sender resignFirstResponder];
}

@end
