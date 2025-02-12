/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 10:32:58 by mgaudin           #+#    #+#             */
/*   Updated: 2025/02/12 10:41:19 by mgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

bool	is_finish(t_env *env)
{
	bool	res;

	pthread_mutex_lock(&env->is_over_mtx);
	res = env->is_over;
	pthread_mutex_unlock(&env->is_over_mtx);
	return (res);
}
