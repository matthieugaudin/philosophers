/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 10:32:58 by mgaudin           #+#    #+#             */
/*   Updated: 2025/02/13 16:05:24 by mgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

bool	get_is_finish(t_env *env)
{
	bool	res;

	pthread_mutex_lock(&env->is_over_mtx);
	res = env->is_over;
	pthread_mutex_unlock(&env->is_over_mtx);
	return (res);
}

long long	get_last_meal(t_philo *philo)
{
	long long	res;

	pthread_mutex_lock(&philo->env->last_meal_mtx);
	res = philo->last_meal;
	pthread_mutex_unlock(&philo->env->last_meal_mtx);
	return (res);
}

long	get_meals_eaten(t_philo *philo)
{
	long	res;

	pthread_mutex_lock(&philo->env->meals_eaten_mtx);
	res = philo->meals_eaten;
	pthread_mutex_unlock(&philo->env->meals_eaten_mtx);
	return (res);
}
