
# Macro

``` c
#include <stdio.h>
#define MULTIPLY(a, b) a* b
int main()
{
    // The macro is expanded as 2 + 3 * 3 + 5, not as 5*8
    printf("%d", MULTIPLY(2 + 3, 3 + 5));
    return 0;
}
```

``` c
#include <stdio.h>
#define merge(a, b) a##b
int main() 
{ 
    printf("%d ", merge(12, 34)); // output : 1234 
}
```

# Print Statements

## %n in printf

``` c
#include<stdio.h>
  
int main()
{
  int c;
  printf("hello%nworld", &c);     // stores the number of character berore %n
  printf("%d", c);                // output : 5  
  getchar();
  return 0;
}

```

## sprintf

``` c
#include<stdio.h>
int main()
{
    char buffer[50];
    int a = 10, b = 20, c;
    c = a + b;
    sprintf(buffer, "Sum of %d and %d is %d", a, b, c);
  
    // The string "sum of 10 and 20 is 30" is stored 
    // into buffer instead of printing on stdout
    printf("%s", buffer);
    // output : Sum of 10 and 20 is 30
    return 0;
}

```

## fprintf

``` c
#include<stdio.h>
int main()
{
    int i, n=2;
    char str[50];
  
    //open file sample.txt in write mode
    FILE *fptr = fopen("sample.txt", "w");
    if (fptr == NULL)
    {
        printf("Could not open file");
        return 0;
    }
  
    for (i=0; i<n; i++)
    {
        puts("Enter a name");
        gets(str);
        fprintf(fptr,"%d.%s\n", i, str);
    }
    fclose(fptr);
  
    return 0;

    //Input:  hello 
    //        world
    //Output :  sample.txt file now having output as 
    //        0.hello
    //        1.world
}

```

## getc(), getchar(), getch() and getche()

__getc():__ It reads a single character from a given input stream and returns the corresponding integer value (ASCII value) on success.  
It returns EOF on failure.

    int getc(FILE *stream);

__getchar():__ The difference between getc() and getchar() is getc() can read from any input stream, but getchar() reads from standard input.  
So getchar() is equivalent to getc(stdin).

    int getchar(void);

__getch():__ getch() is a nonstandard function and is present in __conio.h__ header file which is mostly used by MS-DOS compilers like Turbo C.  
"It is not part of the C standard library"
unlike above functions,it does not use any buffer, so the entered character is immediately returned without waiting for the enter key.

    int getch();

__getche():__ Like getch(), this is also a non-standard function present in conio.h.  
It reads a single character from the keyboard and displays immediately on output screen without waiting for enter key.

    int getche(void);

# The Scanf variations

## specific input formate

``` c
// C program to demonstrate that
// we can ignore some string
// in scanf()
#include <stdio.h>
int main()
{
    int a;
    scanf("This is the value %d", &a);
    printf("Input value read : a = %d", a);
    return 0;
}
// Input : This is the value || 100 output: 100
    
```

``` c
#include <stdio.h>
int main()
{
    int a;
    scanf("%*s %d", &a);
    printf("Input value read : a=%d", a);
    return 0;
// Input Formate: string NUM... 
}
```

# File Handling

- Creation of a new file (fopen() with attributes as __“a”__ or __“a+”__ or __“w”__ or __“w+”__)
- Opening an existing file (fopen())
- Reading from file (fscanf() or fgets())
- Writing to a file (fprintf() or fputs())
- Moving to a specific location in a file (fseek(), rewind())
- Closing a file (fclose())

## Difference between Various Modes

- r : read mode
- w : write mode (creates new file if not available)
- a : append mode (append/add the contents at the end of availabe content)

- r+ : read + write mode

``` txt
    // previous content
    aaaaaaaaa
```

``` txt
    // after writing "bbb" in r+ mode
    bbbaaaaaa
    // will over write wihout cleaning previous data
```

- w+ : write mode (creates new file if not available)

``` txt
    // previous content
    aaaaaaaaa
```

``` txt
    // after writing "bbb" in w+ mode
    bbb
    // clears file before writing.
```

- a+ : append mode (append/add the contents at the end of availabe content)

``` txt
    // previous content
    aaaaaaaaa
```

``` txt
    // after writing "bbb" in a+ mode
    aaaaaaaaabbb
    // will append new content 
```

``` c
FILE *filePointer = NULL; 
filePointer = fopen(“fileName.txt”, “w”);

```
