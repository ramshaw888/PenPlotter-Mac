//
//  Queue.h
//  PenPlotter
//
//  Created by Aaron Ramshaw on 27/06/2014.
//  Copyright (c) 2014 Aaron Ramshaw. All rights reserved.
//

#include "Line.h"

typedef struct qNode * Node;
typedef struct priorityQueue * Queue;

Queue initialiseQueue( LineList l );
void printQueue( Queue q );
void freeQueue( Queue q );
void freeNode( Node n );

void push( Node n, Queue q );
Node pop( Queue q );
Node peek( Queue q );

double getFunctionValue( Node n );

LineList getLines( Node n );

Node duplicateNode( Node n );

int addLineToNode( Line l, Node n );

Line getDirectionA( Line l );

Line getDirectionB( Line l );

void setParent( Node child, Node parent );

void backtrack( Node endpoint );

int sizeOfQueue( Queue q );