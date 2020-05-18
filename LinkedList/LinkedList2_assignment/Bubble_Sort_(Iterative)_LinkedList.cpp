// Bubble Sort (Iterative) LinkedList
// Send Feedback
// Sort a given linked list using Bubble Sort (iteratively). While sorting, you need to swap the entire nodes, not just the data.
// You don't need to print the elements, just sort the elements and return the head of updated LL.
// Input format : Linked list elements (separated by space and terminated by -1)`

// Sample Input 1 :
// 1 4 5 2 -1
// Sample Output 1 :
// 1 2 4 5

//solution

//head is the head of the linked list
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
//swap function
node* swap_nodes(node *head,int i,int j)
{
    //write your code here
  node* temp=head;
  node* node1_prev=NULL;
  node* node1=NULL;
  node* node2_prev=NULL;
  node* node2=NULL;
  int count=0,flag=0,flag1=0;
  int small,big;
  if(i<j)
  {
    small=i;
    big=j;
  }
  else
  {
    small=j;
    big=i;
  }
  while(temp!=NULL&&count<big)
  {
   // temp=temp->next;
   // count++;
    if(flag1==0)
    {
    	if(small!=0)
    	{
    		if(count+1==small)
    		{
      			node1_prev=temp;
      			node1=temp->next;
              	flag1=1;
    		}
    	}
    	else
    	{
      		node1_prev=NULL;
      		node1=head;
      		flag=1;
          	flag1=1;
    	}
    }
    if(count+1==big)
    {
      node2_prev=temp;
      node2=temp->next;
    }
    temp=temp->next;
    count++;
  }
  if(flag==0)
  {
  	node1_prev->next=node2;
  	node2_prev->next=node1;
  	node* temp1=node1->next;
  	node* temp2=node2->next;
  	node1->next=temp2;
  	node2->next=temp1;
  }
  else
  {
    node* temp1=node2->next;
    if(big!=1)
    	node2->next=node1->next;
    else
      	node2->next=node1;
    node2_prev->next=node1;
    node1->next=temp1;
    head=node2;
  }
	return head;
}
//length function
int length(node *head) 
{
  if(head==NULL)
    return 0;
  int a=length(head->next);
    return a+1;
}
//bubble sort function
node* bubble_sort_LinkedList_itr(node* head)
{
    //write your code here
  int count=0,i=0;
  int len=length(head);
  node* temp=head;
  while(count<len-1)
  {
    temp=head;
    count=0;
    i=0;
    while(temp->next!=NULL)
    {
      if(temp->data>temp->next->data)
        head=swap_nodes(head,i,i+1);		//change arguments 2 & 3 to integer instead of pointer
      else
      {
        temp=temp->next;
        count++;
      }
      i++;
    }
  }
  return head;
}
