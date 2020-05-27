// Code : Kruskal's Algorithm
// Send Feedback
// Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
// Find and print the Minimum Spanning Tree (MST) using Kruskal's algorithm.
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
// 1 2 1
// 0 1 3
// 0 3 5

//solution

#include <iostream>
using namespace std;
#include<bits/stdc++.h>
class edge{
  public:
  int st;
  int end;
  int wt;
  /*edge(int st,int end,int wt){		//CONSTRUCTOR
    this->st=st;
    this->end=end;
    this->wt=wt;
  }*/
};
//comaprator
bool compareEdge(edge e1,edge e2){
  return (e1.wt<e2.wt);
}
//findparent function
int findParent(int child,int *parent){
  if(parent[child]==child)
    return child;
  int ans=findParent(parent[child],parent);
  return ans;
}
int main()
{
  int V, E, tempX, tempY;
  cin >> V >> E;
  edge input[E];
  edge output[V-1]; 
  int parent[V];
  for(int i=0;i<V;i++){
    parent[i]=i;
  }
 /* for(int i=0;i<V;i++){
    cout<<parent[i]<<" ";
  }*/
  for(int i=0;i<E;i++){
    int st,end,wt;
    cin>>st>>end>>wt;
    edge e;
    e.st=st;
    e.end=end;
    e.wt=wt;
    input[i]=e;
  }
  /*for(int i=0;i<E;i++){			//testing DONE
    int st=input[i].st;
    int end=input[i].end;
    int wt=input[i].wt;
    cout<<st<<" "<<end<<" "<<wt<<endl;
  }*/
  //SORTING INPUT ARRAY
  sort(input,input+E,compareEdge);
  //TEST SORTING
 /* for(int i=0;i<E;i++){			//testing DONE
    int st=input[i].st;
    int end=input[i].end;
    int wt=input[i].wt;
    cout<<st<<" "<<end<<" "<<wt<<endl;
  }*/
  int count=0;
  int i=0;
  while(i<V-1){
    edge e=input[count];
    int v1=e.st;
    int v2=e.end;
    int v1p=findParent(v1,parent);
    int v2p=findParent(v2,parent);
    if(v1p!=v2p){
      output[i]=e;
      i++;
      count++;
      parent[findParent(v1p,parent)]=findParent(v2p,parent);
    }
    else{
      count++;
      continue;
    }
  }
  //printing final output
  for(int i=0;i<V-1;i++){
    int v1=output[i].st;
    int v2=output[i].end;
    if(v1>v2){
      int temp=v1;
      v1=v2;
      v2=temp;
    }
    int wt=output[i].wt;
    cout<<v1<<" "<<v2<<" "<<wt;
    cout<<endl;
  }

  /*

  	   Write Your Code Here
	   Complete the Rest of the Program
	   You have to Print the output yourself
	 
  */

  return 0;
}
