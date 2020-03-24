#include<bits/stdc++.h>
using namespace std;
struct edge{
    int src;
    int dest;
};
class graph{
    int v;
    list<int>* adj;
    public:
    graph(int v){
        this->v=v;
        adj= new list<int>[v];
    }
    void addedge(int s, int d){
        adj[s].push_back(d);
    }
  int calculatesink(){
      int count=0;
    for(int i=0;i<v;i++){
        if(adj[i].size()==0){
            count++;
        }
    }
    return count;
  }  
};
void creategraph(edge edges[], int n, int m){
    graph g(n);
    for(int i=0;i<m;i++){
        g.addedge(edges[i].src, edges[i].dest);
    }
    int a= g.calculatesink();
    cout<<"anss"<<a;
}
int main(){
    int n=4;
    int m=2;
    edge edges[2]={{1,2},{3,2}};
    creategraph(edges,n,m);
    return 0;   
}
