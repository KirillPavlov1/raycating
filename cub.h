/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvirgin <cvirgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 16:46:16 by cvirgin           #+#    #+#             */
/*   Updated: 2021/04/13 17:18:49 by cvirgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# define SCALE 10
# include "libft/libft.h"
# include <math.h>
# include <stdio.h>
# include <fcntl.h>
# include "libmlx/mlx.h"

typedef struct	s_im{
	void	*img;
	void	*addr;
	int		bpp;
	int		len;
	int		endian;
	int		x;
	int		y;
}				t_img;

typedef struct	s_sprite{
	double			x;
	double			y;
	int				visible;
	double			dis;
	int				startx;
	int				endx;
	struct s_sprite	*next;
}				t_sprite;
typedef struct	s_mlx
{
	t_sprite	*item;
	char		**map;
	void		*mlx;
	void		*mlx_win;
	double		angle;
	int			lineheight;
	int			pl;
	t_img		image[5];
	int			rayx;
	int			rayy;
	int			state;
	int			color_c;
	int			color_f;
	int			screen;
	int			w;
	int			a;
	int			s;
	int			d;
	int			l;
	int			r;
	int			map_start;
	double		*z;
	struct	{
		double	x;
		double	y;
	}			s_player;
	struct	{
		double	x;
		double	y;
		double	start;
		double	end;
	}			s_ray;
	struct	{
		double	x;
		double	y;
	}			s_dir;
	struct	{
		double	x;
		double	y;
	}			s_ray_dir;
	struct	{
		double	x;
		double	y;
	}			s_plane;
	struct	{
		double	x;
		double	y;
	}			s_net;
	struct	{
		double	x;
		double	y;
	}			s_dot;
	struct	{
		double	x;
		double	y;
	}			s_cross_x;
	struct	{
		double	spritex;
		double	spritey;
		double	transx;
		double	transy;
		double	texy;
		double	texx;
		int		startx;
		int		starty;
		int		endx;
		int		endy;
		int		w;
		int		screenx;
	}			s_ds;
	struct	{
		double	x;
		double	y;
	}			s_cross_y;
	struct	{
		void	*img;
		void	*addr;
		int		bpp;
		int		len;
		int		endian;
	}			s_img1;
	struct	{
		void	*img;
		void	*addr;
		int		bpp;
		int		len;
		int		endian;
	}			s_img2;
	struct	{
		int		res_x;
		int		res_y;
		char	*north;
		char	*south;
		char	*east;
		char	*west;
		char	*sprite;
		struct	{
			int	r;
			int	g;
			int	b;
		}		s_f;
		struct	{
			int	r;
			int	g;
			int	b;
		}		s_c;
	}			s_config;
}				t_mlx;
char			**make_map(t_list *map, int size);
unsigned int	parser(char *line, t_mlx *lib);
void			free2dem(char **str);
void			freemap(t_list *map);
t_mlx			*create_mlx(t_mlx *lib);
t_mlx			*ft_newmlx(void);
void			find_player(t_mlx *lib, char **map);
int				draw_player(t_mlx *lib);
void			draw_map(t_mlx *lib, char **map);
int				run_game(t_mlx *lib);
void			my_mlx_pixel_put(t_mlx *lib, int x, int y, int color);
int				right_side(t_mlx *lib);
int				down_side(t_mlx *lib);
int				up_side(t_mlx *lib);
int				left_side(t_mlx *lib);
void			draw_ray(t_mlx *lib);
void			draw_3d(t_mlx *lib);
void			init_net2(t_mlx *lib);
void			my_mlx_pixel_put2(t_mlx *lib, int x, int y, int color);
int				my_get_color(t_mlx *lib, int x, int y, int i);
int				pour_north(t_mlx *lib, int start, int end, int current);
int				pour_south(t_mlx *lib, int x, int y, int start);
int				pour_east(t_mlx *lib, int x, int y, int start);
int				pour_west(t_mlx *lib, int x, int y, int start);
int				color_set(t_mlx *lib, int x, int y, int current);
int				create_rgb(int r, int g, int b);
int				init_sprites(t_mlx *lib);
void			dis_sprites(t_mlx *lib);
void			draw_sprite(t_mlx *lib);
void			sort_sprites(t_mlx *lib);
int				check_extension(char *file, char *end);
void			make_screen(t_mlx *lib);
int				ft_validator(t_mlx *lib);
int				count_2dem(char **mas);
char			*join_strs(char **str);
int				check_line(char *line);
int				check_255(char **new);
void			ft_error(char *str);
int				only_spaces(char *str);
int				check_onsym(char **new);
void			check_values(t_mlx *lib, t_list **map);
void			init_values(t_mlx *lib);
int				main_check(int argc, char **argv);
int				cross_sprite(t_mlx *lib, int x);
int				cross_parallel(t_mlx *lib, int x, int y);
double			count_n(t_mlx *lib, int x, int y);
int				cross(t_mlx *lib, int x, int y);
int				choose_dot(t_mlx *lib);
void			init_net(t_mlx *lib);
void			nswe(t_mlx *lib);
void			make_unvisible(t_mlx *lib);
void			move_player(t_mlx *lib);
int				parser3(t_mlx *lib, char **str);
int				parser2(t_mlx *lib, char **str);
int				parser_continue5(char **str, t_mlx *lib);
void			init_up_down(t_mlx *lib);
t_sprite		*new_sprite(double x, double y);
void			sprite_add_back(t_sprite **item, t_sprite *new);
#endif
