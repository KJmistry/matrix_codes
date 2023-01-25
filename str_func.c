#include <stdio.h>
#include <string.h>

int main()
{
	// Strings Declared
	char str1[] = "aaaaaaaaaabbbbbbbbb";
	char str2[] = "ccccccccccddddddddddoooooooooo";

    printf("str1: %s --- %ld\nstr2: %s --- %ld\n",str1,sizeof(str1),str2,sizeof(str2));

    printf("%p---%p ==> %d \n",str1, str2, str2-str1);

    printf("%d \n",strcmp(str1, str2));
	// String copy used
	strcpy(str1, str2);

	printf("str1: %s --- %ld\nstr2: %s --- %ld\n",str1,sizeof(str1),str2,sizeof(str2));

    return 0;
}
