
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

This waste of space, however, does not happen if we link the libraries dynamically. A dynamic library remains separate from the client program and can be shared anywhere.  

#### __Shared Libraries:__

Libraries that can be linked in by dynamic linker when process is loaded into memory. (.so)(libc.so)  

- Changes do not require binaries to be recompiled
- Requires .so to reside on target platdform.
- should be compiled as a position-independent code. (__-fpic__ or __-fPIC__)
  - __-fpic__ : size limit on the size of global offset table.  __(limitations are machine specific)__
  - __-fPIC__ : No size limit on the size of global offset table.
  - preffer first option untill it throws the size rerated error message.
- Global offset table contains entries of functions that will be dynamically linked. Use these entries as a reference while linking.  

### __Shared Library Naming Conventions__

- __Real Name__: lib**name**.so.x.y.z
  - __name__: library Name
  - __x__: major version
  - __y__: minor version
  - __z__: patch/increment  
  
  __ex.__: libjpeg.so.8.2.2  

- __Shared Object Name__:
  - __Lable for major version of shared object__:
  soname for libjpeg.so.8.2.2  
__ex.__: In above case __soname__ is __libjpeg.so.8__  

- __Linker Name__:
  - lib**name**.so  -->  -l**name**

There are two ways to link a library dynamically:

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
    gcc -fpic -o libfun.so.1.2.3 fun.o -shared -Wl,-soname,libfun.so.1 # creating shared library consist of all defination related object files
                                                                       # currenlty using only one fun.o file 
    ls
    fun.c  fun.o  libfun.so.1.2.3                                      # generated libfun.so.1.2.3 shared object

    readelf -a libfun.so.1.2.3 | grep soname
    0x000000000000000e (SONAME)             Library soname: [libfun.so.1]
                                                                       # veryfying soname 
    mv libfun.so.1.2.3 dlib/                                           # moving libfun.so.1.2.3 to dlib (dynamic library) directory
```

``` bash
    # creating symbolic link for libfun.so.1.2.3 in dlib directory
    cd dlib/    

    ln -s libfun.so.1.2.3 libfun.so.1                                  # symbolic link : libfun.so.1 -> libfun.so.1.2.3
    ln -s libfun.so.1 libfun.so                                        # symbolic link : libfun.so -> libfun.so.1

    ls -al
    total 24
    drwxrwxr-x 2 kshitijmistry kshitijmistry  4096 Feb 21 14:49 .      # generated symbolic links
    drwxrwxr-x 5 kshitijmistry kshitijmistry  4096 Feb 21 14:50 ..
    lrwxrwxrwx 1 kshitijmistry kshitijmistry    11 Feb 21 14:49 libfun.so -> libfun.so.1
    lrwxrwxrwx 1 kshitijmistry kshitijmistry    15 Feb 21 14:49 libfun.so.1 -> libfun.so.1.2.3
    -rwxrwxr-x 1 kshitijmistry kshitijmistry 15096 Feb 21 14:48 libfun.so.1.2.3
                            
```

``` bash
    # compiling main program test.c 

    gcc test.c -lfun -I include/ -L dlib/                              # we have already generarted libfun.so symbolic link which is currently 
                                                                       # being used with -l[name] option (libfun.so ==> fun) 
    
    file a.out
    a.out: ELF 64-bit LSB pie executable, x86-64, version 1 (SYSV), dynamically linked, interpreter /lib64/ld-linux-x86-64.so.2, BuildID[sha1]=08f9714c4d723b97f9cffa857e2304410c469232, for GNU/Linux 3.2.0, not stripped

    
    readelf -a a.out | grep Shared                                     # verifying shared libraries
    0x0000000000000001 (NEEDED)          Shared library: [libfun.so.1] # locally created for fun defination
    0x0000000000000001 (NEEDED)          Shared library: [libc.so.6]   # std libc (since we are using printf statement)

    # will throw error if we execute a.out directly
    ./a.out
    ./a.out: error while loading shared libraries: libfun.so.1: cannot open shared object file: No such file or directory

    # reason behind this error: laoder loades the program and searches libfun.so.1 in standard lib directory 
    # can be resolved by moving .so files to standard lib directory (/lib/x86_64-linux-gnu) [not prefferable]
    # another way to resolve by using environment variable LD_LIBRARY_PATH

    echo $LD_LIBRARY_PATH                                              # initially path will be empty

    LD_LIBRARY_PATH=/home/kshitijmistry/Desktop/codes/Libraries/dlib:$LD_LIBRARY_PATH  # providing path to the directory where .so file is located 

    echo $LD_LIBRARY_PATH                                              # echo after adding path 
    /home/kshitijmistry/Desktop/codes/Libraries/dlib:
    export LD_LIBRARY_PATH                                             # environment variable doesnt get passed to the
                                                                       # next process that will start running on shell untill we export it   

    ./a.out                                                            # works fine 
    19
    hello

```
