/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sekahram <sekahram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 14:18:35 by sekahram          #+#    #+#             */
/*   Updated: 2023/05/24 14:29:58 by sekahram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_philo(t_philo **ph)
{
	t_philo	**head;

	head = ph;
	while (ph && *ph)
		free(*ph++);
	free(head);
}

void	free_args(t_args *args)
{
	int	i;

	i = -1;
	while (++i < args->nb_philo)
		pthread_mutex_destroy(&args->forks[i]);
	free(args->forks);
	pthread_mutex_destroy(&args->printf_lock);
	pthread_mutex_destroy(&args->check_lock);
	pthread_mutex_destroy(&args->nb_lock);
	pthread_mutex_destroy(&args->death_lock);
	free(args);
}
