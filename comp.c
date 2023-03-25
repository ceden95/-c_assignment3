#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "comp.h"

#define MAX_WORD_LENGTH 256

int is_permut(char *file_word, char *perm, int perm_len)
{
    char sorted_file_word[MAX_WORD_LENGTH];

    /*sorted section from word in file in perm length*/
    strncpy(sorted_file_word, file_word, perm_len); /*copy the section in perm length*/
    sorted_file_word[perm_len] = '\0'; /* string ends acording to perm length*/
    qsort(sorted_file_word, perm_len, sizeof(char), compare); /*sorting the chars*/
    
    /*compare sectiom from file worn and perm*/
    if (memcmp(sorted_file_word, perm, perm_len) == 0) { 
        return 1;
    }
    return 0;
}


int compare(const void *x, const void *y)
{
    char a = *(char *)x;
    char b = *(char *)y;
    return a - b;
}
