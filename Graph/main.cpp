#include "graph.cpp"

using namespace std;

int main()
{
	CGraph<Point, int> graph;
	cout << "GRAPH NODES" << endl;
	graph.printNodes();
	cout << "GRAPH EDGES" << endl;
	graph.printEdges();
	cout << "Insert Nodes to find path" << endl;
	int a,b,c,d;
    //1 double distance = 0f;
	cin >> a >> b >> c >> d;
	Point A,B;
	A.setX(a);A.setY(b);
	B.setX(c);B.setY(d);
	vector<Point>ans;
	int distance = graph.pathBetweenNodes(A,B,ans);
	for(auto i = static_cast<int>(ans.size() - 1); i >= 0; --i ){
		cout << ans[i].getX() << ", " << ans[i].getY() << " -> ";
	}
	cout << "//" << endl;
    cout << "COSTO DEL RECORRIDO: " << distance << endl;
	return 0;
}