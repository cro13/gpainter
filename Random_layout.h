#ifndef RANDOMLAYOUT_H
#define RANDOMLAYOUT_H

#include "Graph.h"

#include "layout.h"

#include "Drawing.h"

#include "Circle.h"

#include "Rectangle.h"

#include "Line.h"

#include <exception>

#include "graph.h"

#include "Text.h"

#include <string>

#include <fstream>

ofstream g("random.svg");

class rand_layout:public Layout{

public:

	rand_layout(Graph* g):Layout(g){

	};

	~rand_layout(){

	      
	}

void layout_graph(){

	int x , y , i;
	
	i = 0;

	Graph::Position p;
	vector <int> vec = graph -> get_nodes();

	for(vector <int> :: iterator it = vec.begin() ; it != vec.end() ; ++it)
	{
		
		x = rand() % 600;
		y = rand() % 700;
		p.x = x;
		p.y = y;
		graph -> set_node_position(*it,p);
		i++;
	}



	}

   
};


#endif