// C program to create a simple linked list with 3 nodes,nodes are added at the end.
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* next;
};
struct node* createnode(int data)
{
	struct node * temp=(struct node*)malloc(sizeof(struct node));
	temp->data=data	;
	temp->next=NULL;
	return temp;
}

void printlist(struct node* head)
{
		while(head!=NULL)
		{
			printf("%d  ",head->data );
			head=head->next;
		}
}
int main(){
//step 1:we created three independent nodes and then we stored the address each nodes in a pointer to node data type.
struct node* node1=createnode(5);
struct node* node2=createnode(10);
struct node* node3=createnode(15);
//step 2:we have linked all the nodes together,new nodes are added at end.
node1->next=node2;
node2->next=node3;
//step3:printing the list by passing the address of first node.
printlist(node1);
}
