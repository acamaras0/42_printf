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

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "../libft/libft.h"

# define CONVERSION "cspdiouxXf%"
# define LENGTH "lLh"
# define FLAGS "#0-+ .*0123456789lLh"
# define ALL "#0-+ .*0123456789lLhcspdiouxXf%"

# define L  1
# define LL 2
# define H  3
# define HH 4
# define BL 5

typedef struct s_struct
{
	va_list		arg;
	char		*form;
	int			print;
	int			length;
	int			index;
	int			hash;
	int			minus;
	int			plus;
	int			zero;
	int			space;
	int			width;
	int			precision;
	int			negative;
	int			number;
	int			star;
	int			floatprecis;
}				t_struct;

void	ifpercent(t_struct *s);	
void	ifchar(t_struct *s, va_list args);
void	ifstring(t_struct *s, va_list args);
void	ifnum(t_struct *s, va_list args);
void	ifpointer(t_struct *s, va_list args);
void	ifunsigned(t_struct *s, va_list args);
void	ifhex(t_struct *s, va_list args, char c);
void	ifoctal(t_struct *s, va_list args);
void	iffloat(t_struct *s, va_list args);

char	*length_modifiers_int(t_struct *s, intmax_t i, va_list args);
char	*length_modifiers_uint(t_struct *s, unsigned long i, va_list args);
char	*length_modifiers_oct(t_struct *s, unsigned long i, va_list args);
char	*length_modifiers_hex(t_struct *s, unsigned long i, va_list args);
char	*length_modifiers_float(t_struct *s, long double i, va_list args);

void	flags_check(const char *format, t_struct *s);
void	length_check(t_struct *s, const char *format);
void	specifier_check(t_struct *s, char c, va_list args);
void	precision_check(const char *format, t_struct *s, va_list args, int n);
void	width_check(const char *format, t_struct *s, va_list args);

void	put_zeroes(t_struct *s, int n);
void	put_spaces(t_struct *s, int n);
char	*to_lower(char *str);
char	*add_zero_plus_minus(char *str, t_struct *s, char c, int conv);

char	*align_to_left(t_struct *s, char *str);
char	*align_to_right(t_struct *s, char *str);
char	*convert_left(t_struct *s, char *str, int i, char c);

char	*ft_ftoa(t_struct *s, long double fl, int prec, int d);
int		ft_printf(const char *format, ...);

#endif