/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lybey <lybey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 18:40:57 by lybey             #+#    #+#             */
/*   Updated: 2023/06/22 19:00:51 by lybey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*t;
	t_list	*buf;

	if (!lst)
		return ;
	t = *lst;
	while (t)
	{
		buf = t->next;
		ft_lstdelone(t, del);
		t = buf;
	}
	*lst = NULL;
}
