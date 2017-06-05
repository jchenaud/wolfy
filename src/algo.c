/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchenaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 06:07:15 by jchenaud          #+#    #+#             */
/*   Updated: 2017/06/05 06:30:04 by jchenaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void	find_wall(t_graf *graf)
{
	int wall_find;

	wall_find = 0;
	while (wall_find == 0)
	{
		if (graf->dist_v < graf->dist_h)
		{
			graf->dist_v += graf->inc_x2;
			graf->map_x += graf->inc_x;
			graf->vertical0 = 0;
		}
		else
		{
			graf->dist_h += graf->inc_y2;
			graf->map_y += graf->inc_y;
			graf->vertical0 = 1;
		}
		wall_find = (graf->map[graf->map_y][graf->map_x] > 0) ? 1 : 0;
	}
	if (graf->vertical0 == 0)
		graf->wall_d = ((graf->map_x - graf->raypos_x +
					(1 - graf->inc_x) / 2) / graf->r_dir_x);
	else
		graf->wall_d = ((graf->map_y - graf->raypos_y +
					(1 - graf->inc_y) / 2) / graf->r_dir_y);
}

static void	find_dor(t_graf *graf)
{
	if (graf->map[graf->map_y][graf->map_x] == 9 && graf->wall_d < 2)
	{
		graf->door_not_far = 1;
		graf->door_y = graf->map_y;
		graf->door_x = graf->map_x;
	}
}

static void	tr_cercle(t_graf *graf)
{
	graf->inc_x2 = sqrt(1 + (graf->r_dir_y * graf->r_dir_y)
			/ (graf->r_dir_x * graf->r_dir_x));
	graf->inc_y2 = sqrt(1 + (graf->r_dir_x * graf->r_dir_x)
			/ (graf->r_dir_y * graf->r_dir_y));
	if (graf->r_dir_x < 0)
	{
		graf->inc_x = -1;
		graf->dist_v = (graf->raypos_x - graf->map_x) * graf->inc_x2;
	}
	else
	{
		graf->inc_x = 1;
		graf->dist_v = (graf->map_x + 1.0 - graf->raypos_x) * graf->inc_x2;
	}
	if (graf->r_dir_y < 0)
	{
		graf->inc_y = -1;
		graf->dist_h = (graf->raypos_y - graf->map_y) * graf->inc_y2;
	}
	else
	{
		graf->inc_y = 1;
		graf->dist_h = (graf->map_y + 1.0 - graf->raypos_y) * graf->inc_y2;
	}
}

static void	drawing(t_graf *graf, int x)
{
	int height_w;
	int draw_start;
	int draw_end;

	height_w = ((int)(W_H / graf->wall_d));
	draw_start = -height_w / 2 + W_H / 2;
	if (draw_start < 0)
		draw_start = 0;
	draw_end = height_w / 2 + W_H / 2;
	if (draw_end >= W_H)
		draw_end = W_H - 1;
	if (graf->map[graf->map_y][graf->map_x] == 1)
	{
		ft_basic_wall(graf->map_x, graf->map_y, graf);
		draw_wall(x, draw_start, draw_end, graf);
	}
	else
	{
		graf->map_value = graf->map[graf->map_y][graf->map_x];
		ft_texture_maker(graf);
		draw_wall_texture(x, draw_start, draw_end, graf);
	}
}

void		calcul_image(t_graf *graf)
{
	int		dont_make;
	int		x;
	double	cam;

	x = -1;
	graf->door_not_far = 0;
	while (x++ < W_W)
	{
		dont_make = 0;
		cam = 2 * x / (double)(W_W) - 1;
		graf->raypos_x = graf->pos_x;
		graf->raypos_y = graf->pos_y;
		graf->r_dir_x = graf->dirx + graf->planex * cam;
		graf->r_dir_y = graf->diry + graf->planey * cam;
		graf->map_x = (int)(graf->raypos_x);
		graf->map_y = (int)(graf->raypos_y);
		tr_cercle(graf);
		find_wall(graf);
		find_dor(graf);
		drawing(graf, x);
	}
}
