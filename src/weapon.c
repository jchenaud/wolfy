/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchenaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 06:33:34 by jchenaud          #+#    #+#             */
/*   Updated: 2017/06/03 06:54:08 by jchenaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void	init_w(t_graf *graf)
{
	int x;
	int y;
	int nb_frame;

	nb_frame = 2;
	if (!(graf->weapon = (t_image**)malloc(sizeof(t_image) * nb_frame)))
		exit (0);
	graf->weapon[0] = (t_image*)mlx_xpm_file_to_image(
			graf->mlx, "sprite/frame.xpm", &x, &y);
	graf->weapon[1] = (t_image*)mlx_xpm_file_to_image(
			graf->mlx, "sprite/frame2.xpm", &x, &y);
	graf->weapon_init = 1;
}

static void	shot(t_graf *graf)
{
	graf->nb_ball--;
	system("afplay sound/shot.wav &");
}

static void	shot_end(t_graf *graf)
{
	system("afplay sound/SFB-goupille-sol.mp3 &");
	graf->shot = 0;
	graf->frame_shot = 0;
}

void		ft_weapon(t_graf *graf)
{
	int k;

	k = 0;
	ft_interface(graf);
	if (graf->weapon_init == 0)
		init_w(graf);
	if (graf->shot == 1 && graf->nb_ball > 0)
	{
		if (graf->frame_shot == 0)
			shot(graf);
		k = 1;
		if (graf->frame_shot != 3)
			graf->frame_shot++;
		else
			shot_end(graf);
	}
	mlx_put_image_to_window(graf->mlx, graf->win, graf->weapon[k],
			W_W / 2 - graf->weapon[k]->width / 2,
			W_H - graf->weapon[k]->height);
}
