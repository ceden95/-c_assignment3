#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "comp.h"

#define NUM_OF_ARGC 3
#define MAX_WORD_LENGTH 256/* assuming max length of file is 256 */

int valid_argc(int argc);
int file_opened(FILE *fptr);
int file_is_empty(FILE *fptr);


/*
 * this program gets 3 arguments at the comment line-
 *    -the program
 *    -the file to check
 *    -a string
 * and the program prints all the permutation of possible strings exist in the file
 * if no permutations are found, it prints a message indicating that.
 *
 */


int main(int argc, char *argv[])
{
    
    FILE *fptr;
    char perm[MAX_WORD_LENGTH]; /* array for the string argument */
    char file_word[MAX_WORD_LENGTH]; /* array for the words from file */
    char *p_to_print; /* pointer to the file_word array */
    int perm_found = 0; /* counter of permutation */
    int perm_len, file_word_len;
    int sub, i;

    /* check if number of arguments correct (3) */
    if (!valid_argc(argc))
    {
	exit (1);
    }
	
    /* open file for reading */
    fptr = fopen(argv[1], "r");
	
    /* check if file opened correctly */
    if (!file_opened(fptr))
    {
        exit(1);
    }
	
    /* reads the first word from file */
    fscanf(fptr, "%s", file_word);
	
    /* if the first word is EOF (the file is empty) */
    if(file_is_empty(fptr))
    {
        exit(1);
    }
	
    /* string sort */
    strcpy(perm, argv[2]); /* copy the string argument to perm array */
	
    perm_len = strlen(perm);
	
    qsort(perm, perm_len, sizeof(char), compare); /*sorted string*/
	
	
    fseek(fptr, 0, SEEK_SET); /* return back to start of file */
	
    while(fscanf(fptr, "%s", file_word) != EOF)
    {
        file_word_len = strlen(file_word);
        
        if ( perm_len <= file_word_len ) /* if string smaller/equal to word in file */
        {
            sub = file_word_len-perm_len; /* difference between words */
            
            for (i=0; i<=sub; i++) /* compare perm_len sections for sub times for each word from file */
            {
                
                if (is_permut(file_word + i, perm, perm_len))
                {
                    p_to_print = file_word + (i*sizeof(char));
                    file_word[perm_len+i] = '\0';
                    printf("%s\n", p_to_print);
                    perm_found++;
                }
            }
        }
    }
    

    /* if permutations not found */
    if (perm_found == 0)
    {
	printf("No permutations found in %s file with %s string.\n", argv[1], argv[2]);
    }
    
    /* close file */
    fclose(fptr);
	
    return 0;
}



/* validate if there is to many arguments, return 1 if valid, 0 if not valid */

int valid_argc(int argc)
{
    /*argc is not valid*/
    if (argc < NUM_OF_ARGC)
    {
        printf("missing arguments!\nmake sure you type in file AND a string.\n");
        return 0;
    }
    	
    if (NUM_OF_ARGC < argc)
    {
        printf("arguments above requested!\nmake sure you type in file and a string ONLY.\n");
        return 0;
    }

    /*argc number is valid*/
    return 1;
}


/* validate if file opened correctly, return 1 if valid, 0 if not valid*/

int file_opened(FILE *fptr)
{
    if (fptr == NULL)
    {
        printf("Error: file not exist.\n");
        return 0;
    }
    return 1;
}


/* validate if file is empty, return 1 if empty, 0 if not*/

int file_is_empty(FILE *fptr)
{
    /* if empty */
    if(ftell(fptr) == 0)
    {
        printf("Error: file is empty.\n");
        fclose(fptr);
        return 1;
    }

    /* not empty */
    return 0;
}
