/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <apitoise@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 13:16:59 by apitoise          #+#    #+#             */
/*   Updated: 2021/06/22 17:29:46 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

void	init_philo(t_struct *st)
{
	int	i;

	st->philo = malloc(st->data.philo_nb * sizeof(t_philo));
	i = 0;
	while (i < st->data.philo_nb)
	{
		st->philo[i].id = i + 1;
		st->philo[i].rfork = st->philo[i].id - 1;
		if (st->philo[i].id == 1)
			st->philo[i].rfork = st->data.philo_nb;
		st->philo[i].lfork = st->philo[i].id + 1;
		if (st->philo[i].id == st->data.philo_nb)
			st->philo[i].lfork = 1;
		st->philo[i].eat = 0;
		st->philo[i].sleep = 0;
		st->philo[i].think = 0;
		i++;
	}
}
