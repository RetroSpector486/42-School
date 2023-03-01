/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbolzon <kbolzon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 11:29:47 by kbolzon           #+#    #+#             */
/*   Updated: 2023/02/22 10:50:24 by kbolzon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

static void	do_push(t_stack **source, t_stack **dest)
{
	t_stack	*tmp;

	if (*source == NULL)
		return ;
	tmp = (*source)->next;
	(*source)->next = *dest;
	*dest = *source;
	*source = tmp;
}

void	push_a(t_stack **stack_a, t_stack **stack_b)
{
	do_push(stack_b, stack_a);
	ft_putstr("pa\n");
}

void	push_b(t_stack **stack_a, t_stack **stack_b)
{
	do_push(stack_a, stack_b);
	ft_putstr("pb\n");
}
