#include<bits/stdc++.h>
using namespace std;
bool DDFS(list<int>* adj, vector<int> &parent, int sv, bool* visited){
	visited[sv] = true;
	list<int>::iterator it;
	for(it = adj[sv].begin();it!=adj[sv].end();it++){
		parent[*it] = sv;
		if(!visited[*it] && DDFS(adj,parent,*it,visited))
			return true;
		if(visited[*it] && parent[sv]!=*it)
			return true;
	}

	return false;
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
	vector<int> parent(V,-1);
	cout<<DDFS(adj, parent, 0,visited);

}