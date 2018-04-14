//deleteing a node by position in a linked list.
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
void deleteatpos(int pos)
{	
	struct node* prev;
	struct node* temp=head;
	int count=1;
	//check wether the first node is not to be deleted.
	if(pos==1)
	{
		//if head is to be deleted then make it refer the next node.
		head=temp->next;
		//deallocate the memory reference of temp.
		free(temp);
		return ;
	}
	//exits loop when we found position or we visited all nodes
	while(count!=pos && temp->next!=NULL)
	{	
		//store the address of previous node which is to be deleted in prev.
		prev=temp;
		temp=temp->next;
		count++;
	}
	if(count==pos)
	{
		prev->next=temp->next;
		free(temp);
	}
	else
		printf("out of order\n");
	

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
	int nodes,pos;
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
	printf("enter the position to delete\n");
	scanf("%d",&pos);
	deleteatpos(pos);
	printlist();
}
