/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <apitoise@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 12:07:55 by apitoise          #+#    #+#             */
/*   Updated: 2021/06/22 16:19:30 by apitoise         ###   ########.fr       */
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
	t_data			data;
	pthread_t		thread;
}				t_philo;

int				ft_error(char *str);
void			init_data(char **av, t_philo *philo);
void			init_philo(t_philo *philo);
int				ft_atoi(const char *str);
int				ft_strcmp(const char *s1, const char *s2);
void			create_threads(t_philo *philo);

#endif
