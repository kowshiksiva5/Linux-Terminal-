Compiling the code:

1. run make in the directory containing shell files

Execute the code :

1. run ./a.out where make was just run
1. while running an Background process,press Enter if prompt not appeared after running it

Description of the files in the code:

1. main.c - contains main function and that initalizes the loop and calls parsing function
1. parsing.h - parses the given input using delimiter and calls the functions accordingly
1. cep.h - it contains all the functions of the builtin commmands like (cd,pwd,ls,pinfo.... ) or calls the functions of respective commmands
1. pinfo - consists function of pinfo commmands
1. prompt.c - prints the prompt for the shell
1. displayuserfriendly - contains some display functions for reprinting prompt...
1. make - contains rules for compiling the code
1. history - contains history that prints the history
1. ls.h - contains all the functions related to ls commmands
1. headers.h - contains all the basic headers used in the complete code
1. fore\_ground.h - contains all the functions that helps the process to run in background when "&" is used after the process


