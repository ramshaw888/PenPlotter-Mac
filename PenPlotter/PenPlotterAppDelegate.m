//
//  PenPlotterAppDelegate.m
//  PenPlotter
//
//  Created by Aaron Ramshaw on 8/06/2014.
//  Copyright (c) 2014 Aaron Ramshaw. All rights reserved.
//

#import "PenPlotterAppDelegate.h"
#include "Queue.h"
#include "Line.h"

@implementation PenPlotterAppDelegate

- (void)applicationDidFinishLaunching:(NSNotification *)aNotification
{
    self.p = [[PenPlotter alloc] init];
    self.graphPlot = [[CartesianPlaneView alloc] initWithFrame:[_window frame]];
}

- (IBAction)addLines:(id)sender {
    
    NSArray *listItems = [[sender stringValue] componentsSeparatedByString:@"\n"];
    NSMutableArray *plotPoints = [[NSMutableArray alloc] init];
    
    LineList l = initialiseLineList();
    
        if( [listItems count] > 0 ) {
    
    
            for( NSString *line in listItems ) {
                // get points from line
                NSArray *lineArray = [line componentsSeparatedByString:@" "];
        
                int points[4];
                if( [lineArray count] == 7 ) {
                    points[0] = [[lineArray objectAtIndex:(NSUInteger) 2] integerValue];
                    points[1] = [[lineArray objectAtIndex:(NSUInteger) 3] integerValue];
                    points[2] = [[lineArray objectAtIndex:(NSUInteger) 5] integerValue];
                    points[3] = [[lineArray objectAtIndex:(NSUInteger) 6] integerValue];
                    addLine(l, points);
                    
                    NSNumber *i = [NSNumber numberWithInt:points[0]];
                    [plotPoints addObject: i ];
                    i = [NSNumber numberWithInt:points[1]];
                    [plotPoints addObject: i ];
                    i = [NSNumber numberWithInt:points[2]];
                    [plotPoints addObject: i ];
                    i = [NSNumber numberWithInt:points[3]];
                    [plotPoints addObject: i ];
                    
                }
        
            }
            if( [plotPoints count] > 0 ) {
                [self.graphPlot plotWhitePoints:plotPoints];
            }
            [self.graphPlot setNeedsDisplay:YES];
    
            Queue q = initialiseQueue(l);
            [_p initialiseQueue: q];
            [_p printQueue];

        }
    
    
}


- (IBAction)plot:(id)sender {
    if( ![_p isEmpty] ) {
        NSString *num = [ _p search ];
        NSLog(@"%@", num);
        self.nodesExpandedCount.stringValue = num;
    }
    
}
- (IBAction)printQueueToLog:(id)sender {
    [_p printQueue];
}

- (IBAction)resetQueue:(id)sender {
    [_p freeQueue];
    self.p = [[PenPlotter alloc] init];
    NSLog(@"Queue resetted");
}
@end
