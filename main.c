#include "includes/ft_printf.h"
#include <stdio.h>

int     main()
{
    char *c;
    c = "string";

    void *p;
    p = &c;

    printf("*********** B A S I C ***********\n\n");

    ft_printf("This is a character :%c\n", 'a');
    printf ("This is a character*:%c\n", 'a');
    ft_printf("______________________________\n\n");
    ft_printf("This is an integer : %d\n", 1);
    printf("This is an integer*: %d\n", 1);
    ft_printf("This is an integer : %d\n", -1);
    printf("This is an integer*: %d\n", -1);
    ft_printf("______________________________\n\n");
    ft_printf("This is a string   : %s\n", c);
    printf("This is a string*  : %s\n", c);
    ft_printf("______________________________\n\n");
    ft_printf("This is a percent  : %%\n");
    printf("This is a percent* : %%\n");
    ft_printf("______________________________\n\n");
    ft_printf("This is a pointer  : %p\n", p);
    printf("This is a pointer* : %p\n", p);
    ft_printf("This is a pointer  : %p\n", NULL);
    printf("This is a pointer* : %p\n", NULL);
    ft_printf("______________________________\n\n");
    ft_printf("This is an u_int   : %u\n", 777);
    printf("This is an u_int*  : %u\n", 777);
    ft_printf("This is an u_int   : %u\n", 55165);
    printf("This is an u_int*  : %u\n", 55165);
    ft_printf("This is neg u_int  : %u\n", -7);
    printf("This is neg u_int* : %u\n", -7); 
    ft_printf("______________________________\n\n");
    ft_printf("This is a hex  : %x\n", 526);
    printf("This is a hex* : %x\n", 526); 
    ft_printf("This is a hex  : %X\n", 42);
    printf("This is a hex* : %X\n", 42);
    ft_printf("______________________________\n\n");
    ft_printf("This is an octal   : %o\n", 526);
    printf("This is an octal*  : %o\n", 526);
    ft_printf("This is an octal   : %o\n", 46);
    printf("This is an octal*  : %o\n", 46);
    ft_printf("This is an octal   : %o\n", -142);
    printf("This is an octal*  : %o\n", -142);

    printf("\n*********** L E N G T H ***********\n\n");

    ft_printf("This is an li : %li\n", 2147483648);
    printf("This is an li*: %li\n", 2147483648);
    ft_printf("This is an li : %li\n", -2147483648);
    printf("This is an li*: %li\n", -2147483648);
    ft_printf("______________________________\n\n");
    ft_printf("This is an ld : %ld\n", 21474836480);
    printf("This is an ld*: %ld\n", 21474836480);
    ft_printf("This is an ld : %ld\n", -9223372036854775807);
    printf("This is an ld*: %ld\n", -9223372036854775807);
    ft_printf("______________________________\n\n");
    ft_printf("This is an lu : %lu\n", 2147483648);
    printf("This is an lu*: %lu\n", 2147483648);
    ft_printf("This is an lu : %lu\n", -2147483648);
    printf("This is an lu*: %lu\n", -2147483648);
    ft_printf("______________________________\n\n");
    ft_printf("This is a lx : %lx\n", 21474836480);
    printf("This is a lx*: %lx\n", 21474836480);
    ft_printf("This is a lx : %lx\n", -9223372036854775);
    printf("This is a lx*: %lx\n", -9223372036854775);
    ft_printf("______________________________\n\n");
    ft_printf("This is a lX : %lX\n", 21474836480);
    printf("This is a lX*: %lX\n", 21474836480);
    ft_printf("This is a lX : %lX\n", -9223372036854775);
    printf("This is a lX*: %lX\n", -9223372036854775);
    ft_printf("______________________________\n\n");
    ft_printf("This is a lo : %lo\n", 2147483648);
    printf("This is a lo*: %lo\n", 2147483648);
    ft_printf("This is a lo : %lo\n", -2147483648);
    printf("This is a lo*: %lo\n", -2147483648);

    /*ft_printf("This is an lli : %lli\n", 1844674407370955161);
    printf("This is an lli*: %lli\n", 1844674407370955161);
    ft_printf("This is an lli : %lli\n", -1844674407370955161);
    printf("This is an lli*: %lli\n", -1844674407370955161);
    ft_printf("______________________________\n\n");
    ft_printf("This is an lld : %lld\n", );
    printf("This is an lld*: %lld\n", );
    ft_printf("This is an lld : %lld\n", );
    printf("This is an lld*: %lld\n", );
    ft_printf("______________________________\n\n");
    ft_printf("This is an llu : %llu\n", );
    printf("This is an llu*: %llu\n", );
    ft_printf("This is an llu : %llu\n", );
    printf("This is an llu*: %llu\n", );
    ft_printf("______________________________\n\n");
    ft_printf("This is a llx : %llx\n", );
    printf("This is a llx*: %llx\n", );
    ft_printf("This is a llx : %llx\n", );
    printf("This is a llx*: %llx\n", );
    ft_printf("______________________________\n\n");
    ft_printf("This is a llX : %llX\n", );
    printf("This is a llX*: %llX\n", );
    ft_printf("This is a llX : %llX\n", );
    printf("This is a llX*: %llX\n", );
    ft_printf("______________________________\n\n");
    ft_printf("This is a llo : %llo\n", );
    printf("This is a llo*: %llo\n", );
    ft_printf("This is a llo : %llo\n", );
    printf("This is a llo*: %llo\n", );*/

    /*ft_printf("This is an li : %hi\n", 18446744073709551615);
    printf("This is an li*: %hi\n", 18446744073709551615);
    ft_printf("This is an li : %hi\n", -2147483648);
    printf("This is an li*: %hi\n", -2147483648);
    ft_printf("______________________________\n\n");
    ft_printf("This is an ld : %hd\n", 21474836480);
    printf("This is an ld*: %hd\n", 21474836480);
    ft_printf("This is an ld : %hd\n", -9223372036854775);
    printf("This is an ld*: %hd\n", -9223372036854775);
    ft_printf("______________________________\n\n");
    ft_printf("This is an lu : %hu\n", 2147483648);
    printf("This is an lu*: %hu\n", 2147483648);
    ft_printf("This is an lu : %hu\n", -2147483648);
    printf("This is an lu*: %hu\n", -2147483648);
    ft_printf("______________________________\n\n");
    ft_printf("This is a lx : %hx\n", 21474836480);
    printf("This is a lx*: %hx\n", 21474836480);
    ft_printf("This is a lx : %hx\n", -9223372036854775);
    printf("This is a lx*: %hx\n", -9223372036854775);
    ft_printf("______________________________\n\n");
    ft_printf("This is a lX : %hX\n", 21474836480);
    printf("This is a lX*: %hX\n", 21474836480);
    ft_printf("This is a lX : %hX\n", -9223372036854775);
    printf("This is a lX*: %hX\n", -9223372036854775);
    ft_printf("______________________________\n\n");
    ft_printf("This is a lo : %ho\n", 2147483648);
    printf("This is a lo*: %ho\n", 2147483648);
    ft_printf("This is a lo : %ho\n", -2147483648);
    printf("This is a lo*: %ho\n", -2147483648);*/
    return 0;
}