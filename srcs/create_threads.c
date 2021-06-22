/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <apitoise@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 14:56:33 by apitoise          #+#    #+#             */
/*   Updated: 2021/06/22 22:32:29 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

static void	*philo_routine(void *arg)
{
	t_struct	*st;
	t_philo		this;

	st = (t_struct *)arg;
	this = st->philo[st->id];
	this.last_eat = get_time();
	this.death = this.last_eat + st->data.die_time * 1000;
	printf("%ld %d is alive\n",this.last_eat, this.id);
	eat(st);
	sleep(st);
	think(st);
	pthread_detach(this.thread);
	return NULL;
}

void	create_threads(t_struct *st)
{
	int	i;

	i = 0;
	while (i < st->data.philo_nb)
	{
		st->id = i;
		pthread_create(&st->philo[i].thread, NULL, philo_routine, st);
		usleep(8);
		i++;
	}
}
