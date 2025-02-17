/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 09:03:06 by mgaudin           #+#    #+#             */
/*   Updated: 2025/02/17 11:49:49 by mgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int main(int argc, char **argv)
{
    t_env   *env;

    if (!parse_data(argc, argv))
        return (1);
    init_data(&env, argv, argc);
	launch_philo(env->philos);
    free_data(env);
    return (0);
}
