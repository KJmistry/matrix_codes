#include <stdio.h>

int main()
{

    FILE *fp1 = fopen("File_Test.txt", "w+");
    FILE *fp2 = fopen("File_Test.txt", "r");
    // printf("%ld\n", ftell(fp1));

    fputs("eeeheehhhehhh", fp1);
    printf("%ld\n", ftell(fp2));

    fseek(fp1,0,SEEK_SET);
    
    // forcefully writing into the File_Test.txt 
    // so the changes will be reflected in fp2

    // By default content will get stored at fclose() 

    printf("%ld\n", ftell(fp2));

    char arr[10];
    fgets(arr,sizeof(arr),fp2);
    printf("%s\n",arr);

    fclose(fp1);
    fclose(fp2);

    return (0);
}