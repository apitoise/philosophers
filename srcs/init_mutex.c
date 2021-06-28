/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mutex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <apitoise@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 20:48:32 by apitoise          #+#    #+#             */
/*   Updated: 2021/06/28 16:36:23 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

void	init_mutex(t_struct *st)
{
	int	nbr;
	int	i;
	
	nbr = st->data.philo_nb;
	pthread_mutex_init(&st->print, NULL);
	st->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * nbr);
	i = 0;
	while (i < nbr)
	{
		pthread_mutex_init(&st->forks[i], NULL);
		i++;
	}
}
