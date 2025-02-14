/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 10:29:20 by mgaudin           #+#    #+#             */
/*   Updated: 2025/02/14 09:21:53 by mgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	monitor(t_philo *philo)
{
	// int	i;

	// while (!is_finish(philo->env))
	// {
	// 	i = 0;
	// 	while (i < philo->env->nb_meals)
	// 	{
	// 		if (philo[i].last_meal - philo->env->start_time > philo->env->die_time)
	// 		{
	// 			pthread_mutex_lock(&);
	// 		}
	// 		i++;
	// 	}		
	// }
	usleep(350000);
	set_is_over(philo->env, true);
}
