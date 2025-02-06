/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:38:43 by mgaudin           #+#    #+#             */
/*   Updated: 2025/02/06 17:21:42 by mgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static long	ft_atol(const char *nptr)
{
	size_t	i;
	long	res;
	int		sign;

	i = 0;
	sign = 1;
	res = 0;
	while (nptr[i] == 32 || (9 <= nptr[i] && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while ('0' <= nptr[i] && nptr[i] <= '9')
	{
		res = res * 10 + (nptr[i] - '0');
		i++;
	}
	return (res * sign);
}

static void	init_env(t_env **env, char **argv, int argc)
{
	int	i;

	*env = malloc(sizeof(t_env)); // to protect
	(*env)->nb_philo = ft_atol(argv[1]);
	(*env)->die_time = ft_atol(argv[2]);
	(*env)->eat_time = ft_atol(argv[3]);
	(*env)->sleep_time = ft_atol(argv[4]);
	if (argc == 6)
		(*env)->nb_meals = ft_atol(argv[5]);
	else
		(*env)->nb_meals = -1;
	(*env)->forks = malloc(sizeof(pthread_mtx) * (*env)->nb_philo); // protect
	i = 0;
	while (i < (*env)->nb_philo)
	{
		pthread_mutex_init(&(*env)->forks[i], NULL);
		i++;
	}
}

static void	init_philos(t_env *env)
{
	t_philo	*philos;
	int		i;

	env->philos = malloc(sizeof(t_philo) * env->nb_philo); // protect
	philos = env->philos;
	i = 0;
	while (i < env->nb_philo)
	{
		philos[i].id = i + 1;
		philos[i].meals_eaten = 0;
		philos[i].elapsed_time = 0;
		philos[i].r_fork = &env->forks[i];
		philos[i].l_fork = &env->forks[philos[i].id % env->nb_philo];
		philos[i].env = env;
		i++;
	}
}

void	init_data(t_env **env, char **argv, int argc)
{
	init_env(env, argv, argc);
	init_philos(*env);
}
