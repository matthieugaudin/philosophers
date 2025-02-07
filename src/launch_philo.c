/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:06:12 by mgaudin           #+#    #+#             */
/*   Updated: 2025/02/07 17:08:18 by mgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

/*
- verify that no philo died (maybe not here)
- verify that all philos have eaten
*/
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

static void	is_thinking(t_philo *philo)
{
	printf("%d %d is thinking\n", 1, philo->id);
}

static void	is_sleeping(t_philo *philo)
{
	printf("%d %d is sleeping\n", 1, philo->id);
	usleep(philo->env->sleep_time * 1000);
	philo->elapsed_time += philo->env->sleep_time;
}

static void	is_eating(t_philo *philo)
{
	if (philo->id % 2)
		pthread_mutex_lock(&philo->l_fork);
	else
		pthread_mutex_lock(&philo->r_fork);
	printf("%d %d has taken a fork\n", 1, philo->id);
	if (philo->id % 2)
		pthread_mutex_lock(&philo->r_fork);
	else
		pthread_mutex_lock(&philo->l_fork);
	printf("%d %d has taken a fork\n", 1, philo->id);
	printf("%d %d is eating\n", 1, philo->id);
	usleep(philo->env->eat_time * 1000);
	philo->elapsed_time += philo->env->eat_time;
	if (philo->id % 2)
	{
		pthread_mutex_unlock(&philo->l_fork);
		pthread_mutex_unlock(&philo->r_fork);
	}
	else
	{
		pthread_mutex_unlock(&philo->r_fork);
		pthread_mutex_unlock(&philo->l_fork);
	}
}
static void	*routine(void *arg)
{
	t_philo *philo;
	

	philo = (t_philo *)arg;
	while (!is_over(philo))
	{
		is_eating(philo);
		is_sleeping(philo);
		is_thinking(philo);
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
	i = 0;
	while (i < philos->env->nb_philo)
	{
		pthread_join(philos[i].th, NULL);
		i++;
	}
}
