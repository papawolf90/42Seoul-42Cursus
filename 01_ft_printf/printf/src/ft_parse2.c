/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 20:55:52 by gunkim            #+#    #+#             */
/*   Updated: 2021/02/07 12:17:03 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_parse_nbr_nonestar(t_fmt *fmt, t_flg flg)
{
	int		nbr;

	nbr = ft_atoi_nonstar(fmt);
	if (nbr < 0)
	{
		fmt->flag[dot] += flg == dot ? 1 : 0;
		fmt->flag[minus] += flg == !dot ? 1 : fmt->flag[minus];
		fmt->wid = flg == !dot ? -1 * nbr : fmt->wid;
	}
	else if (flg == !dot)
		fmt->wid = nbr;
	else if (flg == dot)
		fmt->prec = nbr;
	return (0);
}

int				ft_atoi_nonstar(t_fmt *fmt)
{
	int			result;
	int			sign;

	result = 0;
	sign = 1;
	while ((9 <= *fmt->str && *fmt->str <= 13) || *fmt->str == ' ')
		fmt->str++;
	if (*fmt->str == '+' || *fmt->str == '-')
		if (*(fmt->str++) == '-')
			sign = -1;
	while ('0' <= *fmt->str && *fmt->str <= '9')
		result = result * 10 + *(fmt->str++) - '0';
	return (sign * result);
}

int				ft_parse_nbr(t_fmt *fmt, t_flg flg)
{
	int			nbr;

	if (fmt->flag[star] >= 1)
	{
		if ((nbr = va_arg(fmt->ap, int)) < 0)
		{
			fmt->flag[dot] = flg == dot ? 0 : fmt->flag[dot];
			fmt->flag[minus] += flg == !dot ? 1 : fmt->flag[minus];
			fmt->wid = flg == !dot ? -1 * nbr : fmt->wid;
		}
		else if (flg == !dot)
			fmt->wid = nbr;
		else if (flg == dot)
			fmt->prec = nbr;
		fmt->flag[star] = 0;
		return (0);
	}
	if (ft_parse_nbr_nonestar(fmt, flg) == ERROR)
		return (ERROR);
	return (0);
}
