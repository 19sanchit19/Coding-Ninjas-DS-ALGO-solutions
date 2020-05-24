// Merge K sorted arrays
// Send Feedback
// Given k different arrays, which are sorted individually (in ascending order). You need to merge all the given arrays such that output array should be sorted (in ascending order).
// Hint : Use Heaps.
// Input Format :
// Line 1 : Integer K
// Line 2 : Arrays 1 size (n1)
// Line 3 : Array 1 elements (separated by space)
// Line 4 : Array 2 size (n2)
// and so on for next arrays
// Sample Input 1 :
// 4
// 3
// 1 5 9
// 2
// 45 90
// 5
// 2 6 78 100 234
// 1
// 0
// Sample Output 1 :
// 0 1 2 5 6 9 45 78 90 100 234

//solution

#include<queue>
vector<int> mergeKSortedArrays(vector<vector<int>*> input){
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return the output.
     * Taking input and printing output is handled automatically.
     */
  priority_queue<int, vector<int>,greater<int>> pq;
  int totalsize=input.size();
  for(int i=0;i<totalsize;i++){
    int size=input[i]->size();
    vector<int> ans1=*input[i];
    for(int j=0;j<size;j++){
      pq.push(ans1[j]);
    }
  }
  int anssize=pq.size();
  vector<int> ans;
  for(int i=0;i<anssize;i++){
    ans.push_back(pq.top());
    pq.pop();
  }
  return ans;

}
