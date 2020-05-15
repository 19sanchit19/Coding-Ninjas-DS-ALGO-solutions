// Binary Search (Recursive)
// Send Feedback
// Given an integer sorted array (sorted in increasing order) and an element x, find the x in given array using binary search. Return the index of x.
// Return -1 if x is not present in the given array.
// Note : If given array size is even, take first mid.
// Input format :

// Line 1 : Array size

// Line 2 : Array elements (separated by space)

// Line 3 : x (element to be searched)

// Sample Input :
// 6
// 2 3 4 5 6 8 
// 5 
// Sample Output:
// 3 

//solution

// input - input array
// size - length of input array
// element - value to be searched
int binarySearch(int input[],int size,int element)
{
    if(size==1)
    {
        if(input[0]==element)
            return 0;
        else
            return -1;
    }
        
    int mid;
  	if(size%2==0)
      mid=size/2-1;
  	else
      mid=size/2;
    int k;
    if(element>input[mid])
    {
        k=binarySearch(input+mid+1,size-mid-1,element);
        if(k==-1)
            return k;
        else
            return k+mid+1;
    }
    if(element<input[mid])
    {
        k=binarySearch(input,mid,element);
        return k;
    }
    else
        return mid;
}

