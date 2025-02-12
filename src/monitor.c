/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 10:29:20 by mgaudin           #+#    #+#             */
/*   Updated: 2025/02/12 10:49:50 by mgaudin          ###   ########.fr       */
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
	usleep(3010000);
	pthread_mutex_lock(&philo->env->is_over_mtx);
	philo->env->is_over = true;
	pthread_mutex_unlock(&philo->env->is_over_mtx);
}
