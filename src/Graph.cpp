#include <windows.h>
#include <thread>
#include <chrono>
#include <iostream>
#include<bits/stdc++.h>
#include "Graph.h"
using namespace std;
# define INF 0x3f3f3f3f
typedef pair<int, int> iPair;


Graph::Graph(int V)
{
    this->V = V;
    this->matAdj = new int*[V];
    for (int i = 0; i < V; i++) {
    	this->matAdj[i] = new int[V];
    }
    adj = new list<iPair> [V];
}


void Graph::addEdge(int u, int v, int w)
{
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
    matAdj[u][v]=w;
}

/*void shortestPath(int src, vector<GraficNode> &nodi, int V)
	{

	    priority_queue< iPair, vector <iPair> , greater<iPair> > pq;
	    vector<int> dist(V, INF);

	    pq.push(make_pair(0, src));
	    dist[src] = 0;

	    while (!pq.empty())
	    {
	        int u = pq.top().second;
	        pq.pop();

	        list< pair<int, int> >::iterator i;
	        for (i = adj[u].begin(); i != adj[u].end(); ++i)
	        {

	            int v = (*i).first;
	            int weight = (*i).second;

	            if (dist[v] > dist[u] + weight)
	            {
	                dist[v] = dist[u] + weight;
	                pq.push(make_pair(dist[v], v));
	                nodi[v].prevNode=&(nodi[u]);
	                Sleep(3000);
	            }
	        }
	    }

	    printf("Vertex   Distance from Source\n");
	    for (int i = 0; i < V; ++i)
	        printf("%d \t\t %d\n", i, dist[i]);
	}*/
