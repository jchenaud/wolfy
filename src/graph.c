#include  "wolf.h"

void	put_pixel_to_img(unsigned int color, int x, int y,t_graf *graf)
{
	if (x < graf->img->width && y < graf->img->height && x >= 0 && y >= 0)
		((unsigned int *)(graf->img->buffer))[x + y *
		graf->img->width] = color;
}

//  t_graf *graf(void)
//  {
//  	static t_graf graf;
//  	return (&graf);
// }

unsigned int ft_basic_wall(int map_x, int map_y,t_graf *graf)
{
	unsigned int color;
	int pos_x = (int)(graf->pos_x);
	int pos_y = (int)(graf->pos_y);
	if (map_x >= pos_x && graf->vertical0 == 0)
		color = 0x10000 * 255 + 0x100 * 0 + 0;
	else if(map_x <= pos_x && graf->vertical0 == 0) 
		color = 0x10000 * 000 + 0x100 * 255 + 0;
	else if (map_y >= pos_y && graf->vertical0 == 1)
		color = 0x10000 * 000 + 0x100 * 0 + 255;
	else if (map_y <= pos_y && graf->vertical0 == 1)
		color = 0x10000 * 0 + 0x100 * 0 + 0;
	else
		color =  0x10000 * 255 + 0x100 * 255 + 255;
	return (color);
}

void draw_wall(int x, int drawStart, int drawEnd, unsigned int  color ,t_graf *graf)
{
	while (drawStart <= drawEnd)
	{
		put_pixel_to_img(color, x, drawStart,graf);
		drawStart++;
	}
}

unsigned int get_color(char *buffer, unsigned int px)
 {
 	unsigned int color;
 	int r;
 	int g;
 	int b;
 	int t;

 	b = buffer[px];
 	g = buffer[px + 1];
 	r = buffer[px + 2];
 	t = buffer[px + 3];
 	//printf("t =  %d\n",graf->text[0]->buffer[px + 3]);

 	color = 0x1000000* r + 0x10000 * g + 0x100*b + t;
 	//printf("color %8.8x \n",color);
 	return(color);
 }


 void	draw_wall_texture(int x, int min, int max, t_graf *graf)
{
	int texturechute;
	int chute;
	int dat;
	double ratio;
	double add;
	int size_img;
	int size_text;

	int t = graf->map_value - 2;

	size_img =  4 * W_W;
	size_text = graf->text[t]->width * 4;

	dat = max - min;
	ratio = (double)graf->text[t]->height / (double)dat;
	add = 0;
	double wallX; //where exactly the wall was hit
	if (graf->vertical0 == 0) wallX = graf->raypos_y + graf->wall_d * graf->r_dir_y;
	else           wallX = graf->raypos_x + graf->wall_d * graf->r_dir_x;
	wallX -= floor((wallX));
	int texX = (int)(wallX * (double)graf->text[t]->width);

	if(graf->vertical0 == 0 && graf->r_dir_x > 0) texX = graf->text[t]->width - texX - 1;
	if(graf->vertical0 == 1 && graf->r_dir_y < 0) texX = graf->text[t]->width - texX - 1;

	while (min < max)
	{
		int texY = (int)add * (size_text);///coucou->texture2->size_line;
		texturechute = texY + texX * 4;
		add += ratio;
		chute = (x * 4) + (min * size_img);//coucou->img->size_line);
		graf->img->buffer[chute] = graf->text[t]->buffer[texturechute];
		graf->img->buffer[++chute] = graf->text[t]->buffer[++texturechute];
		graf->img->buffer[++chute] = graf->text[t]->buffer[++texturechute];
		min++;
	}
}

void ft_trace_sky(t_graf *graf)
{
		int y;
		int x;
		y  = 0;
		while ( y <= W_H / 2)
		{
			x = 0;
			while (x <= W_W)
			{
				put_pixel_to_img(0x10000 * 65 + 0x100 * 239 + 163,  x, y,graf);
				x++;
			}
			y++;
		}
		while ( y <= W_H)
		{
			x = 0;
			while (x <= W_W)
			{
				put_pixel_to_img(0x10000 * 193 + 0x100 * 88 + 85,  x, y,graf);
				x++;
			}
			y++;
		}
}

