/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_setters.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sekahram <sekahram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 14:18:35 by sekahram          #+#    #+#             */
/*   Updated: 2023/05/24 14:29:32 by sekahram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_meals(t_philo *ph)
{
	pthread_mutex_lock(&ph->args->check_lock);
	ph->last_meal = get_time();
	pthread_mutex_unlock(&ph->args->check_lock);
}

void	set_nb(t_philo *ph)
{
	pthread_mutex_lock(&ph->args->nb_lock);
	++ph->nb_eat;
	pthread_mutex_unlock(&ph->args->nb_lock);
}

void	set_death(t_philo *ph)
{
	pthread_mutex_lock(&ph->args->death_lock);
	ph->args->stop_sim = 1;
	pthread_mutex_unlock(&ph->args->death_lock);
}
