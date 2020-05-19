// Reverse Queue
// Send Feedback
// Given a queue of integers, reverse it without help of any explicit stack or queue. You need to change in the given queue itself.
// Note : No need to return or print the queue.
// Input format :
// Line 1 : First Element - Size of Queue, Rest Elements - Elements Of Queue
// Output format :
// Queue elements
// Sample Input :
// 4 1 2 3 4     (1 is at front)
// Sample Output :
// 4 3 2 1    (4 is at front)

//solution

#include <queue>

void reverseQueue(queue<int> &q) {
  
	// Write your code here
  /*int k=q.size();
  int j;
  //cout<<k<<endl;
  /*int j=q.front();
  q.pop();
  q.push(j);
  j=q.front();
  q.pop();
  q.push(j);*/
  /*for(int i=0;i<k;i++){
    //cout<<i+1<<endl;
    q.push(q.front());
    q.pop();
    
  }*/
  
  //WE WILL HANDLE THIS USING RECURSION
  
  //base case
  if(q.size()==1)
    return;
  int j=q.front();
  q.pop();
  //recursive call
  reverseQueue(q);
  //our part
  q.push(j);
  

}