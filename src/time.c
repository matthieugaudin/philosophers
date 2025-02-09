/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaudin <mgaudin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 17:28:31 by mgaudin           #+#    #+#             */
/*   Updated: 2025/02/09 20:30:01 by mgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

long	get_start_time(void)
{
	struct timeval	time;
	int				res;

	gettimeofday(&time, NULL);
	res = (time.tv_sec * 1000 + time.tv_usec / 1000);
	return (res);
}

long	get_current_time(t_philo *philo)
{
	struct timeval	time;
	long			actual_time;
	long			res;

	gettimeofday(&time, NULL);
	actual_time = (time.tv_sec * 1000 + time.tv_usec / 1000);
	res = actual_time - philo->env->start_time;
	return (res);
}

long	get_eleapsed_time(t_philo *philo)
{
	long	start;
	long	current;

	start = get_start_time();
	current = get_current_time(philo);
	return (current - start);
}
