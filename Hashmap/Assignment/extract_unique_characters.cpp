// Extract Unique characters
// Send Feedback
// Given a string, you need to remove all the duplicates. That means, the output string should contain each character only once. The respective order of characters should remain same.
// Input format :
// String S
// Output format :
// Output String
// Constraints :
// 0 <= Length of S <= 10^8
// Sample Input 1 :
// ababacd
// Sample Output 1 :
// abcd
// Sample Input 2 :
// abcde
// Sample Output 2 :
// abcde

//solution

#include<unordered_map>
char* uniqueChar(char *str){
    // Write your code here
  //unordered_map<char,bool> present;
  int count=0;
  for(int i=0;str[i]!='\0';i++){
    //present[str[i]]=true;
    count++;
  }
  //int count=0;
  char* ans=new char[count];
  int i=0;
  unordered_map<char,bool> visited;
  for(int j=0;j<count;j++){
    if(visited[str[j]]==false){
      visited[str[j]]=true;
      ans[i]=str[j];
      i++;
    }
  }
  
  ans[i]='\0';
  return ans;
	
}