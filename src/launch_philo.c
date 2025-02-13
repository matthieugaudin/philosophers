/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaudin <mgaudin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:06:12 by mgaudin           #+#    #+#             */
/*   Updated: 2025/02/14 18:48:02 by mgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	launch_philo(t_philo *philos)
{
	int	i;

	i = 0;
	while (i < philos->env->nb_philo)
	{
		pthread_create(&philos[i].th, NULL, &routine, &philos[i]);
		i++;
	}
	pthread_create(&philos->env->meals_th, NULL, &check_meals, philos);
	monitor(philos);
	i = 0;
	while (i < philos->env->nb_philo)
	{
		pthread_join(philos[i].th, NULL);
		i++;
	}
	pthread_join(philos->env->meals_th, NULL);
}
