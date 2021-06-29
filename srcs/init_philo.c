/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <apitoise@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 13:16:59 by apitoise          #+#    #+#             */
/*   Updated: 2021/06/29 16:39:02 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

void	init_philo(t_philo *philo, int philo_nb, t_struct *st)
{
	int	i;

	i = 0;
	while (i < philo_nb)
	{
		philo[i].id = i + 1;
		philo[i].rfork = philo[i].id - 1;
		philo[i].lfork = philo[i].id;
		if (philo[i].id == philo_nb)
			philo[i].lfork = 0;
		philo[i].eat = 0;
		philo[i].eat_max_reached = 0;
		philo[i].st = st;
		i++;
	}
}
