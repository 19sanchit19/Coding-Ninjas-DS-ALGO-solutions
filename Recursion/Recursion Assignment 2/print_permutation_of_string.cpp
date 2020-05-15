// Print Permutations - String
// Send Feedback
// Given a string, find and print all the possible permutations of the input string.
// Note : The order of permutations are not important. Just print them in different lines.
// Sample Input :
// abc
// Sample Output :
// abc
// acb
// bac
// bca
// cab
// cba

//solution

#include <iostream>
#include <string>
using namespace std;
#include <string>
#include<vector>
using namespace std;

int returnPermutations(string input, string output[]){
   	/* Don't write main() function.
	 * Don't read input, it is passed as function argument.
	 * Print output as specified in the question
	*/
  //base case
  if(input.size()==0)
    return 0;
  else if(input.size()==1){
    string ans;
    ans=input[0]+ans;
    output[0]=ans;
    return 1;
  }
  //recursive call and small calculation
  else{
    int newans=returnPermutations(input.substr(1,input.size()-1),output);	//recursive call
    vector<string> output1;
    for(int i=0;i<newans;i++){
      output1.push_back(output[i]);
    }
    //^^ all the small permutations are in output1 now
    vector<string> newoutput;
    int size=output1[0].size();
    for(int i=0;i<output1.size();i++){
     
      for(int j=0;j<=size;j++){
        string newstring=output1[i];
        string newchar;
        newchar=input[0]+newchar;
      	newstring.insert(j,newchar);
        newoutput.push_back(newstring);
      }
    }
    //all string combinations in newoutput
    //copy them into output
    for(int i=0;i<newoutput.size();i++){
      output[i]=newoutput[i];
    }
    return newoutput.size();
  }
}

void printPermutations(string input){

    	/* Don't write main() function.
	 * Don't read input, it is passed as function argument.
	 * Print output as specified in the question
	*/
  string output[100000];
  int k=returnPermutations(input,output);
  for(int i=k-1;i>=0;i--){
    cout<<output[i]<<endl;
  }
}
