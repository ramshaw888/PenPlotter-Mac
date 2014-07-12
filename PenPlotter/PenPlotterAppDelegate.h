//
//  PenPlotterAppDelegate.h
//  PenPlotter
//
//  Created by Aaron Ramshaw on 8/06/2014.
//  Copyright (c) 2014 Aaron Ramshaw. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "PenPlotter.h"
#import "CartesianPlaneView.h"

@interface PenPlotterAppDelegate : NSObject <NSApplicationDelegate>

@property (assign) IBOutlet NSWindow *window;
@property PenPlotter *p;
- (IBAction)addLines:(id)sender;
- (IBAction)plot:(id)sender;
- (IBAction)printQueueToLog:(id)sender;
- (IBAction)resetQueue:(id)sender;
@property (weak) IBOutlet NSTextFieldCell *output;
@property (weak) IBOutlet NSTextField *nodesExpandedCount;
//@property (nonatomic, strong) IBOutlet CartesianPlaneView *Plot;
@property (nonatomic, strong) IBOutlet CartesianPlaneView *graphPlot;


@property (weak) IBOutlet NSTextFieldCell *plotOut;



@end
