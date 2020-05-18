// Insert node (recursive)
// Send Feedback
// Given a linked list, an integer n and a position i, Insert that node n into Linked List at ith position recursively.
// If position i is greater than length of LL, then you should return the same LL without any change. And if position i is equal to length of input LL, insert the node at last position.
// Indexing starts from 0. You don't need to print the elements, just insert and return the head of updated LL.
// Input format :
// Line 1 : Linked list elements (separated by space and terminated by -1)
// Line 2 : Integer i (position)
// Line 3 : Integer n (Node to be inserted)
// Output format :
// Updated LL elements (separated by space)
// Sample Input 1 :
// 3 4 5 2 6 1 9 -1
// 3
// 100
// Sample Output 1 :
// 3 4 5 100 2 6 1 9
// Sample Input 2 :
// 3 4 5 2 6 1 9 -1
// 0
// 20
// Sample Output 2 :
// 20 3 4 5 2 6 1 9

//solution

//head is head of linked list,i is the index, data is data of your node
// Following is the node structure
/**************
 class Node{
    public:
    int data;
    Node *next;
    Node(int data){
        this -> data = data;
        this -> next = NULL;
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

int length(Node *head) 
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



Node* insertNodeRec(Node *head, int i, int data)
{
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input is handled automatically.
     */
    // base case
  	static int x=length(head);
  	static int j=i;
	if(j==x)
    {
    	Node *temp=head;
        Node *newnode=new Node(data);
        for(int k=0;k<i-1;k++)
        {
        	temp=temp->next;
        }
        temp->next=newnode;
      	return head;
    }
    if(head==NULL)
      return head;
  	if(i!=0)
    {
      Node *p=insertNodeRec(head->next,i-1,data);
      head->next=p;
      return head;
    }
  	else
    {
      Node *newnode= new Node(data);
      newnode->next=head;
      head=newnode;
      return head;
    }
}



