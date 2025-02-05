/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaudin <mgaudin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 08:48:59 by mgaudin           #+#    #+#             */
/*   Updated: 2025/02/05 20:29:42 by mgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdbool.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/types.h>

typedef struct s_philo
{
    long			id;
	long			nb_philo;
    long    		meals_eaten;
    long    		elapsed_time;
	pthread_t		th;
    pthread_mutex_t	*r_fork;
    pthread_mutex_t	*l_fork;
}   t_philo;

typedef struct s_env
{
    long			die_time;
	long			eat_time;
    long			sleep_time;
	long			meals_to_eat;
	pthread_mutex_t	*forks;
	t_philo			*philo;
}   t_env;

void    parser(int argc, char **argv);

#endif /* PHILO_H */