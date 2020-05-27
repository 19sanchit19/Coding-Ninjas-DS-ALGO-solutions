// Largest Piece
// Send Feedback
// Its Gary's birthday today and he has ordered his favourite square cake consisting of '0's and '1's . But Gary wants the biggest piece of '1's and no '0's . A piece of cake is defined as a part which consist of only '1's, and all '1's share an edge with eachother on the cake. Given the size of cake N and the cake , can you find the size of the biggest piece of '1's for Gary ?
// Constraints :
// 1<=N<=50
// Input Format :
// Line 1 : An integer N denoting the size of cake 
// Next N lines : N characters denoting the cake
// Output Format :
// Size of the biggest piece of '1's and no '0's
// Sample Input :
// 2
// 11
// 01
// Sample Output :
// 3

//solution

int recursiveDFS(int i,int j,bool** visited,char cake[NMAX][NMAX],int n){
  int count=0;
  visited[i][j]=true;
  //moving in four directions
  //1(i-1,j)
  if(i-1>=0&&i-1<=n-1&&j>=0&&j<=n-1)//checking within limits
  {
    if(cake[i-1][j]=='1'){
      if(!visited[i-1][j]){
        count+=recursiveDFS(i-1,j,visited,cake,n);
      }
    }
  }
  
  //2(i+1,j)
  if(i+1>=0&&i+1<=n-1&&j>=0&&j<=n-1)//checking within limits
  {
    if(cake[i+1][j]=='1'){
      if(!visited[i+1][j]){
       	count+=recursiveDFS(i+1,j,visited,cake,n);
 
      }
    }
  }
    
  //3(i,j-1)
  if(i>=0&&i<=n-1&&j-1>=0&&j-1<=n-1)//checking within limits
  {
    if(cake[i][j-1]=='1'){
      if(!visited[i][j-1]){
        count+=recursiveDFS(i,j-1,visited,cake,n);

      }
    }
  }
    
  //4(i,j+1)
  if(i>=0&&i<=n-1&&j+1>=0&&j+1<=n-1)//checking within limits
  {
    if(cake[i][j+1]=='1'){
      if(!visited[i][j+1]){
        count+=recursiveDFS(i,j+1,visited,cake,n);

      }
    }
  }
    
  
 return count+1; 
}
int solve(int n,char cake[NMAX][NMAX])
{
	// Write your code here .
  //creating visited array
  bool** visited=new bool*[n];
  for(int i=0;i<n;i++){
    visited[i]=new bool[n];
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++)
      visited[i][j]=false;
  }
  /*for(int i=0;i<n;i++){
    for(int j=0;j<n;j++)
      cout<<visited[i][j]<<" ";
    cout<<endl;
  }*/
  //corresponding visited array ready
  int max=0;
  int ans;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(cake[i][j]=='1'&&visited[i][j]==false){
        ans=recursiveDFS(i,j,visited,cake,n);
        if(ans>max)
          max=ans;
      }
      else
        continue;
    }
  }
  return max;
}