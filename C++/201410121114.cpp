#include <string.h>
#include <stdio.h>
#include <stdlib.h>
int comp(const void* ele1, const void* ele2)
 {
    return strcmp( *(const char** )ele1, *(const char** )ele2);
 }
int main()
{
    char *names[]= { "could", "you", "sort", "me", "please", "thank", "you!" };
    int i;
    qsort(names, 7, sizeof( * names), comp);
    for(i=0;i<7;i++)
        printf("%s\n",names[i]);
    return 0;
}
