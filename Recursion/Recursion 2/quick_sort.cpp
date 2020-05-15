// Quick Sort Code
// Send Feedback
// Sort an array A using Quick Sort.
// Change in the input array itself. So no need to return or print anything.


// Input format :
// Line 1 : Integer n i.e. Array size
// Line 2 : Array elements (separated by space)
// Output format :
// Array elements in increasing order (separated by space)
// Constraints :
// 1 <= n <= 10^3
// Sample Input 1 :
// 6 
// 2 6 8 5 4 3
// Sample Output 1 :
// 2 3 4 5 6 8
// Sample Input 2 :
// 5
// 1 5 2 7 3
// Sample Output 2 :
// 1 2 3 5 7 

//solution

void swap(int *a, int *b)
{
    int t;
    t=*a;
    *a=*b;
    *b=t;
}
int partition(int input[],int size)
{
    int i,j,a=*input;
    int count=0;
    for(i=1;i<size;i++)
    {
        if(input[i]<=a)
            count++;
    }
    swap(input,input+count);
    i=0;
    j=size-1;
    while(i!=count&&j!=count)
    {
        if(input[i]<=a||input[j]>a)
        {
            if(input[i]<=a)
                i++;
            if(input[j]>a)
                j--;
            
        }
        else
        {
            swap(input+i,input+j);
            i++;
            j--;
        }
    }
    return count;
}
void quickSort(int input[],int size)
{
    if(size<=1)
        return;
    int p=partition(input,size); 
    quickSort(input,p);
    quickSort(input+p+1,size-p-1);
}
