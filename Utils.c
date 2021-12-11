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
    else if(c>=97 && c<=122)
    {
        return c-96;
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
    
    // get gematria value of word
    int wordSum = 0;
    for (temp = word; *temp!='\0'; temp++)
    {
        wordSum+= CharToInt(*temp);
    }
    
    // find all substrings that has the same gematria value
    int tempSum=0;
    char* sameValue;
    sameValue = (char*)(malloc(sizeof(text)));
    if(sameValue==NULL) exit(0);
    
    int j=0;
    for (temp = text; *temp!='\0'; temp++)
    {
        // add substring to final
        if(tempSum == wordSum)
        {
             // get rid of unnecessary char
             int count = 0;
             while (CharToInt(sameValue[0])==0)
             {
                sameValue++;
                count++;
             }
                final = strcat(final,strcat(sameValue,"~"));
                temp = temp-j+count;
        
            // reset pointer
            sameValue = (char*)(calloc(sizeof(sameValue),sizeof(char)));
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
            sameValue = (char*)(calloc(sizeof(sameValue),sizeof(char)));
            temp = temp-j;
            tempSum=0;
            j=0;
        }
    }
    // incase loop missed last char
    if(tempSum == wordSum)
    {
        // get rid of unnecessary char
        int count = 0;
        while (CharToInt(sameValue[0])==0)
        {
            sameValue++;
            count++;
        }
        final = strcat(final,strcat(sameValue,"~"));
        temp = temp-j+count;
        // reset pointer
        sameValue = (char*)(calloc(sizeof(sameValue),sizeof(char)));
        tempSum=0;
        j=0;
    }
    free(sameValue);
    return final;
}