#include <stdio.h>
#define BUFFER_SIZE 20

int string_length(char *);

int main()
{   
    int length;
    char string[]="123456666";
    //string[6]='d';
    string[9]='d';
    
    char *ptr = string;
    //printf("%d",BUFFER_SIZE);
    length = string_length(string);
    printf("String Length is : %d \n",length);
    return 0;

}

int string_length(char *StrPtr)
{   
    int StringIndex = -1;
    if(StrPtr == NULL)
       {
        printf("Destination pointer is NULL\n");
        return 0;
       }
    
    do
    {
        StringIndex++;

        if(StringIndex == BUFFER_SIZE)
            {
            printf("BUFFER OVERLOADED !");
            goto end;
            // break;
            }
        printf("%d\n",StringIndex);

    }while(StrPtr[StringIndex] != '\0');    

end:return StringIndex;
}