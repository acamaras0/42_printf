/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamaras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 11:45:28 by acamaras          #+#    #+#             */
/*   Updated: 2021/11/17 15:40:21 by acamaras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

static char	**free_content(char **s1, int j)
{
	while (j >= 0)
	{
		if (s1[j])
			free((void *)&(s1[j]));
		j--;
	}
	free((void *)s1);
	return (NULL);
}

static char	**ft_alloc_check(char const *s, char c)
{
	char	**fresh;

	fresh = (char **)malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!fresh)
	{
		return (NULL);
	}
	return (fresh);
}

static int	ft_workloop(char const *s, char ***fresh, int *j, char c)
{
	int	start;
	int	i;

	i = 0;
	start = 0;
	while ((*j) < ft_count_words(s, c))
	{
		while (s[i] && s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		(*fresh)[*j] = ft_strsub(s, start, i - start);
		if (!(*fresh)[*j])
		{
			free_content(*fresh, *j);
			return (1);
		}
		i++;
		(*j)++;
	}
	return (0);
}

char	**ft_strsplit(char const *s, char c)
{
	char	**fresh;
	int		j;

	if (!s)
		return (NULL);
	fresh = ft_alloc_check(s, c);
	if (!fresh)
		return (NULL);
	j = 0;
	if (ft_workloop(s, &fresh, &j, c) == 1)
		return (NULL);
	fresh[j] = NULL;
	return (fresh);
}
