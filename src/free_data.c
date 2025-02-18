/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 19:38:30 by mgaudin           #+#    #+#             */
/*   Updated: 2025/02/18 10:13:42 by mgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

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
