/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchenaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 06:50:09 by jchenaud          #+#    #+#             */
/*   Updated: 2017/06/03 06:50:11 by jchenaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	ft_texture_maker(t_graf *graf)
{
	int x;
	int y;

	if (graf->texture_init == 0)
	{
		graf->text = (t_image**)malloc(sizeof(t_image) * NB_TEXTURE);
		graf->text[0] = (t_image*)mlx_xpm_file_to_image(
				graf->mlx, "texture/brick64.xpm", &x, &y);
		graf->text[1] = (t_image*)mlx_xpm_file_to_image(
				graf->mlx, "texture/metal_tiles.xpm", &x, &y);
		graf->text[2] = (t_image*)mlx_xpm_file_to_image(
				graf->mlx, "texture/paper.xpm", &x, &y);
		graf->text[3] = (t_image*)mlx_xpm_file_to_image(
				graf->mlx, "texture/carbon.xpm", &x, &y);
		graf->text[4] = (t_image*)mlx_xpm_file_to_image(
				graf->mlx, "texture/road.xpm", &x, &y);
		graf->text[5] = (t_image*)mlx_xpm_file_to_image(
				graf->mlx, "texture/lock.xpm", &x, &y);
		graf->text[7] = (t_image*)mlx_xpm_file_to_image(
				graf->mlx, "texture/door_1.xpm", &x, &y);
		graf->texture_init = 1;
	}
}
