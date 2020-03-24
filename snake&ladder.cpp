#include<bits/stdc++.h>
using namespace std;
int getthemoves(int* moves, int N){
    queue<pair<int,int>>q ;
    bool* visited= new bool[N];
    for(int i=0;i<N;i++){
        visited[i]=false;
    }
    int ans;
    q.push({0,0});
    visited[0]=true;
    while(!q.empty()){
        pair<int, int> temp= q.front();
        q.pop();
        if(temp.first==N-1){
            ans=temp.second;
            break;
        }
        int x=temp.first;
        for(int j=x+1;j<=(x+6)&&j<N; j++){
            if(!visited[j]){
                visited[j]=true;
                if(moves[j]!=-1){
                    q.push({moves[j],temp.second+1});
                }else{
                  q.push({j,temp.second+1});   
                }
                
            }
        }
    }
    return ans;
}
int main(){
    int N=30;
    int* moves= new int[N];
      for(int i=0;i<N;i++){
          moves[i]=-1;
      }
      
    moves[2] = 21; 
    moves[4] = 7; 
    moves[10] = 25; 
    moves[19] = 28; 
  
    moves[26] = 0; 
    moves[20] = 8; 
    moves[16] = 3; 
    moves[18] = 6; 
    cout<<getthemoves(moves,N)<<endl;
    
}
