
# __Compilation Process__

1. Preprocessing
2. Compiling
3. Assembling
4. Linking

## __1.Preprocessing__

- Expands macros and include files in source code.[ ex. #include , #define ]
  - Input: __`file.c`__  
  - Output: __`file.i`__

- file.i cointains code with expanded macros

## __2.Compiling__

- Expanded source code is compiled into assembly language.
  - Input: __`file.i`__  
  - Output: __`file.s`__

- file.s cointains architecture-specific assembly code.

## __3.Assembling__

- Assembly code is compiled into an object file with machine code that is readable by a specific processor architecture.
  - Input: __`file.s`__  
  - Output: __`file.o`__

- file.o cointains architecture-specific machine code.

## __4.Linking__

- Links object codes together into single object file
- Links symbols from other objects and external libraries together to create a single object file.
  - Input: __`file.o`__  
  - Output: __`file.o`__

### __Object Files__

In linux object Files are in Executable and Linkable format (ELF)

Three Types of Object file:

1. __Relocatable Object File__  
Non-executable file that needs to be linked into another file.

2. __Executable Object File__  
An executable binary program.

3. __Shared Object__  
A shared library. Not executable, useful for dynamic linking.

# __Libraries__

__Libraries typically contain functions that can be reused by different programs.__

Before the function can be used in your program, the library must be linked.

## __Two ways to link__

  __1. Statically__  
  __2. Dynamically__

### __Static linking__

When linked statically, the library becomes part of the client’s exe file. This leads to a waste of space on the hard disk and memory, as different copies of the library code gets repeated.

### __Dynamic linking__

This waste of space, however, does not happen if we link the libraries dynamically. A dynamic library remains separate from the client program and can be shared anywhere. There are two ways to link a library dynamically:

    1.Load-time dynamic linking
    2.Run-time dynamic linking

## __gcc - main command to invoke compiler__

- -I non-standard directories to search for include files (.h files)  
- -L non-standard directories to search for library files (.a , .so files)  
- -l [libname] specific library to link in  
  - -lc libc (standard c)
  - -lm  libm (math library)
  - -lpthread libc (pthread library)
  
## __C reate a Static Library__

### __Step 1: Create an object file__

    gcc -c lib_static.c -o lib_static.o

### __Step 2: Create a static library__

    ar rcs libstatic.a lib_static.o

We are using the archiving software (i.e., ar) to create a static library. The archiving software, ar, takes all the object files and creates an archive file (with .a extension).

### __My Example:__

``` bash
    gedit test.c                                                       # .c file having main which is calling fun defined in another library
```

``` bash
    gedit fun.c                                                        # .c file having fun defination 
```

``` bash
    gedit header.h                                                     # .h file having fun declaration (function prototype)  
    mv header.h include/                                               # moving header(.h) file to include directory
```

``` bash
    gcc -c fun.c                                                       # compiling file having function defination
                                                                       # generated fun.o file as an output of previous command
    ar cr libfun.a /libraries/fun.o                                    # creating archive libfun.a file consist of all defination related object files
                                                                       # currenlty only one fun.o file is available
                                                                       # generated libfun.a file as an output of previous command
    mv libfun.a libraries/                                             # moving libfun.c file to libraries directory
```

``` bash
    #will get errors if we execute following command

    gcc test.c 
    test.c:3:10: fatal error: header.h: No such file or directory      # unable to locate header.h file since it is located in include directory
    3 | #include "header.h"
      |          ^~~~~~~~~~
    
    gcc test.c -I include/                                             # providing path for header.h using -I [path] option
    /usr/bin/ld: /tmp/ccCSHLHG.o: in function `main`:                  # only declaration is provided in header file, unable to find the defination  
    test.c:(.text+0xe): undefined reference to `func`                  # for 'func' function since library is not linked
    
    gcc test.c -lfun -I include/                                       # linking fun library (libfun.a which we have already created) 
                                                                       # using option -lfun (-l[library name])
    /usr/bin/ld: cannot find -lfun: No such file or directory          # still getting error since libfun is located in libraries directory

```

``` bash
    # executes correctly
    gcc test.c -lfun -I include/ -L libraries/                         # providing path for libfun using -L [path] option
                                                                       # compiled successfully 
    ./a.out
    
```

## __Create a Dynamic Library__

### __Step 1: Create an object file__

    gcc -Wall -fPIC -c lib_dynamic.c

### __Step 2: Create a shared object__

    gcc -shared -Wl,-soname,libdynamic.so -o libdynamic.so lib_dynamic.o
