#include<bits/stdc++.h>
using namespace std;
void BFS(list<int>* adj, int V, int sv, int ev){
	bool* visited = new bool[V];
	for(int i = 0;i<V;i++){
		visited[i] = false;
	}
	vector<int> parent(V,-1);
	queue<int> q;
	q.push(sv);
	visited[sv] = true;
	while(!q.empty()){
		int f = q.front();
		q.pop();
		if(f == ev)
			break;
		list<int>::iterator it;
		for(it = adj[f].begin();it!=adj[f].end();it++){
			if(!visited[*it]){
				parent[*it] = f;
				visited[f] = true;
				q.push(*it);
			}
		}
	}
	int curr = ev;
	while(curr!=sv){
		cout<<parent[curr]<<" ";
		curr = parent[curr];
	}
}
int main(){

	int V,E;
	cin>>V>>E;
		list<int> adj[V];
	for(int i = 0;i<E;i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int sv,ev;
	cin>>sv>>ev;
	BFS(adj,V,sv,ev);
	return 0;
}