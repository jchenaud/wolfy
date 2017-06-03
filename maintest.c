#include "src/wolf.h"

int main (int argc, char **argv)
{
	t_graf *graf;
	int fd  = open(argv[1], O_RDONLy);

	graf = (t_graf*)malloc(sizeof(t_graf));
	ft_map(fd, graf);
	close(fd);
	//free(graf);
	while(1);
}