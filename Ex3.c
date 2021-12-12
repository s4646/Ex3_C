#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Utils.h"
#define TXT 1024 
#define WORD 30

int CharToInt(char c);
int CharToAtbash(char c);
int IsAnagram(char array1[], char array2[]);
char* Gematria(char* word, char* text);
char* Atbash(char* word, char* text, int wordSize);
char* Anagram(char* word, char* text, int wordSize, int textSize);

int main() 
{
    // get word and text
    char tmpWord[WORD] = {'\0'};
    char tmpText[TXT] = {'\0'};
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
            tmpWord[i] = c;
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
            tmpText[j] = c;
            j++;
        }
    }
    // initialize pointers with EXACT size of word and text
    char* word = (char*)malloc(i*sizeof(char));
    char* text = (char*)malloc(j*sizeof(char));
    if(word==NULL || text==NULL) exit(0);
    for (size_t i = 0; i < WORD; i++)
    {
        if(tmpWord[i]=='\0')
            break;
        word[i]=tmpWord[i];
    }
    for (size_t i = 0; i < TXT; i++)
    {
        if(tmpText[i]=='\0')
            break;
        text[i]=tmpText[i];
    }
    
    printf("%s\n", word);
    printf("%s\n\n", text);
    
    char* test1 = Gematria(word,text);
    printf("%s\n\n", test1);

    char* test2 = Atbash(word,text,i);
    printf("%s\n\n", test2);

    char* test3 = Anagram(word, text, i, j);
    printf("%s\n\n", test3);

    free(word);
    free(text);
    free(test1);
    free(test2);
    free(test3);

    return 0;
}