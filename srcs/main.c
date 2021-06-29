/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <apitoise@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 12:07:13 by apitoise          #+#    #+#             */
/*   Updated: 2021/06/29 17:25:33 by apitoise         ###   ########.fr       */
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
	t_philo		*philo;

	if (check_arguments(ac, av))
		return (ft_error("Bad arguments."));
	init_st(&st, av);
	philo = malloc(st.data.philo_nb * sizeof(t_philo));
	init_philo(philo, st.data.philo_nb, &st);
	create_threads(&st, philo);
	ft_exit(&st, philo);
}
