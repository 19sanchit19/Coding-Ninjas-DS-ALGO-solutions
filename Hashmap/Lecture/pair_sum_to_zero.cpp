// Code : Pair Sum to 0
// Send Feedback
// Given a random integer array A of size N. Find and print the pair of elements in the array which sum to 0.
// Array A can contain duplicate elements.
// While printing a pair, print the smaller element first.
// That is, if a valid pair is (6, -6) print "-6 6". There is no constraint that out of 5 pairs which have to be printed in 1st line. You can print pairs in any order, just be careful about the order of elements in a pair.
// Input format :
// Line 1 : Integer N (Array size)
// Line 2 : Array elements (separated by space)
// Output format :
// Line 1 : Pair 1 elements (separated by space)
// Line 2 : Pair 2 elements (separated by space)
// Line 3 : and so on
// Constraints :
// 0 <= N <= 10^4
// Sample Input:
// 5
// 2 1 -2 2 3
// Sample Output :
// -2 2
// -2 2

//solution

 #include<unordered_map> 	
	void PairSum(int *input, int n) {	 
		
	/* Don't write main().
     	* the input array is already passed as function argument.
     	* Don't need to return anything. Print the desired pairs in the function itself.
     	*/
     	unordered_map<int,int> freq;
      for(int i=0;i<n;i++){
        freq[input[i]]++;
      }
      //frequency table is ready
      	unordered_map<int,int> visited;
      for(int i=0;i<n;i++){
        if(visited[input[i]]!=1&&visited[-1*input[i]]!=1&&freq[input[i]]>0&&freq[-1*input[i]]>0){
          visited[input[i]]=1;
          visited[-1*input[i]]=1;
          int a=freq[input[i]];
          int b=freq[-1*input[i]];
          int min_num=min(input[i],-1*input[i]);
          int max_num=max(input[i],-1*input[i]);
          for(int j=0;j<a*b;j++){
            cout<<min_num<<" "<<max_num<<endl;
          }
        }
      }
     	
     	
 	}

