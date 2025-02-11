/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaudin <mgaudin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 09:03:06 by mgaudin           #+#    #+#             */
/*   Updated: 2025/02/11 12:16:08 by mgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int main(int argc, char **argv)
{
    t_env   *env;

    if (parser(argc, argv))
        return (1);
    init_data(&env, argv, argc);
	launch_philo(env->philos);
    return (0);
}
