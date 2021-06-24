/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_message.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <apitoise@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 10:47:44 by apitoise          #+#    #+#             */
/*   Updated: 2021/06/23 13:03:39 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

void	display_message(int id, char *str, t_struct *st)
{
	unsigned long	time;

	time = get_time() - st->start;
	printf("%ld %d %s\n", time, id, str);
}
