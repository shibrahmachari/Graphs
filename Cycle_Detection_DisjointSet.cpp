#include<bits/stdc++.h>
using namespace std;
struct Edge{
	int src, dest, weight;
};
struct Graph{
	int V,E;

	struct Edge* edge;						//Array of edges
};
struct Graph* createGraph(int V, int E){
	struct Graph* graph = new Graph;
	graph->V = V;
	graph->E = E;
	graph->edge = new Edge[graph->E];
	return graph;
}
int find(int* parent, int x){
	if(parent[x] == -1)
		return x;

	return find(parent, parent[x]);
}
void Union(int* parent, int x, int y){
	int xset = find(parent, x);
	int yset = find(parent, y);

	if(xset!= yset)
		parent[xset] = yset;
}
int isCycle(Graph* graph){
	int* parent = new int[graph->V];
	for(int i = 0;i<graph->V;i++)
		parent[i] = -1;

	for(int i = 0;i<graph->E;i++){
		int x = find(parent, graph->edge[i].src);
		int y = find(parent, graph->edge[i].dest);

		if(x == y)
			return 1;

		Union(parent, x, y);
	}
	return 0;
}
int main()  
{  
    /* Let us create the following graph  
        0  
        | \  
        | \  
        1-----2 */
    int V,E;
    cin>>V>>E; 
    Graph* graph = createGraph(V, E);  
  	for(int i = 0;i<E;i++){
  		int u,v;
  		cin>>u>>v;
  	graph->edge[i].src = u;  
    graph->edge[i].dest = v;  
  	}
    if (isCycle(graph))  
        cout<<"graph contains cycle";  
    else
        cout<<"graph doesn't contain cycle";  
  
    return 0;  
}  
