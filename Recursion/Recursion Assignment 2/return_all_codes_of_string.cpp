// Return all codes - String
// Send Feedback
// Assume that the value of a = 1, b = 2, c = 3, ... , z = 26. You are given a numeric string S. Write a program to return the list of all possible codes that can be generated from the given string.
// Note : The order of codes are not important. And input string does not contain 0s.
// Input format :
// A numeric string
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

int getCodes(string input, string output[10000]) {
    /*
    You are given the input text and output string array. Find all possible codes and store in the output string array. Don’t print the codes.
    Also, return the number of codes return to the output string. You do not need to print anything.
    */
  //base case
  if(input.size()==1){
    output[0]=input[0]-'0'+'a'-1;
    return 1;
  }
  //recursive call
  else{	//else begins
    int smallans=getCodes(input.substr(1,input.size()-1),output);
    char newchar1=input[0]-'0'+'a'-1;
  	for(int i=0;i<smallans;i++)
      output[i]=newchar1+output[i];
    int a=input[0]-'0';
    if(a==1||a==2){	//biggest if inside else
      	int b=input[1]-'0';
      	if(10*a+b<=26){
       		string output1[10000];
        	if(input.size()==2){
          		char newchar2=10*a+b+'a'-1;
          		string ans;
          		output[smallans]=newchar2+ans;
          		return smallans+1;
        	}
       		else{
        		int smallans1=getCodes(input.substr(2,input.size()-2),output1);
        		for(int i=0;i<smallans1;i++){
          			char newchar=10*a+b+'a'-1;
          			output[smallans+i]=newchar+output1[i];
        		}//for ends
        		return smallans+smallans1;
      		}//small else ends
    	}//second biggest if
    	return smallans;
  	}//biggest if ends
    return smallans;
  }//else ends
}

