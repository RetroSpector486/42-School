/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbolzon <kbolzon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:38:13 by kbolzon           #+#    #+#             */
/*   Updated: 2023/02/22 10:50:24 by kbolzon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

static void	do_swap(t_stack *stack)
{
	int	tmp;

	if (stack == NULL || stack->next == NULL)
		return ;
	tmp = stack->number;
	stack->number = stack->next->number;
	stack->next->number = tmp;
	tmp = stack->index;
	stack->index = stack->next->index;
	stack->next->index = tmp;
}

void	swap_a(t_stack **stack_a)
{
	do_swap(*stack_a);
	ft_putstr("sa\n");
}

void	swap_b(t_stack **stack_b)
{
	do_swap(*stack_b);
	ft_putstr("sb\n");
}

void	swap_ab(t_stack **stack_a, t_stack **stack_b)
{
	do_swap(*stack_a);
	do_swap(*stack_b);
	ft_putstr("ss\n");
}
