/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamaras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 15:18:27 by acamaras          #+#    #+#             */
/*   Updated: 2022/02/15 15:37:51 by acamaras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

char    *length_modifiers(t_struct *s, intmax_t i, va_list args)
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
    return (ft_itoa(i));
}

void ifpercent(t_struct *s)
{
    ft_putchar('%');
    s->print++;
}

void     ifchar(t_struct *s, va_list args)
{
    unsigned char c;

    c = (unsigned char)va_arg(args, int);
    ft_putchar(c);
    s->print++;
}

void     ifstring(t_struct *s, va_list args)
{
    char    *str;

    str = va_arg(args, char *);
    if (str == NULL)
    {
        ft_putstr("(null)");
        return;
    }
    else
        ft_putstr(str);
    s->print+=ft_strlen(str);
}

void     ifnum(t_struct *s, va_list args)
{
    intmax_t     i;
    char    *str;

    i = 0;
    str = length_modifiers(s, i, args);
    ft_putstr(str);
    s->print += ft_strlen(str);
    ft_strdel(&str);
}

void     ifpointer(t_struct *s, va_list args)
{
    unsigned long long i;
    int j;
    char *str;
    char *joined;

    j = 0;
    i = va_arg(args, unsigned long long);
    str = ft_itoa_base((unsigned long long)i, 16);
    while (str[j++])
    {
        if (str[j] >= 65 && str[j] <= 90)
            str[j] += 32;
    }
    joined = ft_strjoin("0x", str);
    ft_putstr(joined);
    s->print += ft_strlen(joined);
    ft_strdel(&str);
    ft_strdel(&joined);
}

void     ifunsigned(t_struct *s, va_list args)
{
    unsigned long i;
    char *str;

    i = va_arg(args, unsigned long);
    str = ft_ultoa(i);
    ft_putstr(str);
    s->print += ft_strlen(str);
    ft_strdel(&str);
}

void     ifhex(t_struct *s, va_list args)
{
    char *str;
    unsigned long i;

    i = va_arg(args, unsigned long);
    str = ft_itoa_base(i, 16);
    ft_putstr(str);
    s->print += ft_strlen(str);
    ft_strdel(&str);
}

void     ifhex2(t_struct *s, va_list args)
{
    char *str;
    unsigned long i;
    int j;

    j = 0;
    i = va_arg(args, unsigned long);
    str = ft_itoa_base(i, 16);
    while (str[j++])
    {
        if (str[j] >= 65 && str[j] <= 90)
            str[j] += 32;
    }
    ft_putstr(str);
    s->print += ft_strlen(str);
    ft_strdel(&str);
}

void     ifoctal(t_struct *s, va_list args)
{
    unsigned long i;
    char *str;

    i = va_arg(args, unsigned long);
    str = ft_itoa_base(i, 8);
    s->print += ft_strlen(str);
    ft_putstr(str);
    ft_strdel(&str);
}


void    length(t_struct *s, const char *format)
{
    printf("HERE\n");
    if (format[s->index] == 'l')
    {   printf("HERE2\n");
        if(format[s->index + 1] == 'l')
            s->length = LL;
        else if (format[s->index -1] != 'l')
            s->length = L;
    }
    if (format[s->index] == 'h')
    {
        if(format[s->index + 1] == 'h')
            s->length =  HH;
        else if (format[s->index -1] != 'h')
            s->length = H;
    }
    while(ft_strchr(LENGTH, format[s->index] && format[s->index]))
        s->index++;
    printf("HERE3\n");
}

void     get_formats(t_struct *s, char c, va_list args)
{
    if (c == 'c')
        ifchar(s, args);
    else if (c == 'd' || c == 'i')
        ifnum(s, args);
    else if (c == 's')
        ifstring(s, args);
    else if (c == '%')
        ifpercent(s);
    else if (c == 'p')
        ifpointer(s, args);
    else if (c == 'u')
        ifunsigned(s, args);
    else if (c == 'x')
        ifhex2(s, args);
    else if (c == 'X')
        ifhex(s, args);
    else if (c == 'o')
        ifoctal(s, args);
}
void zero(t_struct *s)
{
    s->print = 0;
    s->length = 0;;
}

int     parse(const char *format, t_struct *s, va_list args, int pos)
{
    s->index = pos;
    if (ft_strchr(LENGTH, format[pos]))
        length(s, format);
    else
    {
        get_formats(s, format[pos], args);
        zero(s);
    }
    pos = s->index;
    if (format[pos] == '\0')
        return(pos);
    return(pos - 1);
}

int     formato(const char *format, t_struct *s, va_list args, int pos)
{
    while(format[pos] != '\0')
    {
        if(format[pos] != '%')
            s->print += write(1, &format[pos], 1);
        else if(format[pos] == '%')
        {
            while (format[pos] != '\0' && ft_strchr(ALL, format[pos + 1]))
            {
                pos++;
                printf("FUCK ME\n");
                if(ft_strchr(CONVERSION, format[pos]))
                {
                    pos = parse(format, s, args, pos) + 2;
                    printf("FUCK ME1\n");
                    break;
                }
                else
                {
                    pos = parse(format, s, args, pos);
                    printf("FUCK ME2\n");
                }
            }
            printf("FUCK ME3\n");
            continue;
        }
        pos++;
    }
    printf("FUCK ME4\n");
    return(s->print);
}

int		ft_printf(const char *format, ...)
{
    va_list args;
    t_struct *s;
    int i;
    int len;

    i = 0;
    s = (t_struct*)(malloc)(sizeof(t_struct));
    if (!s)
        return(0);
    s->form = (char *)format;
    va_start(args, format);
    len = ft_strlen(format);
    if (len == 0)
            return(0);
    if (len == 1 && format[0] == '%')
        return(0);
    i = formato(format, s, args, 0);
    va_end(args);
    free(s);
    return (i);
}