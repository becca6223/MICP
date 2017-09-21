#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "link_palindrome.h"

//Helper Function Declarations 
List* _Create_Linked_List(char* list_of_chars);
void _Free_Linked_List(List* head);
void Call_All_Funcs(char* list_of_chars);

int main (int argc, const char* argv[])
{
	//test case 1
	//this will be aborted
	char* list_of_chars = NULL;
	//Call_All_Funcs(list_of_chars);

	//test case 2 
	list_of_chars = "a";
	Call_All_Funcs(list_of_chars);

	//test case 3 
	list_of_chars = "aa";
	Call_All_Funcs(list_of_chars);

	//test case 4 
	list_of_chars = "@abba@";
	Call_All_Funcs(list_of_chars);

	//test case 5
	list_of_chars = "cba";
	Call_All_Funcs(list_of_chars);

	//test case 6
	list_of_chars = "! !";
	Call_All_Funcs(list_of_chars);

	return (EXIT_SUCCESS); 
}


//Helper Function Definitions
void Call_All_Funcs(char* list_of_chars)
{
	//create a linked list
	List* head = _Create_Linked_List(list_of_chars);
	
	//Process for checking if the linked list is palindrome
	Check_Input(head);
	int length = Get_Link_List_Length(head);
	if(length == 1)
	{
		printf("is '%s' a palindrome ? %s\n", list_of_chars, "Yes");
	}
	else
	{
		bool is_it_palindrome = Check_Palindrome(head, length);
		char* result = is_it_palindrome ? "Yes" : "No";
		printf("is '%s' a palindrome ? %s\n", list_of_chars, result); 
	}

	_Free_Linked_List(head);
	
	return;
}

List* _Create_Linked_List(char* list_of_chars)
{
	if(list_of_chars != NULL)
	{
		int length = strlen(list_of_chars);
		int c = 0; 
		List dummy; 
		List* temp = &dummy;

		while(c != length)
		{
			temp -> next = malloc(sizeof(*(temp -> next)));
			temp -> next -> value = list_of_chars[c];
			temp -> next -> next = NULL;
			temp = temp -> next;
			c++;
		}
		
		return(dummy.next);
	}

	return(NULL);
}

void _Free_Linked_List(List* head) 
{
	List* temp = head; 
	while(temp != NULL)
	{	
		List* next = temp -> next;
		free(temp);
		temp = next;
	}
	
	return;
}

