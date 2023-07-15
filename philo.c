/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sekahram <sekahram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 14:18:35 by sekahram          #+#    #+#             */
/*   Updated: 2023/05/24 14:39:43 by sekahram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*only_you(t_philo *ph)
{
	pthread_mutex_lock(&ph->args->forks[ph->r_fork]);
	printf("%-5ld %d has taken a fork\n", get_time() - ph->start_t,
		ph->num + 1);
	pthread_mutex_unlock(&ph->args->forks[ph->r_fork]);
	return (NULL);
}

void	*start(void *philo)
{
	t_philo	*ph;

	ph = (t_philo *)philo;
	ph->start_t = get_time();
	set_meals(ph);
	if (ph->args->nb_philo == 1)
		return (only_you(ph));
	if (ph->num % 2 == 1)
		psleep(1);
	while (!check_death(ph))
	{
		eat_time(ph);
		sleep_time(ph);
		think_time(ph);
	}
	return (NULL);
}

int	check_philo(t_philo **ph, t_args *ag)
{
	int	i;

	i = -1;
	while (++i < ag->nb_philo)
	{
		if (check_meals(ph[i]) != 0
			&& get_time() - check_meals(ph[i]) > ag->die_t)
		{
			die_time(ph[i]);
			return (1);
		}
		if (!ph[i]->is_finished && check_nb(ph[i]) == ag->max_eat
			&& ++ag->philo_ate)
			++ph[i]->is_finished;
		if (ag->philo_ate == ag->nb_philo)
		{
			set_death(ph[i]);
			return (1);
		}
	}
	return (0);
}

int	main(int ac, char *av[])
{
	t_philo	**philo;
	t_args	*ag;
	int		i;

	if (ac < 5 || ac > 6)
		return (handle_error(ARGS_NUM_ERROR));
	i = -1;
	if (check_args(++av))
		return (handle_error(ARGS_ERROR));
	ag = parse_args(av);
	philo = init_philo(ag);
	init_mutex(ag);
	while (++i < ag->nb_philo)
		pthread_create(&(philo[i]->tid), NULL, start, philo[i]);
	while (!check_philo(philo, ag))
		psleep(1);
	i = -1;
	while (++i < ag->nb_philo)
		pthread_join(philo[i]->tid, NULL);
	free_philo(philo);
	free_args(ag);
	return (0);
}
