/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 08:48:59 by mgaudin           #+#    #+#             */
/*   Updated: 2025/02/07 16:27:28 by mgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define pthread_mutex_t pthread_mtx
# include <stdio.h>
# include <stdbool.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/types.h>
# include <sys/time.h>

typedef struct s_philo
{
    long			id;
    long    		meals_eaten;
    long    		elapsed_time;
	pthread_t		th;
    pthread_mtx		*r_fork;
    pthread_mtx		*l_fork;
    struct s_env	*env;
}   t_philo;

typedef struct s_env
{
    long		nb_philo;
    long		die_time;
	long		eat_time;
    long		sleep_time;
	long		nb_meals;
    int         start_time; // to init
	pthread_mtx	*forks;
	t_philo		*philos;
}   t_env;

bool    parser(int argc, char **argv);
void	init_data(t_env **env, char **argv, int argc);
void	launch_philo(t_philo *philos);

#endif /* PHILO_H */