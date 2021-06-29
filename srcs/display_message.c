/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_message.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <apitoise@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 10:47:44 by apitoise          #+#    #+#             */
/*   Updated: 2021/06/29 16:04:33 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

void	display_message(t_philo *this, char *str)
{
	unsigned long	time;

	pthread_mutex_lock(&this->st->print);
	time = get_time() - this->st->start;
	printf("%ld\t%d\t%s\n", time, this->id, str);
	pthread_mutex_unlock(&this->st->print);
}
