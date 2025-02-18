/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 09:03:06 by mgaudin           #+#    #+#             */
/*   Updated: 2025/02/18 10:27:24 by mgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int main(int argc, char **argv)
{
    t_env   *env;

    if (!parse_data(argc, argv))
        return (1);
    if (!init_data(&env, argv, argc))
        return (1);
	if (!launch_philo(env->philos))
        return (1);
    free_data(env);
    return (0);
}
