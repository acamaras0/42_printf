#include "includes/ft_printf.h"
#include <stdio.h>

int     main()
{
    char a;
    a = 'a';

    int b;
    b = 1;

    char *c;
    c = "string";

    void *p;
    p = &c;

    unsigned int j;
    j = 777;

    int x;
    x = 526;

    ft_printf("This is a character :%c\n", a);
    printf ("This is a character*:%c\n", a);
    ft_printf("******************************\n");
    ft_printf("This is an integer : %d\n", b);
    printf("This is an integer*: %d\n", b);
    ft_printf("This is an integer : %li\n", -2147483648);
    printf("This is an integer*: %li\n", -2147483648);
    ft_printf("This is an integer : %li\n", 2147483648);
    printf("This is an integer*: %li\n", 2147483648);
    ft_printf("******************************\n");
    ft_printf("This is a string   : %s\n", c);
    printf("This is a string*  : %s\n", c);
    ft_printf("******************************\n");
    ft_printf("This is a percent  : %%\n");
    printf("This is a percent* : %%\n");
    ft_printf("******************************\n");
    ft_printf("This is a pointer  : %p\n", p);
    printf("This is a pointer* : %p\n", p);
    ft_printf("This is a pointer  : %p\n", NULL);
    printf("This is a pointer* : %p\n", NULL);
    ft_printf("******************************\n");
    ft_printf("This is an u int   : %u\n", j);
    printf("This is an u int*  : %u\n", j); 
    ft_printf("******************************\n");
    ft_printf("This is a hex  : %x\n", x);
    printf("This is a hex* : %x\n", x); 
    ft_printf("This is a hex  : %X\n", 42);
    printf("This is a hex* : %X\n", 42);
    ft_printf("******************************\n");
    ft_printf("This is an octal   : %o\n", x);
    printf("This is an octal*  : %o\n", x);
    ft_printf("This is an octal   : %o\n", 46);
    printf("This is an octal*  : %o\n", 46);
    ft_printf("This is an octal   : %o\n", -142);
    printf("This is an octal*  : %o\n", -142);



    return 0;
}