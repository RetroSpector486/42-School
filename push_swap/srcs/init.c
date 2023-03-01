/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbolzon <kbolzon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 14:23:54 by kbolzon           #+#    #+#             */
/*   Updated: 2023/02/27 10:09:59 by kbolzon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

t_stack	*fill_stack_values(int argc, char **argv)
{
	t_stack		*stack_a;
	long int	nb;
	int			i;

	stack_a = NULL;
	nb = 0;
	i = 1;
	while (i < argc)
	{
		nb = ft_atoi(argv[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			exit_w_error(&stack_a, NULL);
		if (i == 1)
			stack_a = new_stack((int)nb);
		else
			stack_add_b(&stack_a, new_stack((int)nb));
		i++;
	}
	return (stack_a);
}

void	assign_index(t_stack *stack_a, int stack_size)
{
	t_stack	*ptr;
	t_stack	*highest;
	int		number;

	while (--stack_size > 0)
	{
		ptr = stack_a;
		number = INT_MIN;
		highest = NULL;
		while (ptr)
		{
			if (ptr->number == INT_MIN && ptr->index == 0)
				ptr->index = 1;
			if (ptr->number > number && ptr->index == 0)
			{
				number = ptr->number;
				highest = ptr;
				ptr = stack_a;
			}
			else
				ptr = ptr->next;
		}
		if (highest != NULL)
			highest->index = stack_size;
	}
}
