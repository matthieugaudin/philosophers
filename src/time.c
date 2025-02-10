/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 17:28:31 by mgaudin           #+#    #+#             */
/*   Updated: 2025/02/10 10:02:29 by mgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

long long	get_start_time(void)
{
	struct timeval	time;
	long long		res;

	gettimeofday(&time, NULL);
	res = ((time.tv_sec * 1000) + (time.tv_usec / 1000));
	return (res);
}

long long	get_eleapsed_time(t_philo *philo)
{
	struct timeval	time;
	long long		actual_time;
	long long		res;

	gettimeofday(&time, NULL);
	actual_time = (time.tv_sec * 1000 + time.tv_usec / 1000);
	res = actual_time - philo->env->start_time;
	return (res);
}
