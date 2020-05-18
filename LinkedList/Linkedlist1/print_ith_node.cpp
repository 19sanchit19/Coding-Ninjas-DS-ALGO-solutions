// Print ith node
// Send Feedback
// Given a linked list and a position i, print the node at ith position.
// If position i is greater than length of LL, then don't print anything.
// Indexing starts from 0.
// Input format :
// Line 1 : Linked list elements (separated by space and terminated by -1)
// Line 2 : Integer i (position)
// Output format :
// Element at ith position
// Sample Input 1 :
// 3 4 5 2 6 1 9 -1
// 3
// Sample Output 1 :
// 2
// Sample Input 2 :
// 3 4 5 2 6 1 9 -1
// 0
// Sample Output 2 :
// 3

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

void printIthNode(Node *head, int i)
{
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Print output and don't return it.
     * Taking input is handled automatically.
     */
	Node *temp=head;
  	for(int k=0;k<i&&temp!=NULL;k++){
      temp=temp->next;
    }
  if(temp!=NULL)
    cout<<temp->data;
}


