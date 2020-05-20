// Second Largest Element In Tree
// Send Feedback
// Given a generic tree, find and return the node with second largest value in given tree. Return NULL if no node with required value is present.
// Input format :
// Line 1 : Elements in level order form separated by space (as per done in class). Order is -
// Root_data, n (No_Of_Child_Of_Root), n children, and so on for every element 
// Output Format :
// Second Largest node data
// Sample Input 1 :
// 10 3 20 30 40 2 40 50 0 0 0 0 
// Sample Output 1 :
// 40

//solution

// Following is the given Tree node structure
/**************

 template <typename T>
class TreeNode {
public:
    T data;
    vector<TreeNode<T>*> children;
    
    TreeNode(T data) {
        this->data = data;
    }
    
    ~TreeNode() {
        for (int i = 0; i < children.size(); i++) {
            delete children[i];
        }
    }
};
***************/
/*erase everything and run this if new fails
// Following is the given Tree node structure
/**************

 template <typename T>
class TreeNode {
public:
    T data;
    vector<TreeNode<T>*> children;
    
    TreeNode(T data) {
        this->data = data;
    }
    
    ~TreeNode() {
        for (int i = 0; i < children.size(); i++) {
            delete children[i];
        }
    }
};
***************/
/*
#include<bits/stdc++.h>
TreeNode<int>* maxDataNode(TreeNode<int>* root) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
 /* if(root==NULL)
    return 0;
  int max=root->data;
  TreeNode<int>* maxNode=root;
  for(int i=0;i<root->children.size();i++){
    TreeNode<int>* k=maxDataNode(root->children[i]);
    if(k->data>=max)
    {
      max=k->data;
      maxNode=k;
    }
    else
      continue;
  }
	return maxNode;
}
TreeNode <int>* secondLargest(TreeNode<int> *root) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
 /* vector<pair<int,TreeNode<int>*>> V;
  pair<int,TreeNode<int>*> p;
  p.first=root->data;
  p.second=root;
  V.push_back(p);
  for(int i=0;i<root->children.size();i++){
    TreeNode<int>* maxnode=maxDataNode(root->children[i]);
    int newmaxdata=maxnode->data;
    pair<int,TreeNode<int>*> p;
    p.first=newmaxdata;
    p.second=maxnode;
    V.push_back(p);
  }
  sort(V.begin(),V.end());
	return V[V.size()-2].second;
}





till here*/
#include<bits/stdc++.h>
pair<TreeNode<int>*,TreeNode<int>*> secondLargestHelper(TreeNode<int>* root){
  //base case
  if(root==NULL){
    pair<TreeNode<int>*,TreeNode<int>*> p;
    p.first=NULL;
    p.second=NULL;
    return p;
  }
  else if(root!=NULL&&root->children.size()==0){
    pair<TreeNode<int>*,TreeNode<int>*> p;
    p.first=root;
    p.second=NULL;
    return p;
  }
  else{
    //recursive call
    vector<pair<int,TreeNode<int>*>> V;
    for(int i=0;i<root->children.size();i++){
      pair <TreeNode<int>*,TreeNode<int>*> p=secondLargestHelper(root->children[i]);
      if(p.first!=NULL){
        pair<int,TreeNode<int>*> p1;
        p1.first=p.first->data;
        p1.second=p.first;
        V.push_back(p1);
      }
      if(p.second!=NULL){
        pair<int,TreeNode<int>*> p2;
        p2.first=p.second->data;
        p2.second=p.second;
        V.push_back(p2);
      }
    }
    pair<int,TreeNode<int>*> pf;
    pf.first=root->data;
    pf.second=root;
    V.push_back(pf);
    sort(V.begin(),V.end());
    TreeNode<int>* max1=V[V.size()-1].second;
    TreeNode<int>* max2=V[V.size()-2].second;
    pair<TreeNode<int>*,TreeNode<int>*> P;
    P.first=max1;
    P.second=max2;
    return P;
  }
    
}

TreeNode <int>* secondLargest(TreeNode<int> *root) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
  pair<TreeNode<int>*,TreeNode<int>*> p=secondLargestHelper(root);
  return p.second;

}

