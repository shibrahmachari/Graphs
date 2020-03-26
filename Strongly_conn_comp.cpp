#include<bits/stdc++.h>
using namespace std;
void DDFS(list<int>* adj, stack<int> &s, int sv, bool* visited){
	visited[sv] = true;
	list<int>::iterator it;
	for(it = adj[sv].begin();it!=adj[sv].end();it++){
		if(!visited[*it]){
			DDFS(adj, s, *it, visited);
		}
	}
	s.push(sv);
}
void Transpose(list<int>* adj, int V, list<int>* ans){
	for(int i = 0;i<V;i++){
		list<int>::iterator it;
		for(it = adj[i].begin();it!=adj[i].end();it++){
			ans[*it].push_back(i);
		}
	}
}
void DFSU(list<int>* adj, int v, bool* visited){
	visited[v] = true;
	cout<<v<<" ";
	list<int>::iterator it;
	for(it = adj[v].begin();it!=adj[v].end();it++){
		if(!visited[*it])
		DFSU(adj, *it, visited);
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
	}
	stack<int> s;
	bool* visited = new bool[V];
	for(int i = 0;i<V;i++){
		visited[i] = false;
	}
	DDFS(adj, s, 0, visited);
    for(int i = 0; i < V; i++) 
        visited[i] = false; 
    list<int> ans[V];
    Transpose(adj,V,ans);
    while(!s.empty()){
    	int v = s.top();
    	s.pop();
    	if(visited[v] == false){
    		DFSU(ans, v, visited);
    		cout<<endl;
    	}
    }
	return 0;
}