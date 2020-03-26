#include <bits/stdc++.h>
using namespace std;
void minAssignment(int pages[],bool* visited, int n, int m, int max, int min){
    int sum=0;
    int i;
    for(int i=0;i<n;i++){
        if(visited[i]==false){
            break;
        }
    }
    int start=i;
    int j;
    for(int j=0;j<n;j++){
        if(!visited[j]){
        sum+=pages[i];
        if(sum==max){
            break;
        }
        if(sum>min&&sum<max){
            break;
        }
        }
    }
    cout<<"day"<<m+1;
    for(int l=j;l>=start;l--){
        cout<<l<<" ";
        visited[l]=true;
    }
    
}
int main() {
int pages[] = {7, 5, 6, 12}; 
  int n= sizeof(pages)/sizeof(int);
 int k=3;
 bool* visited= new bool[n];
 for(int i=0;i<n;i++){
     visited[i]=false;
 }
 int maxi=INT_MIN;
 int mini=INT_MAX;
 for(int i=0;i<n;i++){
     maxi= max(maxi,pages[i]);
     mini=min(mini,pages[i]);
 }
 for(int i=0;i<k;i++){
    minAssignment(pages,visited,n,i, maxi, mini);
   
 }
	return 0;
}
