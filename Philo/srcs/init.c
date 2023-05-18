/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbolzon <kbolzon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 16:10:54 by kbolzon           #+#    #+#             */
/*   Updated: 2023/03/29 14:44:43 by kbolzon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo.h"

void	create_mutex(t_simu *simu)
{
	int	i;

	i = 0;
	pthread_mutex_init(simu->msg, NULL);
	pthread_mutex_init(simu->death, NULL);
	pthread_mutex_init(simu->stop, NULL);
	while (i < simu->numbers)
		pthread_mutex_init(simu->forks + i++, NULL);
}

void	destroy_all(t_simu *simu, t_general *philo)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(simu->death);
	pthread_mutex_destroy(simu->msg);
	pthread_mutex_destroy(simu->stop);
	while (i < simu->numbers)
	{
		pthread_mutex_destroy(simu->forks + i);
		pthread_mutex_destroy(philo[i].eat);
		free(philo[i].eat);
		i++;
	}
	free(philo);
	free(simu->forks);
	free(simu->threads);
	free(simu->death);
	free(simu->msg);
	free(simu->stop);
}

t_general	*philo_init(t_simu *simu)
{
	t_general	*philo;
	int			i;

	i = -1;
	philo = malloc(sizeof(t_general) * simu->numbers);
	simu->stop = malloc(sizeof(pthread_mutex_t));
	simu->death = malloc(sizeof(pthread_mutex_t));
	simu->msg = malloc(sizeof(pthread_mutex_t));
	while (++i < simu->numbers)
		philosophers(simu, philo, i);
	return (philo);
}

void	philosophers(t_simu *simu, t_general *philo, int i)
{
	philo[i].index = i;
	philo[i].left_fork = i;
	philo[i].right_fork = (i + 1) % simu->numbers;
	philo[i].is_dead = NO;
	philo[i].data = simu;
	philo[i].eat = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(philo[i].eat, NULL);
	if (simu->no_of_meals == -1)
		philo[i].no_of_meals = -1;
	else
		philo[i].no_of_meals = simu->no_of_meals;
}

void	print_msg(int id, t_general *philo)
{
	unsigned int	time;

	pthread_mutex_lock(philo->data->msg);
	time = get_time() - philo->data->start;
	if (id == FORK)
		printf("%u\t%d has taken a fork\n", time, philo->index + 1);
	else if (id == EATING)
		printf("%u\t%d is eating\n", time, philo->index + 1);
	else if (id == SLEEPING)
		printf("%u\t%d is sleeping\n", time, philo->index + 1);
	else if (id == THINKING)
		printf("%u\t%d is thinking\n", time, philo->index + 1);
	else if (id == DIED)
		printf("%u\t%d has died\n", time, philo->index + 1);
	else if (id == DONE)
		printf("Simulation finished!\n");
	if (id != DIED && id != DONE)
		pthread_mutex_unlock(philo->data->msg);
}
