//
//  CartesianPlaneView.m
//  PenPlotter
//
//  Created by Aaron Ramshaw on 8/07/2014.
//  Copyright (c) 2014 Aaron Ramshaw. All rights reserved.
//

#import "CartesianPlaneView.h"
#import "PenPlotter.h"

@implementation CartesianPlaneView

- (instancetype)initWithFrame:(NSRect)frame
{
    self = [super initWithFrame:frame];
    if (self) {
        _pointsWhite = [[NSMutableArray alloc] init];
        _pointsGreen = [[NSMutableArray alloc] init];
    }
    return self;
}

- (void)drawRect:(NSRect)dirtyRect
{
    [super drawRect:dirtyRect];
    NSLog(@"Drawing");
    
    CGContextRef context = (CGContextRef)[[NSGraphicsContext currentContext] graphicsPort];
    CGContextSetRGBFillColor(context, 0, 0, 0, 1);
    CGContextFillRect(context, NSRectToCGRect(dirtyRect));
    
    CGContextSetStrokeColorWithColor(context, [NSColor whiteColor].CGColor);
    CGContextSetLineWidth(context, 2);
    CGMutablePathRef pathRef = CGPathCreateMutable();
    CGPathMoveToPoint(pathRef, NULL, 0, 0);
    
    CGPathAddLineToPoint(pathRef, NULL, 100, 120 );

    NSLog(@"Points count is %lu",[_pointsWhite count] );
    
    for( int i = 0; i < [_pointsWhite count]; i+=2 ) {
        NSNumber *x = [_pointsWhite objectAtIndex:i];
        NSNumber *y = [_pointsWhite objectAtIndex:i+1];
        CGPathAddLineToPoint(pathRef, NULL, [x floatValue]*10, [y floatValue]*10 );
    }

    CGContextAddPath(context, pathRef);
    CGContextStrokePath(context);
    
    CGPathRelease(pathRef);

    
}

-(void) plotWhitePoints:(NSMutableArray*) points {
    self.pointsWhite = points;
    NSLog(@"Points set for graph");
}
-(void) plotGreenPoints:(NSMutableArray*) points {
    self.pointsGreen = points;
   // [super setNeedsDisplay:YES];
}

@end
