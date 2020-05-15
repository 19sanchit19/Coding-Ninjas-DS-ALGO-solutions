// Return Keypad Code
// Send Feedback
// Given an integer n, using phone keypad find out all the possible strings that can be made using digits of input n.
// Return empty string for numbers 0 and 1.
// Note : 1. The order of strings are not important.
// 2. Input and output has already been managed for you. You just have to populate the output array and return the count of elements populated in the output array.
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

/* Insert all the possible combinations of the integer number into the output string array. You do not need to
   print anything, just return the number of strings inserted into the array.
    */
#include<string>
using namespace std;
//global string array containing keypad cobinations
string key[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
int keypad(int num,string output[])
{
    if(num<=1)
    {
        output[0]="";
        return 1;
    }
    int k=keypad(num/10,output);
    int n=num%10;
    int l=key[n].length();
    for(int j=1;j<l;j++)
    {
        for(int i=0;i<k;i++)
            output[j*k+i]=output[i]+key[n][j];
    }
    for(int i=0;i<k;i++)
        output[i]=output[i]+key[n][0];
    return l*k;
}
