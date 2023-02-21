
# __Signals__

- fork() system call is used to duplicate the process. done by communicating with the Operating System.
- Use __signal__, to achieve communication from the Operating System to the program.

## Uncustomized signal handling

- Pressing __Ctrl+C__  ->  The Operating System calls the default signal handler  ->  stop currently running program.
- A signal, __SIGINT__ (Interrupt signal), occurs when we press __Ctrl+C__

``` c
    #include <stdio.h>
    int main( ) 
    {
            while ( 1 ) 
                printf ( "Program Running\n" ) ;
            return 0 ;
    }

    //Ctrl+C --> SIGINIT --> Signal Handler Defination --> End program Execution
```

## Customized signal handling

- we can register our own signal handler, sighandler( ), by calling the signal( ) function.

``` c
    # include <stdio.h>
    # include <signal.h>

    // signal handler function
    void sighandler ( int signum ) 
    {
        printf ( "SIGINT received. Inside sighandler\n" ) ;
    }

    int main( ) 
    {
                signal ( SIGINT, sighandler ) ;
                while ( 1 ) 
                        printf ( "Program Running\n" ) ;
                return 0 ;
    }
```

- i.e. __SIGINT__ for customizing __Ctrl+C__ , __SIGTSTP__ for __Ctrl+Z__ , __SIGTERM__ for __kill__ command.

## Stop the running process

- obtain the pid of our process using:

``` bash
    ps -a
```

- Kill process using:

``` bash
    kill pid
```

- __SIGKILL__ the uncatchable signal.

``` bash
    kill -SIGKILL pid
```

__use SIGKILL if Kill is also customized.__
