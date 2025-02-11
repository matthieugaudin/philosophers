/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaudin <mgaudin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 19:51:59 by mgaudin           #+#    #+#             */
/*   Updated: 2025/02/11 18:18:36 by mgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static bool	is_finish(t_env *env)
{
	bool	res;

	pthread_mutex_lock(&env->is_over_mtx);
	res = env->is_over;
	pthread_mutex_unlock(&env->is_over_mtx);
	return (res);
}

static void	print_state(t_philo *philo, int state)
{
	pthread_mutex_lock(&philo->env->print_mtx);
	if (state == EAT && !is_finish(philo->env))
		printf("%lld %ld is eating\n", current_time(philo), philo->id);
	else if (state == SLEEP && !is_finish(philo->env))
		printf("%lld %ld is sleeping\n", current_time(philo), philo->id);
	else if (state == THINK && !is_finish(philo->env))
		printf("%lld %ld is thinking\n", current_time(philo), philo->id);
	else if (state == FORK && !is_finish(philo->env))
		printf("%lld %ld has taken a fork\n", current_time(philo), philo->id);
	else if (state == DIE && !is_finish(philo->env))
		printf("%lld %ld died\n", current_time(philo), philo->id);
	pthread_mutex_unlock(&philo->env->print_mtx);
}

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
	print_state(philo, THINK);
	if (philo->env->nb_philo % 2)
		usleep((philo->env->eat_time * 2 - philo->env->sleep_time));
}

void	*routine(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	if (philo->env->nb_philo % 2)
		usleep((philo->env->eat_time * 2 - philo->env->sleep_time));
	while (true)
	{
		if (is_finish(philo->env))
			break ;
		is_eating(philo);
		if (is_finish(philo->env))
			break ;
		is_sleeping(philo);
		if (is_finish(philo->env))
			break ;
		is_thinking(philo);
	}
	return (NULL);
}
