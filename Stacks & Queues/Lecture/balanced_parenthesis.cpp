// Code : Balanced Parenthesis
// Send Feedback
// Given a string expression, check if brackets present in the expression are balanced or not. Brackets are balanced if the bracket which opens last, closes first.
// You need to return true if it is balanced, false otherwise.
// Note: This problem was asked in initial rounds in Facebook
// Sample Input 1 :
// { a + [ b+ (c + d)] + (e + f) }
// Sample Output 1 :
// true
// Sample Input 2 :
// { a + [ b - c } ]
// Sample Output 2 :
// false

//solution

#include<stack>
stack <char> s;
bool checkBalanced(char *exp) {
	// Write your code here
  while(*exp!='\0'){
  	if(*exp=='('||*exp==')'||*exp=='{'||*exp=='}'||*exp=='['||*exp==']')
    {
    	if(	*exp=='('||*exp=='{'||*exp=='['	/*(s.top()=='('&&*exp==')') ||	(s.top()=='['&&*exp==']') ||(s.top()=='{'&&*exp=='}')*/	)
          s.push(*exp);
      	else
        {
          if(*exp==')')
          {
         	if(s.top()=='(')
              s.pop();
            else
              //s.push(*exp);
              return false;
          }
          else if(*exp=='}')
          {
            if(s.top()=='{')
              s.pop();
            else
              //s.push(*exp);
              return false;
          }
            
          else
          {
            if(s.top()=='[')
              s.pop();
            else
              //s.push(*exp);
              return false;
          }
              
        }
      exp++;
  	}
  	else
  	{
    	 exp++;
  	}
  }
  return s.empty()==1;
}