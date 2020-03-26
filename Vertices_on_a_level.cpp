#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;

int BFS(int** edges, int n, int sv, int level){
    bool* visited= new bool[n];
    for(int i=0;i<n;i++){
        visited[i]=false;
    }
    int count = 0;
    queue<int> q;
    q.push(sv);
    q.push(-1);
    int currlevel = 1;
    visited[sv]=true;
    while(!q.empty()){
        if(q.front() == -1){
            currlevel++;
            q.pop();
        }
        int temp=q.front();
        q.pop();
         for(int i=0;i<n;i++){
            if(!visited[i] && edges[temp][i]==1){
                q.push(i);
                visited[i] = true;
                if(currlevel == level)
                    count++;
            }
        }
        q.push(-1);

    }
    return count;
}
int main()
{
  int V, E;
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
    int level;
    cin>>level;
    cout<<BFS(edges, V, 0, level);
    for(int i=0;i<V;i++){
        delete[] edges;
    }
   
    delete[] edges;
}