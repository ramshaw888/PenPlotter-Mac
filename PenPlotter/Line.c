//
//  Line.c
//  PenPlotter
//
//  Created by Aaron Ramshaw on 26/06/2014.
//  Copyright (c) 2014 Aaron Ramshaw. All rights reserved.
//

#include <stdlib.h>
#include <stdio.h>
#include "Line.h"
#include <Math.h>

struct lineList {
    Line head;
    int size;
};

struct line {
    int x1;
    int y1;
    int x2;
    int y2;
    Line next;
};

LineList initialiseLineList(void) {
    LineList l = malloc( sizeof( *l ) );
    l->head = NULL;
    l->size = 0;
    return l;
}

void addLine( LineList l, int points[] ) {
    l->size++;
    Line curr = malloc( sizeof(struct line) );
    curr->x1 = points[0];
    curr->y1 = points[1];
    curr->x2 = points[2];
    curr->y2 = points[3];
    curr->next = l->head;
    l->head = curr;
}


LineList duplicateLineList( LineList l ) {

    LineList new = initialiseLineList();
    new->size = l->size;
    Line currOld = l->head;
    Line curr;
    Line prev;
    prev = new->head;
    int i = 0;
    
    for( i = 0; i < l->size; i++ ) {
        curr = malloc( sizeof( struct line ) );
        if( i == 0 ) {
            new->head = curr;
        } else {
            prev->next = curr;
        }
        curr->x1 = currOld->x1;
        curr->y1 = currOld->y1;
        curr->x2 = currOld->x2;
        curr->y2 = currOld->y2;
        
        currOld = currOld->next;
        prev = curr;
        if( currOld != NULL ) {
            curr = curr->next;
        } else {
            curr->next = NULL;
            
        }
    }

    return new;
}

void printUndrawnLines( LineList l ) {
    printf("linelist size is %d\n", l->size );
    Line curr = l->head;
    int i = 0;
    if( curr == NULL ) {
        printf("top is null\n");
    }
    while( curr != NULL && l->size != 0 ) {
        printf("\t%d. %d %d to %d %d\n", i, curr->x1, curr->y1, curr->x2, curr->y2 );
        curr = curr->next;
        i++;
    }
}

int count( LineList l ) {
    return l->size;
}

void freeLines( LineList l ) {
    freeLineNodes(l->head);
    free( l );
}

void freeLineNodes( Line l ) {
    if( l != NULL && l->next != NULL ) {
        freeLineNodes(l->next);
    }
    free(l);
}

double getHeuristicValue( LineList l ) {
    return 0.0;
}

int size( LineList l ) {
    return l->size;
}

Line getLineListTop( LineList l ) {
    return l->head;
}

Line newLine( Line l ) {
    Line new = malloc( sizeof( struct line ) );
    new->x1 = l->x1;
    new->x2 = l->x2;
    new->y1 = l->y1;
    new->y2 = l->y2;
    new->next = NULL;
    return new;
}
Line newLineReverse( Line l ) {
    Line new = malloc( sizeof( struct line ) );
    new->x1 = l->x2;
    new->x2 = l->x1;
    new->y1 = l->y2;
    new->y2 = l->y1;
    new->next = NULL;
    return new;
}

double distance( int x1, int y1, int x2, int y2 ) {
    double dist = 0.0;
    dist = (x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2);
    dist = sqrt(dist);
    return dist;
}

int getx1 (Line l) {
    return l->x1;
}
int gety1 (Line l) {
    return l->y1;
}
int getx2 (Line l) {
    return l->x2;
}
int gety2 (Line l) {
    return l->y2;
}

void removeLineFromList( Line l, LineList ll ) {
    ll->size--;
    Line curr = ll->head;
    Line prev = NULL;
    
    while( curr != NULL ) {
        if( (l->x1 == curr->x1 && l->y1 == curr->y1 && l->x2 == curr->x2 && l->y2 == curr->y2) || (l->x1 == curr->x2 && l->y1 == curr->y2 && l->x2 == curr->x1 && l->y2 == curr->y1) ) {
            
            // single item
            if( prev == NULL && curr->next == NULL ) {
                ll->head = NULL;
                free( curr );
            }
            // first item (not single)
            else if( prev == NULL ) {
                ll->head = curr->next;
                free( curr );
            }
            // last item
            else if( curr->next == NULL ) {
                prev->next = NULL;
                free( curr );
            }
            // normal case
            else {
                prev->next = curr->next;
                free( curr );
            }
            return;
        }
        prev = curr;
        curr = curr->next;
    }
}

Line getNextLine( Line l ) {
    return l->next;
}