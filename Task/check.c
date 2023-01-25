#include <stdio.h>
#include <string.h>

int CopyStr(char*, int, const char*, int);

int main()
{
      int number;
      char string2[5];
      // const char string1[]={'a','b','c','d'};  //S<D without null
       const char string1[]={'a','b','c','d','a','b','c','d','a','b'}; //S<D


      // const char string1[]={'a','b','c','d','e','f'}; //S>D without null
      // const char string1[]={'a','b','c','d','e','f','\0'};//S>D


      // const char string1[]={'a','b','c','d','e'};//S=D without null
      //const char string1[]={'a','b','c','d','\0'};//S=D

      //printf("source_size = %d\n",source_len);


      number = CopyStr((char *)string2,5,(const char *)string1,3);


      printf("Destination string after calling CopyStr: %s\n",string2);

      printf("Number of characters copied: %d ",number);
}

int CopyStr(char *DestStrPtr, int DestSizeMax, const char *SourceStrPtr, int SourceSizeMax)
{  
      /* What if
       * - DestStrPtr is NULL
       * - DestSizeMax is 0
       * - SourceStrPtr is NULL
       * - SourceSizeMax is 0
       * - SourceStrPtr[0] is '\0'
       *
       * These error check are missning and their testcases are also missing in the main function.
       */

      int flag = 0;
      if(SourceSizeMax<DestSizeMax)
      {
             DestSizeMax=SourceSizeMax;
             /* Lets say SourceSizeMax = 10, DestSizeMax = 11
              * Accessible indices of DestStrPtr are 0-10
              * Now, So DestSizeMax = 10
              * and then you are doing
              * DestStrPtr[10+1]='\0'; which leads to array index out of bound and may crash the program.
              */
               DestStrPtr[DestSizeMax]='\0';
             /* Here (SourceSizeMax) size of SourceStrPtr is passed, not the length of that string
              * So the SourceStrPtr may have characters < its size
              * So, even if ignoring the indices of the statement, it is wrong. DestStrPtr[DestSizeMax+1]='\0';
             */
             flag = 1;
      }

      int count=0;

      for(int dest_index=0; dest_index < DestSizeMax; dest_index++)
      {
             /* What if SourceStrPtr have '\0' in between.
              * What is need of copying data after that
              */
             DestStrPtr[dest_index] = SourceStrPtr[dest_index];
             //printf("%c\n",SourceStrPtr[dest_index]);
             count++;
      }

      if(flag == 0)
      {
               DestStrPtr[DestSizeMax-1]='\0';
      }

      /* '\0' character is also counted here.
       */    
      return count;
}