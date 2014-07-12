//
//  CartesianPlaneView.h
//  PenPlotter
//
//  Created by Aaron Ramshaw on 8/07/2014.
//  Copyright (c) 2014 Aaron Ramshaw. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@interface CartesianPlaneView : NSView

@property NSMutableArray *pointsWhite;
@property NSMutableArray *pointsGreen;

-(void) plotWhitePoints:(NSMutableArray*) points;
-(void) plotGreenPoints:(NSMutableArray*) points;

@end
