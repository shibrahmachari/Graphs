#include<bits/stdc++.h>
using namespace std;
struct Edge{
	int src, dest, weight;
};
struct subset{
	int parent, rank;
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
int find(struct subset subsets[], int x){
	if(subsets[x].parent != x)
		subsets[x].parent = find(subsets, subsets[x].parent);

	return subsets[x].parent;
}
void Union(struct subset subsets[], int x, int y){
	int xset = find(subsets, x);
	int yset = find(subsets, y);

	if(subsets[xset].rank<subsets[yset].rank)
		subsets[xset].parent = yset;
	else if(subsets[xset].rank>subsets[yset].rank)
		subsets[yset].parent = xset;

	else{
		subsets[xset].parent = yset;
		subsets[yset].rank++;
	}
}

int isCycle(Graph* graph){
	struct subset subsets[graph->V];
	for (int v = 0; v < graph->V; ++v) 
    { 
        subsets[v].parent = v; 
        subsets[v].rank = 0; 
    } 

	for(int i = 0;i<graph->E;i++){
		int x = find(subsets, graph->edge[i].src);
		int y = find(subsets, graph->edge[i].dest);

		if(x == y)
			return 1;

		Union(subsets, x, y);
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
