#include <stdio.h>
#include <string.h>

void fibWords ( char *strl, int n ) 
{
	if(n < 0)
	{
		char temp[]="Empty String";
		strcpy(strl,temp);
		return;
	}
	if(n == 0)
	{
		strl[0]='A';
		strl[1]=0;
		return;
	}
	if(n == 1)
	{
		strl[0]='B';
		strl[1]=0;
		return;
	}
	char temp1[1000000]="B";
	char temp2[1000000];
	strl[0] = 'B';
	strl[1] = 'A';
	strl[2] = 0;
	for(int i = 2; i < n; i++)
	{
		strcpy(temp2,strl);
		strcat(strl,temp1);
		strcpy(temp1,temp2);
	}
	// Write your code here
}

int main(int argc, char const *argv[])
{
    char str[1000];
    fibWords(str,10);
    printf("%s",str);
    return 0;
}





