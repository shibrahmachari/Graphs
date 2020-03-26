#include<bits/stdc++.h>
using namespace std;
void DDFS(list<int>* adj, int sv, bool* visited, vector<int> &parent, vector<int> discovery, vector<int> low, vector<int> &ap){
	static int time = 0;

	discovery[sv] = low[sv] = ++time;
	visited[sv] = true;
	list<int>::iterator it;
	int children = 0;
	for(it = adj[sv].begin();it!=adj[sv].end();it++){
		if(!visited[*it]){
			children++;	
			parent[*it] = sv;
			DDFS(adj,*it, visited, parent, discovery, low, ap);
			low[sv] = min(low[sv], low[*it]);
			

			if(parent[sv] == -1 && children >1)
				ap.push_back(sv);

			if(parent[sv] != -1 && low[*it]>=discovery[sv])
				ap.push_back(sv);
		}

		else if(*it != parent[sv]){
			low[sv] = min(low[sv], discovery[*it]);
		}
	}
}
int main(){
	int V,E;
	cin>>V>>E;
	list<int> adj[V];
	for(int i =  0;i<E;i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	bool* visited = new bool[V];
	for(int i = 0;i<V;i++){
		visited[i] = false;
	}
	vector<int> parent(V, -1);
	vector<int> discovery(V);
	vector<int> ap;
	vector<int> low(V);
	for(int i = 0;i<V;i++){
		if(!visited[i])
		DDFS(adj,i, visited, parent, discovery, low, ap);
	}

	for(int i = 0;i<ap.size() - 1;i++){
		cout<<ap[i]<<" ";
	}
	return 0;
}