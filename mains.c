#include <stdio.h>
#include "ft_printf.h"

int main ()
{
   /* ft_printf("FT:FLOAT: %f\n", 2.5);
    printf("PF:FLOAT: %f\n\n", 2.5);

    ft_printf("FT:FLOAT: %f\n", -1.00);
    printf("PF:FLOAT: %f\n\n", -1.00);

    ft_printf("FT:FLOAT: %.f\n", -1.00);
    printf("PF:FLOAT: %.f\n\n", -1.00);

    ft_printf("FT:FLOAT: %.f\n", 2.5);
    printf("PF:FLOAT: %.f\n\n", 2.5);

    ft_printf("FT:FLOAT: %.10f\n", 2.5);
    printf("PF:FLOAT: %.10f\n\n", 2.5);

    ft_printf("FT:FLOAT: {%f}{%lf}{%Lf}\n", 1.42, 1.42, 1.42l);
    printf("PF:FLOAT: {%f}{%lf}{%Lf}\n\n", 1.42, 1.42, 1.42l);

*/


    //ft_printf("FT X: %#02.8x\n", 42);
    //printf("PF X: %#02.8x\n\n", 42);

    //ft_printf("FT D:% 8i\n", 42);
    //printf("PF D:% 8i\n\n", 42);

    //ft_printf("FT D:% -8i\n", 42);
    //printf("PF D:% -8i\n\n", 42);

    //ft_printf("FT D:%+i\n", 42);
    //printf("PF D:%+i\n\n", 42);

    //ft_printf("FT X: %#2.8x\n", 34);
    //printf("PF X: %#2.8x\n\n", 34);

    //ft_printf("FT C: %c\n", 0);
    //printf("PF C: %c\n\n", 0);

    //ft_printf("FT D:{%03d}\n", 0);
    //printf("PF D:{%03d}\n\n", 0);

    //ft_printf("FT D:{%010.5d}\n", -216);
    //printf("PF D:{%010.5d}\n\n", -216);

    //ft_printf("FT S:{%.*s}\n", 0, "hello");
    //printf("PF S:{%.*s}\n\n", 0, "hello");

    //ft_printf("FT S:{%.*s}\n", -5, "42");
    //printf("PF S:{%.*s}\n\n", -5, "42");


    ft_printf("FT X: %#08.5x\n", 42);
    printf("PF X: %#08.5x\n\n", 42);

    //ft_printf("FT X: %#8.5x\n", 42);
    //printf("PF X: %#8.5x\n\n", 42);

    //ft_printf("FT O:%#08o\n", 42);
    //printf("PF O:%#08o\n\n", 42);

    //ft_printf("FT D:% 08i\n", 42);
    //printf("PF D:% 08i\n\n", 42);

    return (0);
}