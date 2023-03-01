/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbolzon <kbolzon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:51:19 by kbolzon           #+#    #+#             */
/*   Updated: 2023/02/22 12:13:31 by kbolzon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	get_totals(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;
	int		size_a;
	int		size_b;

	tmp_a = *stack_a;
	tmp_b = *stack_b;
	size_a = get_stack(tmp_a);
	size_b = get_stack(tmp_b);
	while (tmp_b)
	{
		tmp_b->move_b = tmp_b->pos;
		if (tmp_b->pos > size_b / 2)
			tmp_b->move_b = (size_b - tmp_b->pos) * -1;
		tmp_b->move_a = tmp_b->target_pos;
		if (tmp_b->target_pos > size_a / 2)
			tmp_b->move_a = (size_a - tmp_b->target_pos) * -1;
		tmp_b = tmp_b->next;
	}
}

void	sort_shortest_move(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	int		shortest;
	int		move_a;
	int		move_b;

	tmp = *stack_b;
	shortest = INT_MAX;
	while (tmp)
	{
		if (nb_abs(tmp->move_a) + nb_abs(tmp->move_b) < nb_abs(shortest))
		{
			shortest = nb_abs(tmp->move_b) + nb_abs(tmp->move_a);
			move_a = tmp->move_a;
			move_b = tmp->move_b;
		}
		tmp = tmp->next;
	}
	m_stack(stack_a, stack_b, move_a, move_b);
}
