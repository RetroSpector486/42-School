/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbolzon <kbolzon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 10:43:09 by kbolzon           #+#    #+#             */
/*   Updated: 2023/02/22 11:19:31 by kbolzon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

static int	arg_number(char *argv)
{
	int	i;

	i = 0;
	if (ft_issign(argv[i]) && argv[i + 1] != '\0')
		i++;
	while (argv[i] && ft_isdigit(argv[i]))
		i++;
	if (argv[i] != '\0' && !ft_isdigit(argv[i]))
		return (0);
	return (1);
}

static int	repeated_values(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 1;
		while (argv[j])
		{
			if (j != i && nbstr_cmp(argv[i], argv[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	is_arg_zero(char *argv)
{
	int	i;

	i = 0;
	if (ft_issign(argv[i]))
		i++;
	while (argv[i] && argv[i] == '0')
		i++;
	if (argv[i] != '\0')
		return (0);
	return (1);
}

int	is_correct_input(char **argv)
{
	int	i;
	int	nb_zero;

	nb_zero = 0;
	i = 1;
	while (argv[i])
	{
		if (!arg_number(argv[i]))
			return (0);
		nb_zero += is_arg_zero(argv[i]);
		i++;
	}
	if (nb_zero > 1)
		return (0);
	if (repeated_values(argv))
		return (0);
	return (1);
}
