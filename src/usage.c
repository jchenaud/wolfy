/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchenaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 02:11:31 by jchenaud          #+#    #+#             */
/*   Updated: 2017/06/05 02:11:36 by jchenaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	use(void)
{
	char *line;

	line = "Usage : ./wolf3d map";
	ft_putendl(line);
	line = "map (good map its better :)";
	ft_putendl(line);
	line = "Basic map : Map_test/";
	ft_putendl(line);
	line = "you can generate map : ./wolf3d size_x size_y";
	ft_putendl(line);
	line = "size_x  & size_y < 2000";
	ft_putendl(line);
	exit(0);
}
