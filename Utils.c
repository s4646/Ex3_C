#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TXT 1024 
#define WORD 30

int NumOfElements(char* ptr)
{
    int j=0;
    for (char* temp = ptr; *temp!='\0'; temp++)
    {
        j++;
    }
    return j;
}

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

int CharToAtbash(char c)
{
    if(c>=65 && c<=90)
    {
        return 90-(-(65-c)%26)-64;
    }
    else if(c>=97 && c<=122)
    {
        return 122-(-(97-c)%26)-96;
    }
    else
        return c;
}

int IsAnagram(char array1[], char array2[])

{
    int num1[27] = {0}, num2[27] = {0}, i = 0;

    while (array1[i] != '\0')
    {
        // if not space
        if(array1[i]!=' ')
        {
            // if undercase
            if((array1[i]>='a' && array1[i]<='z'))
            {
                num1[array1[i] - 'a']++;
            }
            // if uppercase
            else if(array1[i]>='A' && array1[i]<='Z')
            {
                num1[array1[i] - 'A']++;
            }
            // not a letter
            else
            {
                num1[27]+=array1[i];
            }
        }
        i++;
    }

    i = 0;
    while (array2[i] != '\0')
    {
        // if not space
        if(array2[i]!=' ')
        {
            // if undercase
            if((array2[i]>='a' && array2[i]<='z'))
            {
                num2[array2[i] - 'a']++;
            }
            // if uppercase
            else if(array2[i]>='A' && array2[i]<='Z')
            {
                num2[array2[i] - 'A']++;
            }
            // not a letter
            else
            {
                num2[27]+=array2[i];
            }
        }
        i++;
    }

    for (i = 0; i < 27; i++)
    {
        if (num1[i] != num2[i])
            return 0;
    }
    return 1;
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
            if(sameValue==NULL) exit(0);
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
            if(sameValue==NULL) exit(0);
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
        if(sameValue==NULL) exit(0);
        tempSum=0;
        j=0;
    }
    free(sameValue);
    return final;
}

char* Atbash(char* word, char* text, int wordSize)
{
    // initiazlie
    char* temp;
    char* final = (char*)malloc(sizeof(char));
    if(final==NULL) exit(0);
    
    // get atbash value of word
    int wordSum = 0;
    for (temp = word; *temp!='\0'; temp++)
    {
        wordSum+= CharToAtbash(*temp);
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
            if(sameValue==NULL) exit(0);
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
            if(sameValue==NULL) exit(0);
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
        if(sameValue==NULL) exit(0);
        tempSum=0;
        j=0;
    }
    free(sameValue);
    
    // filter combinations that are not the word or its palindrome
    j=0;
    char* ret = (char*)calloc(1,sizeof(char));
    temp = calloc(wordSize,sizeof(char));
    if(ret==NULL || temp==NULL) exit(0);
    for (char* arr = final; *arr!='\0'; arr++)
    {
        int value = CharToAtbash(*arr);
        // end of combination
        if(*arr=='~')
        {   
            // add combination and reset pointer
            if(wordSize==j)
            {
                ret = strcat(ret,strcat(temp,"~"));
            }
            // no match - reset pointer
            temp = calloc(wordSize,sizeof(char));
            if(temp==NULL) exit(0);
            j=0;
        }
        // char's atbash value equals to word's char's gematric value
        if(value==CharToInt(word[j]) || value==CharToInt(word[wordSize-j-1]))
        {
            temp[j++]=*arr;
        }
        // no match
        else
        {
            continue;
        }
    }
    free(temp);
    free(final);
    return ret;
}

char* Anagram(char* word, char* text, int wordSize, int textSize, char* gem)
{
    char* potential = gem;
    char* final = (char*)calloc(1,sizeof(char));
    if(final==NULL) exit(0);
    int numOfWords = 0;
    // get number of potential anagrams
    for (char* temp = potential; *temp!='\0'; temp++)
    {
        if(*temp=='~')
            numOfWords++;
    }
    // for each candidate, if anagram - add to final
    char* temp = potential;
    char* other;
    for (size_t i = 0; i < numOfWords; i++)
    {
        other = calloc(textSize,sizeof(char));
        if(other==NULL) exit(0);
        int j = 0;
        for (; *temp!='~'; temp++)
        {
            other[j++] = *temp;
        }
        if(IsAnagram(other,word))
        {
            final = strcat(final,strcat(other,"~"));
        }
        temp++;
    }
    //free(potential);
    free(other);
    return final;
}