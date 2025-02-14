/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:38:43 by mgaudin           #+#    #+#             */
/*   Updated: 2025/02/14 13:39:33 by mgaudin          ###   ########.fr       */
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

	*env = malloc(sizeof(t_env));
	(*env)->nb_philo = ft_atol(argv[1]);
	(*env)->die_time = ft_atol(argv[2]);
	(*env)->eat_time = ft_atol(argv[3]);
	(*env)->sleep_time = ft_atol(argv[4]);
	(*env)->start_time = current_time();
	if (argc == 6)
		(*env)->nb_meals = ft_atol(argv[5]);
	else
		(*env)->nb_meals = -1;
	(*env)->is_over = false;
	(*env)->forks = malloc(sizeof(pthread_mutex_t) * (*env)->nb_philo);
	i = 0;
	while (i < (*env)->nb_philo)
	{
		pthread_mutex_init(&(*env)->forks[i], NULL);
		i++;
	}
	pthread_mutex_init(&(*env)->print_mtx, NULL);
	pthread_mutex_init(&(*env)->is_over_mtx, NULL);
	pthread_mutex_init(&(*env)->last_meal_mtx, NULL);
	pthread_mutex_init(&(*env)->meals_eaten_mtx, NULL);
}

static void	init_philos(t_env *env)
{
	t_philo	*philo;
	int		i;

	env->philos = malloc(sizeof(t_philo) * env->nb_philo);
	philo = env->philos;
	i = 0;
	while (i < env->nb_philo)
	{
		philo[i].id = i + 1;
		philo[i].meals_eaten = 0;
		philo[i].last_meal = 0;
		philo[i].r_fork = &env->forks[i];
		philo[i].l_fork = &env->forks[philo[i].id % env->nb_philo];
		philo[i].env = env;
		i++;
	}
}

void	init_data(t_env **env, char **argv, int argc)
{
	init_env(env, argv, argc);
	init_philos(*env);
	// printf("nb_philos : %ld\n", (*env)->nb_philo);
	// printf("die_time : %lld\n", (*env)->die_time);
	// printf("eat_time : %lld\n", (*env)->eat_time);
	// printf("sleep_time : %lld\n", (*env)->sleep_time);
	// printf("start_time : %lld\n", (*env)->start_time);
	// printf("nb_meals : %ld\n", (*env)->nb_meals);
}
