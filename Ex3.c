#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Utils.h"
#define TXT 1024 
#define WORD 30

int CharToInt(char c);
char* Gematria(char* word, char* text);

int main() 
{
    char* word = (char*)malloc(sizeof(char)*WORD);
    char* text = (char*)malloc(sizeof(char)*TXT);
    if(word==NULL || text==NULL)
    {
        exit(0);
    }
    char c;
    int i=0;
    while(i<WORD)
    {   
        scanf("%c", &c);
        if(c=='\n' || c=='\t' || c=='\0')
        {
            break;
        }
        else
        {
            word[i] = c;
            i++;
        }
    }
    int j=0;
    while(j<TXT)
    {
        scanf("%c", &c);
        if(c=='~')
        {
            break;
        }
        else
        {
            text[j] = c;
            j++;
        }
    }

    word = (char*)realloc(word,i);
    text = (char*)realloc(text,j);
    if(word==NULL || text==NULL)
    {
        exit(0);
    }
    printf("%s\n", word);
    printf("%s\n\n", text);
    
    char* test = Gematria(word,text);
    printf("%s\n", test);
    
    free(word);
    free(text);
    free(test);

    return 0;
}