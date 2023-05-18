/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbolzon <kbolzon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 16:10:51 by kbolzon           #+#    #+#             */
/*   Updated: 2023/05/09 15:49:34 by kbolzon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo.h"

unsigned int	get_time(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return ((current_time.tv_sec * 1000) + (current_time.tv_usec / 1000));
}

void	take_fork(t_general *philo)
{
	pthread_mutex_lock(&philo->data->forks[philo->left_fork]);
	print_msg(FORK, philo);
	pthread_mutex_lock(&philo->data->forks[philo->right_fork]);
	print_msg(FORK, philo);
}

void	eating(t_general *philo)
{
	pthread_mutex_lock(philo->eat);
	print_msg(EATING, philo);
	if (philo->data->count_eat != -1)
		philo->data->current_meal++;
	philo->meal_time = get_time();
	philo->next_meal = philo->meal_time
		+ (unsigned int)philo->data->time_to_die;
	usleep(philo->data->time_to_eat * 1000);
	pthread_mutex_unlock(&philo->data->forks[philo->left_fork]);
	pthread_mutex_unlock(&philo->data->forks[philo->right_fork]);
	pthread_mutex_unlock(philo->eat);
}

void	sleeping(t_general *philo)
{
	usleep(10);
	print_msg(SLEEPING, philo);
	usleep(philo->data->time_to_sleep * 1000);
}
