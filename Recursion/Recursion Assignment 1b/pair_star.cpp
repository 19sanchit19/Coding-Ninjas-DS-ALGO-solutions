// Pair star
// Send Feedback
// Given a string S, compute recursively a new string where identical chars that are adjacent in the original string are separated from each other by a "*".
// Input format :
// String S
// Output format :
// Modified string
// Constraints :
// 0 <= |S| <= 1000
// where |S| represents length of string S.
// Sample Input 1 :
// hello
// Sample Output 1:
// hel*lo
// Sample Input 2 :
// aaaa
// Sample Output 2 :
// a*a*a*a

//solution

// Change in the given string itself. So no need to return or print the changed string
#include<string.h>
void pairStar(char input[])
{
    if(input[0]=='\0')
        return;
    if(input[0]!=input[1])
        pairStar(input+1);
    else
    {
        int k=strlen(input);
        int i=k+1;
        for(;i>=2;i--)
            input[i]=input[i-1];
        input[i]='*';
        pairStar(input+2);
    }
}