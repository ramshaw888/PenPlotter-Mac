//
//  Line.h
//  PenPlotter
//
//  Created by Aaron Ramshaw on 27/06/2014.
//  Copyright (c) 2014 Aaron Ramshaw. All rights reserved.
//

typedef struct line * Line;
typedef struct lineList * LineList;

LineList initialiseLineList(void);
void addLine( LineList l, int points[] );

LineList duplicateLineList( LineList l );

void printUndrawnLines( LineList l );
int count( LineList l );

void freeLines( LineList l );
void freeLineNodes( Line l );

double getHeuristicValue( LineList l );

int size( LineList l );

Line getLineListTop( LineList l );

Line newLine( Line l );
Line newLineReverse( Line l );

double distance( int x1, int y1, int x2, int y2 );

int getx1 (Line l);
int gety1 (Line l);
int getx2 (Line l);
int gety2 (Line l);

void removeLineFromList( Line l, LineList ll );

Line getNextLine( Line l );