//inserting a node at desired postition,printing them.
#include<stdio.h>
#include<stdlib.h>
void printlist();
struct node
{	
	int data;
	struct node* next;
};
struct node* head=NULL;
void createnode(int data)
{
		struct node*new=(struct node*)malloc(sizeof(struct node));
		new->data=data;
		new->next=head;
		head=new;

}
void insertnodeafter(int data)
{
	struct node* temp=head;
	int element;
	printf("enter the element after which to insert\n");
	printlist();
	scanf("%d",&element);
	while(temp->data!=element && temp->next!=NULL)
		temp=temp->next;
	if(temp->data==element)
		{
		struct node*new=(struct node*)malloc(sizeof(struct node));
		new->data=data;
		new->next=temp->next;
		temp->next=new;
		}
	else 
		printf("no such element in list\n");
}
void insertnodeatlast(int data)
{
	struct node* temp=head;
	while(temp->next!=NULL)
		temp=temp->next;
	struct node*new=(struct node*)malloc(sizeof(struct node));
	new->data=data;
	new->next=NULL;
	temp->next=new;
		
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

int main(){
	//step 1:take the user response
	while(1)
	{	
		int input,data;
		printf("enter the value of node\n");
		scanf("%d",&data);
		//printf("select from the list\n");
		printf("Enter 1 to create a node at beginning\n");
		printf("Enter 2 to create a node after a number\n");
		printf("Enter 3 to create a node at end\n");
		printf("Enter 4 to print the list\n");
		printf("Enter 5 to exit the program\n");
		scanf("%d",&input);
		switch(input){
			case 1:
			//by default node will be created at the beginning
			createnode(data);
			printlist();
			break;
			case 2:
			if(head==NULL){
			printf("please add some nodes first \n");
			break;
			}
			insertnodeafter(data);
			printlist();
			break;
			case 3:
			insertnodeatlast(data);
			printlist();
			break;
			case 5:
			return 0 ;
			case 4:
			if(head==NULL)
				printf("no elements to print,add some nodes first\n");
			else 
				printlist();
			break;
			default:
			printf("invalid input! Try again\n");
		}
	}
}
