/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strslen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 14:55:27 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/24 01:18:06 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t			ft_strslen(char **strs)
{
	size_t	len;

	len = 0;
	while (strs[len])
		len++;
	return (len);
}
