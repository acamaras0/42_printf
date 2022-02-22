/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamaras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:39:18 by acamaras          #+#    #+#             */
/*   Updated: 2021/11/16 18:40:47 by acamaras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strtrim(char const *s)
{
	size_t		start;
	size_t		end;

	if (!s)
		return (NULL);
	start = 0;
	end = ft_strlen(s);
	if (s == NULL)
		return (NULL);
	while (s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
		start++;
	while ((s[end] == '\0' || s[end] == ' '
			||s[end] == '\n' || s[end] == '\t') && end != start)
		end--;
	return (ft_strsub(s, start, end - start + 1));
}
