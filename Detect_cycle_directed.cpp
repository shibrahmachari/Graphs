#include<bits/stdc++.h>
using namespace std;
bool DDFS(list<int>* adj, bool* recstack, int sv, bool* visited){
	recstack[sv] = true;
	visited[sv] = true;
	list<int>::iterator it;
	for(it = adj[sv].begin();it!=adj[sv].end();it++){
		if(!visited[*it] && DDFS(adj, recstack, *it, visited)){
			return true;
		}
		else if(recstack[*it])
			return true;
	}
	recstack[sv] = false;
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
	}
	bool* visited = new bool[V];
	for(int i = 0;i<V;i++){
		visited[i] = false;
	}
	bool* recstack = visited;
	cout<<DDFS(adj, recstack, 0,visited);

}