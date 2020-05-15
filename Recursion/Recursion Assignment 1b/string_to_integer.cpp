// String to Integer
// Send Feedback
// Write a recursive function to convert a given string into the number it represents. That is input will be a numeric string that contains only numbers, you need to convert the string into corresponding integer and return the answer.
// Input format :
// Numeric string S (string, Eg. "1234")
// Output format :
// Corresponding integer N (int, Eg. 1234)
// Constraints :
// 0 <= |S| <= 9
// where |S| represents length of string S.
// Sample Input 1 :
// 1231
// Sample Output 1 :
// 1231
// Sample Input 2 :
// 12567
// Sample Output 2 :
// 12567

//solution

#include<string.h>
#include<math.h>
int stringToNumber(char input[])
{
    int sum;
    int k=strlen(input);
    if(k==0)
        return 0;
    sum=(input[0]-48)*((int)pow(10,k-1))+stringToNumber(input+1);
    return sum;
}

