//Program to swap nodes with value x and y in a linked list
//It may be assumed that all keys in linked list are distinct.

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
struct node ** find( struct node **head, int data )
{
    while ( *head && ( *head )->data != data ) head = &( *head )->next;

    return head;
}

void swap( struct node **head, int data1, int data2 )
{
    struct node **left, **right;

    if ( *( left = find( head, data1 ) ) && *( right = find( head, data2 ) ) )
    {
        struct node *tmp = *left;
        *left = *right;
        *right = tmp;

        tmp = ( *left )->next;
        ( *left )->next = ( *right )->next;
        ( *right )->next = tmp;
    }
    else
    	printf("elements not present in list\n");
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
	int x,y;
	printf("enter the values from the list to be swapped\n");
	scanf("%d %d",&x,&y);
	swap(&head,x,y);	
	printf("swapped list is:\n");
	printlist();
}
