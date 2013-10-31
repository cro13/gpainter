#ifndef CIRCLELAYOUT_H
#define CIRCLELAYOUT_H

#include "Graph.h"

#include "layout.h"

#include "Drawing.h"

#include "Circle.h"

#include "Rectangle.h"

#include "Line.h"

#include <exception>

#include "graph.h"

#include <iostream>

#include "Text.h"

#include <string>

#include <cmath>

class circle_layout : public Layout{

public:

	circle_layout(Graph* g):Layout(g){
	};

	~circle_layout(){

	      
	}

void layout_graph(){


	int x , y , i;
	
	i = 0;

	double alpha = 0;
	int rcerc = 250;


	vector <int> vec = graph->get_nodes();
	

	Graph :: Position p;

	for(vector <int> :: iterator it = vec.begin() ; it != vec.end() ; ++it)
	{
		
		x = rcerc * cos ( alpha ) +2*rcerc;
		y = rcerc * sin ( alpha ) +2*rcerc;
		p.x = x;
		p.y = y;
		graph -> set_node_position(i , p);
		i++;
		alpha += 20;
	}


	}

};

#endif