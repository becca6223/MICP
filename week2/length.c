#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "length.h"

//Function Definitions
Input GetUserInput(char* input)
{
    //initialize struct Input 
    Input userInput;
    
    userInput.stringLength = strlen(input);
    
    char* actualString = malloc(sizeof(*actualString) * userInput.stringLength);
    strcpy(actualString, input);
    userInput.inputString = actualString;
    
    //Check the values being put in struct Input
    printf("string length = %d\n", userInput.stringLength);
    printf("input string = %s\n", userInput.inputString);
    
    return(userInput);
}

int LongestSubstringNoRepeatChar(Input stringInfo)
{
    int left = 0; //left pointer in an array of characters
    int right = 1; //right pointer in an array of characters
    int length = stringInfo.stringLength; 
    char* inputString = stringInfo.inputString;
    
    //The input string is not valid
    if(inputString == NULL)
    {
    	return(-1); 
	}
    
    //No need to check when there is only 1 character
    if(length == 1)
    {
    	return(1);
	}
	
	//when the string has more than 1 character
	int longestLength = 1; //set to 1 first, the minimum length
	int currentLength = 1;
	while (right < length)
    {
   		char* charAddress = strchr(&(inputString[left]), inputString[right]);
		int difference = &(inputString[right]) - charAddress; 
		//printf("the difference is %d\n", difference);
		if(difference > 0)
		{
			//exist repeated character in the substring
			if(currentLength > longestLength)
			{
				longestLength = currentLength;
			}
			left = left + charAddress - &(inputString[left]) + 1; //update left pointer to the beginning of a new substring
			currentLength = right - left + 1; //update the current length from left to right pointer (no need to loop through the previous substring to get the length)
		}
		else if(difference  == 0)
		{
			//no repeated character in the substring
			currentLength++;
		}
		right++;
	}

	//this can be optimized if use hashset from other languages. time complexity for hastset is O(1)
   	if(currentLength > longestLength)
	{
		longestLength = currentLength;
	}

	return(longestLength);
}


