//inserting a node at the beginning of a linked list
#include<stdio.h>
#include<stdlib.h>
struct node
{	
	int data;
	struct node* next;
};
struct node* head=NULL;
struct node* createnodeatbeg(int data)
{
	if(head==NULL)
	{
		struct node*new=(struct node*)malloc(sizeof(struct node));
		new->data=data;
		new->next=NULL;
		return new;
	}
	else
	{
		struct node*new=(struct node*)malloc(sizeof(struct node));
		new->data=data;
		new->next=head;
		return new;
	}
}
void printlist(struct node* head)
{
		if(head==NULL)
			printf("no elements to print");
		while(head!=NULL)
		{
			printf("%d  ",head->data );
			head=head->next;
		}
}
int main()
{	
	int nodes;
	printf("enter number of nodes\n");
	scanf("%d",&nodes);
	for(int i=0;i<nodes;i++)
	{
	int data;
	scanf("%d",&data);
	head=createnodeatbeg(data);
	}
	printlist(head);
}
