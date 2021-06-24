/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <apitoise@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 10:42:51 by apitoise          #+#    #+#             */
/*   Updated: 2021/06/24 14:49:41 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

static int	is_sleeping(int id, t_struct *st)
{
	unsigned long	time;

	display_message(id, "is sleeping", st);
	time = get_time() - st->start;
	if (time + st->data.sleep_time > st->philo[id].death)
		return (1);
	usleep(st->data.sleep_time);
	return (0);
}

static int	eat(int id, t_struct *st)
{
	unsigned long	time;

	display_message(id, "is eating", st);
	time = get_time() - st->start;
	if (time + st->data.eat_time > st->philo[id].death)
		return (1);
	usleep(st->data.eat_time);
	st->philo[id].last_eat = get_time() - st->start;
	st->philo[id].death = st->philo[id].last_eat + st->data.die_time;
	pthread_mutex_unlock(&st->forks[st->philo[id].rfork]);
	pthread_mutex_unlock(&st->forks[st->philo[id].lfork]);
	st->philo[id].rfork_taken = 0;
	st->philo[id].lfork_taken = 0;
	return (0);
}

static void	take_forks(int id, t_struct *st)
{
	int	prev;
	int	next;

	prev = id - 1;
	if (id == 0)
		prev = st->data.philo_nb - 1;
	next = id + 1;
	if (id == st->data.philo_nb - 1)
		next = 0;
	display_message(id, "is thinking", st);
//	printf("lfork = %d; rfork = %d\n", st->philo[prev].lfork_taken, st->philo[next].rfork_taken);
	while (st->philo[prev].lfork_taken || st->philo[next].rfork_taken) ;
	pthread_mutex_lock(&st->forks[st->philo[id].lfork]);
	st->philo[id].lfork_taken = 1;
	display_message(id, "has taken a fork", st);
	pthread_mutex_lock(&st->forks[st->philo[id].rfork]);
	st->philo[id].rfork_taken = 1;
	display_message(id, "has taken a fork", st);
}

int	routine(int id, t_struct *st, unsigned long death, int first)
{
	unsigned long	time;
	int				ret;

	time = get_time() - st->start;
	if (!first)
		st->philo[id].death = death;
	if (time < st->philo[id].death)
		take_forks(id, st);
	else
		return (1);
	time = get_time() - st->start;
	if (time < st->philo[id].death)
	{
		ret = eat(id, st);
		if (ret == 1)
			return (1);
	}
	else
		return (1);
	time = get_time() - st->start;
	if (time < st->philo[id].death)
	{
		ret = is_sleeping(id, st);
		if (ret == 1)
			return (1);
	}
	else
		return (1);
	return (0);
}
