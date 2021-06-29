/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <apitoise@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 16:53:51 by apitoise          #+#    #+#             */
/*   Updated: 2021/06/29 17:29:03 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

void	ft_exit(t_struct *st, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < st->data.philo_nb)
	{
		pthread_mutex_destroy(&st->forks[i]);
		i++;
	}
	free(st->forks);
	free(philo);
	pthread_mutex_destroy(&st->print);
}
