/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sekahram <sekahram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 14:18:35 by sekahram          #+#    #+#             */
/*   Updated: 2023/05/24 14:30:47 by sekahram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	get_time(void)
{
	struct timeval	tv;
	size_t			ms;

	gettimeofday(&tv, NULL);
	ms = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (ms);
}

void	psleep(size_t ms)
{
	size_t	start;

	start = get_time();
	while (get_time() - start < ms)
		usleep(100);
}

int	ft_isdigit(char *s)
{
	while (*s)
	{
		if (!((*s >= '0' && *s <= '9') || (*s == '+' && *(s + 1) != '+')))
			return (0);
		++s;
	}
	return (1);
}

long	ft_atol(char *s)
{
	int		sign;
	long	out;

	out = 0;
	sign = -1;
	while (*s == ' ' || *s == '\r' || *s == '\t')
		++s;
	if (*s == '-' && ++s)
		sign = 1;
	else if (*s == '+')
		++s;
	while (*s >= '0' && *s <= '9')
		out = out * 10 - (*s++ - '0');
	return (sign * out);
}
