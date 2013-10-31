#ifndef GRAPH_H
#define GRAPH_H


#include <iostream>

#include <vector>

#include <string>

#include <cstdlib>

#include "Drawing.h"

#include "Circle.h"

#include "Rectangle.h"

#include "Line.h"

#include "Text.h"


using namespace std;

class Graph {
private:
	vector <int> Nodes;
	

public:
	
    struct Edge {
        const int node1;
        const int node2;

        Edge(const int n1, const int n2) : node1(n1), node2(n2) {}
    };

    struct Position {
        int x;
        int y;
    };

	vector <Edge*> Edges;
	vector <Position> Pos;

	Graph() {};


    void add_node(const int node_id){

		Nodes.push_back(node_id);
	};

    void remove_node(const int node_id){

		int poz;
		for(vector <int> :: iterator it = Nodes.begin(); it != Nodes.end(); ++it)
			{
				if( (*it) == node_id)
			     break;
			 poz++;
		}

		Nodes.erase(Nodes.begin() + poz);

		for(vector <int> :: iterator it = Nodes.begin(); it != Nodes.end(); ++it)
				remove_edge( (*it)  ,node_id);
		
	};

    void add_edge(const int node_id_1, const int node_id_2){

       Edge* e = new Edge(node_id_1 , node_id_2);
	   Edges.push_back(e);

	};

    void remove_edge(const int node_id_1, const int node_id_2){
		
		int poz;
		poz = 0;

		for(vector <Edge*> :: iterator it = Edges.begin() ; it != Edges.end() ; ++it)
			{
				
				if( (*it) -> node1 == node_id_1 && (*it) -> node2 == node_id_2)
						break;
				poz++;
		}

		Edges.erase(Edges.begin() + poz);
	};


    // returns all edges of the graph
    vector<Edge*> get_edges() const{

		return Edges;
	
	};

    // returns all edges of a node
    vector<Edge*> get_edges(const int node_id)const{
		
		vector <Edge*> tmp;
			 
		for(vector <Edge*> :: const_iterator it = Edges.begin() ; it != Edges.end() ; ++it)
			if( (*it) -> node1 == node_id)
			{
				Edge* e = new Edge( (*it) ->node1 , (*it)->node2);
				tmp.push_back(e);
			}
			else
				if( (*it) -> node2 == node_id)
				{
					Edge* e = new Edge( (*it) -> node2 , (*it) -> node1);
					tmp.push_back(e);
				}
			
			return tmp;
		
	};

    // get all nodes of the graph
    vector<int> get_nodes() const{

		return Nodes;
	};

    int get_number_of_vertices()const{
		
		int nr = 0;

		for(vector <int> :: const_iterator it = Nodes.begin() ; it != Nodes.end() ; ++it)
			nr++;

		return nr;
	};

    int get_number_of_edges()const{
		
		int nr = 0;

		for(vector <Edge*> :: const_iterator it = Edges.begin() ; it != Edges.end() ; ++it)
			nr++;
		
		return nr;
	};

    void set_node_position(const int node_id, const Position& new_position){

				Pos.push_back(new_position);
		
	};
    Position get_node_position(const int node_id)const{
		
		Position poz;

		for(vector <int> :: const_iterator it = Nodes.begin() ; it != Nodes.end() ; ++it)
			if( (*it) == node_id)
			{
				poz.x = Pos[node_id-1].x;
				poz.y = Pos[node_id-1].y;
				return poz;
			}
	};

    void as_svg(ostream& out){
		  
	Drawing d;

	d.height = 800;

	d.width = 1200;

	Circle* c;

	Line* l;
	
	Text* t;

	vector <int> vec =get_nodes();
	
	Graph::Position p;
	Graph::Position p1;


	for(vector <int> :: iterator it = vec.begin() ; it != vec.end() ; ++it)
	{
		p=get_node_position(*it);
		c = new Circle();
	    c -> x = p.x;
		c -> y = p.y;
		c -> radius = 20;
		c -> color.set_by_name("blue");

		t = new Text();
		t -> x1 = p.x;
		t -> y1 = p.y;
		t -> txt = to_string((*it));
		t -> color.set_by_name("green");

		d.add_shape(c);
		d.add_shape(t);
	}

	vector<Graph::Edge*> edg = get_edges();


	for(vector <int> :: iterator it = vec.begin() ; it != vec.end() ; ++it)
	{
		for(vector <int> :: iterator its = vec.begin(); its !=vec.end(); ++its)
		
			
			for(vector<Graph :: Edge*> :: iterator x = edg.begin() ; x != edg.end() ; ++x)
				if( (*x) -> node1 == (*it) && (*x) -> node2 == (*its) )
				{
				
					l = new Line();
					p =get_node_position((*x) -> node1);
					p1 =get_node_position((*x) -> node2);
					l -> x1 = p.x;
					l -> x2 = p1.x;
					l -> y1 = p.y;
					l -> y2 = p1.y;
					l -> color.set_by_name("red");
					d.add_shape(l);
					}
			}



	out<<d;
		
	};

    void clear_graph(){
		
		Nodes.clear();
		Edges.clear();
		Pos.clear();

		
	};

};

ostream& operator<<(ostream& out, const Graph& g) {

	vector <int> nodes = g.get_nodes();

	out << "Nodurile sunt: ";

	for(vector <int> :: iterator it = nodes.begin() ; it != nodes.end() ; ++it)
		out << *it << " ";

	out << endl << endl;

	out << "Muchiile sunt: \n";

	vector <Graph :: Edge*> edg = g.get_edges();

	for(vector <Graph :: Edge*> :: iterator it = edg.begin() ; it != edg.end() ; ++it)
	{
		out << (*it) -> node1 << " " << (*it) -> node2 << '\n';
	}
	
	return out;

}

istream& operator>>(istream& in, Graph& h) {

	string del;
	int nrnod;
	in >> del;
	in >> nrnod;

	for(int i = 1 ; i <= nrnod ; i ++)
	{
		int nod;
		in >> nod;
		h.add_node(nod);
		in >> del;
	}

	int arcs;
	in >> del;
	in >> arcs;

	for(int i = 1 ; i <= arcs ; i++)
	{
		int x , y;
		in >> x >> y;
		h.add_edge(x , y);
	}

	return in;

}



#endif
