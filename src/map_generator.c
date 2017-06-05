/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_generator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchenaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 02:46:13 by jchenaud          #+#    #+#             */
/*   Updated: 2017/06/05 02:57:06 by jchenaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static	void	random_gen(int y_size, int x_size, int fd)
{
	int			i;
	int			j;
	t_three_int	n;

	i = 0;
	while (i < y_size)
	{
		j = 0;
		while (j < x_size)
		{
			if (i == 0 || j == 0 || i == y_size - 1 || j == x_size - 1)
				write(fd, "1", 1);
			else
			{
				n.n = rand() % 2;
				n.n2 = rand() % 2;
				n.n3 = rand() % 2;
				(n.n == 1 && n.n2 == 1 && n.n3 == 1) ? write(fd, "1", 1)
					: write(fd, "0", 1);
			}
			(j + 1 == x_size) ? write(fd, "\n", 1) : write(fd, " ", 1);
			j++;
		}
		i++;
	}
}

void			map_gen(int argc, char **argv)
{
	int fd;
	int y_size;
	int x_size;

	if (argc == 3)
	{
		y_size = ft_atoi(argv[1]);
		x_size = ft_atoi(argv[2]);
		if (y_size > 2000 || x_size > 2000)
			use();
		system("rm -f map.gen");
		fd = open("map.gen", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
		if (fd == -1)
			exit(0);
		ft_putnbr_fd(y_size, fd);
		write(fd, " ", 1);
		ft_putnbr_fd(x_size, fd);
		write(fd, "\n", 1);
		random_gen(y_size, x_size, fd);
		write(1, "map gen is ok\n", 14);
		close(fd);
		return ;
	}
	use();
}
