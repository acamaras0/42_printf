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
    char *s = "lala";
    void *p = s;

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

    printf ("\n\nWidth string1: %*s \n", 5, "Ana");
    ft_printf ("Width string1: %*s \n", 5, "Ana");
    printf ("Width string2: %.5s \n", "AnaBanana");
    ft_printf ("Width string2: %.5s \n", "AnaBanana");

    printf ("\n\nWidth string3: %5s \n", "");
    ft_printf ("Width string3: %5s \n", "");
    printf ("Width string4: %.2s \n", NULL);
    ft_printf ("Width string4: %.2s \n", NULL);
    printf ("Width string5: %s \n", "BANANA");
    ft_printf ("Width string5: %s \n", "BANANA");

    printf ("\n\nWidth percent: %5% \n");
    ft_printf ("Width percent: %5% \n");
    printf ("\nWidth char2: %5c \n", 'a');
    ft_printf ("Width char2: %5c \n", 'a');
    printf ("\nWidth char3: %-7c \n", '7');
    ft_printf ("Width char3: %-7c \n", '7');

    printf ("\nWidth uint1: %*u \n", -5, 6);
    ft_printf ("Width uint1: %*u \n", -5, 6);
    printf ("\nWidth uint2: %05u \n", 5);
    ft_printf ("Width uint2: %05u \n", 5);
    printf ("\nWidth uint3: %07u \n", -5);
    ft_printf ("Width uint3: %07u \n", -5);

    printf ("\nWidth pointer1: %*p \n", -5, p);
    ft_printf ("Width pointer1: %*p \n", -5, p);
    printf ("\nWidth pointer3: %20p \n", p);
    ft_printf ("Width pointer3: %20p \n", p);

    printf ("\nWidth oct1: %*o \n", 20, 42);
    ft_printf ("Width oct1: %*o \n", 20, 42);
    printf ("\nWidth oct2: %020o \n", -42);
    ft_printf ("Width oct2: %020o \n", -42);
    printf ("\nWidth oct2: %-7o \n", 0);
    ft_printf ("Width oct2: %-7o \n", 0);

   printf ("\nCharacters: %c %c \n", 'a', 65);
   ft_printf ("Characters: %c %c \n", 'a', 65);
   printf ("\nDecimals: %d %ld\n", 1977, 650000L);
   ft_printf ("Decimals: %d %ld\n", 1977, 650000L);
   printf ("\nPreceding with blanks: %10d \n", 1977);
   ft_printf ("Preceding with blanks: %10d \n", 1977);
   printf ("\nPreceding with zeros: %010d \n", 1977);
   ft_printf ("Preceding with zeros: %010d \n", 1977);
   printf ("\nSome different radices: %d %x %o %#x %#o \n", 100, 100, 100, 100, 100);
   ft_printf ("Some different radices: %d %x %o %#x %#o \n", 100, 100, 100, 100, 100);
   //printf ("floats: %4.2f %+.0e %E \n", 3.1416, 3.1416, 3.1416);
   //printf ("floats: %4.2f %+.0e %E \n", 3.1416, 3.1416, 3.1416);

   printf("\n\n Test for hash x: %#x", 42);
   ft_printf("\n Test for hash x: %#x\n", 42);
   printf("\n Test for hash X: %#X", 42);
   ft_printf("\n Test for hash X: %#X\n", 42);
   printf("\n Test for hash o: %#o", 42);
   ft_printf("\n Test for hash o: %#o\n", 42);

    printf ("\nPF Width hex2: %05x \n", 42);
    ft_printf ("\nFT Width hex2: %05x \n", 42);

    printf ("\nPFWidth hex1: %*x \n", 20, 42);
    ft_printf ("FTWidth hex1: %*x \n", 20, 42);

    printf ("\nPFWidth hex1: %*X \n", 20, 42);
    ft_printf ("FTWidth hex1: %*X \n", 20, 42);

    printf ("\nPFWidth hex3: %-7x \n", 0);
    ft_printf ("FTWidth hex3: %-7x \n", 0);


    printf("\nPF Test for hash x4: %8x", 40);
    ft_printf("\nFT Test for hash x4: %8x\n",40);
    printf("\nPF Test for hash x2: %x", 42);
    ft_printf("\nFT Test for hash x2: %x\n",42);

    printf("\nPF Test for hash x1: %#08x", 42);
    ft_printf("\nFT Test for hash x1: %#08x\n",42);
    printf("\nPF Test for hash X1: %#08X", 42);
    ft_printf("\nFT Test for hash X1: %#08X\n",42);
    printf("\nPF Test for hash x3: %#8x", 42);
    ft_printf("\nFT Test for hash x3: %#8x\n",42);

    printf("\nPF Test for hash x1: %08x", 42);
    ft_printf("\nFT Test for hash x1: %08x\n",42);

}