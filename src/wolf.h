#include  "../minilibx_siera/mlx.h"//"mlx.h"
#include "key_define.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <fcntl.h>
#include "../libft/libft.h"
#define W_W 1280
#define W_H 720
#define NB_TEXTURE 8




typedef struct		s_image
{
	int				width;
	int				height;
	char			*buff;
	//float			vertexes[8];
	//struct s_image	*next;
}					t_image;

// struct	s_map
// {
// 	int		size;
// 	int 	nb_l;
// }
// t_map;

typedef struct s_text_help
{
	int texturechute;
	int chute;
	int dat;
	double ratio;
	double add;
	int size_img;
	int size_text;
	int texy;
	int texx;
	double wallx;
	int t;
}				t_text_help;

typedef struct 	s_vec
{
	double raypos_x;
	double raypos_y;
	double r_dir_x;
	double r_dir_y;
}				t_vec;


typedef struct	s_graf
{
	int			**map;
	int 		map_value;
	void		*mlx;
	void		*win;
	t_image		*img;
	int			*push;
	unsigned int color;
	float		pos_x;
	float		pos_y;
	float		move_speed;
	float 		rot_speed;
	//float		angle;
	float 		dirx;
	float		diry;
	double		Planex;
	double 		Planey;
	int 		texture_init;
	t_image		*amobox;
	t_image     **text;
	t_image     **weapon;
	int 		weapon_init;
	int 		door_not_far;
	int 		door_y;
	int 		door_x;
	int 		time;
	char		*nb_ball_c;
	int 		nb_ball;
	// t_image		*text1;
	// t_image 	*text2;
	// t_image  	*text3;
	// t_image 	*text4;
	// t_image 	*text5;
	// _image  	*text6;
	// t_image 	*text7;
	// t_image 	*text8;

	//t_vec		*vec;
	double raypos_x;
	double raypos_y;
	double r_dir_x;
	double r_dir_y;
	double wall_d;
	int 	vertical0;
	int 	frame_shot;
	int 	shot;
	int		size;
	int 	nb_l;

}				t_graf;




//t_graf 		*graf(void);
//void		put_pixel_to_img(unsigned int color, int x, int y);
void	put_pixel_to_img(unsigned int color, int x, int y,t_graf *graf);
int			key_off(int key,t_graf *graf);
int			key_on(int key, t_graf *graf);
int			main_loop(t_graf *graf);
void		push(t_graf *graf);
void		ft_map(const int fd,t_graf *graf);
void 		init(int ac, char **av,t_graf *graf);
void		ft_rotate(t_graf *graf);
//static void rotate_left(t_graf *graf);
void		ft_lateral_move(t_graf *graf);
void    	ft_move(t_graf *graf);



//t_graf		init(int ac, char **av);
int 		main(int ac, char **av);
void 		calcul_image(t_graf *graf);
void 		ft_trace_sky();
void 	draw_wall(int x, int draw_start, int draw_end, t_graf *graf);
void	ft_basic_wall(int map_x, int map_y,t_graf *graf);
void	ft_texture_maker(t_graf *graf);
void   draw_wall_texture(int x, int min, int max, t_graf *graf);
void	ft_weapon (t_graf *graf);
void    ft_spawn(t_graf *graf);
void ft_interface (t_graf *graf);





