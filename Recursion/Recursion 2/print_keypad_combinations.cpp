// Print Keypad Combinations Code
// Send Feedback
// Given an integer n, using phone keypad find out and print all the possible strings that can be made using digits of input n.
// Note : The order of strings are not important. Just print different strings in new lines.
// Input Format :
// Integer n
// Output Format :
// All possible strings in different lines
// Constraints :
// 1 <= n <= 10^6
// Sample Input:
// 23
// Sample Output:
// ad
// ae
// af
// bd
// be
// bf
// cd
// ce
// cf

//solution

#include <iostream>
#include<string>
using namespace std;
string key[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
string output="";
void printKeypad(int num)
{
    if(num==0)
    {
        cout<<output<<endl;
        return;
    }
    int n=num%10;
    int l=key[n].length();
    for(int i=0;i<l;i++)
    {
        output=key[n][i]+output;
        printKeypad(num/10);
        output=output.substr(1);
    }
    
    /*cout<<output<<endl;*/
}
