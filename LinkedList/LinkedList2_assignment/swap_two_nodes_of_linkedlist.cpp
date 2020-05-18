// Swap two Node of LL
// Send Feedback
// Given a linked list, i & j, swap the nodes that are present at i & j position in the LL. You need to swap the entire nodes, not just the data.
// Indexing starts from 0. You don't need to print the elements, just swap and return the head of updated LL.
// Assume i & j given will be within limits. And i can be greater than j also.
// Input format :

// Line 1 : Linked list elements (separated by space and terminated by -1)

// Line 2 : i and j (separated by space)

// Sample Input 1 :
// 3 4 5 2 6 1 9 -1
// 3 4
// Sample Output 1 :
// 3 4 5 6 2 1 9
// Sample Input 2 :
// 3 4 5 2 6 1 9 -1
// 2 4
// Sample Output 2 :
// 3 4 6 2 5 1 9

//solution

//head is head of your linked list, i and j are indexes to be swapped
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
