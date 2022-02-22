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

#include "ft_printf.h"

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
        return (0);
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
    str = ft_itoa(va_arg(args, int));
    s->printed += ft_strlen(str);
    ft_strdel(&str);
}

void     ifpointer(t_struct *s, va_list args)
{
    unsigned long long i;
    char *str;
    char *joined;

    i = va_arg(args, unsigned long long);
    str = ft_itoa_base((unsigned long long)i, 16);
    if (str[0] == '0')
        return;
    else
        while (str[i++])
        {
            if (str[i] >= 65 && str[i] <= 90)
                str[i] += 32;
        }
    }
    joined = ft_strjoin("0x", str);
    ft_putstr(joined);
    s->print += ft_strlen(joined);
    free(str);
    free(joined);
}

int     ifunsigned(unsigned long i)
{
    unsigned int length;
    char *str;

    length = 0;
    if (i == 0)
        length += write(1, "0", 1);
    else
    {
        str = ft_uitoa(i);
        length += ifstring(str);
        free(str);
    }   
    return (length);
}

int     ifhex(unsigned long i, const char format)
{
    char *str;
    int j;

    j = 0;
    if (i == 0)
        return(write(1, "0", 1));
    else 
        str = ft_itoa_base(i, 16);
    if (format == 'x')
        while (str[j++])
        {
            if (str[j] >= 65 && str[j] <= 90)
                str[j] += 32;
        }
    return (ifstring(str));
}

int     ifoctal(unsigned long i)
{
    unsigned long length;
    char *str;

    length = 0;
    str = NULL;
    if (i == 0)
        length += write(1, "0", 1);
    else
        str = ft_itoa_base(i, 8);
    return (ifstring(str));
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
        ifpercent(s, args);
    else if (c == 'p')
        ifpointer(s, args));
    else if (c == 'u')
        ifunsigned(s, args));
    else if (c == 'X' || c == 'x')
        ifhex(s, args);
    else if (c == 'o')
        ifoctal(s, args));
}

int     parse(t_struct *s, const char *format, va_list args, int i)
{
    f->pos = i;
    get_format(s, format[i], args);
    i = f->pos;
    if (format[i] == '\0')
        return(i);
    return(i -1);
}

int     format(const char *format, t_struct *s, va_list args, int i)
{
    while(format[i] != '\0')
    {
        if(format[i] != '%')
            s->print += write(1, &format[i], 1);
        while (format[i])
        {
             if (format[i] == '%')
            {
                i++;
                if(ft_strchr(CONVERSION, format[i]))
                {
                    i = parse(s, i, format, args) + 2;
                    break;
                }
            }
            else
                i = parse(s, i, format, args);
        }
        i++;
    }
    return(s->print);
}

int		ft_printf(const char *format, ...)
{
    va_list args;
    t_struct *s;
    int i;
    int length;

    i = 0;
    length = 0;
    s = (t_struct*)(malloc)(sizeof(t_struct));
    if (!s)
        return(0);
    s->form = (char *)format;
    va_start(args, format);
    length = ft_strlen(format);
    if (length = 0)
            return(0);
    if (length == 1 && format[0] == '%')
        return(0);
    i = format(format, s, args, 0);
    va_end(args);
    free(s);
    return (i);
}