#ifndef GRAPH_H
#define GRAPH_H

#include "nodeAndEdge.h"
#include <vector>
using namespace std;

template <class G>
class CNode;

template <class G>
class CEdge;

template <class N, class E>
class CGraph
{
public:
        typedef CGraph<N,E> self;
        typedef CNode<self> Node;
        typedef CEdge<self> Edge;
        typedef N n;
        typedef E e;

        vector<Node*> m_nodes;

        void generateNodes(int numNodes);
        void buildGraph();

        int getRandomNumber(int min, int max);

    //public:
        CGraph();
        ~CGraph();

        bool insertNode(N);
        bool removeNode(N);
        bool insertEdge(E,N,N);
        bool removeEdge(E,N,N);

        void printNodes();
        void printEdges();

        const vector<Node*> & getNodesList() const{
            return m_nodes;
        };

};

#endif // GRAPH_H