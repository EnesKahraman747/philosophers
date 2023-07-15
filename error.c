/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sekahram <sekahram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 14:18:35 by sekahram          #+#    #+#             */
/*   Updated: 2023/05/24 14:29:26 by sekahram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	handle_error(short error_code)
{
	if (error_code == ARGS_ERROR)
		printf("Argument is not a digit "
			"or it overflows int "
			"or it is negative "
			"or have two plus signs\n");
	else if (error_code == ARGS_NUM_ERROR)
		printf("Wrong number of arguments\n");
	return (1);
}
