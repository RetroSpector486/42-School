/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbolzon <kbolzon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 09:32:24 by kbolzon           #+#    #+#             */
/*   Updated: 2023/02/22 10:50:24 by kbolzon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

static void	push_all_3(t_stack **stack_a, t_stack **stack_b)
{
	int	stack_size;
	int	is_pushed;
	int	i;

	stack_size = get_stack(*stack_a);
	is_pushed = 0;
	i = 0;
	while (stack_size > 6 && i < stack_size && is_pushed < stack_size / 2)
	{
		if ((*stack_a)->index <= stack_size / 2)
		{
			push_b(stack_a, stack_b);
			is_pushed++;
		}
		else
			reverse_a(stack_a);
		i++;
	}
	while (stack_size - is_pushed > 3)
	{
		push_b(stack_a, stack_b);
		is_pushed++;
	}
}

static void	shift_stack(t_stack **stack_a)
{
	int	lowest_pos;
	int	stack_size;

	stack_size = get_stack(*stack_a);
	lowest_pos = get_lowest_pos(stack_a);
	if (lowest_pos > stack_size / 2)
	{
		while (lowest_pos < stack_size)
		{
			rr_a(stack_a);
			lowest_pos++;
		}
	}
	else
	{
		while (lowest_pos > 0)
		{
			reverse_a(stack_a);
			lowest_pos--;
		}
	}
}

void	sort_all(t_stack **stack_a, t_stack **stack_b)
{
	push_all_3(stack_a, stack_b);
	sort_little(stack_a);
	while (*stack_b)
	{
		get_target_pos(stack_a, stack_b);
		get_totals(stack_a, stack_b);
		sort_shortest_move(stack_a, stack_b);
	}
	if (!is_sorted(*stack_a))
		shift_stack(stack_a);
}
