/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:38:43 by mgaudin           #+#    #+#             */
/*   Updated: 2025/02/18 15:24:16 by mgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

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
			free(env->forks);
			return (false);
		}
		i++;
	}
	if (!init_env_mutex_suit(env, i))
	{
		free(env->forks);
		return (false);
	}
	return (true);
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
	if (!(*env)->forks)
	{
		free(*env);
		return (false);
	}
	if (!init_env_mutex(*env))
	{
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
