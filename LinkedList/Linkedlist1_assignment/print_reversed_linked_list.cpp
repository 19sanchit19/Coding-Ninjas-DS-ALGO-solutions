// Print reverse LinkedList
// Send Feedback
// Print a given linked list in reverse order. You need to print the tail first and head last. You can’t change any pointer in the linked list, just print it in reverse order.
// Input format : Linked List elements (separated by space and terminated by -1)

// Output format : Linked List elements in reverse order (separated by space)

// Sample Input 1 :
// 1 2 3 4 5 -1
// Sample Output 1 :
// 5 4 3 2 1
// Sample Input 2 :
// 1 2 3 -1
// Sample Output 2 :
// 3 2 1

//solution

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

int length(node *head) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input is handled automatically.
     */
  if(head!=NULL)
  {
    	node *temp=head;
  		int count=0;
  		while(temp->next!=NULL){
      	temp=temp->next;
      	count++;
    	}
  	return count+1;
  }
  else
    return 0;
}



void print_linkedlist_spl(node*head)
{
    //write your code here
  //will solve using recursion
  //base case
  static int l=length(head);
  if(l!=0)
  {
  if(head->next==NULL)
  {
    cout<<head->data;
    return;
  }
  
  print_linkedlist_spl(head->next);//recursion call
  //small calculation;
  cout<<" "<<head->data;
  }
  else
    return;
}
