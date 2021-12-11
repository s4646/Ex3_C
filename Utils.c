#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TXT 1024 
#define WORD 30

int CharToInt(char c)
{
    if(c>=65 && c<=90)
    {
        return c-64;
    }
    if(c>=91 && c<=122)
    {
        return c-90;
    }
    else
        return 0;
}

char* Gematria(char* word, char* text)
{
    // initiazlie
    char* temp;
    char* final = (char*)malloc(sizeof(char));
    if(final==NULL) exit(0);
    *final='\0';
    
    // get gematria value of word
    int wordSum = 0;
    for (temp = word; *temp!='\0'; temp++)
    {
        wordSum+= *temp;
    }
    
    // find all substrings that has the same gematria value
    int tempSum=0;
    char* sameValue = (char*)(malloc(sizeof(text)));
    if(sameValue==NULL) exit(0);
    
    int j=0;
    for (temp = text; *temp!='\0'; temp++)
    {
        if(tempSum == wordSum)
        {
            // add substring t final
            strcat(final,sameValue);
            strcat(final,(char*)'~');
            // reset pointer
            sameValue = realloc(sameValue,sizeof(temp));
            tempSum=0;
            j=0;
        }
        else if(tempSum<wordSum)
        {
            // add char to substring
            sameValue[j] = *temp;
            tempSum+=CharToInt(sameValue[j]);
            j++;
        }
        else
        {
            // reset pointer
            sameValue = realloc(sameValue,sizeof(temp));
            tempSum=0;
            j=0;
        }
    }
    free(sameValue);
    free(temp);
    return final;
}