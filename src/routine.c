/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaudin <mgaudin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 19:51:59 by mgaudin           #+#    #+#             */
/*   Updated: 2025/02/09 20:31:35 by mgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	hanle_actions(t_philo *philo)
{
	if (!philo->is_over)
	{
		pthread_mutex_lock(&philo->env->print_mutex);
		printf("%ld %ld is eating\n", get_eleapsed_time(philo), philo->id);
		pthread_mutex_unlock(&philo->env->print_mutex);
		usleep(philo->env->eat_time * 1000);
	}
	philo->last_meal_time = get_current_time(philo);
	if (!philo->is_over)
	{
		pthread_mutex_lock(&philo->env->print_mutex);
		printf("%ld %ld is sleeping\n", get_eleapsed_time(philo), philo->id);
		pthread_mutex_unlock(&philo->env->print_mutex);
		usleep(philo->env->sleep_time * 1000);
	}
	if (!philo->is_over)
	{
		pthread_mutex_lock(&philo->env->print_mutex);
		printf("%ld %ld is thinking\n", get_eleapsed_time(philo), philo->id);
		pthread_mutex_unlock(&philo->env->print_mutex);
	}
}

static void	handle_unlocking(t_philo *philo)
{
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

static void	handle_locking(t_philo *philo)
{
	if (philo->id % 2)
		pthread_mutex_lock(philo->l_fork);
	else
		pthread_mutex_lock(philo->r_fork);
	pthread_mutex_lock(&philo->env->print_mutex);
	if (!philo->is_over)
		printf("%ld %ld has taken a fork\n", get_eleapsed_time(philo), philo->id);
	pthread_mutex_unlock(&philo->env->print_mutex);
	if (philo->id % 2)
		pthread_mutex_lock(philo->r_fork);
	else
		pthread_mutex_lock(philo->l_fork);
	pthread_mutex_lock(&philo->env->print_mutex);
	if (!philo->is_over)
		printf("%ld %ld has taken a fork\n", get_eleapsed_time(philo), philo->id);
	pthread_mutex_unlock(&philo->env->print_mutex);
}

void	*routine(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	while (!philo->is_over)
	{
		handle_locking(philo);
		hanle_actions(philo);
		handle_unlocking(philo);
	}
	return (NULL);
}