void ft_texture_maker(t_graf *graf)
{
	//void *texture;
	//char *xpm;
	//xpm = "texture/brick64.xpm"; //"texture/wood.xpm"; //"texture/paper.xpm";//"texture/carbon.xpm";
	int x;
	int y;
	if (graf->texture_init == 0)
	{
		graf->text = (t_image**)malloc(sizeof(t_image)* NB_TEXTURE);
		////// test anti leaks;
		//int i = 0;
		// while (0 < 7 )
		// 	graf->text[i]->buffer =  (char*)malloc(sizeof(char));

/////////////////////////////////
		graf->text[0] = (t_image*)mlx_xpm_file_to_image(graf->mlx,"texture/brick64.xpm",&x,&y);
		graf->text[1] = (t_image*)mlx_xpm_file_to_image(graf->mlx,"texture/metal_tiles.xpm",&x,&y);
		graf->text[2] = (t_image*)mlx_xpm_file_to_image(graf->mlx,"texture/paper.xpm",&x,&y);
		graf->text[3] = (t_image*)mlx_xpm_file_to_image(graf->mlx,"texture/carbon.xpm",&x,&y);
		graf->text[4] = (t_image*)mlx_xpm_file_to_image(graf->mlx,"texture/road.xpm",&x,&y); // 8 la port
		graf->text[5] = (t_image*)mlx_xpm_file_to_image(graf->mlx,"texture/lock.xpm",&x,&y); // 8 la port
		//graf->text[6] = (t_image*)mlx_xpm_file_to_image(graf->mlx,"texture/door 1.xpm",&x,&y); // 8 la port
		//graf->text[7] = (t_image*)mlx_xpm_file_to_image(graf->mlx,"texture/door 1.xpm",&x,&y); // 8 la port
		graf->text[7] = (t_image*)mlx_xpm_file_to_image(graf->mlx,"texture/door_1.xpm",&x,&y); // 8 la port
		graf->texture_init = 1;
		///
	}
	//mlx_put_image_to_window(graf->mlx, graf->win, graf->text[0], graf->text[0]->height, graf->text[0]->width);
	//sleep(5);
}

void ft_weapon (t_graf *graf)
{
	int x;
	int y;
	int nb_frame;
	int k = 0;
	nb_frame = 2;
	ft_interface (graf);
	if (graf->weapon_init == 0)
	{
		graf->weapon = (t_image**)malloc(sizeof(t_image)* nb_frame);
		graf->weapon[0] = (t_image*)mlx_xpm_file_to_image(graf->mlx,"sprite/frame.xpm",&x,&y);
		graf->weapon[1] = (t_image*)mlx_xpm_file_to_image(graf->mlx,"sprite/frame2.xpm",&x,&y);
		graf->weapon_init = 1;
	}
	if (graf->shot == 1 && graf->nb_ball > 0)
	{
		if (graf->frame_shot == 0)
		{
			graf->nb_ball--;
			system("afplay sound/shot.wav &");//shot.wav");
		}
		k = 1;
		if (graf->frame_shot != 3)
			graf->frame_shot++;
		else 
		{
			system("afplay sound/SFB-goupille-sol.mp3 &");
			graf->shot = 0;
			graf->frame_shot = 0;
		}
	}
		mlx_put_image_to_window(graf->mlx, graf->win, graf->weapon[k], W_W/2 - graf->weapon[k]->width/2, W_H - graf->weapon[k]->height);
}

void ft_interface (t_graf *graf)
{
	int x;
	int y;
	if (graf->weapon_init == 0)
	{
		graf->amobox = (t_image*)mlx_xpm_file_to_image(graf->mlx,"sprite/ammo.xpm",&x,&y);
	}
	mlx_put_image_to_window(graf->mlx, graf->win, graf->amobox, W_W - 200 , W_H - 150);


}



