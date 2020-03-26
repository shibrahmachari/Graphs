#include<bits/stdc++.h>
using namespace std;

void printDFS(int **edges,int n,int t,int sv,bool * visited, int** ans)
{
    visited[sv]=true;
    for(int i=0;i<n;i++)
    {
        if(i==sv){
            ans[sv][i] = 1;
            continue;
        }
        if(edges[sv][i]==1)
        {
            if(visited[i])
                continue;
        else{
                ans[t][i] = 1;
                printDFS(edges,n,t,i,visited,ans);
            }
        }
    }
    //cout<<endl;
}
void DFS(int **edges,int n)
{

    bool* visited = new bool(n);

    for(int i=0;i<n;i++)
    {
        visited[i]=false;
    }
    int** ans = new int*[n];
    for(int i=0;i<n;i++)
    {
        ans[i]=new int[n];
        for(int j=0;j<n;j++)
        {
            ans[i][j]=0;
        }
    }
    for(int i=0;i<n;i++)
    {
            printDFS(edges,n,i,i,visited,ans);
            for(int i=0;i<n;i++)
             {
                visited[i]=false;
             }
    }
     for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    
}
int main()
{
    int n;
    int e;
    cin>>n>>e;
    int** edges= new int*[n];
    for(int i=0;i<n;i++)
    {
        edges[i]=new int[n];
        for(int j=0;j<n;j++)
        {
            edges[i][j]=0;
        }
    }

    for(int i=0;i<e;i++)
    {
        int f,s;
        cin>>f>>s;
        edges[f][s]=1;
    }
    DFS(edges,n);
   
}