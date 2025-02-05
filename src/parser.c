/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paser.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaudin <mgaudin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 11:43:46 by mgaudin           #+#    #+#             */
/*   Updated: 2025/02/05 18:57:23 by mgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	show_helper(void)
{
	printf("Program should be launched as follow : \n\n");
	printf("number_of_philosophers time_to_die time_to_eat ");
	printf("time_to_sleep [number_of_times_each_philosopher_must_eat]");
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

void    parser(int argc, char **argv)
{
	if (argc != 4 || argc != 5)
		show_helper();
	if (!valid_value(argv[1]))
		show_helper();
	else if (!valid_value(argv[2]))
		show_helper();
	else if (!valid_value(argv[3]))
		show_helper();
	else if (!valid_value(argv[4]))
		show_helper();
	if (argc == 5)
	{
		if (!valid_value(argv[5]))
			show_helper();
	}
}
