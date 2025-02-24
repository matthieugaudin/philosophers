/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_meals.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 18:17:33 by mgaudin           #+#    #+#             */
/*   Updated: 2025/02/18 15:29:59 by mgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*check_meals(void *arg)
{
	t_philo	*philo;
	long	meals_eaten;
	int		i;

	philo = (t_philo *)arg;
	while (!get_is_finish(philo->env))
	{
		i = 0;
		while (i < philo->env->nb_philo)
		{
			meals_eaten = get_meals_eaten(&philo[i]);
			if (meals_eaten != philo->env->nb_meals)
				break ;
			i++;
		}
		if (i == philo->env->nb_philo)
		{
			set_is_over(philo->env, true);
			return (NULL);
		}
		usleep(5000);
	}
	return (NULL);
}
