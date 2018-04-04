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
	cin >> a >> b >> c >> d;
	Point A,B;
	A.setX(a);A.setY(b);
	B.setX(c);B.setY(d);
	vector<Point>ans;
	graph.pathBetweenNodes(A,B,ans);
	for(auto i = static_cast<int>(ans.size() - 1); i >= 0; --i ){
		cout << ans[i].getX() << ", " << ans[i].getY() << " -> ";
	}
	cout << "//" << endl;
	return 0;
}