//inserting a node after at a given position.
//nodes must be present in the list before using insertnodeatpos function.

#include<stdio.h>
#include<stdlib.h>
struct node
{	
	int data;
	struct node* next;
};
struct node* head;
void createnodeatbeg(int key)
{
		struct node*new=(struct node*)malloc(sizeof(struct node));
		new->data=key;
		new->next=head;
		head=new;
}
void printlist()
{
		struct node* temp=head;
		printf("list is:");
		while(temp!=NULL)
		{
			printf("%d  ",temp->data );
			temp=temp->next;
		}
		printf("\n");
}
void insertnodeatpos(struct node* head)
{
	struct node* temp=head;
	int element,key;
	printf("enter the element after which to insert\n");
	scanf("%d",&element);
	printf("enter the number to insert\n");
	scanf("%d",&key);
	while(temp->data!=element && temp->next!=NULL)
		temp=temp->next;
	if(temp->data==element)
		{
		struct node*new=(struct node*)malloc(sizeof(struct node));
		new->data=key;
		new->next=temp->next;
		temp->next=new;
		}
	else 
		printf("no such element in list\n");
}
int main()
{	
	head=NULL;
	int nodes;
	printf("enter number of nodes\n");
	scanf("%d",&nodes);
	for(int i=0;i<nodes;i++)
	{
	int data;
	printf("enter number\n");
	scanf("%d",&data);
	createnodeatbeg(data);
	}
	printlist();

	insertnodeatpos(head);

	printlist(head);
}
