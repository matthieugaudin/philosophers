/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 08:48:59 by mgaudin           #+#    #+#             */
/*   Updated: 2025/02/10 15:55:02 by mgaudin          ###   ########.fr       */
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
    long long  		last_meal_time; // can change
    long			id;
    long    		meals_eaten; // can change
    bool            is_over;
	pthread_t		th;
    pthread_mtx		*r_fork;
    pthread_mtx		*l_fork;
    struct s_env	*env;
}   t_philo;

typedef struct s_env
{
    long		    nb_philo;
    long long		die_time;
	long long		eat_time;
    long long		sleep_time;
	long		    nb_meals;
    long long       start_time;
    long            death_flag; // can change
    pthread_t       monitor;
    pthread_mtx     over_mutex;
    pthread_mtx     print_mutex;
	pthread_mtx	    *forks;
	t_philo		    *philos;
}   t_env;

bool    parser(int argc, char **argv);
void	init_data(t_env **env, char **argv, int argc);
void	launch_philo(t_philo *philos);
long long	get_start_time(void);
long long	get_eleapsed_time(t_philo *philo);
void	*routine(void *arg);

#endif /* PHILO_H */