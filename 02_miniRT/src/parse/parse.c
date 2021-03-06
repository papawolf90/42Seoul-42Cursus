/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 17:31:51 by gunkim            #+#    #+#             */
/*   Updated: 2021/05/25 15:18:41 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include "libft.h"
#include "get_next_line.h"
#include "struct.h"
#include "vector.h"
#include "alias.h"
#include "error.h"
#include "utils.h"
#include "parse.h"
#include "object.h"

static t_bool	ft_check_declare_at_least(t_scene *s)
{
	if ((s->flag_declare & 0x1)
		&& (s->flag_declare & 0x10)
		&& (s->count_c > 0))
		return (success);
	return (ft_err_msg(ERR_NOT_ENOUGH_DECLARE));
}

t_bool			ft_parse_line(t_scene *scene, char *line)
{
	char				**splits;
	int					i;
	static t_pft_parse	pft_parse[] = {
		{"#", ft_pass_line}, {"R", ft_parse_resolution},
		{"A", ft_parse_ambient}, {"c", ft_parse_camera},
		{"l", ft_parse_light}, {"sp", ft_parse_sphere},
		{"pl", ft_parse_plane}, {"sq", ft_parse_square},
		{"cy", ft_parse_cylinder}, {"tr", ft_parse_triangle},
		{NULL, NULL}
	};

	i = 0;
	splits = ft_split_rt(line, WHITE_SPACE);
	while (pft_parse[i].id && *splits
			&& ft_strncmp(pft_parse[i].id, splits[0], 2))
		i++;
	if (pft_parse[i].id == NULL)
		return (ft_err_msg(ERR_PAR_NOID) && ft_destroy_splits(splits));
	if (pft_parse[i].parse(scene, splits))
		return (ft_destroy_splits(splits));
	ft_destroy_splits(splits);
	return (success);
}

t_bool			ft_parse_rt(t_ctrl *ctrl, char *rt_file)
{
	int		fd;
	int		ret;
	char	*line;

	ft_init_object_list(ctrl->scene);
	fd = open(rt_file, O_RDONLY);
	if (fd == OPEN_FAIL)
		return (ft_err_msg(ERR_OPEN_FAIL));
	while (1)
	{
		ret = get_next_line(fd, &line);
		if (ret == GNL_FAIL)
			return (!close(fd) && ft_err_msg(ERR_GNL));
		if (ft_parse_line(ctrl->scene, line))
			return (ft_err_line(line) && !close(fd) && ft_destroy(line));
		if (ret == GNL_EOF)
			break ;
		free(line);
	}
	free(line);
	close(fd);
	return (ft_check_declare_at_least(ctrl->scene));
}
