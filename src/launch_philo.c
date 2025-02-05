/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaudin <mgaudin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:06:12 by mgaudin           #+#    #+#             */
/*   Updated: 2025/02/05 20:31:19 by mgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

// static bool	is_over(t_philo *philo)
// {
// 	int	i;

// 	i = 0;
// 	while (i < philo[i].nb_philo)
// 	{
// 		if (philo[i].elapsed_time >= philo[i].die_time)
// 			return (true);
// 		i++;
// 	}
// 	i = 0;
// 	if (philo[i].meals_to_eat != -1)
// 	{
// 		while (i < philo[i].nb_philo)
// 		{
// 			if (philo[i].meals_eaten != philo[i].meals_to_eat)
// 				break ;
// 			i++;
// 		}
// 	}
// 	if (i == philo[i].nb_philo - 1)
// 		return (true);
// 	return (false);
// }

// static void	*routine(void *arg)
// {
// 	t_philo *philo;

// 	philo = (t_philo *)arg;
// 	while (!is_over(philo))
// 	{
// 		// algo to resolve deadlock and starvation
// 		// eat
// 		// sleep
// 		// think (do nothing and wait)
// 	}
// 	return (NULL);
// }

// void	launch_philo(t_philo *philo)
// {
// 	int	i;

// 	i = 0;
// 	while (i < philo->nb_philo)
// 	{
// 		pthread_create(&philo[i].th, NULL, &routine, philo);
// 		i++;
// 	}
// 	i = 0;
// 	while (i < philo->nb_philo)
// 	{
// 		pthread_join(philo[i].th, NULL);
// 		i++;
// 	}
// }
