// Code : BFS Traversal
// Send Feedback
// Given an undirected and disconnected graph G(V, E), print its BFS traversal.
// Here you need to consider that you need to print BFS path starting from vertex 0 only.
// V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
// E is the number of edges present in graph G.
// Note : 1. Take graph input in the adjacency matrix.
// 2. Handle for Disconnected Graphs as well
// Input Format :
// Line 1: Two Integers V and E (separated by space)
// Next 'E' lines, each have two space-separated integers, 'a' and 'b', denoting that there exists an edge between Vertex 'a' and Vertex 'b'.
// Output Format :
// BFS Traversal (separated by space)
// Constraints :
// 2 <= V <= 1000
// 1 <= E <= 1000
// Sample Input 1:
// 4 4
// 0 1
// 0 3
// 1 2
// 2 3
// Sample Output 1:
// 0 1 3 2

//solution

#include <iostream>
using namespace std;
#include<queue>
void print(int** edges,int V,int SV,bool* visited){
  queue<int> q;
  q.push(SV);
  visited[SV]=true;
  while(q.size()!=0){
    int front=q.front();
    cout<<front<<" ";
    q.pop();
    for(int i=0;i<V;i++){
      if(i==front)
        continue;
      if(edges[front][i]==1){
        if(visited[i]==false){
          q.push(i);
          visited[i]=true;
        }
        else{
          continue;
        }
      }
    }
  }
} 
int main() {
    int V, E;
    cin >> V >> E;

  /*

  	   Write Your Code Here
	   Complete the Rest of the Program
	   You have to take input and print the output yourself
	 
  */
  //my code
  int** edges = new int*[V];
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
  
  bool* visited = new bool[V];
  for(int i=0;i<V;i++){
    visited[i]=false;
  }
  print(edges,V,0,visited);
  //deleting dynamically allocated memory		//##TO DO
  ///delete 
  //end
  return 0;
}
