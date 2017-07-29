#include <stdio.h>
#include <stdlib.h>
#include "length.h"

//Function Declarations 
void CallAllFuncs(char* input);

//Function Definitions
void CallAllFuncs(char* input)
{
	Input stringInfo = GetUserInput(input);
	int length = LongestSubstringNoRepeatChar(stringInfo);
	printf("length = %d\n\n", length);
	return;
}

int main (int argc, const char* argv[])
{
	/*char* test = "hello";
	printf("first char address is %p", (void*)test);
	printf("second char address is %p",(void*)&(test[1]));
	char* pu = test; 
	printf("pu address is %p", (void*))
	printf("the difference is %d\n", (&(test[1]) - test));*/
	
	//Assume the user will input less than 256 char
	//For C, it will take more effort to code an dynamic input
	
	char* input = "a"; //ER = 1;
	CallAllFuncs(input);

	input = "aa"; //ER = 1
	CallAllFuncs(input);

	input = "abc";  //ER = 3;
	CallAllFuncs(input);

	input = "abca"; //ER = 3;
	CallAllFuncs(input);

	input = "abcaaqrst"; //ER = 5;
	CallAllFuncs(input);

	input = "abcabcd"; //ER = 4
	CallAllFuncs(input);

	input = "bbcfvdkll"; //ER = 7;
	CallAllFuncs(input);

	input = "abcbbdqrtrs3"; //ER = 5;
	CallAllFuncs(input);
	return(EXIT_SUCCESS);
}
