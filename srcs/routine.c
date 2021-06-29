/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <apitoise@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 10:42:51 by apitoise          #+#    #+#             */
/*   Updated: 2021/06/29 15:59:14 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

static int	is_sleeping(t_philo *this)
{
	display_message(this, "is sleeping");
	usleep(this->st->data.sleep_time);
	display_message(this, "is thinking");
	return (0);
}

static int	eat(t_philo *this)
{
	display_message(this, "is eating");
	usleep(this->st->data.eat_time);
	this->eat++;
	this->last_eat = get_time() - this->st->start;
	this->death = this->last_eat + this->st->data.die_time;
	pthread_mutex_unlock(&this->st->forks[this->rfork]);
	pthread_mutex_unlock(&this->st->forks[this->lfork]);
	return (0);
}

static void	take_forks(t_philo *this)
{
	pthread_mutex_lock(&this->st->forks[this->lfork]);
	display_message(this, "has taken a fork");
	pthread_mutex_lock(&this->st->forks[this->rfork]);
	display_message(this, "has taken a fork");
}

void	routine(t_philo *this)
{
		take_forks(this);
		eat(this);
		is_sleeping(this);
}
