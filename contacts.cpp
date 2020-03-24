#include<bits/stdc++.h>
using namespace std;
struct contact{
    string field1,  field2, field3;
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
        adj[d].push_back(s);
    }

void dfs(bool* visited, int src){
    cout<<src<<" ";
    visited[src]=true;
    list<int>:: iterator it;
    for(it=adj[src].begin();it!=adj[src].end();it++){
        if(!visited[*it]){
            dfs(visited, *it);
        }
    }

}
void connectcomp(){
    bool* visited= new bool[v];
    for(int i=0;i<v;i++){
        visited[i]=false;
    }
    for(int i=0;i<v;i++){
        if(!visited[i]){
            dfs(visited, i);
            cout<<endl;
        }
    }
}
};
void findSameContacts(contact arr[], int n){
    graph g(n);
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i].field1==arr[j].field1||arr[i].field2==arr[j].field2||arr[i].field3==arr[j].field3){
                g.addedge(i,j);
            }
          else if(arr[i].field1==arr[j].field2||arr[i].field1==arr[j].field3)
          {
              g.addedge(i,j);
          }
          else if(arr[i].field2==arr[j].field1||arr[i].field2==arr[j].field3){
              g.addedge(i,j);
          }
          else if((arr[i].field3==arr[j].field2||arr[i].field1==arr[j].field1)){
              g.addedge(i,j);
          }
        }
    }
    g.connectcomp();
}

int main()
{ contact arr[] = {{"Gaurav", "gaurav@gmail.com", "gaurav@gfgQA.com"}, 
                     {"Lucky", "lucky@gmail.com", "+1234567"}, 
                     {"gaurav123", "+5412312", "gaurav123@skype.com"}, 
                     {"gaurav1993", "+5412312", "gaurav@gfgQA.com"}, 
                     {"raja", "+2231210", "raja@gfg.com"}, 
                     {"bahubali", "+878312", "raja"} 
                    }; 
  
    int n = sizeof arr / sizeof arr[0]; 
    findSameContacts(arr, n); 
    return 0; 
    }
