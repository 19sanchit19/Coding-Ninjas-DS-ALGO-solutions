// Minimum bracket Reversal
// Send Feedback
// Given a string expression which consists only ‘}’ and ‘{‘. The expression may not be balanced. You need to find the minimum number of bracket reversals which are required to make the expression balanced.
// Return -1 if the given expression can't be balanced.
// Input Format :
// String S
// Output Format :
// Required count
// Sample Input 1 :
// {{{
// Sample Output 1 :
// -1
// Sample Input 2 :
// {{{{}}
// Sample Output 2 :
// 1

//solution

#include<stack>
int countBracketReversals(char input[]){
  stack<char> s;
	// Write your code here
	int i=0;	
  while(input[i]!='\0'){
  	if(input[i]=='{'){
      s.push(input[i]);
    }    
    else
    {
      //if(s.size()>0)
      	s.pop();
    }
    i++;
  }
  int k=s.size();
 // cout<<k<<endl;
  if(k%2!=0)
    return -1;
  else
  {
    if(k>=0)
    	return k/2;
    else
      return -1*k/2;
  }
}
