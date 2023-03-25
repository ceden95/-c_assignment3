
/*
 * Function: is_permut
 * ----------------------------
 *   function compare two strings, by sorting a section of one of 
 *   the and compare it to the other sorted(already) string
 *   
 *   file_word: pointer the word to setion(if needed) and compare
 *   perm: pointer to sorted word to compare to
 *   perm_len: int represent the length of perm word
 *
 *   returns: 1 if the section and the word perm are equal, 0 if not.
 */
int is_permut(char *file_word, char *perm, int perm_len);


/*
 * Function: compare
 * ----------------------------
 *   compare is function creates for qsort().
 *   gets 2 void pointers to chars(casting) from a string and 
 *   returns the different between them.
 *   
 *   x: void pointer
 *   y: void pointer
 *
 *   returns: 0 if the two chars are equal, negative number if x is bigger, 
 *   and positive number if y is bigger.
 */
int compare(const void *x, const void *y);

