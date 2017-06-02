#include "wolf.h"
#include <time.h>

int			key_off(int key,t_graf *graf)
{
	graf->push[key] = 0;
	return (0);
}

int			key_on(int key, t_graf *graf)
{
//	key == ESC ? exit(0) : 0;
	graf->push[key] = 1;
	return (0);
}

int			main_loop(t_graf *graf)
{
  int music;
  music = ( (clock()/CLOCKS_PER_SEC) - graf->time > 21) ? 1 : 0 ;
  printf ("time %d , clock %lu\n",graf->time, clock()/CLOCKS_PER_SEC);
  if ( music == 1)
  {
      system("afplay sound/22-u-r-a-hero.mp3 &");
      graf->time =  (clock()/CLOCKS_PER_SEC);
  }
	push(graf);
	ft_trace_sky(graf);
	calcul_image(graf);
  mlx_put_image_to_window(graf->mlx, graf->win, graf->img, 0, 0);
  free(graf->nb_ball_c);
 graf->nb_ball_c = ft_itoa(graf->nb_ball);
 mlx_string_put(graf->mlx, graf->win, 1100,660, 0xFFFFFF,graf->nb_ball_c);
	
  ft_weapon(graf);

	ft_bzero(graf->img->buffer, graf->img->width * graf->img->height * 4);
	return (0);
}


void		push(t_graf *graf)
{	
	double  moveSpeed;
	moveSpeed= 0.08;
	double rotSpeed;
	rotSpeed = 0.02; 
	if (graf->push[UP] != 0)
    {
   // printf(" map [%d] [%d\n", );
      if(graf->map[(int)(graf->pos_y)][(int)(graf->pos_x + graf->dirX * moveSpeed)] == 0) graf->pos_x += (double)(graf->dirX * moveSpeed);
      if(graf->map[(int)(graf->pos_y + graf->dirY * moveSpeed)][(int)(graf->pos_x)] == 0) graf->pos_y += graf->dirY * moveSpeed;
    }
    if (graf->push[DN] != 0)
    {
      if(graf->map[(int)(graf->pos_y)][(int)(graf->pos_x - graf->dirX * moveSpeed)] == 0) graf->pos_x -= graf->dirX * moveSpeed;
      if(graf->map[(int)(graf->pos_y - graf->dirY * moveSpeed)][(int)(graf->pos_x)] == 0) graf->pos_y -= graf->dirY * moveSpeed;
    }
    if (graf->push[LT] != 0)
    {
      double tmp_dirx = graf->dirX * cos(-90) - graf->dirY * sin(-90);
      double tmp_diry = graf->dirX  * sin(-90) + graf->dirY * cos(-90);
      if(graf->map[(int)(graf->pos_y)][(int)(graf->pos_x + tmp_dirx * moveSpeed)] == 0) graf->pos_x += (double)(tmp_dirx * moveSpeed);
      if(graf->map[(int)(graf->pos_y +tmp_diry * moveSpeed)][(int)(graf->pos_x)] == 0) graf->pos_y += tmp_diry * moveSpeed;

    }
    if (graf->push[RT] != 0)
    {
      double tmp_dirx = graf->dirX * cos(+90) - graf->dirY * sin(+90);
      double tmp_diry = graf->dirX  * sin(+90) + graf->dirY * cos(+90);
      if(graf->map[(int)(graf->pos_y)][(int)(graf->pos_x + tmp_dirx * moveSpeed)] == 0) graf->pos_x += (double)(tmp_dirx * moveSpeed);
      if(graf->map[(int)(graf->pos_y +tmp_diry * moveSpeed)][(int)(graf->pos_x)] == 0) graf->pos_y += tmp_diry * moveSpeed;
    }

     if ((graf->push[A] != 0))
    {
      ///la direction ainsi que le plan de la caméra doivent également effectuer une rotation
      double oldDirX = graf->dirX;
      graf->dirX = graf->dirX * cos(-rotSpeed) - graf->dirY * sin(-rotSpeed);
      graf->dirY = oldDirX * sin(-rotSpeed) + graf->dirY * cos(-rotSpeed);
      double oldPlaneX = graf->PlaneX;
      graf->PlaneX = graf->PlaneX * cos(-rotSpeed) - graf->PlaneY * sin(-rotSpeed);
      graf->PlaneY = oldPlaneX * sin(-rotSpeed) + graf->PlaneY * cos(-rotSpeed);
    }
    ///effectuer une rotaion vers la gauche
    if ((graf->push[D] != 0))
    {
      ///la direction ainsi que le plan de la caméra doivent également effectuer une rotation
      double oldDirX = graf->dirX;
      graf->dirX = graf->dirX * cos(rotSpeed) - graf->dirY * sin(rotSpeed);
      graf->dirY = oldDirX * sin(rotSpeed) + graf->dirY * cos(rotSpeed);
      double oldPlaneX = graf->PlaneX;
      graf->PlaneX = graf->PlaneX * cos(rotSpeed) - graf->PlaneY * sin(rotSpeed);
      graf->PlaneY = oldPlaneX * sin(rotSpeed) + graf->PlaneY * cos(rotSpeed);
    }
    if(graf->push[W] && graf->door_not_far == 1)
    {
    		graf->map[graf->door_y][graf->door_x] = 0;

    }
    if(graf->push[SPACE] && graf->frame_shot == 0 != 0)
    {
      graf->shot = 1;
    }
    if ((graf->push[R] != 0))
    {
      graf->nb_ball = 32;
      system("afplay sound/relod.wav &");//shot.wav");

    }


	if(graf->push[ESC])
	{
  //  int k;
 //   int i = 0;
 //  while (i < graf->nb_l)
 // {
 //     if (graf->map[i])
 //       free(graf->map[i]);
  //    i++;
 // }
 // free(graf->map);
  //i = 0;
    // while (graf->text[i])// segfault
    // {
    //  if(graf->text[i])
    //     free(graf->text[i]->buffer);
    //   i++;
    // }
  //  i = 0;
    // while (graf->weapon[i++])
    // {
    //  if(graf->weapon[i])
    //   free(graf->weapon[i]);
    // }
  //  free(graf->text);
    //free(graf->weapon);
   // mlx_destroy_image(graf->mlx, graf->img);
   // mlx_destroy_window(graf->mlx, graf->win);

   // free(graf->mlx);
    //free(graf->win);
    //free(graf->img);
  //  free(graf->nb_ball_c);
    //free(graf->amobox->buffer);
   // free(graf->push); segfault
	//	free(graf);
    // while(1)
    //   ;
		exit(0);
	}




    ////////////////////A SUPRIMER //////////////////////////
     if ((graf->push[P] != 0))
     {
     	int y;
     	int x;
     	y = 0;
     	printf(" add  map = %p\n",graf->map);
     	while (y < graf->nb_l)
     	{
     		x = 0;
     		while (x < graf->size)
     		{
     			printf("%d ",graf->map[x][y]);
     			x++;
     		}
     		printf("\n");
     		y++;
     	}
     }
 
   // printf("plop\n");
// 	graf->push[Q] ? graf->angle -= 1 : 0;
// 	graf->push[E] ? graf->angle += 1 : 0;
// 	graf->push[UP] ? graf->pos_x += -0.3  : 0;
// 	graf->push[DN] ? graf->pos_x += 0.3 : 0;
// 	graf->push[UP] ? graf->pos_y += 0  : 0;
// 	graf->push[DN] ? graf->pos_y += 0 : 0;
}
