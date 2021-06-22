/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <apitoise@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 12:30:42 by apitoise          #+#    #+#             */
/*   Updated: 2021/06/22 17:25:56 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

void	init_data(char **av, t_struct *st)
{
	st->data.philo_nb = ft_atoi(av[1]);
	st->data.die_time = ft_atoi(av[2]);
	st->data.eat_time = ft_atoi(av[3]);
	st->data.sleep_time = ft_atoi(av[4]);
	if (av[5])
		st->data.eat_max = ft_atoi(av[5]);
	else
		st->data.eat_max = -1;
}
