// #include<stdio.h>

// int main(void)
// {
// 	char arr[] = "kj";
	
// 	// Way 1
// 	// for(int i = 0; i < 6; i++)
// 	// 	printf("%i ", arr[i]);

// 	// printf("\n");
	
// 	// // Way 2
// 	printf("%u \n",sizeof(arr));
	
// 	// for(int i = 0; i < 6; i++)
// 	// 	printf("%i ", i[arr]);

// 	// printf("\n");

// 	// return (0);
// }

// // This code is contributed by sarajadhav12052009
#include<stdio.h>

int main(void)
{
    // int arr[10]={1,2,3,4,5,6,7,8,9,10};
    int arr1[10]={1,2,3,4,5,6,7,8,9,10};
    arr1[20]=69;
    
    int arr2[10]={11,12,13,14,15,16,17,18,19,20};
    int arr3[10]={21,22,23,24,25,26,27,28,29,30};
    printf("%d\n",arr2[-1]);
    printf("%d\n",arr2[-5]);
    printf("%d\n",arr2[-0]);
    printf("%d\n",arr2[0]);
    
    printf("%d\n",arr2[20]);
    char str[60]="kjm";
    printf("%c\n",str[18]);

    char array[10] = {[0 ... 3]1, [6 ... 9]2}; 

	for (int i = 0; i < 10; i++) 
		printf("%d ", array[i]); 
	return 0; 

}

