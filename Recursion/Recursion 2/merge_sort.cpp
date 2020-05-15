// Merge Sort Code
// Send Feedback
// Sort an array A using Merge Sort.
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
// 2 1 5 2 3
// Sample Output 2 :
// 1 2 2 3 5 

//solution

void mergingtwosortedarrays(int a[],int a1,int b[],int b1,int c[])
{
    int i=0,j=0,k=0;
    int d=0,e=0;
    for(;k<a1+b1;k++)
    {
        if(d<a1&&e<b1)
        {

            if(a[i]<=b[j])
            {
                c[k]=a[i];
                d++;
                if(i<a1-1)
                    i++;
            }
            else
            {
                c[k]=b[j];
                e++;
                if(j<b1-1)
                    j++;
            }
        }
        else if(e<b1)
        {
            c[k]=b[j];
            if(j<b1-1)
                j++;
        }
        else
        {
            c[k]=a[i];
            if(i<a1-1)
                i++;
        }
    }
}
void mergeSort(int input[],int size)
{
    int *output=new int[size];
    if(size<=1)
        return;
    int mid=size/2;
    mergeSort(input,mid);
    mergeSort(input+mid,size-mid);
    mergingtwosortedarrays(input,mid,input+mid,size-mid,output);
    int i=0;
    for(;i<size;i++)
        input[i]=output[i];
    
}