/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbolzon <kbolzon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 10:10:58 by kbolzon           #+#    #+#             */
/*   Updated: 2023/02/27 10:10:45 by kbolzon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

t_stack	*get_stack_bot(t_stack *stack)
{
	while (stack && stack->next != NULL)
		stack = stack->next;
	return (stack);
}

t_stack	*get_stack_b_b(t_stack *stack)
{
	while (stack && stack->next && stack->next->next != NULL)
		stack = stack->next;
	return (stack);
}

t_stack	*new_stack(int number)
{
	t_stack	*new;

	new = malloc(sizeof * new);
	if (!new)
		return (NULL);
	new->number = number;
	new->index = 0;
	new->pos = -1;
	new->target_pos = -1;
	new->move_a = -1;
	new->move_b = -1;
	new->next = NULL;
	return (new);
}

void	stack_add_b(t_stack **stack, t_stack *new)
{
	t_stack	*bot;

	if (!new)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	bot = get_stack_bot(*stack);
	bot->next = new;
}

int	get_stack(t_stack *stack)
{
	int	size;

	size = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		stack = stack->next;
		size++;
	}
	return (size);
}
