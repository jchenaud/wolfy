/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchenaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 03:26:59 by jchenaud          #+#    #+#             */
/*   Updated: 2017/06/03 03:27:06 by jchenaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static	void	rotate_left(t_graf *graf)
{
	double old_dx;
	double old_planx;

	old_dx = graf->dirx;
	old_planx = graf->Planex;
	graf->dirx = graf->dirx * cos(-graf->rot_speed) -
		graf->diry * sin(-graf->rot_speed);
	graf->diry = old_dx * sin(-graf->rot_speed) +
		graf->diry * cos(-graf->rot_speed);
	graf->Planex = graf->Planex * cos(-graf->rot_speed) -
		graf->Planey * sin(-graf->rot_speed);
	graf->Planey = old_planx * sin(-graf->rot_speed) +
		graf->Planey * cos(-graf->rot_speed);
}

void			ft_rotate(t_graf *graf)
{
	double old_dx;
	double old_planx;

	if (graf->push[A] != 0)
		rotate_left(graf);
	if (graf->push[D] != 0)
	{
		old_dx = graf->dirx;
		old_planx = graf->Planex;
		graf->dirx = graf->dirx * cos(graf->rot_speed) -
			graf->diry * sin(graf->rot_speed);
		graf->diry = old_dx * sin(graf->rot_speed) +
			graf->diry * cos(graf->rot_speed);
		old_planx = graf->Planex;
		graf->Planex = graf->Planex * cos(graf->rot_speed) -
			graf->Planey * sin(graf->rot_speed);
		graf->Planey = old_planx * sin(graf->rot_speed) +
			graf->Planey * cos(graf->rot_speed);
	}
}

void			ft_lateral_move(t_graf *graf)
{
	double	tmp_dirx;
	double	tmp_diry;

	if (graf->push[LT] != 0)
	{
		tmp_dirx = graf->dirx * cos(-90) - graf->diry * sin(-90);
		tmp_diry = graf->dirx * sin(-90) + graf->diry * cos(-90);
		if (graf->map[(int)(graf->pos_y)]
				[(int)(graf->pos_x + tmp_dirx * graf->move_speed)] == 0)
			graf->pos_x += (double)(tmp_dirx * graf->move_speed);
		if (graf->map[(int)(graf->pos_y + tmp_diry * graf->move_speed)]
				[(int)(graf->pos_x)] == 0)
			graf->pos_y += tmp_diry * graf->move_speed;
	}
	if (graf->push[RT] != 0)
	{
		tmp_dirx = graf->dirx * cos(90) - graf->diry * sin(90);
		tmp_diry = graf->dirx * sin(90) + graf->diry * cos(90);
		if (graf->map[(int)(graf->pos_y)]
				[(int)(graf->pos_x + tmp_dirx * graf->move_speed)] == 0)
			graf->pos_x += (double)(tmp_dirx * graf->move_speed);
		if (graf->map[(int)(graf->pos_y + tmp_diry * graf->move_speed)]
				[(int)(graf->pos_x)] == 0)
			graf->pos_y += tmp_diry * graf->move_speed;
	}
}

void			ft_move(t_graf *graf)
{
	graf->move_speed = 0.08;
	graf->rot_speed = 0.02;
	if (graf->push[UP] != 0)
	{
		if (graf->map[(int)(graf->pos_y)]
				[(int)(graf->pos_x + graf->dirx * graf->move_speed)] == 0)
			graf->pos_x += (double)(graf->dirx * graf->move_speed);
		if (graf->map[(int)(graf->pos_y + graf->diry * graf->move_speed)]
				[(int)(graf->pos_x)] == 0)
			graf->pos_y += graf->diry * graf->move_speed;
	}
	if (graf->push[DN] != 0)
	{
		if (graf->map[(int)(graf->pos_y)]
				[(int)(graf->pos_x - graf->dirx * graf->move_speed)] == 0)
			graf->pos_x -= graf->dirx * graf->move_speed;
		if (graf->map[(int)(graf->pos_y - graf->diry * graf->move_speed)]
				[(int)(graf->pos_x)] == 0)
			graf->pos_y -= graf->diry * graf->move_speed;
	}
}
