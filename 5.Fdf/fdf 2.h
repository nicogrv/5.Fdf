/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasgriveau <nicolasgriveau@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 18:44:51 by ngriveau          #+#    #+#             */
/*   Updated: 2023/01/06 20:05:31 by nicolasgriv      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "get_next_line.h"
# include "./lib/minilibx-linux/mlx.h"
# include <time.h>
# include <math.h>
# include <X11/X.h>
//
//	LINUX: 0		MacOS: 1	LINUX ECOLE: 2	MacBook Air 13.3: 3
//
# define OS 1
//
//	Resolution	
//
# define WIN_WIDTH 1440
# define WIN_HEIGHT 795
//
//	Message error
//
# define MSG_INVALID_MAP "Error invalid map"
//
//	MAPS
//
# define MAP1 "./maps/42.fdf"
# define MAP2 "./maps/pylone.fdf"
# define MAP3 "./maps/worldmap_s.fdf"
# define MAP4 "./maps/t3.fdf"
# define MAP5 "./maps/pentenegpos.fdf"
# define MAP6 "./maps/100-6.fdf"
# define MAP7 "./maps/julia.fdf"
# define MAP8 "./maps/france.fdf"
# define MAP9 "./maps/worldmap.fdf"
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//

# if OS == 0 || OS == 2
#  define TOUCH_LEFTARROW 65361
#  define TOUCH_RIGHTARROW 65363
#  define TOUCH_UPARROW 65362
#  define TOUCH_DOWNARROW 65364
#  define TOUCH_MOINS 45
#  define TOUCH_PLUS 61
#  define TOUCH_ONE 49
#  define TOUCH_TOW 50
#  define TOUCH_THREE 51
#  define TOUCH_FOUR 52
#  define TOUCH_FIVE 53
#  define TOUCH_W 119
#  define TOUCH_A 100
#  define TOUCH_S 115
#  define TOUCH_D 97
#  define ESC 65307
#  define TOUCH_C 99
#  define TOUCH_X 120
#  define TOUCH_M 109
#  define TOUCH_N 110
#  define TOUCH_I 105
#  define TOUCH_P 112
#  if OS == 2
#   define WIDTH 2560
#   define HEIGHT 1310 
#  else
#   define WIDTH WIN_WIDTH
#   define HEIGHT WIN_HEIGHT 
#  endif
# elif OS == 1 || OS == 3
#  define TOUCH_LEFTARROW 123
#  define TOUCH_RIGHTARROW 124
#  define TOUCH_UPARROW 126
#  define TOUCH_DOWNARROW 125
#  define TOUCH_MOINS 27
#  define TOUCH_PLUS 24
#  define TOUCH_ONE 18
#  define TOUCH_TOW 19
#  define TOUCH_THREE 20
#  define TOUCH_W 13
#  define TOUCH_A 0
#  define TOUCH_S 1
#  define TOUCH_D 2
#  define ESC 53
#  define TOUCH_C 8
#  define TOUCH_X 7
#  define TOUCH_M 46
#  define TOUCH_N 45
#  define TOUCH_I 34
#  define TOUCH_P 35
#  define TOUCH_FOUR 21
#  define TOUCH_FIVE 23
#  if OS == 3
#   define WIDTH 1000
#   define HEIGHT 1000
#  else
#   define WIDTH WIN_WIDTH
#   define HEIGHT WIN_HEIGHT 
#  endif
# else
# endif

typedef struct s_pixel
{
	float	x;
	float	y;
	float	z;
	float	h;

}	t_pixel;

typedef struct s_img
{
	void	*i;
	int		size;
	int		p;
	int		e;
	char	*data;
	int		r;
	int		b;
	int		g;
}	t_img;

typedef struct s_line
{
	float	ax;
	float	ay;
	float	bx;
	float	by;
	float	hcolor1;
	float	hcolor2;
	int		reverse;
}	t_line;

typedef struct s_pathmap
{
	char	*map0;
	char	*map1;
	char	*map2;
	char	*map3;
	char	*map4;
	char	*map5;
	char	*map6;
	char	*map7;
	char	*map8;
	char	*map9;
	char	*currentmap;
	int		indexmap;
}	t_pathmap;

typedef struct s_map
{
	t_pixel			**initm;
	t_pixel			**m;
	t_line			line;
	t_pathmap		pathmap;
	int				x;
	int				y;
	float			minh;
	float			maxh;

	float			z;
	float			r;
	float			i;
	int				movex;
	int				movey;

	float			hauteur;

	unsigned long	color[101];
	int				setupcolor;

	void			*mlx;
	void			*mlx_win;
	int				winx;
	int				winy;
	t_img			img;

	int				mouse_move;
	float			varcos;
	float			varsin;
	int				verifmonitor;
	int				verifprojection;
}	t_map;

//		COLOR_MAP
void	ft_setup_color_pt1(t_map *m);
void	ft_setup_color_pt2(t_map *m);
void	ft_setup_color_pt3(t_map *m);

//		COLOR CALCUL
void	ft_color(int nbr, t_map *m);
void	ft_draw(t_map *m, float x, float y, int color);
void	ft_tab_deg(t_map *m, int start, int end);
void	ft_tab_color(t_map *m);
void	ft_init_color(t_map *m);

//		MONITORING
void	ft_monitoring_invalid_map(t_map *m);
void	ft_monitoring_display_info_pt1(t_map *m);
void	ft_monitoring_display_info_pt2(t_map *m);
void	ft_monitoring_display_info_pt3(t_map *m);
void	ft_monitoring_fade_color(t_map *m);
void	ft_monitoring(t_map *m);

//		LINE
void	ft_line_direction_pt1(float dx, float unity, float tmp, t_map *m);
void	ft_line_direction_pt2(float dy, float unity, float tmp, t_map *m);
void	ft_line_direction_pt3(float dy, float unity, float tmp, t_map *m);
void	ft_reverse_direction(float tmp, t_map *m);
void	ft_ligne(t_map *m);

//		LINE COLOR
int		ft_color_line(float nbpix, float pospix, t_map *m);
int		ft_color_line_down(float nbpix, float pospix, float deltah, t_map *m);
int		ft_color_line_up(float nbpix, float pospix, float deltah, t_map *m);

//		MAP
int		ft_x_map(char *ligne, int xmax);
int		ft_y_map(int fd, int *xmax);
int		ft_fill_map(t_map *m, int fd);
int		ft_fill_map_pt2(t_map *m, char *ligne, int y);
int		ft_copy_map(t_map *map);
int		ft_map(t_map *m);

//		MAP CALCUL
void	ft_hauteur(t_map *m);
void	ft_rota(t_map *m);
void	ft_incl(t_map *m);
void	ft_centre(t_map *m);
void	ft_move(t_map *m);

//		KEY MOUSE
void	ft_mouse_move(int x, int y, t_map *m);
int		ft_zoom(int keycode, int x, int y, t_map *m);
int		ft_key(int keycode, t_map *m);
void	ft_key_pt2(int keycode, t_map *m);
void	ft_key_pt3(int keycode, t_map *m);
void	ft_key_pt4(int keycode, t_map *m);
void	ft_init_path_map(t_map *m);
void	ft_intdex_map(t_map *m);

//		PRINT MAP
void	ft_print_map(t_map *m);
void	ft_print_map_y(int x, int y, t_map *m);
void	ft_print_map_x(int x, int y, t_map *m);

//		CLEAN
void	ft_free_map(t_map *m, int exit);
void	ft_clean_mac(t_map *m);
void	ft_clean(t_map *m);
int		ft_error_malloc_copy(t_map *m, int index, int y);
int		ft_error_malloc_init(int y, t_map *m);
int		ft_error_malloc_copy(t_map *m, int index, int y);

// 		ANIMATION
void	ft_annimation(t_map *m);
void	ft_annimationpt2(t_map *m);

//		START
int		ft_all(t_map *m);
int		ft_intivalue(t_map *m);
int		main(int argc, char **argv);
int		ft_cross_close(t_map *m);

//		MLX INIT
int		ft_init_mlx(t_map *m);

#endif
