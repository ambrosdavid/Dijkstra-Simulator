using namespace std;
using namespace sf;
# define INF 0x3f3f3f3f
typedef pair<int, int> iPair;

class Model{
public:
	void popolateGraph(Graph &g){
		g.addEdge(0, 1, 4);
	    g.addEdge(0, 7, 8);
	    g.addEdge(1, 2, 8);
	    g.addEdge(1, 7, 11);
	    g.addEdge(2, 3, 7);
	    g.addEdge(2, 8, 2);
	    g.addEdge(2, 5, 4);
	    g.addEdge(3, 4, 9);
	    g.addEdge(3, 5, 14);
	    g.addEdge(4, 5, 10);
	    g.addEdge(5, 6, 2);
	    g.addEdge(6, 7, 1);
	    g.addEdge(6, 8, 6);
	    g.addEdge(7, 8, 7);
	}


	void shortestPath(int src, vector<GraficNode> &nodi, int V, list< pair<int, int> > *adj)
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
	                Sleep(500);
	            }
	        }
	    }

	    printf("Vertex   Distance from Source\n");
	    for (int i = 0; i < V; ++i)
	        printf("%d \t\t %d\n", i, dist[i]);
	}
};
