/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sekahram <sekahram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 14:18:35 by sekahram          #+#    #+#             */
/*   Updated: 2023/05/24 14:30:44 by sekahram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

# define ARGS_ERROR 1
# define ARGS_NUM_ERROR 2

typedef struct s_args
{
	int				nb_philo;
	int				max_eat;
	int				philo_ate;
	size_t			die_t;
	int				eat_t;
	int				sleep_t;
	int				stop_sim;
	pthread_mutex_t	*forks;
	pthread_mutex_t	printf_lock;
	pthread_mutex_t	check_lock;
	pthread_mutex_t	nb_lock;
	pthread_mutex_t	death_lock;
}				t_args;

typedef struct s_philo
{
	pthread_t	tid;
	t_args		*args;
	int			num;
	size_t		start_t;
	size_t		last_meal;
	int			nb_eat;
	short		is_finished;
	int			r_fork;
	int			l_fork;
}				t_philo;

size_t	get_time(void);
void	psleep(size_t ms);
long	ft_atol(char *s);
int		ft_isdigit(char *s);
void	eat_time(t_philo *ph);
void	sleep_time(t_philo *ph);
void	think_time(t_philo *ph);
void	die_time(t_philo *ph);
t_philo	**init_philo(t_args *args);
void	init_mutex(t_args *args);
int		check_args(char **s);
t_args	*parse_args(char **s);
void	free_philo(t_philo **ph);
void	free_args(t_args *args);
size_t	check_meals(t_philo *ph);
int		check_nb(t_philo *ph);
int		check_death(t_philo *ph);
void	set_meals(t_philo *ph);
void	set_nb(t_philo *ph);
void	set_death(t_philo *ph);
int		handle_error(short error_code);

#endif
