/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <apitoise@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 10:42:51 by apitoise          #+#    #+#             */
/*   Updated: 2021/06/28 16:33:38 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

static int	is_sleeping(t_struct *st)
{
	unsigned long	time;

	display_message(st->philo.id, "is sleeping", st);
	time = get_time() - st->start;
	if (time + st->data.sleep_time > st->philo.death)
		return (1);
	usleep(st->data.sleep_time);
	return (0);
}

static int	eat(t_struct *st)
{
	unsigned long	time;

	display_message(st->philo.id, "is eating", st);
	time = get_time() - st->start;
	if (time + st->data.eat_time > st->philo.death)
		return (1);
	usleep(st->data.eat_time);
	st->philo.eat++;
	st->philo.last_eat = get_time() - st->start;
	st->philo.death = st->philo.last_eat + st->data.die_time;
	pthread_mutex_unlock(&st->forks[st->philo.rfork]);
	pthread_mutex_unlock(&st->forks[st->philo.lfork]);
	st->philo.rfork_taken = 0;
	st->philo.lfork_taken = 0;
	return (0);
}

static void	take_forks(t_struct *st)
{
	int	prev;
	int	next;

	prev = st->philo.id - 1;
	if (st->philo.id == 0)
		prev = st->data.philo_nb - 1;
	next = st->philo.id + 1;
	if (st->philo.id == st->data.philo_nb - 1)
		next = 0;
	display_message(st->philo.id, "is thinking", st);
//	printf("%d try to lock fork nb %d\n",st->philo.id, st->philo.lfork);
	pthread_mutex_lock(&st->forks[st->philo.lfork]);
//	printf("fork nb %d is locked\n", st->philo.lfork);
	st->philo.lfork_taken = 1;
	display_message(st->philo.id, "has taken a fork", st);
//	printf("%d try to lock fork nb %d\n",st->philo.id, st->philo.rfork);
	pthread_mutex_lock(&st->forks[st->philo.rfork]);
//	printf("fork nb %d is locked\n", st->philo.rfork);
	st->philo.rfork_taken = 1;
	display_message(st->philo.id, "has taken a fork", st);
}

int	routine(t_struct *st)
{
	unsigned long	time;
	int				ret;

	time = get_time() - st->start;
	if (time < st->philo.death)
		take_forks(st);
	else
		return (1);
	time = get_time() - st->start;
	if (time < st->philo.death)
	{
		ret = eat(st);
		if (ret == 1)
			return (1);
	}
	else
		return (1);
	time = get_time() - st->start;
	if (time < st->philo.death)
	{
		ret = is_sleeping(st);
		if (ret == 1)
			return (1);
	}
	else
		return (1);
	return (0);
}
