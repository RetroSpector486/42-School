/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbolzon <kbolzon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:38:13 by kbolzon           #+#    #+#             */
/*   Updated: 2023/02/19 14:16:16 by kbolzon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

static void	rr_ab(t_stack **a, t_stack **b, int *move_a, int *move_b)
{
	while (*move_a < 0 && *move_b < 0)
	{
		(*move_a)++;
		(*move_b)++;
		rrr_ab(a, b);
	}
}

static void	rotate_both(t_stack **a, t_stack **b, int *move_a, int *move_b)
{
	while (*move_a > 0 && *move_b > 0)
	{
		(*move_a)--;
		(*move_b)--;
		reverse_ab(a, b);
	}
}

static void	rotate_a(t_stack **a, int *move)
{
	while (*move)
	{
		if (*move > 0)
		{
			reverse_a(a);
			(*move)--;
		}
		else if (*move < 0)
		{
			rr_a(a);
			(*move)++;
		}
	}
}

static void	rotate_b(t_stack **b, int *move)
{
	while (*move)
	{
		if (*move > 0)
		{
			reverse_b(b);
			(*move)--;
		}
		else if (*move < 0)
		{
			rr_b(b);
			(*move)++;
		}
	}
}

void	m_stack(t_stack **a, t_stack **b, int move_a, int move_b)
{
	if (move_a < 0 && move_b < 0)
		rr_ab(a, b, &move_a, &move_b);
	else if (move_a > 0 && move_b > 0)
		rotate_both(a, b, &move_a, &move_b);
	rotate_a(a, &move_a);
	rotate_b(b, &move_b);
	push_a(a, b);
}
