#include "../includes/ft_printf.h"

char    *length_modifiers_int(t_struct *s, unsigned long i, va_list args)
{
    if (s->length == L)
        i = (long int)va_arg(args, long int);
    else if (s->length == LL)
        i = (long long int)va_arg(args, long long int);
    else if (s->length == H)
        i = (short int)va_arg(args, int);
    else if (s->length == HH)
        i = (signed char)va_arg(args, int);
    else if (s->length == 0)
            i = (int)va_arg(args, int);
    return(ft_itoa(i));
}

char    *length_modifiers_uint(t_struct *s, unsigned long i, va_list args)
{
    if (s->length == L)
        i = (unsigned long int)va_arg(args, long int);
    else if (s->length == LL)
        i = (unsigned long long int)va_arg(args, long long int);
    else if (s->length == H)
        i = (unsigned short int)va_arg(args, int);
    else if (s->length == HH)
        i = (unsigned char)va_arg(args, int);
    else if (s->length == 0)
            i = (unsigned int)va_arg(args, unsigned int);
    return(ft_itoa_base(i, 10));
}

char    *length_modifiers_oct(t_struct *s, unsigned long i, va_list args)
{
    if (s->length == L)
        i = (unsigned long)va_arg(args, unsigned long);
    else if (s->length == LL)
        i = (unsigned long long)va_arg(args, unsigned long long);
    else if (s->length == H)
        i = (unsigned short)va_arg(args, unsigned int);
    else if (s->length == HH)
        i = (unsigned char)va_arg(args, unsigned int);
    else if (s->length == 0)
            i = va_arg(args, unsigned int);
    return(ft_itoa_base(i, 8));
}

char    *length_modifiers_hex(t_struct *s, unsigned long i, va_list args)
{
    if (s->length == L)
        i = (unsigned long int)va_arg(args, uintmax_t);
    else if (s->length == LL)
        i = (unsigned long long int)va_arg(args, uintmax_t);
    else if (s->length == H)
        i = (unsigned short)va_arg(args, int);
    else if (s->length == HH)
        i = (unsigned char)va_arg(args, int);
    else if (s->length == 0)
            i = (unsigned int)va_arg(args, unsigned int);
    return(ft_itoa_base(i, 16));
}