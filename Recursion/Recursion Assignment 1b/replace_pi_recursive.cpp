// Replace pi (recursive)
// Send Feedback
// Given a string, compute recursively a new string where all appearances of "pi" have been replaced by "3.14".
// Sample Input 1 :
// xpix
// Sample Output :
// x3.14x
// Sample Input 2 :
// pipi
// Sample Output :
// 3.143.14
// Sample Input 3 :
// pip
// Sample Output :
// 3.14p

//solution

// Change in the given string itself. So no need to return or print anything
#include<string.h>
void replacePi(char input[])
{
    if(input[0]=='\0')
        return;
    if(input[0]=='p'&&input[1]=='i')
    {
        int k=strlen(input);
        int i=k+2;
        for(;i>=4;i--)
            input[i]=input[i-2];
        input[0]='3';
        input[1]='.';
        input[2]='1';
        input[3]='4';
        replacePi(input+4);
    }
    else
        replacePi(input+1);
}


