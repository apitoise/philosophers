/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <apitoise@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 14:56:33 by apitoise          #+#    #+#             */
/*   Updated: 2021/06/29 16:48:19 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

static int	eat_monitor(t_philo *philo, t_struct *st)
{
	int	i;

	i = 0;
	while (i < st->data.philo_nb)
	{
		if (philo[i].eat_max_reached)
			i++;
		else
			return (0);
	}
	return (1);
}

static int	monitor(t_philo *philo, t_struct *st)
{
	int				i;
	unsigned long	time;

	i = 0;
	while (i < st->data.philo_nb)
	{
		time = get_time() - st->start;
		if (st->data.eat_max == philo[i].eat)
			i++;
		else if (time > philo[i].death)
		{
			pthread_mutex_lock(&st->print);
			printf("%ld\t%d\tdie\n", time, philo[i].id);
			return (1);
		}
		else
			i++;
	}
	return (0);
}

static void init_start(t_philo *this)
{
	this->last_eat = get_time() - this->st->start;
	this->death = this->last_eat + this->st->data.die_time;
}

static void	*philo_routine(void *arg)
{
	t_philo		*this;
	int			loop;
	
	loop = 0;
	this = (t_philo *)arg;
	init_start(this);
	while (!loop)
	{
		routine(this);
		if (this->st->data.eat_max == this->eat)
		{
			this->eat_max_reached = 1;
			display_message(this, "max eat reached");
			loop = 1;
		}
	}
	return (NULL);
}

void	create_threads(t_struct *st, t_philo *philo)
{
	int	i;

	i = 0;
	while (!st->philo_dead && !st->all_eat_max_reached)
	{
		while (i < st->data.philo_nb)
		{
			pthread_create(&philo[i].thread, NULL, philo_routine, &philo[i]);
			pthread_detach(philo[i].thread);
			usleep(10000);
			i++;
		}
		st->philo_dead = monitor(philo, st);
		st->all_eat_max_reached = eat_monitor(philo, st);
	}
}
