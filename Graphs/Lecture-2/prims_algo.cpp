// Code : Prim's Algorithm
// Send Feedback
// Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
// Find and print the Minimum Spanning Tree (MST) using Prim's algorithm.
// For printing MST follow the steps -
// 1. In one line, print an edge which is part of MST in the format -
// v1 v2 w
// where, v1 and v2 are the vertices of the edge which is included in MST and whose weight is w. And v1 <= v2 i.e. print the smaller vertex first while printing an edge.
// 2. Print V-1 edges in above format in different lines.
// Note : Order of different edges doesn't matter.
// Input Format :
// Line 1: Two Integers V and E (separated by space)
// Next E lines : Three integers ei, ej and wi, denoting that there exists an edge between vertex ei and vertex ej with weight wi (separated by space)
// Output Format :
// MST
// Constraints :
// 2 <= V, E <= 10^5
// Sample Input 1 :
// 4 4
// 0 1 3
// 0 3 5
// 1 2 1
// 2 3 8
// Sample Output 1 :
// 0 1 3
// 1 2 1
// 0 3 5

//solution

#include <iostream>
using namespace std;
#include<bits/stdc++.h>

int main()
{
  int V, E, tempX, tempY;
  cin >> V >> E;
  /*

  	   Write Your Code Here
	   Complete the Rest of the Program
	   You have to Print the output yourself
	 
  */
  int **edges=new int*[V];
  for(int i=0;i<V;i++){
    edges[i]=new int[V];
    for(int j=0;j<V;j++){
      edges[i][j]=0;
    }
  }
  
  for(int i=0;i<E;i++){
    int f,s,w;
    cin>>f>>s>>w;
    edges[f][s]=w;
    edges[s][f]=w;
  }
  //Adjacency matrix is ready
  int *distance=new int[V];
  bool* visited=new bool[V];
  for(int i=0;i<V;i++){
    visited[i]=false;
    distance[i]=INT_MAX;
  }
  distance[0]=0;
  for(int i=0;i<V;i++){
    int min_vertex=min(distance,visited,V);			//creatiing min function to find unvisited minimum vertex
    visited[min_vertex]=true;
    for(int j=0;j<V;j++){
      if(!visited[j]){
        if(edges[min_vertex][j]!=0){
        	int c_dist=distance[min_vertex]+edges[min_vertex][j];
          	if(c_dist<distance[j]){
              distance[j]=c_dist;
            }
          	else
              continue;
        }
       	else
          continue;
      }
      else
        continue;
    }
  }

  
  //PRINTING OUTPUT
  for(int i=0;i<V;i++){
    cout<<i<<" "<<distance[i]<<endl;
  }
  return 0;
}
