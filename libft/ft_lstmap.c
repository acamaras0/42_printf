/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamaras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 17:39:45 by acamaras          #+#    #+#             */
/*   Updated: 2021/11/23 19:00:04 by acamaras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static void	free_list(t_list *head)
{
	t_list	*tmp;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp->content);
		free(tmp);
	}
}

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*fresh;
	t_list	*head;

	if (!lst || !f)
		return (NULL);
	fresh = f(lst);
	if (!fresh)
		return (NULL);
	head = fresh;
	while (lst->next != NULL)
	{
		lst = lst->next;
		fresh->next = f(lst);
		if (!fresh->next)
		{
			free_list(head);
			return (NULL);
		}
		fresh = fresh->next;
	}
	return (head);
}
