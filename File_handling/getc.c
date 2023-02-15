#include <stdio.h>

int main()
{
FILE *fp = fopen("File_Test.txt", "r");
int ch = getc(fp);
// while (ch != EOF)
// {
	/* display contents of file on screen */

    fseek(fp,-3,SEEK_CUR);
	ch = getc(fp);
	putchar(ch);
// }
	
if (feof(fp))
	printf("\n End of file reached.");
else
	printf("\n Something went wrong.");
fclose(fp);
	
getchar();
return 0;
}
