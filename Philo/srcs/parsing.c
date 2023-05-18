/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbolzon <kbolzon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 16:11:03 by kbolzon           #+#    #+#             */
/*   Updated: 2023/05/09 15:56:43 by kbolzon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo.h"

int	reset_set(t_simu *simu, int num, int i)
{
	if (i == 3)
	{
		if (num < 60)
			return (error_put(simu,
					"Error: The time_to_eat can't be less than 60 ms!", 1));
		simu->time_to_eat = num;
	}
	else if (i == 4)
	{
		if (num < 60)
			return (error_put(simu,
					"Error: The time_to_sleep can't be less than 60 ms!", 1));
		simu->time_to_sleep = num;
	}
	else
		check_last(simu, num, i);
	return (0);
}

int	check_last(t_simu *simu, int num, int i)
{
	if (i == 5)
	{
		if (num == 0)
		{
			simu->no_of_meals = -1;
			simu->current_meal = -1;
			simu->max_meal = -1;
		}
		else
		{
			simu->no_of_meals = num;
			simu->current_meal = 0;
			simu->max_meal = num * simu->numbers;
		}
	}
	return (0);
}

int	set_data(t_simu *simu, int num, int i)
{
	if (i == 1)
	{
		if (num == 0)
			return (error_put(NULL,
					"Error: No Philosopher at the table!", 1));
		simu->numbers = num;
		simu->threads = malloc(sizeof(pthread_t) * num);
		simu->forks = malloc(sizeof(pthread_mutex_t) * num);
	}
	else if (i == 2)
	{
		if (num < 60)
			return (error_put(simu,
					"Error: time_to_die can't be less than 60ms!", 1));
		simu->time_to_die = num;
	}
	else
		reset_set(simu, num, i);
	return (0);
}

int	get_number(char *arg)
{
	int	i;
	int	num;

	i = 0;
	num = 0;
	while (arg[i])
	{
		if (arg[i] >= '0' && arg[i] <= '9')
				num = num * 10 + (arg[i] - '0');
		else
			return (error_put(NULL, "Error: Numbers only!", -1));
		i++;
	}
	return (num);
}

int	parsing(char **argv, t_simu *simu)
{
	int	num;
	int	i;

	i = 1;
	while (argv[i])
	{
		num = get_number(argv[i]);
		if (num == -1)
			return (1);
		if (set_data(simu, num, i))
			return (1);
		i++;
	}
	if (i == 5)
	{
		simu->no_of_meals = -1;
		simu->current_meal = -1;
		simu->max_meal = -1;
	}
	simu->is_dead = NO;
	return (0);
}
