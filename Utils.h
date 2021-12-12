#ifndef UTILS_H_INCLUDED
#define UTILS_H_INCLUDED

int NumOfElements(char* ptr);
int CharToInt(char c);
int CharToAtbash(char c);
int IsAnagram(char array1[], char array2[]);
char* Gematria(char* word, char* text);
char* Atbash(char* word, char* text, int wordSize);
char* Anagram(char* word, char* text, int wordSize, int textSize, char* gem);

#endif // UTILS_H_INCLUDED