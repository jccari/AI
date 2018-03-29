#include "graph.h"
#include <iostream>

using namespace std;

template <class N,class E>
CGraph<N,E>::CGraph(){}

template <class N,class E>
CGraph<N,E>::~CGraph(){}

template <class N,class E>
bool CGraph<N,E>::insertNode(N x)
{
	Node* tmp = new Node(x);
	m_nodes.push_back(tmp);
	cout << ">> [OK]: Node "<< x << " Insertion Successful " << endl;
	return 1;
}

template <class N,class E>
bool CGraph<N,E>::insertEdge(E x, N a, N b)
{
	Node* Na ;Node* Nb;
	for(int i=0; i< m_nodes.size() ;i++){
		if(m_nodes[i]->m_data == a ) Na = m_nodes[i];
		if(m_nodes[i]->m_data == b ) Nb = m_nodes[i];
	}
	//poner condicion para que Na y Nb existan!!!!!!!!!!!!!!!
    if (Na == nullptr or Nb== nullptr ){
        cout << ">> [ERROR]: Cant remove Edge, check if exists nodes" << endl;
        return false;
    }

	Edge* tmp = new Edge(x,Na, Nb);
	Na->m_edges.push_back( new Edge(x,Na, Nb) );
    if ( Na != Nb)
	    Nb->m_edges.push_back( new Edge(x,Nb, Na) );

	cout << ">> [OK]: Edge "<< Na->m_data << " to "<< Nb->m_data << " Insertion Successful" << endl;
	return 1;
}

template <class N,class E>
bool CGraph<N,E>::removeNode(N x)
{
	Node* tmp = nullptr;
	for(int i=0; i< m_nodes.size(); i++){
		if(m_nodes[i]->m_data == x){ 
			tmp = m_nodes[i];
			for(int j=0; j<tmp->m_edges.size(); j++)
				removeEdge(tmp->m_edges[i]->m_data, tmp->m_edges[i]->m_node[0]->m_data, tmp->m_edges[i]->m_node[1]->m_data);

			cout << ">> [OK]: Node "<< tmp->m_data <<" Deleting ... " << endl;
			m_nodes.erase(m_nodes.begin()+i);
		}
	}

    printNodes();
	printEdges();
	return 1;
}

template <class N,class E>
bool CGraph<N,E>::removeEdge(E x, N a, N b)
{
	Node* Na; Node* Nb;
	for(int i=0; i< m_nodes.size() ;i++){
		if(m_nodes[i]->m_data == a ) Na = m_nodes[i];
		if(m_nodes[i]->m_data == b ) Nb = m_nodes[i];
	}
	Edge* borrar;
	//if(Na) // poner cond para que exista Na
	for(int i=0; i< Na->m_edges.size() ;i++)
		if(Na->m_edges[i]->m_data==x){
			borrar = Na->m_edges[i];
			Na->m_edges.erase(Na->m_edges.begin()+i);
		}

	delete borrar;
    cout << ">> [OK]: Removing edge: " + Na->m_data +" - "+ Nb->m_data << endl;
	printEdges();
	return 1;
}



template <class N,class E>
void CGraph<N,E>::printNodes()
{
	cout << "\n Nodes List: ";
	for(int i=0; i<m_nodes.size(); i++)
		cout << m_nodes[i]->m_data << " - " ;
	cout << endl;
}


template <class N,class E>
void CGraph<N,E>::printEdges()
{
	cout << "\n Edges List: "<< endl;
	for(int i=0; i<m_nodes.size();i++){
		for(int j=0; j<m_nodes[i]->m_edges.size();j++){
			cout << " [ "<<i<<" ] "<< m_nodes[i]->m_edges[j]->m_node[0]->m_data << " to " << m_nodes[i]->m_edges[j]->m_node[1]->m_data 
				 <<" with " << m_nodes[i]->m_edges[j]->m_data  << endl;
		}	
	}
	
}
