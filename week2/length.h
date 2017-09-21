#ifndef _LENGTH_H_
#define _LENGTH_H_

typedef struct {

    int stringLength;
    char* inputString;

} Input; 

Input GetUserInput(char* input);
int LongestSubstringNoRepeatChar(Input stringInfo);

#endif 
