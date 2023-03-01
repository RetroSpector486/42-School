/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbolzon <kbolzon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 11:29:47 by kbolzon           #+#    #+#             */
/*   Updated: 2023/02/27 10:09:40 by kbolzon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

static void	do_rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*bot;

	tmp = *stack;
	*stack = (*stack)->next;
	bot = get_stack_bot(*stack);
	tmp->next = NULL;
	bot->next = tmp;
}

void	reverse_a(t_stack **stack_a)
{
	do_rotate(stack_a);
	ft_putstr("ra\n");
}

void	reverse_b(t_stack **stack_b)
{
	do_rotate(stack_b);
	ft_putstr("rb\n");
}

void	reverse_ab(t_stack **stack_a, t_stack **stack_b)
{
	do_rotate(stack_a);
	do_rotate(stack_b);
	ft_putstr("rr\n");
}
