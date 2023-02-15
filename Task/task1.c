#include <stdio.h>
#include <string.h>

int CopyStr(char*, int, const char*, int);

int main()
{
      int number;
      char string2[5];
      // const char string1[]={'a','b','c','d'};  //S<D without null
       //const char string1[]={'a','b','c','d','a','b','c','d','a','b'}; //S<D


      const char string1[]={'a','b','5','d','e'}; //S>D without null
      // const char string1[]={'a','b','c','d','e','f','\0'};//S>D


      // const char string1[]={'a','b','c','d','e'};//S=D without null
      //const char string1[]={'a','b','c','d','\0'};//S=D

      //printf("source_size = %d\n",source_len);


      number = CopyStr((char *)string2,5,(const char *)string1,5);


      printf("Destination string after calling CopyStr: %s\n",string2);

      printf("Number of characters copied: %d ",number);
}

int CopyStr(char *DestStrPtr, int DestSizeMax, const char *SourceStrPtr, int SourceSizeMax)
{       
       
       if(DestStrPtr == NULL)
       {
        printf("Destination pointer is NULL\n");
        return 0;
       }
       if(DestSizeMax == 0)
       {
        printf("Invalid Destination size\n");
        return 0;
       }
       if(SourceStrPtr == NULL)
       {
        printf("Destination pointer is NULL\n");
        return 0;
       }
       if(SourceSizeMax == 0)
       {
        printf("Invalid source size\n");
        return 0;
       }
      
      int count=0;
      int flag = 0;
      if(SourceSizeMax<DestSizeMax)
      {
            DestSizeMax=SourceSizeMax;
            DestStrPtr[DestSizeMax]='\0';
            flag = 1;
      }

      for(int dest_index=0; dest_index < DestSizeMax; dest_index++)
      {
             
             DestStrPtr[dest_index] = SourceStrPtr[dest_index];
             if(SourceStrPtr[dest_index] == '\0')
             {       
                     flag=1;
                     break;
             }
             count++;
      }

      if(flag == 0)
      {
               DestStrPtr[DestSizeMax-1]='\0';
               count--;
      }   
      return count;
}