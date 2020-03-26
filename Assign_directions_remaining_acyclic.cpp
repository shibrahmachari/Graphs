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
	for(int i = 0;i<V;i++){
		if(!visited[i])
		DDFS(adj, s, i, visited);
	}
	std::vector<int> v;
	while(!s.empty()){
		v.push_back(s.top());
		s.pop();
	}

	it = std::find (v.begin(), v.end(), u); 
	it1 = std::find (v.begin(), v.end(), v); 
	/*
	if(it<it1)
	u->v;
	else
	v->u;
	*/
}