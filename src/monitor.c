/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 10:29:20 by mgaudin           #+#    #+#             */
/*   Updated: 2025/02/14 15:35:58 by mgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static bool	is_philo_dead(t_philo *philo)
{
	long long	last_meal;
	long long	die_time;
	long long	current;

	last_meal = get_last_meal(philo);
	current = current_time();
	die_time = philo->env->die_time;
	if (current - last_meal > die_time && last_meal != 0)
		return (true);
	else
		return (false);
}

void	monitor(t_philo *philo)
{
	int	i;

	while (!get_is_finish(philo->env))
	{
		i = 0;
		while (i < philo->env->nb_philo)
		{
			if (is_philo_dead(&philo[i]))
			{
				print_state(&philo[i], DIE);
				set_is_over(philo->env, true);
			}
			i++;
		}
		usleep(5000);
	}
}
