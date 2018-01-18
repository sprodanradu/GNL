/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprodan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 20:02:00 by sprodan-          #+#    #+#             */
/*   Updated: 2017/12/21 15:48:13 by sprodan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*head;

	head = (t_list*)malloc(sizeof(t_list));
	if (!head)
		return (NULL);
	if (content == NULL)
	{
		head->content = NULL;
		head->content_size = 0;
		head->next = NULL;
		return (head);
	}
	head->content = (void*)malloc(content_size);
	if (!head->content)
		return (NULL);
	head->content = ft_memcpy(head->content, content, content_size);
	head->content_size = content_size;
	head->next = NULL;
	return (head);
}
