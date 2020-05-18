// Palindrome LinkedList
// Send Feedback
// Check if a given linked list is palindrome or not. Return true or false.
// Indexing starts from 0.
// Input format : Linked list elements (separated by space and terminated by -1)

// Sample Input 1 :
// 9 2 3 3 2 9 -1
// Sample Output 1 :
// true
// Sample Input 2 :
// 0 2 3 2 5 -1
// Sample Output 2 :
// false

//solution

//head is the head of you linked list
// Following is the node structure
/**************
class node{
public:
    int data;
    node * next;
    node(int data){
        this->data=data;
        this->next=NULL;
    }
};
***************/
/**********
 * Following is the Node class that is already written.
 
class Node{
public:
    int data;
    Node *next;
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};
 
*********/

int length(node *head) 
{
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input is handled automatically.
     */
  //base case
  if(head==NULL)
    return 0;
  int a=length(head->next);
    return a+1;
}



bool check_palindrome(node* head)
{
    //write your code here
  int l=length(head);
  node *temp_tail=head;
  node *temp_head=head;
  while(l>0)
  {
  for(int i=0;i<l-1;i++){
    temp_tail=temp_tail->next;
  }
  
  if(temp_tail->data==temp_head->data){
	temp_head=temp_head->next;
    l-=2;
    temp_tail=temp_head;
  }
    
  else
  {
    return false;
    break;
  }
  }
  return true;
}
