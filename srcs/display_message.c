/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_message.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <apitoise@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 10:47:44 by apitoise          #+#    #+#             */
/*   Updated: 2021/06/28 17:13:56 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

void	display_message(int id, char *str, t_struct *st)
{
	unsigned long	time;

	time = get_time() - st->start;
	printf("%ld\t%d\t%s\n", time, id, str);
}
