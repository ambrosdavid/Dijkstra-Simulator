#include <iostream>
#include<bits/stdc++.h>
#include "GraficNode.h"
using namespace std;

class Graph
{


public:
	int V;    // No. of vertices
	int **matAdj;
	    // In a weighted graph, we need to store vertex
	    // and weight pair for every edge
	list< pair<int, int> > *adj;
    Graph(int V);  // Constructor

    // function to add an edge to graph
    void addEdge(int u, int v, int w);

    // prints shortest path from s
    //void shortestPath(int s, vector<GraficNode> &nodi);
};
