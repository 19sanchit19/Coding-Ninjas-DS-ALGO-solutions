// Return subset of an array
// Send Feedback
// Given an integer array (of length n), find and return all the subsets of input array.
// Subsets are of length varying from 0 to n, that contain elements of the array. But the order of elements should remain same as in the input array.
// Note : The order of subsets are not important.
// Input format :

// Line 1 : Size of array

// Line 2 : Array elements (separated by space)

// Sample Input:
// 3
// 15 20 12
// Sample Output:
// [] (this just represents an empty array, don't worry about the square brackets)
// 12 
// 20 
// 20 12 
// 15 
// 15 12 
// 15 20 
// 15 20 12 

//solution

/***
You need to save all the subsets in the given 2D output array. And return the number of subsets(i.e. number of rows filled in output) from the given function.

In ith row of output array, 1st column contains length of the ith subset. And from 1st column actual subset follows.
For eg. Input : {1, 2}, then output should contain 
	{{0}, 		// Length of this subset is 0
	{1, 2},		// Length of this subset is 1
	{1, 1},		// Length of this subset is also 1
	{2, 1, 2}}	// Length of this subset is 2

Don’t print the subsets, just save them in output.
***/

int subset(int input[],int n,int output[][20])
{
    if(n==0)
    {
        output[0][0]=0;
        return 1;
    }
    else
    {
        int k=subset(input+1,n-1,output);
        for(int i=0;i<k;i++)
        {
            output[k+i][0]=output[i][0]+1;
            output[k+i][1]=input[0];
            for(int j=0;j<output[i][0];j++)
                output[k+i][j+2]=output[i][j+1];
        }
        return 2*k;
    }
}
