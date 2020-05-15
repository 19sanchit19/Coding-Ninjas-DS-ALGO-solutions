// Count Zeros
// Send Feedback
// Given an integer N, count and return the number of zeros that are present in the given integer using recursion.
// Input Format :
// Integer N
// Output Format :
// Number of zeros in N
// Constraints :
// 0 <= N <= 10^9
// Sample Input 1 :
// 10204
// Sample Output 1 :
// 2
// Sample Input 2 :
// 708000
// Sample Output 2 :
// 4

//Solution


int countZeros(int n)
{
  int count;
   
  if(n==0)
    return 0;
 count=countZeros(n/10);
  if(n%10==0)
    return count+1;
  else
    return count;

}
 // Write your code here

