/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongguki <dongguki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 11:54:06 by dongguki          #+#    #+#             */
/*   Updated: 2021/05/21 15:26:51 by dongguki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_map	map_init(t_map map)
{
	map.t_flag = 0;
	map.i_no = 0;
	map.i_so = 0;
	map.i_ea = 0;
	map.i_we = 0;
	map.i_s = 0;
	map.c_ceiling = 0xFFFF0000;
	map.c_floor = 0xFFFF0000;
	map.sx = 0;
	map.sy = 0;
	map.m_flag = 0;
	map.map = (t_list *)malloc(sizeof(t_list));
	if (!map.map)
		free_error(map);
	map.map->content = 0;
	map.map->next = 0;
	map.map->prev = 0;
	map.px = 0;
	map.py = 0;
	return (map);
}

t_cub	cub_init(t_cub cub)
{
	cub.mlx = 0;
	cub.win = 0;
	cub.img_we.img = 0;
	cub.img_ea.img = 0;
	cub.img_s.img = 0;
	cub.img_no.img = 0;
	cub.img_so.img = 0;
	cub.rx = X;
	cub.ry = Y;
	cub.action = 0;
	cub.spr = 0;
	return (cub);
}

int		isit_cub(char *title)
{
	if (ft_strncmp(title + ft_strlen(title) - 4, ".cub", 4))
		return (1);
	return (0);
}

int		main(int gc, char **gv)
{
	t_map	map;

	map.t_flag = 0;
	if (gc == 3)
		if (!ft_strncmp(gv[2], "--save", 6) && !isit_cub(gv[1]))
			make_bmp(gv[1]);
		else if (!ft_strncmp(gv[1], "--save", 6) && !isit_cub(gv[2]))
			make_bmp(gv[2]);
		else
			printf("Error\n: not valid arguments\n");
	else if (gc != 2 || isit_cub(gv[1]))
		printf("Error\n: not valid arguments\n");
	else
	{
		map = map_init(map);
		map = parse(gv[1], map);
		display(map);
		free_map(map);
	}
	return (0);
}
