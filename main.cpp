#include <iostream>
#include "graph.h"
#include <time.h>
#include "Random_layout.h"
#include <fstream>
#include "Circle_Layout.h"

ifstream f("graf.in");
ofstream os("graf.svg");

using namespace std;

int main()
{
	Graph G;

	f >> G;

	cout << G;

	cout << endl << endl << endl;

	srand((unsigned)time(NULL));

	/*  //test-afisarea muchiilor cu capatul in 1
	vector<Graph::Edge*> tst;
	tst=G.get_edges(1);
	for(vector<Graph::Edge*>::iterator it=tst.begin();it!=tst.end();++it)
		cout<<(*it)->node1<<" "<<(*it)->node2<<endl;
		*/

	cout << "Ce layout vrei aplici Grafului\n 1.Layout Radom\n 2.Layout in cerc\n Apasa 0 pentru a iesi din meniu\n";
	int read = 1 , option ;

	while ( read ) {

	cin >> option;

	switch ( option ) {

	case 0 : {
		        return 0;
			}

	case 1 : {

				rand_layout rand(&G);
				rand.layout_graph();
				G.as_svg(os);
				cout<<"Layout successfully generated\n";
				break;

			 }

	case 2 : {

				circle_layout circ(&G);
				circ.layout_graph();
				G.as_svg(os);
				cout<<"Layout successfully generated\n";
				break;
			}
			 break;
	}

}
	

	system("pause");

	return 0;
}