/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <apitoise@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 14:56:33 by apitoise          #+#    #+#             */
/*   Updated: 2021/06/28 17:01:14 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

static void init_death(t_philo *philo, unsigned long die_time)
{
	philo->death = philo->last_eat + die_time;
}

static void	*philo_routine(void *arg)
{
	t_struct	*st;
	t_philo		this;
	int			ret;

	st = (t_struct *)arg;
	this = st->philo;
	this.last_eat = get_time() - st->start;
	init_death(&st->philo, st->data.die_time);
	while (!st->end)
	{
		ret = routine(st);
		if (ret == 1)
		{
			printf("OK\n");
			st->end = 1;
			display_message(this.id, "died", st);
		}
//		if (st->data.eat_max && this.eat == st->data.eat_max)
//		{
//			st->end = 1;
//			display_message(this.id, "max eat reached", st);
//		}
	}
	return (NULL);
}

void	create_threads(t_struct *st, t_philo *philo)
{
	int	i;

	i = 0;
	st->end = 0;
	st->start = get_time();
	while (i < st->data.philo_nb)
	{
		st->philo = philo[i];
		pthread_create(&st->philo.thread, NULL, philo_routine, st);
		pthread_detach(st->philo.thread);
		usleep(10000);
		i++;
	}
}
