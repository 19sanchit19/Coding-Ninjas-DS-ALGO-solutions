// Pairs with difference K
// Send Feedback
// You are given with an array of integers and an integer K. Write a program to find and print all pairs which have difference K.
// Take difference as absolute.
// Input Format :
// Line 1 : Integer n, Size of array
// Line 2 : Array elements (separated by space)
// Line 3 : K
// Output format :
// Print pairs in different lines (pair elements separated by space). In a pair, smaller element should be printed first.
// (Order of different pairs is not important)
// Constraints :
// 0 <= n <= 10^4
// Sample Input 1 :
// 4 
// 5 1 2 4
// 3
// Sample Output 1 :
// 2 5
// 1 4
// Sample Input 2 :
// 4
// 4 4 4 4 
// 0
// Sample Output 2 :
// 4 4
// 4 4
// 4 4
// 4 4
// 4 4
// 4 4

//solution

//#define unordered_map map
#include<map>
void printPairs(int *input, int n, int k) {
	// Write your code here
	map<int,int> freq;
  	for(int i=0;i<n;i++){
      freq[input[i]]++;
    }
  	map<int,bool> visited;
  	if(k==0){
      for(int i=0;i<n;i++){
        if(!visited[input[i]]){
          	visited[input[i]]=true;
        	int a=freq[input[i]]-1;
        	int x=(a*(a+1))/2;
        	for(int j=0;j<x;j++)
          		cout<<input[i]<<" "<<input[i]<<endl;
      	}
      }
    }
  	for(int i=0;i<n;i++){
     if(!visited[input[i]]){
        if(freq[k+input[i]]>=1||freq[input[i]-k]>=1){
           visited[input[i]]=true;
          int a=freq[input[i]];
          //case 1
          if(!visited[k+input[i]]){
          	int b=freq[k+input[i]];
          	int min1=min(input[i],k+input[i]);
          	int max1=max(input[i],k+input[i]);
             for(int i=0;i<a*b;i++){
              cout<<min1<<" "<<max1<<endl;
            }
          }
          //case 2
          if(!visited[input[i]-k]){
          	int c=freq[input[i]-k];
            int min1=min(input[i],input[i]-k);
          	int max1=max(input[i],input[i]-k);
            for(int i=0;i<a*c;i++){
              cout<<min1<<" "<<max1<<endl;
            }
          }
          
        }
      }
    }
}


