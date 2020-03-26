#include <iostream>
using namespace std;
#define V 4
int countTriangle(int graph[][V], bool ans){
    int count=0;
    for(int i=0;i<V;i++){
    for(int j=0;j<V;j++)
    {  for(int k=0;k<V;k++)
        {  if(graph[i][j]==1&&graph[j][k]==1&&graph[k][i]==1)
            count++;
        }
    }
        
    }
    if(!ans)  count=count/6;
     else count= count/3;
    return count;
}
int main() {
	   int graph[][V] = { {0, 1, 1, 0}, 
                       {1, 0, 1, 1}, 
                       {1, 1, 0, 1}, 
                       {0, 1, 1, 0} 
                     }; 
  
    // Create adjacency matrix 
    // of a directed graph 
    int digraph[][V] = { {0, 0, 1, 0}, 
                        {1, 0, 0, 1}, 
                        {0, 1, 0, 0}, 
                        {0, 0, 1, 0} 
                       }; 
  
    cout << "The Number of triangles in undirected graph : "
         << countTriangle(graph, false); 
    cout << "\n\nThe Number of triangles in directed graph : "
         << countTriangle(digraph, true); 
	return 0;
}
