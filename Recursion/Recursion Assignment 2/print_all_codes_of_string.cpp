// Print all Codes - String
// Send Feedback
// Assume that the value of a = 1, b = 2, c = 3, ... , z = 26. You are given a numeric string S. Write a program to print the list of all possible codes that can be generated from the given string.
// Note : The order of codes are not important. Just print them in different lines.
// Input format :
// A numeric string S
// Output Format :
// All possible codes in different lines
// Constraints :
// 1 <= Length of String S <= 10
// Sample Input:
// 1123
// Sample Output:
// aabc
// kbc
// alc
// aaw
// kw

//solution

#include <string.h>
using namespace std;
void helper(string input,string output){
  //base case
  if(input.size()==0)
    cout<<output<<endl;
  else{
    //small calculation
    //case 1
    char ans=input[0]-'0'+'a'-1;
    output=ans+output;
    helper(input.substr(1,input.size()-1),output);
    //case 2
    int a=input[0]-'0';
    int b=input[1]-'0';
    int num=10*a+b;
    if(num>=10&&num<=26){
      char newchar=num-'0'+'a'-1;
      string output1;
      output1=newchar+output1;
      helper(input.substr(2,input.size()-2),output1);
    }
  }
  
}
void printAllPossibleCodes(string input) {
    /*
    Given the input as a string, print all its possible combinations. You do not need to return anything.
    */
  string output;
  helper(input,output);
}

