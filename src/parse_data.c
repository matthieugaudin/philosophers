/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 11:43:46 by mgaudin           #+#    #+#             */
/*   Updated: 2025/02/17 12:44:31 by mgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	show_helper(void)
{
		write(2, "Program should be launched as follow : \n\n", 42);
    	write(2, "./philo number_of_philosophers time_to_die time_to_eat ", 55);
    	write(2, "time_to_sleep [number_of_times_each_philosopher_must_eat]\n", 59);
}

static bool	check_num(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		if (ft_atol(argv[i]) == 0)
			return (false);
		while (argv[i][j])
		{
			if (!('0' <= argv[i][j] && argv[i][j] <= '9')
				&& !(argv[i][j] == '+' && j == 0 && argv[i][j + 1]))
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

static bool	check_overflow(int argc, char **argv)
{
	long	i;
	long	j;
	long	res;

	i = 1;
	res = 0;
	while (i < argc)
	{
		j = 0;
		if (argv[i][j] == '+')
			j++;
		while (argv[i][j])
		{
			res = res * 10 + (argv[i][j] - '0');
			if (res > 2147483647)
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

bool    parse_data(int argc, char **argv)
{
	if (argc != 5 && argc != 6)
	{
		show_helper();
		return (false);
	}
	else if (!check_num(argc, argv))
	{
		write(2, "Parameters should be non-zero positive numbers\n", 48);
		return (false);
	}
	else if (!check_overflow(argc, argv))
	{
		write(2, "Parameters should not exceed INT_MAX\n", 38);
		return (false);
	}
	else if (ft_atol(argv[1]) > 200)
	{
		write(2, "number_of_philosophers maximum value is 200\n", 45);
		return (false);
	}
	return (true);
}
