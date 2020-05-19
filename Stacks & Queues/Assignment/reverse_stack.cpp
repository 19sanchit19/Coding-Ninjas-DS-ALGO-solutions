// Reverse Stack
// Send Feedback
// Reverse a given Stack with the help of another empty stack. Two stacks will be given. Out of which first contains some integers and second one is empty. You need to reverse the first one using second stack. Change in the given first stack itself.
// Note : You don't need to print or return the stack, just reverse the given stack and it will be printed internally.
// Input format :
// Line 1 : Size of Stack
// Line 2 : Stack elements (separated by space)
// Sample Input 1 :
// 4 
// 1 2 3 4     (4 is at top)
// Sample Output 1 :
// 1 2 3 4    (1 is at top)

//solution

#include <stack>

void reverseStack(stack<int> &input, stack<int> &extra) {
	// Write your code here
  //we will do this recursively
  //base case
  if(input.size()==1)
    return;
  int j=input.top();
  input.pop();
  //recursive call
  reverseStack(input,extra);
  //small calculation
  int m=input.size();
  for(int i=0;i<m;i++){
    int l=input.top();
    input.pop();
    extra.push(l);
  }
  input.push(j);
  for(int i=0;i<m;i++){
    int l=extra.top();
    extra.pop();
    input.push(l);
  }

}