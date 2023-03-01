/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbolzon <kbolzon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 09:32:20 by kbolzon           #+#    #+#             */
/*   Updated: 2023/02/20 17:12:53 by kbolzon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

static int	find_largest_index(t_stack *stack)
{
	int	index;

	index = stack->index;
	while (stack)
	{
		if (stack->index > index)
			index = stack->index;
		stack = stack->next;
	}
	return (index);
}

void	sort_little(t_stack **stack)
{
	int	highest;

	if (is_sorted(*stack))
		return ;
	highest = find_largest_index(*stack);
	if ((*stack)->index == highest)
		reverse_a(stack);
	else if ((*stack)->next->index == highest)
		rr_a(stack);
	if ((*stack)->index > (*stack)->next->index)
		swap_a(stack);
}
