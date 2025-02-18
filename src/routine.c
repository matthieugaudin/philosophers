/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 19:51:59 by mgaudin           #+#    #+#             */
/*   Updated: 2025/02/18 15:38:34 by mgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	is_eating(t_philo *philo)
{
	if (philo->id % 2)
		pthread_mutex_lock(philo->l_fork);
	else
		pthread_mutex_lock(philo->r_fork);
	print_state(philo, FORK);
	if (philo->id % 2)
		pthread_mutex_lock(philo->r_fork);
	else
		pthread_mutex_lock(philo->l_fork);
	print_state(philo, FORK);
	print_state(philo, EAT);
	usleep(philo->env->eat_time * 1000);
	set_last_meal(philo);
	set_meals_eaten(philo);
	if (philo->id % 2)
	{
		pthread_mutex_unlock(philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);
	}
	else
	{
		pthread_mutex_unlock(philo->r_fork);
		pthread_mutex_unlock(philo->l_fork);
	}
}

static void	is_sleeping(t_philo *philo)
{
	print_state(philo, SLEEP);
	usleep(philo->env->sleep_time * 1000);
}

static void	is_thinking(t_philo *philo)
{
	long long	think_time;

	think_time = philo->env->eat_time * 2 - philo->env->sleep_time;
	print_state(philo, THINK);
	if (philo->env->nb_philo % 2 && think_time > 0)
		usleep(think_time * 0.8 * 1000);
}

static void	handle_one(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	print_state(philo, FORK);
	pthread_mutex_unlock(philo->r_fork);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		usleep(500);
	if (philo->env->nb_philo == 1)
	{
		handle_one(philo);
		return (NULL);
	}
	while (true)
	{
		if (get_is_finish(philo->env))
			break ;
		is_eating(philo);
		if (get_is_finish(philo->env))
			break ;
		is_sleeping(philo);
		if (get_is_finish(philo->env))
			break ;
		is_thinking(philo);
	}
	return (NULL);
}
