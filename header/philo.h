/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <apitoise@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 12:07:55 by apitoise          #+#    #+#             */
/*   Updated: 2021/06/22 21:43:45 by apitoise         ###   ########.fr       */
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
	int	philo_nb;
	int	eat_time;
	int	die_time;
	int	sleep_time;
	int	eat_max;
	int	count;
}				t_data;

typedef struct s_philo
{
	int				id;
	int				eat;
	int				sleep;
	int				think;
	int				rfork;
	int				lfork;
	unsigned long	last_eat;
	unsigned long	death;
	pthread_t		thread;
}				t_philo;

typedef struct s_struct
{
	t_data			data;
	t_philo			*philo;
	pthread_mutex_t	mutex;
	pthread_mutex_t	*forks;
	int		id;
}				t_struct;

int				ft_error(char *str);
void			init_data(char **av, t_struct *st);
void			init_philo(t_struct *st);
void			init_mutex(t_struct *st);
int				ft_atoi(const char *str);
int				ft_strcmp(const char *s1, const char *s2);
void			create_threads(t_struct *st);
unsigned long	get_time(void);

#endif