#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "link_palindrome.h"

void Check_Input(List* head)
{
	assert(head != NULL);
	return;
}

int Get_Link_List_Length(List* head)
{
	int length = 0; 
	List* temp = head; 

	while(temp != NULL)
	{
		length++;
		temp = temp -> next;
	}

	return(length);
}

bool Check_Palindrome(List* head, int length)
{
	int even_or_odd_length = length % 2;
	char* stack = malloc(sizeof(*stack) * (length / 2));
	List* temp = head; 
	int c = 0; //keep track of the position in the link list

	while(c != (length / 2))
	{
		stack[c] = temp -> value;
		temp = temp -> next; 
		c++;
	}

	if(even_or_odd_length == 1)
	{	//it is odd
		temp = temp -> next; //skip the middle value in the linked list
	}

	while(c != 0)
	{
		c--; 
		if(stack[c] != (temp -> value))
		{
			return(false);
		}
		temp = temp -> next;
	}
	free(stack);
	return(true);
}
