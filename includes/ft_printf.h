/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamaras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 15:19:26 by acamaras          #+#    #+#             */
/*   Updated: 2022/02/15 15:19:35 by acamaras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "../libft/libft.h"

# define CONVERSION "cspdiouxXf%"
# define LENGTH "lLh"
# define ALL "lLhcspdiouxXf%"
# define L  1
# define LL 2
# define H  3
# define HH 4

typedef struct s_struct
{
    va_list arg;
    const char *form;
    int print;
    int length;
    int index; 
}   t_struct;


void     ifpercent(t_struct *s);
void     ifchar(t_struct *s, va_list args);
void     ifstring(t_struct *s, va_list args);
void     ifnum(t_struct *s, va_list args);
void     ifpointer(t_struct *s, va_list args);
void     ifunsigned(t_struct *s, va_list args);
void     ifhex(t_struct *s, va_list args);
void     ifhex2(t_struct *s, va_list args);
void     ifoctal(t_struct *s, va_list args);

typedef void     (*t_dispach)(t_struct *s, va_list args);

static const t_dispach g_dispach[11] = {
    ifchar,
    ifstring,
    ifpointer,
    ifnum,
    ifnum,
    ifoctal,
    ifunsigned,
    ifhex2,
    ifhex,
    NULL,
};

char    *length_modifiers_int(t_struct *s, unsigned long i, va_list args);
char    *length_modifiers_uint(t_struct *s, unsigned long i, va_list args);
char    *length_modifiers_oct(t_struct *s, unsigned long i, va_list args);
char    *length_modifiers_hex(t_struct *s, unsigned long i, va_list args);

int		ft_printf(const char *format, ...);

#endif