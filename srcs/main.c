/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <apitoise@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 12:07:13 by apitoise          #+#    #+#             */
/*   Updated: 2021/06/22 21:03:10 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

static int	check_arguments(int ac, char **av)
{
	int	i;
	int	j;

	if (ac < 5 || ac > 6)
		return (1);
	i = 1;
	while (av[i])
	{
		j = 0;
		if (!ft_atoi(av[i]))
			return (1);
		while (av[i][j])
		{
			if (av[i][j] >= '0' && av[i][j] <= '9')
				j++;
			else
				return (1);
		}
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_struct	st;

	if (check_arguments(ac, av))
		return (ft_error("Bad arguments."));
	init_data(av, &st);
	init_philo(&st);
	init_mutex(&st);
	create_threads(&st);
	free(st.philo);
	free(st.forks);
}
