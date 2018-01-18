/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprodan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 15:19:06 by sprodan-          #+#    #+#             */
/*   Updated: 2017/12/21 16:12:05 by sprodan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*i;
	t_list	*new;
	t_list	*tmp;

	new = (t_list*)malloc(sizeof(t_list));
	if (!new || !lst)
		return (NULL);
	new = f(lst);
	lst = lst->next;
	tmp = new;
	while (lst != NULL)
	{
		i = lst->next;
		tmp->next = f(lst);
		tmp = tmp->next;
		if (tmp == NULL)
			return (NULL);
		lst = i;
	}
	return (new);
}
