/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <apitoise@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 12:30:42 by apitoise          #+#    #+#             */
/*   Updated: 2021/06/22 15:21:33 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

void	init_data(char **av, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < ft_atoi(av[1]))
	{
		philo[i].data.philo_nb = ft_atoi(av[1]);
		philo[i].data.die_time = ft_atoi(av[2]);
		philo[i].data.eat_time = ft_atoi(av[3]);
		philo[i].data.sleep_time = ft_atoi(av[4]);
		if (av[5])
			philo[i].data.eat_max = ft_atoi(av[5]);
		else
			philo[i].data.eat_max = -1;
		i++;
	}
}
