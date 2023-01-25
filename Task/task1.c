#include <stdio.h>
#include <string.h>

int CopyStr(char*, int, const char*, int);

int main()
{
    int number;
    char string2[5]; 
    // const char string1[]={'a','b','c','d'};  //S<D without null
    // const char string1[]={'a','b','c','\0'}; //S<D


    // const char string1[]={'a','b','c','d','e','f'}; //S>D without null
    // const char string1[]={'a','b','c','d','e','f','\0'};//S>D 


    // const char string1[]={'a','b','c','d','e'};//S=D without null
    const char string1[]={'a','b','c','d','\0'};//S=D


    int source_len=sizeof(string1)/sizeof(string1[0]);
    //printf("source_size = %d\n",source_len);
    
    
    number = CopyStr((char *)string2,5,(const char *)string1,source_len);
    
    
    printf("Destination string after calling CopyStr: %s\n",string2);

    printf("Number of characters copied: %d ",number);
}

int CopyStr(char *DestStrPtr, int DestSizeMax, const char *SourceStrPtr, int SourceSizeMax)
{   
    int flag = 0;
    if(SourceSizeMax<DestSizeMax)
    {
        DestSizeMax=SourceSizeMax;
        DestStrPtr[DestSizeMax+1]='\0';
        flag = 1;
    }

    int count=0;

    for(int dest_index=0; dest_index < DestSizeMax; dest_index++)
    {
        DestStrPtr[dest_index] = SourceStrPtr[dest_index];
        //printf("%c\n",SourceStrPtr[dest_index]);
        count++;
    }
    
    if(flag == 0)
    {
        DestStrPtr[DestSizeMax-1]='\0';
    }

    
    return count;
}
