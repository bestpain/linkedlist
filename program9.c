//Finding the number of nodes in a  linked list using iteration.
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

int length()
{
	int count=0;
	struct node* temp=head;
	while(temp!=NULL)
		{
			count++;
			temp=temp->next;
		}
	return count;

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

int main()
{	
	head=NULL;
	int nodes,key;
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
	int size=length();
	printf("the number of nodes is %d\n",size);
	
}
