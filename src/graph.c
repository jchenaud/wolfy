/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchenaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 06:31:32 by jchenaud          #+#    #+#             */
/*   Updated: 2017/06/03 06:31:38 by jchenaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	put_pixel_to_img(unsigned int color, int x, int y, t_graf *graf)
{
	if (x < graf->img->width && y < graf->img->height && x >= 0 && y >= 0)
		((unsigned int *)(graf->img->buff))[x + y *
			graf->img->width] = color;
}

void	ft_basic_wall(int map_x, int map_y, t_graf *graf)
{
	int pos_x;
	int pos_y;

	pos_y = (int)(graf->pos_y);
	pos_x = (int)(graf->pos_x);
	if (map_x >= pos_x && graf->vertical0 == 0)
		graf->color = 0x10000 * 255 + 0x100 * 0 + 0;
	else if (map_x <= pos_x && graf->vertical0 == 0)
		graf->color = 0x10000 * 000 + 0x100 * 255 + 0;
	else if (map_y >= pos_y && graf->vertical0 == 1)
		graf->color = 0x10000 * 000 + 0x100 * 0 + 255;
	else if (map_y <= pos_y && graf->vertical0 == 1)
		graf->color = 0x10000 * 0 + 0x100 * 0 + 0;
	else
		graf->color = 0x10000 * 255 + 0x100 * 255 + 255;
}

void	draw_wall(int x, int draw_start, int draw_end, t_graf *graf)
{
	while (draw_start <= draw_end)
	{
		put_pixel_to_img(graf->color, x, draw_start, graf);
		draw_start++;
	}
}

void	ft_trace_sky(t_graf *graf)
{
	int y;
	int x;

	y = 0;
	while (y <= W_H / 2)
	{
		x = -1;
		while (++x <= W_W)
			put_pixel_to_img(0x10000 * 65 + 0x100 * 239 + 163, x, y, graf);
		y++;
	}
	while (y <= W_H)
	{
		x = -1;
		while (++x <= W_W)
			put_pixel_to_img(0x10000 * 193 + 0x100 * 88 + 85, x, y, graf);
		y++;
	}
}

void	ft_interface(t_graf *graf)
{
	int x;
	int y;
	int pos_x;
	int pos_y;

	pos_x = W_W - 200;
	pos_y = W_H - 150;
	if (graf->weapon_init == 0)
		graf->amobox = (t_image*)mlx_xpm_file_to_image(
				graf->mlx, "sprite/ammo.xpm", &x, &y);
	mlx_put_image_to_window(graf->mlx, graf->win, graf->amobox, pos_x, pos_y);
}
