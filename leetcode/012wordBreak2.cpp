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
i */

#include "stdio.h"

void printArray(void** a, int len)
{
   int *p1 = (int*)*a;
   printf("%d\n", p1[1]);

}

int main()
{
    int array[3] = {1,2, 3};
    int *p = array;
    void ** q = (void**)&p;
    printArray(q, 3);
}
