#include <iostream>
using namespace std;
#define size 4
bool checkStar(int mat[size][size]){
    int* indeg= new int[size];
    for(int i=0;i<size;i++){
        indeg[i]=0;
    }
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            if(mat[i][j]==1){
                indeg[i]++;
            }
        }
    }
    int count=0;
    int cn=0;
    for(int i=0;i<size;i++){
        if(indeg[i]==size-1)cn++;
        else if(indeg[i]==1)count++;
    }
    if(cn==1&&count==size-1)return true;
    else return false;
}
int main() {
 int mat[size][size] = { {0, 1, 1, 1}, 
                            {1, 0, 0, 0}, 
                            {1, 0, 0, 0}, 
                            {1, 0, 0, 0}}; 
  
    checkStar(mat) ? cout << "Star Graph" :  
                     cout << "Not a Star Graph"; 

	return 0;
}
