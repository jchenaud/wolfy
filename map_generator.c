#include "libft/libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char** argv)
{
	int fd;
	int y_size;
	int x_size;

	if (argc == 3)
	{
		y_size = ft_atoi(argv[1]);
		x_size = ft_atoi(argv[2]);
		if (y_size > 2000 || x_size > 2000)
			return (0);
		system("rm -f map.gen");
		fd = open("map.gen", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
		ft_putnbr_fd(y_size, fd);
		write(fd, " ", 1);
		ft_putnbr_fd(x_size, fd);
		write(fd, "\n", 1);
		for (int i = 0; i < y_size; i++)
		{
			for (int j = 0; j < x_size; j++)
			{
				if (i == 0 || j == 0 || i == y_size - 1 || j == x_size - 1)
					write(fd, "1", 1);
				else
				{
					int n = rand() % 2;
					int n2 = rand() % 2;
					int n3 = rand() % 2;
					(n == 1 && n2 == 1 && n3 == 1) ? write(fd, "1", 1) : write(fd, "0", 1);
				}
				(j + 1 == x_size) ? write(fd, "\n", 1) : write(fd, " ", 1);
			}
		}
		write(1,"its ok\n",7);
		close(fd);
	}
}
