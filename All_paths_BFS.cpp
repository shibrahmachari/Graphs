#include<bits/stdc++.h>
using namespace std;
bool notvisit(int x, vector<int> v){
	int n = v.size();
	for(int i = 0;i<n;i++){
		if(v[i] == x)
			return false;
	}
	return true;
}
void printpaths(vector<int> v){
	int n = v.size();
	for(int i = 0;i<n;i++){
		cout<<v[i]<<" ";
	}
	cout<<endl;
}
void BFSallpaths(list<int>* adj, int n, int sv, int ev){
	queue<vector<int>> q;
	vector<int> v;
	v.push_back(sv);
	q.push(v);
	while(!q.empty()){
		v = q.front();
		q.pop();
 

		int e = v[v.size() - 1];

		if(e == ev){
			printpaths(v);
		}

		list<int>::iterator it;
		for(it = adj[e].begin();it!=adj[e].end();it++){
			if(notvisit(*it, v)){
				vector<int> path(v);
				path.push_back(*it);
				q.push(path);
			}
		}
	}
}
int main(){
	int n,e;
	cin>>n>>e;
	list<int> adj[n];
	for(int i = 0;i<e;i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int sv,ev;
	cin>>sv>>ev;
	BFSallpaths(adj, n, sv, ev);
}