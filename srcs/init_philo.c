/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <apitoise@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 13:16:59 by apitoise          #+#    #+#             */
/*   Updated: 2021/06/28 16:33:15 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

void	init_philo(t_philo *philo, int philo_nb)
{
	int	i;

	i = 0;
	while (i < philo_nb)
	{
		philo[i].id = i + 1;
		philo[i].rfork = philo[i].id - 2;
		if (philo[i].id == 1)
			philo[i].rfork = philo_nb - 1;
		philo[i].lfork = philo[i].id - 1;
		philo[i].eat = 0;
		philo[i].sleep = 0;
		philo[i].think = 0;
		philo[i].lfork_taken = 0;
		philo[i].rfork_taken = 0;
		i++;
	}
}
