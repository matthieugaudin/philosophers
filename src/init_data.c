/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:38:43 by mgaudin           #+#    #+#             */
/*   Updated: 2025/02/18 10:29:28 by mgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

long long	ft_atoll(const char *nptr)
{
	long long	i;
	long long	res;
	int			sign;

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

static void	free_mutexes(t_env *env, int i, int status)
{
	while (--i >= 0)
		pthread_mutex_destroy(&env->forks[i]);
	if (status >= 1)
		pthread_mutex_destroy(&env->print_mtx);
	if (status >= 2)
		pthread_mutex_destroy(&env->is_over_mtx);
	if (status >= 3)
		pthread_mutex_destroy(&env->meals_eaten_mtx)
}

static bool	init_env_mutex_suit(t_env *env, int i)
{
	if (pthread_mutex_init(&env->print_mtx, NULL))
	{
		free_mutexes(env, i, 0);
		return (false);
	}
	if (pthread_mutex_init(&env->is_over_mtx, NULL))
	{
			free_mutexes(env, i, 1);
			return (false);
	}
	if (pthread_mutex_init(&env->last_meal_mtx, NULL))
	{
			free_mutexes(env, i, 2);
			return (false);
	}
	if (pthread_mutex_init(&env->meals_eaten_mtx, NULL))
	{
			free_mutexes(env, i, 3);
			return (false);
	}
	return (true);
}

static bool	init_env_mutex(t_env *env)
{
	int	i;

	i = 0;
	while (i < env->nb_philo)
	{
		if (pthread_mutex_init(&env->forks[i], NULL))
		{
			free_mutexes(env, i, 0);
			return (false);
		}
		i++;
	}
	if (!init_env_mutex_suit(env, i))
		return (false);
}

static bool	init_env(t_env **env, char **argv, int argc)
{
	*env = malloc(sizeof(t_env));
	if (!*env)
		return (false);
	(*env)->nb_philo = ft_atoll(argv[1]);
	(*env)->die_time = ft_atoll(argv[2]);
	(*env)->eat_time = ft_atoll(argv[3]);
	(*env)->sleep_time = ft_atoll(argv[4]);
	(*env)->start_time = current_time();
	if (argc == 6)
		(*env)->nb_meals = ft_atoll(argv[5]);
	else
		(*env)->nb_meals = -1;
	(*env)->is_over = false;
	(*env)->forks = malloc(sizeof(pthread_mutex_t) * (*env)->nb_philo);
	{
		free(*env);
		return (false);
	}
	if (!init_env_mutex(*env))
	{
		free((*env)->forks);
		free(*env);
		return (false);
	}
	return (true);
}

static bool	init_philos(t_env *env)
{
	t_philo	*philo;
	int		i;

	env->philos = malloc(sizeof(t_philo) * env->nb_philo);
	if (!env->philos)
	{
		free_data(env);
		return (false);
	}
	philo = env->philos;
	i = 0;
	while (i < env->nb_philo)
	{
		philo[i].id = i + 1;
		philo[i].meals_eaten = 0;
		philo[i].last_meal = 0;
		philo[i].r_fork = &env->forks[i];
		if (env->nb_philo == 1)
			philo[i].l_fork = NULL;
		else
			philo[i].l_fork = &env->forks[philo[i].id % env->nb_philo];
		philo[i].env = env;
		i++;
	}
	return (true);
}

bool	init_data(t_env **env, char **argv, int argc)
{
	if (!init_env(env, argv, argc))
		return (false);
	if (!init_philos(*env))
		return (false);
	return (true);
}
