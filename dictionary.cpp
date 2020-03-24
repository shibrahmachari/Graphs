#include <bits/stdc++.h>
using namespace std;
class graph{
  int v;
  list<int> * adj;
  public:
  graph(int v){
      this->v=v;
      adj=new list<int>[v];
  }
  
  void topologicalsortutil(stack<int>& s, bool* visited, int v){
      visited[v]=true;
      for(int i=0;i<v;i++){
          if(!visited[i])
          topologicalsortutil(s,visited,i);
      }
      s.push(v);
  }
  
  void topologicalsort(){
      stack<int> s;
      bool* visited= new bool[v];
      for(int i=0;i<v;i++){
          visited[i]=false;
      }
      for(int j=0;j<v;j++){
         if(!visited[j])
      topologicalsortutil(s,visited,j);
      }
      while(!s.empty()){
          cout<<(char)(s.top()+'a')<<" ";
          s.pop();
      }
  }
  void add(int s, int v){
  adj[s].push_back(v);
  }
};
  void addegde(string words[], int n){
      graph g(n);
      for(int i=0;i<n-1;i++){
          string s= words[i];
          string t=words[i+1];
          for(int j=0;j<min(s.size(),t.size());j++){
              if(s[i]!=t[i]){
                 g. add(s[i]-'a',t[i]-'a');
                  break;
              }
          }
      }
     g.topologicalsort();      
  }
  
  int main() 
{ 
    string words[] = {"caa", "aaa", "aab"}; 
    addegde(words, 3); 
    return 0; 
} 
