#include<stdio.h>
#include<stdlib.h>

typedef struct Node 
{ 
	int value;
	struct Node *next;
} node;

node *linked_list=NULL;

/* Function to insert an item in the beginning of the list */
void insert (int num)
{
	node *new;
	new = malloc(sizeof(node));		
	
 	new -> value = num;
	new -> next = linked_list;

	linked_list = new;
}

/* Function to search an item on the list */
node* search (int num)
{
	node *n;
	for( n = linked_list ; n != NULL ; n = n->next)
	{	
		printf("%d\n",n->value);
		if (n-> value == num)
			return n; 
	}
	return NULL;
}

/* Function to remove an item from the beginning of the list */
void list_remove (int num)
{
	node *n, *previous=NULL;
	for( n = linked_list; n != NULL; previous=n, n = n->next)
	{
		if (n->value == num)
		{			
			if( n != linked_list) 
				previous->next = n->next;
			else
				linked_list = n->next;
			free(n);
			break;
		}
	}
}


int main(int argc, char *argv[])
{	
	int i;

	for(i=0;i<10;i++) 		insert(i);	

	if(search(5))
		printf("Found 5!\n");

	list_remove(9);
	list_remove(0);
	list_remove(6);

	if(search(11))
		printf("Found 11!\n");


	return 0;
}

