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

typedef struct s_struct
{
    va_list arg;
    char *form;
    int print;
    int pos;
}   t_struct;


typedef int     (*t_dispach)();

static const t_dispach g_dispach[11] = {
    ifchar;
    ifstring;
    ifpointer;
    ifnum;
    ifnum;
    ifoctal;
    ifunsigned;
    ifhex;
    ifhex;
    NULL;
    ifpercent;
};
int		ft_printf(const char *format, ...);

#endif