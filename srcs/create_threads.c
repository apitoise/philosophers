/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <apitoise@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 14:56:33 by apitoise          #+#    #+#             */
/*   Updated: 2021/06/22 16:12:20 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

static void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	printf("philo[%d] is alive\n", philo->id);
	pthread_detach(philo->thread);
	return NULL;
}

void	create_threads(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo[i].data.philo_nb)
	{
		pthread_create(&philo[i].thread, NULL, philo_routine, &philo[i]);
		i++;
	}
	sleep(10);
}
