#include<bits/stdc++.h>
using namespace std;
int main()
{
  int m, n;
  cin >> m>> n;
    
    int** edges= new int*[m];
    for(int i=0;i<m;i++){
        edges[i]=new int[n];
        for(int j=0;j<n;j++){
            edges[i][j]=1;
        }
    }
    int r = 1;
  vector<int> X1 = {1, 3}; 
  vector<int> Y1 = {3, 3}; 
  int s = X1.size();

  for(int i = 0;i<s;i++){
  	int xf = 0,xn = 0, yf = 0, yn = 0;
  	while(xf<=r){
  		edges[X1[i]+xf][Y1[i]] = 0;
  	}
  	while(xn<=r){
  		edges[X1[i]-xf][Y1[i]] = 0;
  	}
  	while(yf<=r){
  		edges[X1[i]][Y1[i]+yf] = 0;
  	}
  	while(yn<=r){
  		edges[X1[i]][Y1[i]-yn] = 0;
  	}
  }

  if(edges[0][0] == 1 && edges[m-1][n-1] == 1){
  	printDFS(edges, )
  }
 }