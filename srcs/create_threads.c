/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <apitoise@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 14:56:33 by apitoise          #+#    #+#             */
/*   Updated: 2021/06/24 13:18:33 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

static void	*philo_routine(void *arg)
{
	t_struct	*st;
	t_philo		this;
	int			ret;
	int			i;

	st = (t_struct *)arg;
	i = st->id;
	this = st->philo[i];
	this.last_eat = get_time() - st->start;
	this.death = this.last_eat + st->data.die_time;
	ret = routine(this.id, st, this.death, 0);
	while (!st->end)
	{
		ret = routine(this.id, st, this.death, 1);
		if (ret == 1)
		{
			st->end = 1;
			display_message(this.id, "died", st);
		}
	}
	return (NULL);
}

void	create_threads(t_struct *st)
{
	int	i;

	i = 0;
	st->end = 0;
	st->start = get_time();
	while (i < st->data.philo_nb)
	{
		st->id = i;
		pthread_create(&st->philo[i].thread, NULL, philo_routine, st);
		pthread_detach(st->philo[i].thread);
		usleep(10);
		i++;
	}
	while (!st->end)
	{
		i++;
	}
}
