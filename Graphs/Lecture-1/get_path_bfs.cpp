// Given an undirected graph G(V, E) and two vertices v1 and v2(as integers), find and print the path from v1 to v2 (if exists). Print nothing if there is no path between v1 and v2.
// Find the path using BFS and print the shortest path available.
// V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
// E is the number of edges present in graph G.
// Print the path in reverse order. That is, print v2 first, then intermediate vertices and v1 at last.
// Note : Save the input graph in Adjacency Matrix.
// Input Format :
// Line 1: Two Integers V and E (separated by space)
// Next E lines : Two integers a and b, denoting that there exists an edge between vertex a and vertex b (separated by space)
// Line (E+2) : Two integers v1 and v2 (separated by space)
// Output Format :
// Path from v1 to v2 in reverse order (separated by space)
// Constraints :
// 2 <= V <= 1000
// 1 <= E <= 1000
// 0 <= v1, v2 <= V-1
// Sample Input 1 :
// 4 4
// 0 1
// 0 3
// 1 2
// 2 3
// 1 3
// Sample Output 1 :
// 3 0 1
// Sample Input 2 :
// 6 3
// 5 3
// 0 1
// 3 4
// 0 3
// Sample Output 2 :


//solution

#include <iostream>
using namespace std;
#include<vector>
#include<queue>
vector<int> v;
vector<int> getPathBFS(int** edges,int V,int tempX,int tempY,bool* visited){
  //we won't use map but a V*2 matrix;
  queue<int> q;
  int**temp=new int*[V];
  for(int i=0;i<V;i++){
    temp[i]=new int[2];
    temp[i][0]=i;
    temp[i][1]=-1;
  }
  /*for(int i=0;i<V;i++){
    for(int j=0;j<2;j++)
      cout<<temp[i][j]<<" ";
    cout<<endl;
  }*/
  int flag=0;
  q.push(tempX);
  visited[tempX]=true;
  while(q.size()!=0){
    int front=q.front();
    //visited[front]=true;
    q.pop();
    for(int i=0;i<V;i++){
      if(edges[front][i]==1){
        if(visited[i])
          continue;
        else{
          q.push(i);
          visited[i]=true;
          temp[i][1]=front;
          if(i==tempY){
            flag=1;
            break;
          }
        }
      }
      else
        continue;
    }
    if(flag==1)
      break;
    else
      continue;
  }
  if(flag==1){
    int newtemp=tempY;
    while(newtemp!=tempX){
      v.push_back(newtemp);
      newtemp=temp[newtemp][1];
    }
    v.push_back(tempX);
  }
  return v;
}

int main()
{
  int V, E, tempX, tempY;
  cin >> V >> E;
  
  int **edges=new int*[V];
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
  
  cin>>tempX>>tempY;

  bool* visited=new bool[V];
  for(int i=0;i<V;i++)
    visited[i]=false;
  
  vector<int> v1=getPathBFS(edges,V,tempX,tempY,visited);
  int k=v1.size();
  for(int i=0;i<k;i++){
    int x=v1[i];
    cout<<x<<" ";
  }
  return 0;
}

