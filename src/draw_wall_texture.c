/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall_texture.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchenaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 06:08:48 by jchenaud          #+#    #+#             */
/*   Updated: 2017/06/06 06:26:14 by jchenaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static t_text_help	ft_init_draw_wall_texture(int min, int max, t_graf *graf)
{
	t_text_help t;

	t.t = graf->map_value - 2;
	t.size_img = 4 * W_W;
	t.size_text = graf->text[t.t]->width * 4;
	t.dat = max - min;
	t.ratio = (double)graf->text[t.t]->height / (double)t.dat;
	t.add = 0;
	return (t);
}

void				draw_wall_texture(int x, int min, int max, t_graf *graf)
{
	t_text_help t;

	t = ft_init_draw_wall_texture(min, max, graf);
	if (graf->vertical0 == 0)
		t.wallx = graf->raypos_y + graf->wall_d * graf->r_dir_y;
	else
		t.wallx = graf->raypos_x + graf->wall_d * graf->r_dir_x;
	t.wallx -= floor((t.wallx));
	t.texx = (int)(t.wallx * (double)graf->text[t.t]->width);
	if (graf->vertical0 == 0 && graf->r_dir_x > 0)
		t.texx = graf->text[t.t]->width - t.texx - 1;
	if (graf->vertical0 == 1 && graf->r_dir_y < 0)
		t.texx = graf->text[t.t]->width - t.texx - 1;
	while (min < max)
	{
		t.texy = (int)t.add * (t.size_text);
		t.texturechute = t.texy + t.texx * 4;
		t.add += t.ratio;
		t.chute = (x * 4) + (min * t.size_img);
		graf->img->buff[t.chute] = graf->text[t.t]->buff[t.texturechute];
		graf->img->buff[++t.chute] = graf->text[t.t]->buff[++t.texturechute];
		graf->img->buff[++t.chute] = graf->text[t.t]->buff[++t.texturechute];
		min++;
	}
}

static t_text_help	ft_init_draw_wall_animtexture(
		int min, int max, t_graf *graf)
{
	t_text_help t;

	ft_texture_maker(graf);
	if (graf->new_frame == 0)
	{
		graf->frame_text++;
		graf->new_frame = 1;
	}
	if (graf->frame_text > NB_TX_FRAME - 1)
		graf->frame_text = 0;
	t.t = graf->frame_text;
	t.size_img = 4 * W_W;
	t.size_text = graf->anim[t.t]->width * 4;
	t.dat = max - min;
	t.ratio = (double)graf->anim[t.t]->height / (double)t.dat;
	t.add = 0;
	return (t);
}

void				draw_wall_animtexture(int x, int min,
		int max, t_graf *graf)
{
	t_text_help t;

	t = ft_init_draw_wall_animtexture(min, max, graf);
	if (graf->vertical0 == 0)
		t.wallx = graf->raypos_y + graf->wall_d * graf->r_dir_y;
	else
		t.wallx = graf->raypos_x + graf->wall_d * graf->r_dir_x;
	t.wallx -= floor((t.wallx));
	t.texx = (int)(t.wallx * (double)graf->anim[t.t]->width);
	if (graf->vertical0 == 0 && graf->r_dir_x > 0)
		t.texx = graf->anim[t.t]->width - t.texx - 1;
	if (graf->vertical0 == 1 && graf->r_dir_y < 0)
		t.texx = graf->anim[t.t]->width - t.texx - 1;
	while (min < max)
	{
		t.texy = (int)t.add * (t.size_text);
		t.texturechute = t.texy + t.texx * 4;
		t.add += t.ratio;
		t.chute = (x * 4) + (min * t.size_img);
		graf->img->buff[t.chute] = graf->anim[t.t]->buff[t.texturechute];
		graf->img->buff[++t.chute] = graf->anim[t.t]->buff[++t.texturechute];
		graf->img->buff[++t.chute] = graf->anim[t.t]->buff[++t.texturechute];
		min++;
	}
}
