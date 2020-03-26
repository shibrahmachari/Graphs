#include <bits/stdc++.h>
using namespace std;
void add_edge(vector<int> adj[], int s, int d)
{  adj[s].push_back(d);
   adj[d].push_back(s);
}
void printpath(int parent[], int i){
    if(parent[i]==-1){
        cout<<"the path is "<<i<<" ";
        return;
    }
    printpath(parent,parent[i]);
    cout<<i<<" ";
    return;
}
void printShortestDistance(vector<int> adj[], int source, int dest, int v){
    bool* visited= new bool[v];
    int* dist= new int[v];
    int* parent= new int[v];
    for(int i=0;i<v;i++){
        visited[i]=false;
        dist[i]=0;
        parent[i]=-1;
    }
    queue<int>q ;
    q.push(source);
    visited[source]=true;
    dist[source]=0;
    parent[source]=-1;
    while(!q.empty()){
        int x= q.front();
        q.pop();
        if(x==dest){
            printpath(parent,x);
            break;
        }
        for(int i=0;i<adj[x].size();i++){
            if(!visited[adj[x][i]]){
                visited[adj[x][i]]=true;
                dist[adj[x][i]]=dist[x]+1;
                parent[adj[x][i]]=x;
                q.push(adj[x][i]);
            }
        }
    }
    cout<<endl;
    cout<<"distance destination:";
    cout<<dist[dest];
}
int main() {
int v=8;
vector<int> adj[v];
   add_edge(adj, 0, 1); 
    add_edge(adj, 0, 3); 
    add_edge(adj, 1, 2); 
    add_edge(adj, 3, 4); 
    add_edge(adj, 3, 7); 
    add_edge(adj, 4, 5); 
    add_edge(adj, 4, 6); 
    add_edge(adj, 4, 7); 
    add_edge(adj, 5, 6); 
    add_edge(adj, 6, 7); 
    int source = 0, dest = 7; 
    printShortestDistance(adj, source, dest, v); 
	return 0;
}
