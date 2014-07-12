//
//  PenPlotter.h
//  PenPlotter
//
//  Created by Aaron Ramshaw on 28/06/2014.
//  Copyright (c) 2014 Aaron Ramshaw. All rights reserved.
//

#import <Foundation/Foundation.h>
#include "Queue.h"
@interface PenPlotter : NSObject
@property Queue q;

-(void) initialiseQueue:(Queue) q;
-(void) printQueue;
-(void) freeQueue;
-(NSString*) search;
-(BOOL) isEmpty;
@end
