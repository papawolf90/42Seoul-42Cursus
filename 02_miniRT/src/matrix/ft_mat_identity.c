/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mat_identity.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 21:08:38 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/19 21:12:43 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

t_mat44				ft_mat_identity(void)
{
	return (ft_mat_set(V_SET(1, 0, 0),
						V_SET(0, 1, 0),
						V_SET(0, 0, 1),
						V_SET(0, 0, 0)));
}