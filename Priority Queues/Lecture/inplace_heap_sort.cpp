// Code : In-place heap sort
// Send Feedback
// Given an integer array of size n. Sort this array (in decreasing order) using heap sort.
// Space complexity should be O(1).
// Input Format :
// Line 1 : Integer n, Array size
// Line 2 : Array elements, separated by space
// Output Format :
// Array elements after sorting
// Constraints :
// 1 <= n <= 10^6
// Sample Input:
// 6 
// 2 6 8 5 4 3
// Sample Output:
// 8 6 5 4 3 2

//solution


void inplaceHeapSort(int input[], int n){
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Change in the given input itself.
     * Taking input and printing output is handled automatically.
     */
  //heapbuilding
  int i=1;
  while(i<n){
    int ci=i;
    while(ci>0){
    	int pi=(ci-1)/2;
    	if(input[pi]>input[ci]){		//swap
      		int temp=input[pi];
      		input[pi]=input[ci];
      		input[ci]=temp;
      
    	}
      	else
          break;
      ci=pi;  
    }
    i++;
  }
  
  
  //heapdestruction
  
          
	while(n>0){
		int temp1=input[0];
      		input[0]=input[n-1];
			input[n-1]=temp1;
      		n-=1;
      		int parentindex=0;
      		int childindex1=2*parentindex+1;
      		int childindex2=2*parentindex+2;
        	while(childindex1<n){
			int minindex;
			if(childindex2<n)
				minindex=(input[childindex1]<input[childindex2]?childindex1:childindex2);
			else
				minindex=childindex1;
       	 		minindex=input[parentindex]<input[minindex]?parentindex:minindex;
        		if(minindex!=parentindex){
          			int temp=input[minindex];
          			input[minindex]=input[parentindex];
                	input[parentindex]=temp;
        		}
        		else
          			break;
          	parentindex=minindex;
          	childindex1=2*parentindex+1;
          	childindex2=2*parentindex+2;
      	}
}
      

}
