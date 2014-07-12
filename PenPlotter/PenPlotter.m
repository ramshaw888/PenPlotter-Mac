//
//  PenPlotter.m
//  PenPlotter
//
//  Created by Aaron Ramshaw on 28/06/2014.
//  Copyright (c) 2014 Aaron Ramshaw. All rights reserved.
//

#import "PenPlotter.h"
#include "Queue.h"
#include "Line.h"


@implementation PenPlotter

-(void) initialiseQueue:(Queue) q {
    self.q = q;
}

-(void) printQueue {
    printQueue(self.q);
}

-(void) freeQueue {
    freeQueue(self.q);
}


-(NSString*) search {
    Node curr = peek(self.q);
    
    int i = 0;
    while( size(getLines(curr)) != 0 ) {
        curr = pop(self.q);
        
        LineList ll = getLines(curr);
        Line lineCurr = getLineListTop( ll );
        while( lineCurr != NULL ) {
            Node new = duplicateNode(curr);
            if( addLineToNode( getDirectionA(lineCurr), new ) ) {
                setParent( new, curr );
                push( new, self.q );
            }
            
            new = duplicateNode(curr);
            if( addLineToNode( getDirectionB(lineCurr), new ) ) {
                setParent( new, curr );
                push( new, self.q );
            }
            
            lineCurr = getNextLine(lineCurr);
        }
        i++;
        NSLog(@"Node number %d", i );
    }
    
    NSLog(@"Completed A* search, backtracking");
    backtrack(curr);
    NSString *number = [NSString stringWithFormat:@"%d",i];
    return number;
}

-(BOOL) isEmpty {
    if( _q != NULL ) {
        return NO;
    } else {
        return YES;
    }
}
@end
