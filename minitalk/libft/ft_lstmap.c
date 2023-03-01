/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbolzon <kbolzon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 13:22:56 by kbolzon           #+#    #+#             */
/*   Updated: 2022/03/01 14:06:07 by kbolzon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void*(f)(void *), void (del)(void *))
{
	t_list		*map_list;
	int			lst_size;

	(void)del;
	if (!lst)
	{
		return (0);
	}
	lst_size = ft_lstsize(lst);
	map_list = ft_lstnew(f(lst->content));
	lst = lst->next;
	while (lst)
	{
		ft_lstadd_back(&map_list, ft_lstnew(f(lst->content)));
			lst = lst->next;
	}
	return (&map_list[0]);
}
