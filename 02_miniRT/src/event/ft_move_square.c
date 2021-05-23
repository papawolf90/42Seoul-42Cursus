/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_square.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 02:03:32 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/22 09:48:34 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "vector.h"
#include "parse.h"

int				ft_move_square(t_object_list *list, t_vec3 trans)
{
	t_square		*square;

	square = (t_square *)list->object;
	square->center = V_PLUS(square->center, trans);
	return (0);
}