/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbolzon <kbolzon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 09:32:53 by kbolzon           #+#    #+#             */
/*   Updated: 2023/02/27 10:10:16 by kbolzon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	is_sorted(t_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->number > stack->next->number)
			return (0);
		stack = stack->next;
	}
	return (1);
}

static void	push_swap(t_stack **stack_a, t_stack **stack_b, int stack_size)
{
	if (stack_size == 2 && !is_sorted(*stack_a))
		swap_a(stack_a);
	else if (stack_size == 3)
		sort_little(stack_a);
	else if (stack_size > 3 && !is_sorted(*stack_a))
		sort_all(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		stack_size;

	if (argc < 2)
		return (0);
	if (!is_correct_input(argv))
		exit_w_error(NULL, NULL);
	stack_b = NULL;
	stack_a = fill_stack_values(argc, argv);
	stack_size = get_stack(stack_a);
	assign_index(stack_a, stack_size + 1);
	push_swap(&stack_a, &stack_b, stack_size);
	free_stacks(&stack_a);
	free_stacks(&stack_b);
	return (0);
}
