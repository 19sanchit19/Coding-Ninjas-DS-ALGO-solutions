// Geometric Sum
// Send Feedback
// Given k, find the geometric sum i.e.
// 1 + 1/2 + 1/4 + 1/8 + ... + 1/(2^k) 
// using recursion.
// Input format :
// Integer k
// Output format :
// Geometric sum
// Constraints :
// 0 <= k <= 1000
// Sample Input 1 :
// 3
// Sample Output 1 :
// 1.875
// Sample Input 2 :
// 4
// Sample Output 2 :
// 1.93750

//solution

#include<math.h>
double geometricSum(int k) 
{
   double sum;
  if(k==0)
    return 1;
  sum=geometricSum(k-1)+pow(2,-k);
  return sum;

}
// Write your code here

