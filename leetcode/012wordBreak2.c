/*
 * Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a valid dictionary word.
 *
 * Return all such possible sentences.
 *
 * For example, given
 * s = "catsanddog",
 * dict = ["cat", "cats", "and", "sand", "dog"].
 *
 * A solution is ["cats and dog", "cat sand dog"].
 */

#include "stdio.h"

int main()
{
    int *p;
    int a=2;
    unsigned long b=1245048;

    p=&a;
    printf("p = %p\n", p);
    printf("&a = %p\n", &a);
    printf("&a = %d\n", &a);
    printf("(void*)b = %d\n", (void*)b);
//    printf("*(void*)b = %d\n", *(void*)b);
//    printf("*(int*)b = %d\n", *(int*)b);
    printf("*(void**)b = %d\n", *(void**)b); 
    return 0;
}
