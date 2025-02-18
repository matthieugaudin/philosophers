/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 19:38:30 by mgaudin           #+#    #+#             */
/*   Updated: 2025/02/18 15:23:51 by mgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	free_mutexes(t_env *env, int i, int status)
{
	while (--i >= 0)
		pthread_mutex_destroy(&env->forks[i]);
	if (status >= 1)
		pthread_mutex_destroy(&env->print_mtx);
	if (status >= 2)
		pthread_mutex_destroy(&env->is_over_mtx);
	if (status >= 3)
		pthread_mutex_destroy(&env->meals_eaten_mtx);
}

void	free_data(t_env *env)
{
	int	i;

	i = 0;
	while (i < env->nb_philo)
	{
		pthread_mutex_destroy(&env->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&env->print_mtx);
	pthread_mutex_destroy(&env->is_over_mtx);
	pthread_mutex_destroy(&env->last_meal_mtx);
	pthread_mutex_destroy(&env->meals_eaten_mtx);
	free(env->forks);
	if (env->philos)
		free(env->philos);
	free(env);
}
