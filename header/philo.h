/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <apitoise@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 12:07:55 by apitoise          #+#    #+#             */
/*   Updated: 2021/06/30 16:41:32 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_data
{
	int				philo_nb;
	unsigned long	eat_time;
	unsigned long	die_time;
	unsigned long	sleep_time;
	int				eat_max;
}				t_data;

typedef struct s_struct
{
	unsigned long	start;
	int				*state;
	int				*last_owner;
	int				all_eat_max_reached;
	t_data			data;
	int				starter;
	pthread_mutex_t	print;
	pthread_mutex_t	*forks;
	int				philo_dead;
}				t_struct;

typedef struct s_philo
{
	int				id;
	int				eat;
	int				eat_max_reached;
	int				rfork;
	int				lfork;
	unsigned long	last_eat;
	unsigned long	death;
	pthread_t		thread;
	t_struct		*st;
}				t_philo;

int				ft_error(char *str);
void			init_data(char **av, t_data *data);
void			init_philo(t_philo *philo, int philo_nb, t_struct *st);
void			init_st(t_struct *st, char **args);
int				ft_atoi(const char *str);
int				ft_strcmp(const char *s1, const char *s2);
void			create_threads(t_struct *st, t_philo *philo);
unsigned long	get_time(void);
void			routine(t_philo *this);
void			display_message(t_philo *this, char *str);
void			ft_exit(t_struct *st, t_philo *philo);

#endif
