#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;

vector<int>* getpath(int** edges, int n, int sv, int ev){
    bool* visited= new bool[n];
    for(int i=0;i<n;i++){
        visited[i]=false;
    }
    
    queue<int> q;
    q.push(sv);
    bool done= false;
    visited[sv]=true;
    unordered_map<int, int> parent;
    while(!q.empty() && !done){
        int temp=q.front();
        q.pop();
        for(int i=0;i<n;i++){
            if(!visited[i] && edges[temp][i]==1){
                q.push(i);
                visited[i] = true;
                parent[i]=temp;
                if(i==ev){
                done=true;
                break;
                }
            }
        }
        
    }
     delete[] visited;
    if(!done)
        return NULL;
    else{
        vector<int>* output= new vector<int>();
        int cuu= ev;
        output->push_back(ev);
        while(cuu!=sv){
            cuu=parent[cuu];
            output->push_back(cuu);
        }
        return output;
    }
    
}
int main()
{
  int V, E, tempX, tempY;
  cin >> V >> E;
    
    int** edges= new int*[V];
    for(int i=0;i<V;i++){
        edges[i]=new int[V];
        for(int j=0;j<V;j++){
            edges[i][j]=0;
        }
    }
    for(int i=0;i<E;i++){
        int f,s;
        cin>>f>>s;
        edges[f][s]=1;
        edges[s][f]=1;
    }
    cin>>tempX>>tempY;
    
 
    vector<int>* output= getpath(edges, V, tempX, tempY);
    if(output!=NULL){
    for(int i=0;i<output->size();i++){
        cout<<output->at(i)<<" ";
        }
    }
    for(int i=0;i<V;i++){
        delete[] edges;
    }
   
    delete[] edges;

  return 0;
}
