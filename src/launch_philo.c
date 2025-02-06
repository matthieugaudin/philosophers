/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:06:12 by mgaudin           #+#    #+#             */
/*   Updated: 2025/02/06 19:03:51 by mgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static bool	is_over(t_philo *philo)
{
	int     i;
    t_env   *env;

	i = 0;
    env = philo->env;
	while (i < env->nb_philo)
	{
		if (philo[i].elapsed_time >= env->die_time)
			return (true);
		i++;
	}
	i = 0;
	if (env->nb_meals != -1)
	{
		while (i < env->nb_philo)
		{
			if (philo[i].meals_eaten != env->nb_meals)
				break ;
			i++;
		}
	}
	if (i == env->nb_philo - 1)
		return (true);
	return (false);
}

static void	*routine(void *arg)
{
	t_philo *philos;

	philos = (t_philo *)arg;
	while (!is_over(philos))
	{
		// algo to resolve deadlock and starvation
		// eat
		// sleep
		// think (do nothing and wait)
	}
	return (NULL);
}

void	launch_philo(t_philo *philos)
{
	int	i;

	i = 0;
	while (i < philos->env->nb_philo)
	{
		pthread_create(&philos[i].th, NULL, &routine, philos);
		i++;
	}
	i = 0;
	while (i < philos->env->nb_philo)
	{
		pthread_join(philos[i].th, NULL);
		i++;
	}
}
