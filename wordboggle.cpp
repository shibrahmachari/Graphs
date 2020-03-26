 #include <iostream>
using namespace std;
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};
bool iscompare(string temp, string* dict, int x){
    for(int i=0;i<x;i++){
        if(dict[i]==temp)
        return true;
    }
    return false;
}
bool issafe(int a,int b,int n,int m){
    if(a<0||b<0||a>=n||b>=m)
    {return true;}
    return false;
}
void dfs(char** graph,bool** visited, int n, int m, int i, int j, int x, string& ans, string dict[]){
    visited[i][j]=true;
    ans=ans+graph[i][j];
    if(iscompare(ans,dict,x)){
        cout<<ans<<endl;
    }
    for(int k=0;k<4;k++){
        int a=k+dx[k];
        int b=k+dy[k]; 
        if(!visited[a,b]&&issafe(a,b,n,m)){
               dfs(graph,visited, n, m, a,b, x,ans,dict);
        }
    }
    ans.pop_back();
     visited[i][j]=false;
}
int main() {
     int t;
     while(t--){
         int n, m, x;
         cin>>n>>m>>x;
         string* dict= new string[x];
         char** graph= new char*[n];
         for(int i=0;i<n;i++){
             graph[i]= new char[m];
             for(int j=0;j<m;j++){
                 cin>>graph[i][j];
             }
         }
         bool** visited= new bool*[n];
         for(int i=0;i<n;i++){
            visited[i]= new bool[m];
             for(int j=0;j<m;j++){
                 visited[i][j]=false;
             }
         }
         string ans="";
           for(int i=0;i<n;i++){
             for(int j=0;j<m;j++){
                 dfs(graph,visited,n,m,i,j,x, ans,dict);
             }
         }
       cout<<endl;
     }
	return 0;
}
