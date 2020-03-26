#include<bits/stdc++.h>
using namespace std;
int BFS(list<int>* adj, int n, int sv){
	bool* visited = new bool[n];
	for(int i = 0;i<n;i++){
		visited[i] = false;
	}
	queue<pair<int,int>> q;
	q.push({sv,0});
	int count = 0,max_level = 0;

	while(!q.empty()){
		pair<int,int> f = q.front();
		visited[f.first] = true;
		q.pop();
		max_level = max(max_level, f.second);
		list<int>::iterator it;
		for(it = adj[f.first].begin();it!=adj[f.first].end();it++){
			if(!visited[*it]){
				q.push({*it, f.second+1});

			}
		}
	}
	return max_level;
}
int main(){
	int n;
	cin>>n;
	int parent[n];
	for(int i = 0;i<n;i++){
		cin>>parent[i];
	}
	list<int> adj[n];
	int root_index = 0;
	for(int i = 0;i<n;i++){
		if (parent[i] == -1) 
            root_index = i; 
  		else{
  		adj[i].push_back(parent[i]);
		adj[parent[i]].push_back(i);
	}
	}
	cout<<BFS(adj,n,root_index);
	//return 0;
}