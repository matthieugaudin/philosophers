/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:06:12 by mgaudin           #+#    #+#             */
/*   Updated: 2025/02/18 10:37:08 by mgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	clean_up_threads(t_philo *philos, int i)
{
	set_is_over(philos->env, true);
	while (--i >= 0)
	{
		pthread_join(philos[i].th, NULL);
	}
	free_data(philos->env);
}

static void	wait_philos(t_philo *philos)
{
	int	i;

	i = 0;
	while (i < philos->env->nb_philo)
	{
		pthread_join(philos[i].th, NULL);
		i++;
	}
	pthread_join(philos->env->meals_th, NULL);
}

bool	launch_philo(t_philo *philos)
{
	int	i;

	i = 0;
	while (i < philos->env->nb_philo)
	{
		if (pthread_create(&philos[i].th, NULL, &routine, &philos[i]))
		{
			clean_up_threads(philos, i);
			return (false);
		}
		i++;
	}
	if (pthread_create(&philos->env->meals_th, NULL, &check_meals, philos))
	{
			clean_up_threads(philos, i);
			return (false);
	}
	monitor(philos);
	wait_philos(philos);
	return (true);
}
