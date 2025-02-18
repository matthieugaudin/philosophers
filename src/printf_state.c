/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_state.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 15:38:41 by mgaudin           #+#    #+#             */
/*   Updated: 2025/02/18 15:39:02 by mgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	print_state(t_philo *philo, int state)
{
	pthread_mutex_lock(&philo->env->print_mtx);
	if (state == EAT && !get_is_finish(philo->env))
		printf("%lld %ld is eating\n", elapsed_time(philo), philo->id);
	else if (state == SLEEP && !get_is_finish(philo->env))
		printf("%lld %ld is sleeping\n", elapsed_time(philo), philo->id);
	else if (state == THINK && !get_is_finish(philo->env))
		printf("%lld %ld is thinking\n", elapsed_time(philo), philo->id);
	else if (state == FORK && !get_is_finish(philo->env))
		printf("%lld %ld has taken a fork\n", elapsed_time(philo), philo->id);
	else if (state == DIE && !get_is_finish(philo->env))
		printf("%lld %ld died\n", elapsed_time(philo), philo->id);
	pthread_mutex_unlock(&philo->env->print_mtx);
}
