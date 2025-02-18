/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:06:12 by mgaudin           #+#    #+#             */
/*   Updated: 2025/02/18 15:36:32 by mgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static bool	is_philo_dead(t_philo *philo)
{
	long long	last_meal;
	long long	die_time;
	long long	elapsed;

	last_meal = get_last_meal(philo);
	elapsed = elapsed_time(philo);
	die_time = philo->env->die_time;
	if (elapsed - last_meal > die_time)
		return (true);
	else
		return (false);
}

static void	monitor(t_philo *philo)
{
	int	i;

	while (!get_is_finish(philo->env))
	{
		i = 0;
		while (i < philo->env->nb_philo)
		{
			if (is_philo_dead(&philo[i]))
			{
				print_state(&philo[i], DIE);
				set_is_over(philo->env, true);
			}
			i++;
		}
		usleep(5000);
	}
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

static void	clean_up_threads(t_philo *philos, int i)
{
	set_is_over(philos->env, true);
	while (--i >= 0)
	{
		pthread_join(philos[i].th, NULL);
	}
	free_data(philos->env);
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
