// Print Subset Sum to K
// Send Feedback
// Given an array A and an integer K, print all subsets of A which sum to K.
// Subsets are of length varying from 0 to n, that contain elements of the array. But the order of elements should remain same as in the input array.
// Note : The order of subsets are not important. Just print them in different lines.
// Input format :
// Line 1 : Size of input array
// Line 2 : Array elements separated by space
// Line 3 : K 
// Sample Input:
// 9 
// 5 12 3 17 1 18 15 3 17 
// 6
// Sample Output:
// 3 3
// 5 1

//solution

#include<vector>
void printSubsetSumToK1(int input[], int size, int k, vector<int> output) {
    // Write your code here
  //base case
  if(size==0){
    if(k==0){
    	for(int i=0;i<output.size();i++)
      		cout<<output[i]<<" ";
    	cout<<endl;
    }
    else
      return;
  }
  else{
    //recursive calls
    //#1 without input[0]
    printSubsetSumToK1(input+1,size-1,k,output);
    //#2 with input[0]
    output.push_back(input[0]);
    printSubsetSumToK1(input+1,size-1,k-input[0],output);
    
  }
  
}
void printSubsetSumToK(int input[],int size,int k){
  vector<int> output;
  printSubsetSumToK1(input,size,k,output);
}