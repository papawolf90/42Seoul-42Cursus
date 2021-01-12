/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 22:44:25 by gunkim            #+#    #+#             */
/*   Updated: 2021/01/12 01:02:59 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int			ft_count_digit(llint nbr)
{
	ullint	base;
	int		sign;
	int		digit;
	
	base = 1;
	sign = 0;
	digit = 0;
	if (nbr == 0)
		return (0);
	if (nbr < 0)
	{
		nbr *= -1;
		sign++;
	}
	while ((ullint)nbr >= base)
	{
		base *= 10;
		digit++;
	}
	return (sign + digit);
}

int			ft_abs(int nbr)
{
	if (nbr < 0)
		return (-1 * nbr);
	return (nbr);
}

int			ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}