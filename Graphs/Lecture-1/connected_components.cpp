// Code : All connected components
// Send Feedback
// Given an undirected graph G(V,E), find and print all the connected components of the given graph G.
// V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
// E is the number of edges present in graph G.
// You need to take input in main and create a function which should return all the connected components. And then print them in the main, not inside function.
// Print different components in new line. And each component should be printed in increasing order (separated by space). Order of different components doesn't matter.
// Input Format :
// Line 1: Two Integers V and E (separated by space)
// Next 'E' lines, each have two space-separated integers, 'a' and 'b', denoting that there exists an edge between Vertex 'a' and Vertex 'b'.
// Output Format :
// Different components in new line
// Constraints :
// 2 <= V <= 1000
// 1 <= E <= 1000
// Sample Input 1:
// 4 2
// 0 1
// 2 3
// Sample Output 1:
// 0 1 
// 2 3 
// Sample Input 2:
// 4 3
// 0 1
// 1 3 
// 0 3
// Sample Output 2:
// 0 1 3 
// 2

//solution

#include <iostream>
using namespace std;
#include<vector>
#include<bits/stdc++.h>
//vector<vector<int>> mv;
//trim above
vector<int> DFSpush(int**edges,int V,int sv,bool *visited,vector<int> v){
  v.push_back(sv);
  visited[sv]=true;
  //vector<int> v1;
  for(int i=0;i<V;i++){
    if(i==sv)
      continue;
    if(edges[sv][i]==1){
      if(visited[i])
        continue;
      else{
        
        v=DFSpush(edges,V,i,visited,v);
      }
    }
  }
  return v;
}
vector<vector<int>> DFSTraversal(int** edges,int V){
  vector<vector<int>> mv;
  bool *visited=new bool[V];
  for(int i=0;i<V;i++)
    visited[i]=false;
  for(int i=0;i<V;i++){
    if(!visited[i]){
      //call the vector filling function
      	vector<int> v;
    	vector<int> v1=DFSpush(edges,V,i,visited,v);
      	int k=v1.size();
      	int* temp=new int[k];
      	int t=k;
      	for(int i=0;i<k;i++){
          temp[i]=v1[t-1];
          t--;
          v1.pop_back();
        }
      	sort(temp,temp+k);
      	for(int i=0;i<k;i++){
          v1.push_back(temp[i]);
        }
      	delete []temp;
    	mv.push_back(v1);
    }
  }
  delete []visited;
  return mv;
}
trim be
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
    for(int j=0;j<V;j++)
      edges[i][j]=0;
  }
  for(int i=0;i<E;i++){
    int f,s;
    cin>>f>>s;
    edges[s][f]=1;
    edges[f][s]=1;
  }
  //function call
  vector<vector<int>> mv=DFSTraversal(edges,V);
  //printing the main vector
  //cout<<edges[2][3]<<" "<<edges[3][2]<<endl;
  //print the matrix
 /* for(int i=0;i<V;i++){
    for(int j=0;j<V;j++)
      cout<<edges[i][j]<<" ";
    cout<<endl;
  }*/
  
  //
  int k=mv.size();
  cout<<k<<endl;
  for(int i=0;i<k;i++){
    int n=mv[i].size();
    for(int j=0;j<n;j++){
      cout<<mv[i][j]<<" ";
    }
    cout<<endl;
  }
 

  return 0;
}
