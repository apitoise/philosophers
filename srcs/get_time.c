/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <apitoise@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 21:14:01 by apitoise          #+#    #+#             */
/*   Updated: 2021/06/22 21:44:21 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

/*unsigned long	get_time(void)
{
	static unsigned long	start;
	static int				init = 0;
	struct timeval			time;

	if (!init)
	{
		gettimeofday(&time, NULL);
		start = (time.tv_sec * 1000000 + time.tv_usec) /  1000;
		++init;
	}
	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000000 + time.tv_usec) / 1000 - start);
}*/

unsigned long	get_time(void)
{
	static struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec *1000) + (tv.tv_usec / 1000));
}
