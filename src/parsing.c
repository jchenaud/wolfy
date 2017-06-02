/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchenaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 00:14:55 by jchenaud          #+#    #+#             */
/*   Updated: 2017/05/31 04:18:39 by jchenaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static char	*first_iteration(int fd, char *line, t_graf *graf)
{
	int c;

	c = 0;
	graf->nb_l = ft_atoi(line);
	if(!(graf->map = (int**)malloc(sizeof(int *) * graf->nb_l)))
		return (NULL);
	while (line[c] >= '0' && line[c] <= '9')
		c++;
	graf->size = ft_atoi(&line[c]);
	ft_strdel(&line);
	get_next_line(fd, &line);
	return (line);
}

void		ft_map(const int fd, t_graf *graf)
{
	char	*line;
	int		c;
	int		y;
	int		x;
	
//	if(!(line = malloc(sizeof(char))))
//		return;
//	line = NULL; // atention rajour quanf makefile
	y = 0;
	while (get_next_line(fd, &line) == 1)
	{			
		if (y == 0)
			line = first_iteration(fd, line, graf);
		if(!(graf->map[y] = (int*)malloc(sizeof(int) * graf->size)))
			return ;
		c = 0;
		x = 0;
		while (c < graf->size * 2)
		{
			graf->map[y][x] = ft_atoi(&line[c]);
			while (line[c] >= '0' && line[c] <= '9')
				c++;
			(c < graf->size * 2) ? c++ : 0;
			x++;
		}
		y++;
		printf("line = %s \n",line);
		if (line)
			ft_strdel(&line);
	}
	//ft_strdel(&line);
	//free(*line);
	//printf("line = %s \n",line);
	//printf("line add =%p \n",line);
	//free(line);
}

void		ft_spawn(t_graf *graf)
{
	int x;
	int y;

	y = 0;
	while (y < graf->nb_l)
	{
		x = 0;
		while (x < graf->size)
		{
			if (graf->map[y][x] == 0)
			{
				graf->pos_x = x + 0.5;
				graf->pos_y = y + 0.5;
				return ;
			}
			x++;
		}
		y++;
	}
}