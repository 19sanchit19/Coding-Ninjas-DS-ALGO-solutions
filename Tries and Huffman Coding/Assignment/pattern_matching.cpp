// Pattern Matching
// Send Feedback
// Given a list of n words and a pattern p that we want to search. Check if the pattern p is present the given words or not.
// Return true or false.
// Input Format :
// Line 1 : Integer n
// Line 2 : n words (separated by space)
// Line 3 : Pattern p (a string)
// Output Format :
// true ot false
// Sample Input 1 :
// 4
// abc def ghi cba
// de
// Sample Output 2 :
// true
// Sample Input 2 :
// 4
// abc def ghi hg
// hi
// Sample Output 2 :
// true
// Sample Input 3 :
// 4
// abc def ghi hg
// hif
// Sample Output 3 :
// false

//solution

// #include "TrieNode.h"
#include <string>
#include <vector>
class TrieNode {
	public :
	char data;
	TrieNode **children;
	bool isTerminal;

	TrieNode(char data) {
		this -> data = data;
		children = new TrieNode*[26];
		for(int i = 0; i < 26; i++) {
			children[i] = NULL;
		}
		isTerminal = false;
	}
};

class Trie {
	TrieNode *root;

	public :
	int count;

	Trie() {
		this->count = 0;
		root = new TrieNode('\0');
	}

	bool insertWord(TrieNode *root, string word) {
		// Base case
		if(word.size() == 0) {
			if (!root->isTerminal) {
				root -> isTerminal = true;
				return true;	
			} else {
				return false;
			}
		}

		// Small Calculation
		int index = word[0] - 'a';
		TrieNode *child;
		if(root -> children[index] != NULL) {
			child = root -> children[index];
		}
		else {
			child = new TrieNode(word[0]);
			root -> children[index] = child;
		}

		// Recursive call
		return insertWord(child, word.substr(1));
	}

	// For user
	void insertWord(string word) {
		if (insertWord(root, word)) {
			this->count++;
		}
	}

	bool patternMatching1(vector<string> vect,TrieNode *root,string pattern) {
		// Complete this function
		// Return true or false
      //first we need to add the string in the vector					##done
      TrieNode *rootfix=root;
      if(root==rootfix){
      	for(int i=0;i<vect.size();i++){
          insertWord(vect[i]);
          string ans=vect[i];
          for(int j=1;j<ans.size();j++){
            int temp=ans[j]-'a';
            if(root->children[temp]==NULL){
              insertWord(ans.substr(j));
            }
          }
        }
        
      }
      //first we need to add all the suffix for each word present		##done
      
      
      
      //recursion
      //base case
      if(pattern.size()==0)
        return true;
      //small calculation
      TrieNode *child;
      int index=pattern[0]-'a';
      if(root->children[index]!=NULL){
        child=root->children[index];
      }
      else{
        return false;
      }
		//recursive call
      return patternMatching1(vect,child,pattern.substr(1));
	}
  	// for user
  bool patternMatching(vector<string> vect, string pattern) {
    return patternMatching1(vect,root,pattern);
  }
};
