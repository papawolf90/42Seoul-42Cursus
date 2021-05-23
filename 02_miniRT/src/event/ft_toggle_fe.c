/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toggle_fe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 14:57:33 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/23 14:57:53 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "console.h"

int				ft_toggle_fe(t_ctrl *ctrl)
{
	ctrl->bool_fish_eye = !ctrl->bool_fish_eye;
	ft_console_msg(ctrl, NUL);
	return (true);
}