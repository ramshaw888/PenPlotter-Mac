//
//  CartesianPlaneViewController.m
//  PenPlotter
//
//  Created by Aaron Ramshaw on 9/07/2014.
//  Copyright (c) 2014 Aaron Ramshaw. All rights reserved.
//

#import "CartesianPlaneViewController.h"
#import "CartesianPlaneView.h"

@interface CartesianPlaneViewController ()

@end

@implementation CartesianPlaneViewController

- (instancetype)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        self.graphPlot = [[CartesianPlaneView alloc] init];
    }
    return self;
}



@end
