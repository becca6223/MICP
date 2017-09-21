#ifndef _LINK_PALINDROME_H_
#define _LINK_PALINDROME_H_
#include <stdbool.h>

typedef struct _list {

	char value;
	struct _list* next;
}List;

//Function Declarations
void Check_Input(List* head);
int Get_Link_List_Length(List* head);
bool Check_Palindrome(List* head, int length);

#endif
