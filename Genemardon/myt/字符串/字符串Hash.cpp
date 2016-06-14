//BKDR 完美字符串HASH
unsigned int BKDRHash(char *str)
{
    unsigned int seed = 131; 
    unsigned int hash = 0;
 
    while (*str)
    {
        hash = hash * seed + (*str++);
    }
 
    return (hash & 0x7FFFFFFF);
}