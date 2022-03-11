#include "ft_printf.h"
#include <stdio.h>
#define RED "\x18[31m"
#define NORMAL "\x1B[0m"

/*int    main(void)
{
    int i;
    int q = 3;
    int r = 2;
    int s = 1;
    long double j;
    //char    str[]= "Thank you Jonas!";
    size_t a;
    long int b;
    char    c;
    unsigned int x = 255;

    c = 65;
    i = 10;
    a = 15;
    b = 123456890123456789;
    j = 3.142165131313113;
    ft_printf("Hello Jona!\n");
    ft_printf("Number: %d | %d |%d |%d\n", i, q, r ,s);
    //ft_printf("My string:%5s\nsize_t: %d\nfloat:%f\n", str, a, j);
    ft_printf("Pointer:%p\n", &a);
    //printf("My string:%5s\n", str);
    ft_printf("%%\n");

    ft_printf("My char: %c\nMy %%i: %i\nMyOcto: %o\nMy uint: %u\n", c, i, i, x);
    ft_printf("XDecimal: %x\n Big X: %X\n", i, i);


    ft_printf("%c | %d |%d| %c\n", c,i, i, c);

    ft_printf("%hd|| %hhd | %ld || %lld", 42, i, 42, b);
    //ft_printf("Jonas: %Lf\n", j);
    //printf("Origin: %Lf\n", j);

    //ft_printf("%.55d\n", 16091985);
    ft_printf("%*d\n", 55, 55);

    ft_printf("%sHello%s\n", RED, NORMAL);

    return (0);
}
*/

int main()
{
    printf ("Width trick: %*d \n", 5, 10);
    ft_printf ("Width trick: %*d \n", 5, 10);
    printf ("\nWidth trick2: %3d \n", 9);
    ft_printf ("Width trick2: %3d \n", 9);

    printf ("\nWidth trick3: %*d \n", 5, 8);
    ft_printf ("Width trick3: %*d \n", 5, 8);
    printf ("\nWidth trick4: %3d \n", 7);
    ft_printf ("Width trick4: %3d \n", 7);

    printf ("\nWidth trick3: %*d \n", -5, 6);
    ft_printf ("Width trick3: %*d \n", -5, 6);
    printf ("\nWidth trick4: %05d \n", 5);
    ft_printf ("Width trick4: %05d \n", 5);

    printf ("\n\nWidth trick5: %*s \n", 5, "Ana");
    ft_printf ("Width trick5: %*s \n", 5, "Ana");
    printf ("Width trick6: %5s \n", "Ana");
    ft_printf ("Width trick6: %5s \n", "Ana");

    printf ("\n\nWidth trick7: %5s \n", "");
    ft_printf ("Width trick7: %5s \n", "");
    printf ("Width trick8: %.2s \n", NULL);
    ft_printf ("Width trick8: %.2s \n", NULL);
    printf ("Width trick8: %s \n", "BANANA");
    ft_printf ("Width trick8: %s \n", "BANANA");

}