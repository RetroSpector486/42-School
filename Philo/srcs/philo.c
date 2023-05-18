/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbolzon <kbolzon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 16:10:58 by kbolzon           #+#    #+#             */
/*   Updated: 2023/05/18 10:34:52 by kbolzon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo.h"

void	*check_death(void *arg)
{
	t_general	*philo;

	philo = (t_general *)arg;
	while (1)
	{
		if (philo->next_meal < get_time())
		{
			philo->data->is_dead = YES;
			pthread_mutex_lock(philo->eat);
			print_msg(DIED, philo);
			pthread_mutex_unlock(philo->data->stop);
			break ;
		}
	}
	return (NULL);
}

int	check_is_eating(t_general *philo)
{
	if ((philo->data->no_of_meals != -1)
		&& (philo->data->current_meal >= philo->data->max_meal))
	{
		philo->data->is_dead = YES;
		pthread_mutex_lock(philo->eat);
		print_msg(DONE, philo);
		pthread_mutex_unlock(philo->data->stop);
		return (0);
	}
	return (1);
}

void	*routine(void *arg)
{
	t_general	*philo;
	pthread_t	death;

	philo = arg;
	philo->next_meal = get_time() + (unsigned int)philo->data->time_to_die;
	pthread_create(&death, NULL, check_death, philo);
	pthread_detach(death);
	while (1)
	{
		if (philo->data->is_dead)
			break ;
		take_fork(philo);
		eating(philo);
		if (!check_is_eating(philo))
			break ;
		sleeping(philo);
		print_msg(THINKING, philo);
	}
	return (NULL);
}

int	error_put(t_simu *simu, char *msg, int ret)
{
	if (simu)
	{
		if (simu->threads)
			free(simu->threads);
		if (simu->forks)
			free(simu->forks);
	}
	printf("%s\n", msg);
	return (ret);
}

int	main(int argc, char **argv)
{
	int			i;
	t_simu		simu;
	t_general	*philo;

	i = 0;
	if (argc == 5 || argc == 6)
	{
		if (parsing(argv, &simu))
			return (0);
		philo = philo_init(&simu);
		simu.start = get_time();
		create_mutex(&simu);
		pthread_mutex_lock(simu.stop);
		while (i < simu.numbers)
		{
			pthread_create(simu.threads + i, NULL, routine, philo + i);
			pthread_detach(simu.threads[i++]);
			usleep(100);
		}
		pthread_mutex_lock(simu.stop);
		destroy_all(&simu, philo);
	}
	else
		printf("Too many arguments!\n");
	return (0);
}
