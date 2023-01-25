// #include <stdio.h>

// int main(void)
// {
//     printf("%d\n",3/0);
//     return 0;
// }
#include <iostream>
using namespace std;
 
int main() {
 
    int arr[5] = {1, 2, 3, 4, 5};
   
    // SIGABRT error
    arr[6] = 6;
   
    return 0;
}
 