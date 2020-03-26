// C++ program to find minimum edge 
// between given two vertex of Graph 
#include<bits/stdc++.h> 
using namespace std; 

// function for finding minimum no. of edge 
// using BFS 
int minEdgeBFS(int** edges, int u, 
							int v, int n) 
{ 
	// visited[n] for keeping track of visited 
	// node in BFS 
	vector<bool> visited(n, 0); 

	// Initialize distances as 0 
	vector<int> distance(n, 0); 

	// queue to do BFS. 
	queue <int> Q; 
	distance[u] = 0; 

	Q.push(u); 
	visited[u] = true; 
	while (!Q.empty()) 
	{ 
		int x = Q.front(); 
		Q.pop(); 

		for (int i=0; i<n; i++) 
		{ 
			if (visited[i]) 
				continue; 

			// update distance for i
			if(edges[x][i] == 1){ 
			distance[i] = distance[x] + 1; 
			Q.push(i); 
			visited[i] = true; 
			}
		} 
	} 
	return distance[v]; 
} 


int main() 
{ 
	// To store adjacency list of graph 
  int V, E;
  cin >> V >> E;
    
    int** edges= new int*[V];
    for(int i=0;i<V;i++){
        edges[i]=new int[V];
        for(int j=0;j<V;j++){
            edges[i][j]=0;
        }
    }
    for(int i=0;i<E;i++){
        int f,s;
        cin>>f>>s;
        edges[f][s]=1;
        edges[s][f]=1;
    }
	int u = 0; 
	int v = 4; 
	cout << minEdgeBFS(edges, u, v, V); 
	return 0; 
} 
