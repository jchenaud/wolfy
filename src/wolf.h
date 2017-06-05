/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchenaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 07:19:02 by jchenaud          #+#    #+#             */
/*   Updated: 2017/06/05 07:34:07 by jchenaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef W_W
# define W_W 1280
# include "../minilibx_siera/mlx.h"
# include "key_define.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <fcntl.h>
# include "../libft/libft.h"
# define W_H 720
# define NB_TEXTURE 8

typedef struct		s_image
{
	int				width;
	int				height;
	char			*buff;
}					t_image;

typedef struct		s_three_int
{
	int				n;
	int				n2;
	int				n3;
}					t_three_int;

typedef struct		s_text_help
{
	int				texturechute;
	int				chute;
	int				dat;
	double			ratio;
	double			add;
	int				size_img;
	int				size_text;
	int				texy;
	int				texx;
	double			wallx;
	int				t;
}					t_text_help;

typedef struct		s_graf
{
	int				**map;
	int				map_value;
	void			*mlx;
	void			*win;
	t_image			*img;
	int				*push;
	unsigned int	color;
	float			pos_x;
	float			pos_y;
	float			move_speed;
	float			rot_speed;
	int				map_x;
	int				map_y;
	int				inc_x;
	int				inc_y;
	double			inc_x2;
	double			inc_y2;
	double			dist_v;
	double			dist_h;
	float			dirx;
	float			diry;
	double			planex;
	double			planey;
	int				texture_init;
	t_image			*amobox;
	t_image			**text;
	t_image			**weapon;
	int				weapon_init;
	int				door_not_far;
	int				door_y;
	int				door_x;
	int				tym;
	char			*nb_ball_c;
	int				nb_ball;
	double			raypos_x;
	double			raypos_y;
	double			r_dir_x;
	double			r_dir_y;
	double			wall_d;
	int				vertical0;
	int				frame_shot;
	int				shot;
	int				size;
	int				nb_l;
}					t_graf;

void				put_pixel_to_img(unsigned int color,
						int x, int y, t_graf *graf);
int					key_off(int key, t_graf *graf);
int					key_on(int key, t_graf *graf);
int					main_loop(t_graf *graf);
void				push(t_graf *graf);
void				ft_map(const int fd, t_graf *graf);
void				ft_rotate(t_graf *graf);
void				ft_lateral_move(t_graf *graf);
void				ft_move(t_graf *graf);
void				use(void);
int					main(int ac, char **av);
void				calcul_image(t_graf *graf);
void				ft_trace_sky();
void				draw_wall(int x, int draw_start,
						int draw_end, t_graf *graf);
void				ft_basic_wall(int map_x, int map_y, t_graf *graf);
void				ft_texture_maker(t_graf *graf);
void				draw_wall_texture(int x, int min, int max, t_graf *graf);
void				ft_weapon (t_graf *graf);
void				ft_spawn(t_graf *graf);
void				ft_interface(t_graf *graf);

void				map_gen(int argc, char **argv);
#endif
