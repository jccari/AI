#include "graph.cpp"

using namespace std;

int menu()
{
	int choose;
	cout << " \n\t LITTLE GRAPH \n";
	cout << " [1] Insert Node\n [2] Insert Edge\n [3] Remove Node\n [4] Remove Edge\n [5] Find Node\n [6] Print Nodes\n [7] Print Edges\n [0] Done "<< endl;
	cout << " Choose a opcion -> " ; cin>> choose;
	return choose;
}

int main()
{
	CGraph<string, int> g;
	g.insertNode("A");
	g.insertNode("B");
	g.insertNode("C");
	g.insertNode("D");
	g.insertEdge(1,"A","A");

	g.insertEdge(1,"A","B");
	g.insertEdge(2,"B","C");
	g.insertEdge(2,"B","D");

	g.insertEdge(3,"C","D");
	g.insertEdge(3,"A","D");

	g.printNodes();
	g.printEdges();

    //g.removeEdge(2,"B","C");
    //g.removeNode("A");

	return 0;
}