/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbolzon <kbolzon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 13:00:57 by kbolzon           #+#    #+#             */
/*   Updated: 2023/05/09 14:20:53 by kbolzon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <sys/time.h>
# include <string.h>
# include <pthread.h>
# include <stdlib.h>
# include <semaphore.h>
# include <fcntl.h>
# include <signal.h>
# include <sys/stat.h>

# define YES 1
# define NO 0
# define FORK 1
# define EATING 2
# define SLEEPING 3
# define THINKING 4
# define DIED 5
# define DONE 6

typedef struct s_simu
{
	int				numbers;
	int				time_to_eat;
	int				time_to_sleep;
	int				time_to_die;
	int				no_of_meals;
	int				is_dead;
	int				count_eat;
	int				current_meal;
	int				max_meal;
	unsigned int	start;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*death;
	pthread_t		*threads;
	pthread_mutex_t	*stop;
	pthread_mutex_t	*msg;
	sem_t			*forks_b;
	sem_t			*msg_b;
	sem_t			*stop_b;
	sem_t			*death_b;
}					t_simu;

typedef struct s_general
{
	int				index;
	int				left_fork;
	int				right_fork;
	int				count_eat;
	int				is_dead;
	int				no_of_meals;
	pthread_mutex_t	*eat;
	t_simu			*data;
	unsigned int	meal_time;
	unsigned int	next_meal;
	pid_t			pid;
}					t_general;

void			*routine(void *arg);
void			routine_2(t_general *philo);
void			routine_bonus(t_general *philo);
void			eating(t_general *philo);
void			sleeping(t_general *philo);
void			*check_death(void *arg);
void			take_fork(t_general *philo);
void			print_msg(int id, t_general *philo);
void			create_mutex(t_simu *simu);
void			destroy_all(t_simu *simu, t_general *philo);
void			philosophers(t_simu *simu, t_general *philo, int i);
void			create_semaphore(t_simu *simu);
t_general		*philo_init(t_simu *simu);
t_general		*philo_init_b(t_simu *simu);
unsigned int	get_time(void);
int				check_is_eating(t_general *philo);
int				get_number(char *arg);
int				parsing(char **argv, t_simu *simu);
int				reset_set(t_simu *simu, int num, int i);
int				set_data(t_simu *simu, int num, int i);
int				error_put(t_simu *simu, char *msg, int ret);
int				check_last(t_simu *simu, int num, int i);

#endif