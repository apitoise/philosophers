/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <apitoise@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 12:36:34 by apitoise          #+#    #+#             */
/*   Updated: 2021/06/22 12:35:20 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (((unsigned char)s1[i] == (unsigned char)s2[j]) && (s1[i] || s2[j]))
	{
		i++;
		j++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[j]);
}


int	ft_atoi(const char *str)
{
	unsigned long	res;
	int				neg;
	int				pos;

	pos = 0;
	while (str[pos] == '\t' || str[pos] == '\n' || str[pos] == '\v'
			|| str[pos] == '\f' || str[pos] == '\r' || str[pos] == ' ')
		pos++;
	neg = 1;
	if (str[pos] == '+' || str[pos] == '-')
	{
		if (str[pos] == '-')
			neg++;
		pos++;
	}
	res = 0;
	while (str[pos] >= '0' && str[pos] <= '9')
	{
		res = res * 10;
		res = res + str[pos] - 48;
		pos++;
	}
	if (neg % 2 == 0)
		return (-res);
	return (res);
}
