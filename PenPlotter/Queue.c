//
//  PQueue.c
//  PenPlotter
//
//  Created by Aaron Ramshaw on 26/06/2014.
//  Copyright (c) 2014 Aaron Ramshaw. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Line.h"
#include "Queue.h"


struct qNode {
    LineList undrawnLines;
    int x1;
    int x2;
    int y1;
    int y2;
    double g;
    Node next;
    Node parent;
};


struct priorityQueue {
    Node top;
    int size;
};


Queue initialiseQueue( LineList l ) {
    Queue q = malloc( sizeof( *q ) );
    q->top = malloc( sizeof( struct qNode ) );
    q->top->undrawnLines = duplicateLineList(l);
    q->top->x1 = 0;
    q->top->x2 = 0;
    q->top->y1 = 0;
    q->top->y2 = 0;
    q->top->g = 0;
    q->top->next = NULL;
    q->top->parent = NULL;
    q->size = 1;
    return q;
}

void printQueue( Queue q ) {
    printf("Print queue\n");
    if( q != NULL && q->size != 0 ) {
        Node curr = q->top;
        int i = 0;
        while( curr != NULL ) {
            printf("%dth node\n", i );
            printUndrawnLines(curr->undrawnLines);
            curr = curr->next;
        }
    }
}

void freeQueue( Queue q ) {
    if( q != NULL ) {
        freeNode(q->top);
        q->size = 0;
    }
}

void freeNode( Node n ) {
    if( n->next != NULL ) {
        freeNode(n->next);
    }
    freeLines(n->undrawnLines);
    free( n );
}

void push( Node n, Queue q ) {
    
    double currFunctionValue = getFunctionValue(n);
    Node curr = q->top;
    Node prev = NULL;
    
    while( curr != NULL && currFunctionValue > getFunctionValue(curr) && curr->next != NULL ) {
        prev = curr;
        curr = curr->next;
    }
    
    if( prev == NULL ) {
        q->top = n;
        n->next = curr;
    } else if( curr == NULL ) {
        q->top = n;
        n->next = NULL;
    } else {
        prev->next = n;
        n->next = curr;
    }
    q->size++;

}

Node pop( Queue q ) {
    if( q != NULL ) {
        Node next = q->top;
        q->top = q->top->next;
        q->size--;
        return next;
    } else {
        return NULL;
    }
}

Node peek( Queue q ) {
    if( q != NULL ) {
        return q->top;
    } else {
        return NULL;
    }
}

double getFunctionValue( Node n ) {
    return n->g + getHeuristicValue(n->undrawnLines);
}

LineList getLines( Node n ) {
    return n->undrawnLines;
}

Node duplicateNode( Node n ) {
    Node new = malloc( sizeof( struct qNode ) );
    new->x1 = n->x1;
    new->x2 = n->x2;
    new->y1 = n->y1;
    new->y2 = n->y2;
    new->g = n->g;
    new->next = NULL;
    new->parent = NULL;
    new->undrawnLines = duplicateLineList(n->undrawnLines);
    return new;
}

int addLineToNode( Line l, Node n ) {
    if( n->x2 != getx2( l ) || n->y2 != gety2( l ) ) {
        
        n->g = n->g + distance( getx1(l), gety1(l), getx2(l), gety2(l) );
        n->g = n->g + distance( getx1(l), gety1(l), n->x2, n->y2 );
        
        n->x1 = getx1( l );
        n->x2 = getx2( l );
        n->y1 = gety1( l );
        n->y2 = gety2( l );
        
        removeLineFromList( l, n->undrawnLines );
        return 1;
    }
    
    return 0;
}

Line getDirectionA( Line l ) {
    Line a = newLine( l );
    return a;
}

Line getDirectionB( Line l ) {
    Line b = newLineReverse( l );
    return b;
}

void setParent( Node child, Node parent ) {
    child->parent = parent;
}

void backtrack( Node endpoint ) {
    
    Node p = endpoint;
    while( p != NULL ) {
        printf("%d %d to %d %d\n", p->x1, p->y1, p->x2, p->y2 );
        p = p->parent;
    }
    
    
}

int sizeOfQueue( Queue q ) {
    return q->size;
}
