// Delete node
// Send Feedback
// Given a linked list and a position i, delete the node of ith position from Linked List iteratively.
// If position i is greater than length of LL, then you should return the same LL without any change.
// Indexing starts from 0. You don't need to print the elements, just delete the node and return the head of updated LL.
// Input format :
// Line 1 : Linked list elements (separated by space and terminated by -1)
// Line 2 : Integer i (position)
// Output format :
// Updated LL elements (separated by space)
// Sample Input 1 :
// 3 4 5 2 6 1 9 -1
// 3
// Sample Output 1 :
// 3 4 5 6 1 9
// Sample Input 2 :
// 3 4 5 2 6 1 9 -1
// 0
// Sample Output 2 :
// 4 5 2 6 1 9

//solution

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

int length(Node *head) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input is handled automatically.
     */
  if(head!=NULL)
  {
    	Node *temp=head;
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



Node* deleteNode(Node *head, int i) 
{
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input is handled automatically.
     */
  Node *temp=head;
  int a=length(head);
  if(i==0)
  {
    head=head->next;
    delete temp;
    return head;
  }
  if(i<a)
  {
  for(int j=0;j<i-1;j++)
  {
    temp=temp->next;
  }
  Node *a=temp->next;
  Node *b=a->next;
  temp->next=b;
  delete a;
  }
  return head;
  
  
  
    
}


