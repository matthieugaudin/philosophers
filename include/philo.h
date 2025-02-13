/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaudin <mgaudin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 08:48:59 by mgaudin           #+#    #+#             */
/*   Updated: 2025/02/14 18:33:20 by mgaudin          ###   ########.fr       */
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
# include <sys/time.h>

enum e_status {
    SLEEP,
	EAT,
	THINK,
	DIE,
	FORK
};

typedef struct s_philo
{
    long long 			last_meal;
    long    			meals_eaten;
    long				id;
	pthread_t			th;
    pthread_mutex_t		*r_fork;
    pthread_mutex_t		*l_fork;
    struct s_env		*env;
}   t_philo;

typedef struct s_env
{
    long long		die_time;
	long long		eat_time;
    long long		sleep_time;
    long long  		start_time;
    long			nb_philo;
	long			nb_meals;
    bool      	  	is_over;
    pthread_t       meals_th;
    pthread_mutex_t is_over_mtx;
    pthread_mutex_t last_meal_mtx;
    pthread_mutex_t meals_eaten_mtx;
    pthread_mutex_t print_mtx;
	pthread_mutex_t	*forks;
	t_philo			*philos;
}   t_env;


bool        parser(int argc, char **argv);
void	    init_data(t_env **env, char **argv, int argc);
void	    launch_philo(t_philo *philos);
void	    *routine(void *arg);
long long	current_time(void);
long long	elapsed_time(t_philo *philo);
void	    monitor(t_philo *philo);
void	    set_meals_eaten(t_philo *philo);
void	    set_last_meal(t_philo *philo);
void        set_is_over(t_env *env, bool is_over);
bool	    get_is_finish(t_env *env);
long long   get_last_meal(t_philo *philo);
long	    get_meals_eaten(t_philo *philo);
void	    print_state(t_philo *philo, int state);
void        *check_meals(void *arg);

#endif /* PHILO_H */