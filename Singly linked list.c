#include<stdio.h>
#include <stdlib.h>
#include<malloc.h>


// structure of linked list
struct Node
{
	int data;
	struct Node *next;

}
*head = NULL;


//Adding to end of the list

void insertAtEnd(int value)
{
	struct Node *newNode;
	newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = value;
	newNode->next= NULL;
	if(head==NULL)
		head = newNode;

	else{
		struct Node *temp;
		temp=head;

	  while(temp->next!= NULL)
		temp = temp->next;

	temp->next = newNode;


	}
	printf("\n Node inserted successfully at end \n");

}

//Adding to beginning of the list

void insertAtBeginning(int value)
{
	struct Node *newNode;
	newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = value;

	if(head==NULL)
	{
		newNode->next=NULL;
		head=newNode;

	}

	else{
		newNode->next=head;
		head=newNode;
	}
	printf("\n Node inserted successfully at beginning\n");
}

//inserting at a specific location
void insertPosition(int value,int pos)
{
	struct Node *newNode;
	newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = value;
	int i=0;

	if(head==NULL)
	{
		newNode->next=NULL;
		head=newNode;

	}

	else{
		struct Node *temp;
		temp=head;
		for(i=0;i<pos-1;i++)
		{
			temp=temp->next;
		}
		newNode->next=temp->next;
		temp->next=newNode;
	}
	printf("\n Node inserted successfully at %d\n",pos);
	}


//Deletion from specific position
void delPosition(int pos)
{
	
	int i=0;

	if(head==NULL)
	{
	printf("List is empty");
	}

	else{
		int i;
		struct Node *temp=head,*temp2;
		if(pos==0){
		head= temp->next;
		
		printf("\n Node Deleted \n");	
		}
		else{
		for(i=1;i<=pos;i++)
		{
			temp2=temp;
			temp=temp->next;	
		}
		temp2->next=temp->next;
		free(temp);
		printf("\n Node Deleted\n");
		}
		
	
		}
	}





//print linked list
void printList()
{
if(head==NULL)
	{
		printf("LINKED LIST EMPTY  !!!!!\n");
	}
	else
	{
		struct Node *ptr;

		ptr=head;
	while(ptr!=NULL)
		{
			printf("[%d]-> ",ptr->data);
			ptr=ptr->next;
		}
		printf("\n");

	}



}




int main()
{
	int q=1;
	while(q>0)
	{

	printf("0.Exit \n1.Insertion at end\n2.Insertion at Beginning \n3.Insert at Positon \n 4.Deletion at specific Location \n9.Print Linked List\n");


	scanf("%d",&q);
	if(q==0)
	{
		exit(0);
	}
	else{



	switch(q)
	{
		case 1:
		printf("Enter value: ");
		int value;
		scanf("%d",&value);
		insertAtEnd(value);
		break;

		case 2:
		printf("Enter value: ");
		scanf("%d",&value);
		insertAtBeginning(value);
		break;

		case 3:
		printf("Enter value: ");
		scanf("%d",&value);
		printf("Enter Positon: ");
		int pos;
		scanf("%d",&pos);
		insertPosition(value,pos);
		break;
		
		case 4:
		printf("Enter Positon: ");
		scanf("%d",&pos);
		delPosition(pos);
		break;
		
		case 9:
			printList();
			break;
		default:
		printf("Switch statement not working");

	}
		}

	}
}
