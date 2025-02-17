/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 11:43:46 by mgaudin           #+#    #+#             */
/*   Updated: 2025/02/17 11:31:31 by mgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	show_helper(bool *is_error)
{
	if (*is_error == false)
	{
		write(2, "Program should be launched as follow : \n\n", 42);
    	write(2, "./philo number_of_philosophers time_to_die time_to_eat ", 55);
    	write(2, "time_to_sleep [number_of_times_each_philosopher_must_eat]\n", 59);
		*is_error = true;
	}
}

static bool	valid_value(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!('0' <= str[i] && str[i] <= '9'))
			return (false);
		i++;
	}
	return (true);
}

bool    parse_data(int argc, char **argv)
{
	bool	is_error;

	is_error = false;
	if (argc != 5 && argc != 6)
	{
		show_helper(&is_error);
		return (true);
	}
	if (!valid_value(argv[1]))
		show_helper(&is_error);
	else if (!valid_value(argv[2]))
		show_helper(&is_error);
	else if (!valid_value(argv[3]))
		show_helper(&is_error);
	else if (!valid_value(argv[4]))
		show_helper(&is_error);
	if (argc == 6)
	{
		if (!valid_value(argv[5]))
			show_helper(&is_error);
	}
	return (is_error);
}
