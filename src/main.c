/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchenaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 00:26:46 by jchenaud          #+#    #+#             */
/*   Updated: 2017/05/31 01:51:32 by jchenaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include "../libft/libft.h"

void	init(int ac, char **av, t_graf *graf)
{
	if (ac < 2)
		exit(0);
	ft_map(open(av[1], O_RDONLY), graf);
	//printf("map ok\n");
	graf->texture_init = 0;
	ft_spawn(graf);
	//ft_bzero(graf->push, 270);
	
	int i = -1;
	graf->push = (int *)malloc(sizeof(int) * 270);
	while (++i < 270)
		graf->push[i] = 0;
	//	;
	///while (1)
		//;
	graf->dirX = 1;
	graf->dirY = 0;
	graf->PlaneX = 0;
	graf->PlaneY = 0.66;
	graf->weapon_init = 0;
	//(void)av;
	graf->time = -22;
	if(!(graf->nb_ball_c = (char*)malloc(sizeof(char)*3)))
	 	exit(0);
	// graf->nb_ball_c[2] = '\0';
	graf->nb_ball = 32;
}

int		main(int ac, char **av)
{
	t_graf *graf;

	graf = (t_graf*)malloc(sizeof(t_graf));
	graf->mlx = mlx_init();
	graf->win = mlx_new_window(graf->mlx, W_W, W_H, "wolf 3d");
	graf->img = (t_image *)mlx_new_image(graf->mlx, W_W, W_H);
	init(ac, av, graf);
	mlx_hook(graf->win, 2, 1, key_on, graf);
	mlx_key_hook(graf->win, key_off, graf);
	mlx_loop_hook(graf->mlx, main_loop, graf);
	mlx_loop(graf->mlx);
	return (0);
}
