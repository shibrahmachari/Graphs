#include<bits/stdc++.h>
using namespace std;
void considergraph(int degree[], int n, int k, int i,int** matrix){
    int sum=0;
    int count=k;
   
    for(int j=0;j<n;j++){
        if(j!=i){
          matrix[i][j]=1;
          sum+=matrix[i][j];
          if(sum==count){
          
              break;
          }
        }
    }
    
}
int main(){
    int degree[]={ 2, 2, 1, 1, 1 };
    int n= sizeof(degree)/sizeof(int);
    int** matrix= new int*[n];
      for(int i=0;i<n;i++){
        matrix[i]= new int[n];
      for(int j=0;j<n;j++){
        matrix[i][j]=0;
       }
       }
       for(int i=0;i<n;i++){
       considergraph(degree, n,degree[i],i, matrix);
       }
        for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
         cout<<matrix[i][j]<<" ";
    }
    cout<<endl;
    }
}
