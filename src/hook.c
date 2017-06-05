/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchenaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 03:09:31 by jchenaud          #+#    #+#             */
/*   Updated: 2017/06/03 03:09:57 by jchenaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include <time.h>

int			key_off(int key, t_graf *graf)
{
	graf->push[key] = 0;
	return (0);
}

int			key_on(int key, t_graf *graf)
{
	graf->push[key] = 1;
	return (0);
}

int			main_loop(t_graf *graf)
{
	//int music;

	// music = ((clock() / CLOCKS_PER_SEC) - graf->tym > 21) ? 1 : 0;
	// if (music == 1)
	// {
	// 	system("afplay sound/22-u-r-a-hero.mp3 &");
	// 	graf->tym = (clock() / CLOCKS_PER_SEC);
	// }
	push(graf);
	ft_trace_sky(graf);
	calcul_image(graf);
	mlx_put_image_to_window(graf->mlx, graf->win, graf->img, 0, 0);
	free(graf->nb_ball_c);
	graf->nb_ball_c = ft_itoa(graf->nb_ball);
	mlx_string_put(graf->mlx, graf->win, 1100, 660, 0xFFFFFF, graf->nb_ball_c);
	ft_weapon(graf);
	ft_bzero(graf->img->buff, graf->img->width * graf->img->height * 4);
	return (0);
}

void		push(t_graf *graf)
{
	ft_move(graf);
	ft_lateral_move(graf);
	ft_rotate(graf);
	if (graf->push[W] && graf->door_not_far == 1)
		graf->map[graf->door_y][graf->door_x] = 0;
	if (graf->push[SPACE] && graf->frame_shot == 0)
		graf->shot = 1;
	if (graf->push[R] != 0)
	{
    graf->frame_shot = 0;
    graf->shot = 0;
		graf->nb_ball = 32;
		system("afplay sound/relod.wav &");
	}
	if (graf->push[ESC])
		exit(0);
}
