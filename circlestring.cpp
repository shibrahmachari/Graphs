#include <bits/stdc++.h>
using namespace std;
class graph{
    int v;
    list<int>* adj;
    int * in;
    public:
    graph(int v){
        this->v=v;
        adj=new list<int>[v];
        in= new int [v];
        for(int i=0;i<v;i++){
            in[i]=0;
        }
    }
    void addedge(int s, int d){
        adj[s].push_back(d);
    }
    void dfs(bool* visited, int src){
        visited[src]=true;
        for(int i=0;i<v;i++){
           dfs(visited,i);
        }
    }
    graph transpose(){
        graph g(v);
        for(int i=0;i<v;i++){
         list<int>::iterator j; 
        for(j = adj[i].begin(); j != adj[i].end(); ++j) 
        { 
            g.adj[*j].push_back(i); 
            (g.in[i])++; 
        } 
        }
        return g;
    }
    bool isstconnect(){
        bool* visited= new bool[v];
        for(int i=0;i<v;i++){
            visited[v]=false;
        }
        int k;
        for(int k=0;k<v;k++){
            if(adj[k].size()>0)
            break;
        }
        dfs(visited,k);
        graph gr=transpose();
        for(int i=0;i<v;i++){
            visited[i]=false;
        }
        gr.dfs(visited,k);
        for(int i=0;i<v;i++){
            if(!visited[i])
            return false;
        }
        return true;
    }
    bool iseulerianutil(){
    if(isstconnect()==false){
        return false;
    }
    for(int i=0;i<v;i++){
        if(adj[i].size()!=in[i])
        return false;
    }
    return true;
    }
};
bool iseulerian(string A[], int n){
    graph g(26);
    for(int i=0;i<n;i++){
        string s=A[i];
        g.addedge(s[0]-'a', s[s.size()-1]-'a');
    }
    return g.iseulerianutil();
}
int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    string A[n];
	    for(int i=0;i<n;i++){
	        cin>>A[i];
	    }
	    if(iseulerian(A,n)){
	        cout<<1;
	    }else{
	        cout<<0;
	    }
	    cout<<endl;
	}
	return 0;
}
