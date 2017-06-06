/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchenaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 00:26:46 by jchenaud          #+#    #+#             */
/*   Updated: 2017/06/05 23:11:51 by jchenaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include "../libft/libft.h"

static void	init_2(t_graf *graf)
{
	graf->dirx = 1;
	graf->diry = 0;
	graf->planex = 0;
	graf->planey = 0.66;
	graf->weapon_init = 0;
	graf->texture_init = 0;
	graf->tym = -22;
	graf->frame_shot = 0;
	graf->frame_text = 0;
}

static void	init(int ac, char **av, t_graf *graf)
{
	int i;

	i = -1;
	if (ac < 2)
		use();
	else if (ac == 3)
	{
		map_gen(ac, av);
		av[1] = "map.gen";
	}
	ft_map(open(av[1], O_RDONLY), graf);
	ft_spawn(graf);
	if (!(graf->push = (int *)malloc(sizeof(int) * 270)))
		exit(0);
	while (++i <= 270)
		graf->push[i] = 0;
	init_2(graf);
	if (!(graf->nb_ball_c = (char*)malloc(sizeof(char) * 3)))
		exit(0);
	graf->nb_ball = 32;
}

int			main(int ac, char **av)
{
	t_graf *graf;

	if (!(graf = (t_graf*)malloc(sizeof(t_graf))))
		exit(0);
	graf->mlx = mlx_init();
	graf->win = mlx_new_window(graf->mlx, W_W, W_H, "wolf 3d");
	graf->img = (t_image *)mlx_new_image(graf->mlx, W_W, W_H);
	init(ac, av, graf);
	mlx_hook(graf->win, 2, 1, key_on, graf);
	mlx_key_hook(graf->win, key_off, graf);
	mlx_loop_hook(graf->mlx, main_loop, graf);
	mlx_loop(graf->mlx);
	exit(0);
}
