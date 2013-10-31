#ifndef LAYOUT_H
#define LAYOUT_H

#include "Graph.h"

class Layout {

protected:
    Graph* graph;

public:

    Layout(Graph* g){

		graph = g;
		
	};

    virtual ~Layout() {
	

	}

    virtual void layout_graph() =0;
};

#endif

