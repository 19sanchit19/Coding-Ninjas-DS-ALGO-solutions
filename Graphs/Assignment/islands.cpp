// Islands
// Send Feedback
// An island is a small piece of land surrounded by water . A group of islands is said to be connected if we can reach from any given island to any other island in the same group . Given N islands (numbered from 1 to N) and two lists of size M (u and v) denoting island u[i] is connected to island v[i] and vice versa . Can you count the number of connected groups of islands.
// Constraints :
// 1<=N<=100
// 1<=M<=(N*(N-1))/2
// 1<=u[i],v[i]<=N
// Input Format :
// Line 1 : Two integers N and M
// Line 2 : List u of size of M
// Line 3 : List v of size of M
// Output Return Format :
// The count the number of connected groups of islands
// Sample Input :
// 2 1
// 1
// 2
// Sample Output :
// 1 

//solution


#include<vector>
#include<bits/stdc++.h>
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
//trim below
//trim above
int solve(int n,int m,vector<int>u,vector<int>v)
{
	// Write your code here .
  //creating adjacency matrix
  int** edges=new int*[n];
  for(int i=0;i<n;i++){
    edges[i]=new int[n];
    
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++)
      edges[i][j]=0;
  }
  for(int i=0;i<m;i++){
    int k=u[i];
    int l=v[i];
    edges[k-1][l-1]=1;
    edges[l-1][k-1]=1;
  }
  /*for(int i=0;i<n;i++){
    for(int j=0;j<n;j++)
      cout<<edges[i][j]<<" ";
    cout<<endl;
  }*/
  //adjacency matrix is ready
  vector<vector<int>> mv=DFSTraversal(edges,n);
  int k=mv.size();
  return k;
}