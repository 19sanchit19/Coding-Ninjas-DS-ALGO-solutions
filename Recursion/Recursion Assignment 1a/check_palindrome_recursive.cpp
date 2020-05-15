// Check Palindrome (recursive)
// Send Feedback
// Check whether a given String S is a palindrome using recursion. Return true or false.
// Input Format :
// String S
// Output Format :
// 'true' or 'false'
// Constraints :
// 0 <= |S| <= 1000
// where |S| represents length of string S.
// Sample Input 1 :
// racecar
// Sample Output 1:
// true
// Sample Input 2 :
// ninja
// Sample Output 2:
// false

//solution

#include<string.h>
bool checkPalindrome(char input[])
{
    bool var;
   int k=strlen(input);
   if(k<=1)
    return true;
   if(input[0]==input[k-1])
   {
    input[k-1]='\0';
    var=checkPalindrome(input+1);
    return var;
   }
    
    else
        return false;
}
