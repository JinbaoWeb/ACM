# include <stdio.h>
char* prefix(char* haystack_start, char* needle_start)
{
	char* haystack = haystack_start;
	char* needle = needle_start;

	while(*haystack && *needle){
		if(*(haystack++) != *(needle++)) return NULL;  //填空位置
	}
	
	if(*needle) return NULL;
	
	return haystack_start;
}
int main(void)
{
	char haystack[] = "abcd1234";
	char needle[] = "abc";
	printf("%s\n", prefix(haystack, needle));
}