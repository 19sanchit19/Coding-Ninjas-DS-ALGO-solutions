// Code : Staircase using Dp
// Send Feedback
// A child is running up a staircase with n steps and can hop either 1 step, 2 steps or 3 steps at a time. Implement a method to count how many possible ways the child can run up to the stairs. You need to return all possible number of ways.
// Time complexity of your code should be O(n).
// Input format :
// Integer n (No. of steps)
// Constraints :
// n <= 70
// Sample Input 1:
// 4
// Sample Output 1:
// 7

//solution


/*long staircase(int n){
    /* Don't write main().
     *  Don't read input, it is passed as function argument.
     *  Return output and don't print it.
     *  Taking input and printing output is handled automatically.
     */
  /*if(arr.size()>=n)
    return arr[n-1];
  if(n<0)
    return 0;
  else if(n==1||n==0){
    arr.push_back(1);
    return 1;
  }
  else if(n==2){
    arr.push_back(2);
    return 2;
  }
  else if(n==3){
    arr.push_back(4);
    return 4;
  }
  arr.push_back(staircase(n-3)+staircase(n-2)+staircase(n-1));
  return staircase(n-3)+staircase(n-2)+staircase(n-1);
    
    
}*/
// trying using tabulation
long arr[70];
long staircase(int n){
  if(n<4){
    if(n<0)
      return 0;
    else if(n==0)
      return 1;
    else if(n==1){
      return 1;
    }
    else if(n==2){
      return 2;
    }
    else{
      return 4;
    }
  }
  else{
    arr[0]=1;
    arr[1]=2;
    arr[2]=4;
    for(int i=3;i<n;i++){
      arr[i]=arr[i-1]+arr[i-2]+arr[i-3];
    }
    return arr[n-1];
  }
}