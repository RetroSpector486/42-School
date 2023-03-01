/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbolzon <kbolzon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 11:29:47 by kbolzon           #+#    #+#             */
/*   Updated: 2023/02/27 10:06:43 by kbolzon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <limits.h>
# include <stddef.h>

typedef struct s_stack
{
	int				number;
	int				index;
	int				pos;
	int				target_pos;
	int				move_a;
	int				move_b;
	struct s_stack	*next;
}	t_stack;

int			is_sorted(t_stack *stack);
int			get_lowest_pos(t_stack **stack);
int			get_stack(t_stack *stack);

void		ft_putstr(char *str);
void		assign_index(t_stack *stack_a, int stack_size);
void		sort_little(t_stack **stack);
void		sort_all(t_stack **stack_a, t_stack **stack_b);
void		get_target_pos(t_stack **stack_a, t_stack **stack_b);
void		stack_add_b(t_stack **stack, t_stack *new);
void		get_totals(t_stack **stack_a, t_stack **stack_b);
void		sort_shortest_move(t_stack **stack_a, t_stack **stack_b);
void		m_stack(t_stack **a, t_stack **b, int move_a, int move_b);
void		exit_w_error(t_stack **stack_a, t_stack **stack_b);

void		push_a(t_stack **stack_a, t_stack **stack_b);
void		push_b(t_stack **stack_a, t_stack **stack_b);
void		swap_a(t_stack **stack_a);
void		swap_b(t_stack **stack_b);
void		swap_ab(t_stack **stack_a, t_stack **stack_b);
void		reverse_a(t_stack **stack_a);
void		reverse_b(t_stack **stack_b);
void		reverse_ab(t_stack **stack_a, t_stack **stack_b);
void		rr_a(t_stack **stack_a);
void		rr_b(t_stack **stack_b);
void		rrr_ab(t_stack **stack_a, t_stack **stack_b);

void		free_stacks(t_stack **stack);
long int	ft_atoi(const char *str);
void		ft_putstr(char *str);
int			ft_isdigit(char c);
int			ft_issign(char c);
int			nb_abs(int nb);
int			is_correct_input(char **argv);
int			nbstr_cmp(const char *s1, const char *s2);

t_stack		*fill_stack_values(int argc, char **argv);
t_stack		*get_stack_bot(t_stack *stack);
t_stack		*get_stack_b_b(t_stack *stack);
t_stack		*new_stack(int number);

#endif
