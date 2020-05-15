// Print Subsets of Array
// Send Feedback
// Given an integer array (of length n), find and print all the subsets of input array.
// Subsets are of length varying from 0 to n, that contain elements of the array. But the order of elements should remain same as in the input array.
// Note : The order of subsets are not important. Just print the subsets in different lines.
// Input format :
// Line 1 : Integer n, Size of array
// Line 2 : Array elements (separated by space)
// Constraints :
// 1 <= n <= 15
// Sample Input:
// 3
// 15 20 12
// Sample Output:
// [] (this just represents an empty array, don't worry about the square brackets)
// 12 
// 20 
// 20 12 
// 15 
// 15 12 
// 15 20 
// 15 20 12 

//solution

#include<vector>
void helper(int input[],int size,vector<int> output){
  //base case
  if(size==0){
    for(int i=0;i<output.size();i++)
      cout<<output[i]<<" ";
    cout<<endl;
  }
  //recursive calls
  else{
     //#1- without 1st element
  	helper(input+1,size-1,output);
 	 //#2- with 1st element
  	output.push_back(input[0]);
  	helper(input+1,size-1,output);
  }
  
}
void printSubsetsOfArray(int input[], int size) {
	// Write your code here
  	vector<int> output;
 	helper(input,size,output);
    
}
