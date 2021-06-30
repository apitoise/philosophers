/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_st.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <apitoise@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 20:48:32 by apitoise          #+#    #+#             */
/*   Updated: 2021/06/30 14:02:35 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

void	init_st(t_struct *st, char **args)
{
	int	nbr;
	int	i;

	init_data(args, &st->data);
	st->philo_dead = 0;
	st->all_eat_max_reached = 0;
	nbr = st->data.philo_nb;
	pthread_mutex_init(&st->print, NULL);
	st->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * nbr);
	st->state = (int *)malloc(sizeof(int) * nbr);
	i = 0;
	while (i < nbr)
	{
		st->state[i] = 0;
		pthread_mutex_init(&st->forks[i], NULL);
		i++;
	}
	st->start = get_time();
}
