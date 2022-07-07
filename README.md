# ft_printf

## This is the first school project for the Algo branch. A recreation in C language of the most used function, printf. 
I recreated this function mostly because I wanted to challange myself. It outputs the same results as the standard library function with the tiny exception of the undefined behaviour cases. 


To compile, run **make**. This will compile the libftprintf.a file. 
Use it by including **ft_printf.h** (located inside includes directory),

then compile it with a program:

***gcc -Wall -Werror -Wextra main.c libftprintf.a -I includes***
