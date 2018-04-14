//deleteing a node by value in a linked list.
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
void deletekey(int key)
{	
	struct node* prev;
	struct node* temp=head;
	//check wether the first node is not the key.
	if(temp->data==key && temp!=NULL)
	{
		//if head is key then make it refer the next node.
		head=temp->next;
		//deallocate the memory reference of temp.
		free(temp);
		return ;
	}
	//exits loop when we found key or we visited all nodes
	while(temp->data!=key && temp->next!=NULL)
	{	
		//store the address of previous node which is to be deleted in prev.
		prev=temp;
		temp=temp->next;
	}
	if(temp->data==key)
	{
		prev->next=temp->next;
		free(temp);
	}
	else
		printf("no such elements\n");
	

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
	printf("enter the element to delete\n");
	scanf("%d",&key);
	deletekey(key);
	printlist();
}
