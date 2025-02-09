/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaudin <mgaudin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:06:12 by mgaudin           #+#    #+#             */
/*   Updated: 2025/02/09 20:28:03 by mgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	exit_philo(t_philo *philo, int philo_id)
{
	int	i;

	i = 0;
	while (i < philo->env->nb_philo)
	{
		philo[i].is_over = true;
		i++;
	}
	if (philo_id != -1)
		philo->env->death_flag = philo_id;
}

static void	*monitor(void *arg)
{
	t_philo *philo;
	int		i;
	
	philo = (t_philo *)arg;
	while (!philo->env->death_flag)
	{
		i = 0;
		while (i < philo->env->nb_philo)
		{
			if (philo[i].meals_eaten != philo->env->nb_meals)
				break ;
			i++;
		}
		if (i == philo->env->nb_philo - 1)
			exit_philo(philo, -1);
		i = 0;
		while (i < philo->env->nb_philo && !philo->env->death_flag)
		{
			if (philo->env->die_time < philo[i].last_meal_time - philo->env->start_time)
				exit_philo(philo, philo[i].id);
			i++;
		}
	}
	return (NULL);
}

void	launch_philo(t_philo *philos)
{
	int	i;

	i = 0;
	while (i < philos->env->nb_philo)
	{
		pthread_create(&philos[i].th, NULL, &routine, &philos[i]);
		i++;
	}
	pthread_create(&philos->env->monitor, NULL, &monitor, philos);
	i = 0;
	while (i < philos->env->nb_philo)
	{
		pthread_join(philos[i].th, NULL);
		i++;
	}
	pthread_join(philos->env->monitor, NULL);
	if (philos->env->death_flag != -1)
		printf("%ld %ld died", get_eleapsed_time(philos), philos->env->death_flag);
}
