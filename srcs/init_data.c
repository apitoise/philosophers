/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <apitoise@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 12:30:42 by apitoise          #+#    #+#             */
/*   Updated: 2021/06/29 16:16:29 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

void	init_data(char **av, t_data *data)
{
	data->philo_nb = ft_atoi(av[1]);
	data->die_time = ft_atoi(av[2]);
	data->eat_time = ft_atoi(av[3]) * 1000;
	data->sleep_time = ft_atoi(av[4]) * 1000;
	if (av[5])
		data->eat_max = ft_atoi(av[5]);
	else
		data->eat_max = -1;
}
