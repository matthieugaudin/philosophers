/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 10:41:37 by mgaudin           #+#    #+#             */
/*   Updated: 2025/02/13 16:09:25 by mgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void    set_is_over(t_env *env, bool is_over)
{
	pthread_mutex_lock(&env->is_over_mtx);
	env->is_over = is_over;
	pthread_mutex_unlock(&env->is_over_mtx);
}

void	set_last_meal(t_philo *philo)
{
	pthread_mutex_lock(&philo->env->last_meal_mtx);
	philo->last_meal = current_time(philo);
	pthread_mutex_unlock(&philo->env->last_meal_mtx);
}

void	set_meals_eaten(t_philo *philo)
{
	pthread_mutex_lock(&philo->env->meals_eaten_mtx);
	philo->meals_eaten += 1;
	pthread_mutex_unlock(&philo->env->meals_eaten_mtx);
}
