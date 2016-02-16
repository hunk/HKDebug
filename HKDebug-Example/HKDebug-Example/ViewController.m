//
//  ViewController.m
//  HKDebug-Example
//
//  Created by hunk on 2/16/16.
//  Copyright © 2016 hunk. All rights reserved.
//

#import "ViewController.h"
#import "HKDebug.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    
    // Debug
    HKNormal(@"normal log without color, but whit the format of HK");
    HKVerbose(@"normal log with Verbose in gray");
    HKDebug(@"this line is with a debug word in %@",@"blue");
    HKInfo(@"a info log");
    HKWarning(@"oh, no, oh no, this is not happening");
    HKError(@"aahhhhh, help!!!!!!");
    HKAlt(@"alternative color");
    HKOpt(@"optional color");
    
    //All line is in color
    HKFullColor(true);
    HKVerbose(@"this is a integer %zd",123);
    HKInfo(@"and this is a float %f",-123.45678);
    HKWarning(@"a date:%@",[NSDate date]);
    HKError(@"array %@",@[@"item 1", @"item 2", @"item 3"]);
    HKAlt(@"dictionary %@",@{@"name": @"Edgar G", @"nick": @"@hunk"});

}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
