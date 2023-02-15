#include <stdio.h>

int main () {
   FILE *fp;
   fpos_t position;
   

   fp = fopen("File_Test.txt","w+");   
    printf("%ld\n", ftell(fp));

   fgetpos(fp, &position);
//    fputs("Hello, World!", fp);
  
   fputs("eeeheehhhehhh", fp);
   fsetpos(fp, &position);
    // fseek(fp,0,SEEK_SET);
    printf("%ld\n", ftell(fp));

    char arr[10];
    fgets(arr,sizeof(arr),fp);
    printf("%s\n",arr);

   fclose(fp);
   
   return(0);
}