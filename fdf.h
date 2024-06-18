/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyathams <pyathams@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 14:10:33 by pyathams          #+#    #+#             */
/*   Updated: 2024/06/18 18:47:51 by pyathams         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <stdlib.h>
# include <fcntl.h>
# include "libft/inc/libft.h"
# include "libft/inc/get_next_line.h"
# include "libft/inc/ft_printf.h"
# include <limits.h>
# include <unistd.h>
# include <stdio.h>
# include <ctype.h>

# ifndef LHEX
#  define LHEX "0123456789ABCDEF"
# endif

# ifndef WHITE
#  define WHITE 0xFFFFFF
# endif

# ifndef WIN_H
#  define WIN_H 720
# endif

# ifndef WIN_W
#  define WIN_W 1280
# endif

# ifndef KEYCODES_H
#  define KEYCODES_H
#  define KEY_ESC 27
#  define KEY_UP 256
#  define KEY_DOWN 258
#  define KEY_LEFT 260
#  define KEY_RIGHT 261
#  define KEY_W 119
#  define KEY_S 115
#  define KEY_A 97
#  define KEY_D 100
#  define KEY_P 112
#  define KEY_MINUS 45
#  define KEY_PLUS 61
#  define KEY_R 114
#  define KEY_U 117
#  define KEY_J 106
#  define KEY_I 105
#  define KEY_K 107
#  define KEY_O 111
#  define KEY_L 108
# endif

# ifndef SHIFT
#  define SHIFT 10
# endif
# ifndef ROT_SHIFT
#  define ROT_SHIFT 0.05
# endif
# ifndef ZOOM_SHIFT
#  define ZOOM_SHIFT 0.5
# endif

typedef struct s_map
{
	int	w;
	int	h;
	int	**zdir_mt;
	int	**clrs;
	int	iscolor;
	int	min_z;
	int	max_z;
}	t_map;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		sz_l;
	int		endian;
}	t_img;


typedef struct s_vars
{
	void	*mlx_connection;
	void	*window;
	t_map	*map;
	t_img	*img;
	int		shift_x;
	int		shift_y;
	float	zoom;
	int		iso;
	float	flat;
	float	rot_x;
	float	rot_y;
	float	rot_z;
}	t_vars;


void	args_handle(t_map **map, int argc, char **argv);
t_map	*width_height_map(char *file);
int		count_numbers(t_map *map, char *line);
void	free_split(char **split);
void	error_exit(void);
void	perror_exit(const char *str);
void	free_map(t_map *map);
int		ft_atoi_base(const char *str, const char *base);
void	malloc_map(t_map *map);
void	zdir_map(t_map *map, char *file);
void	filling_zdir(t_map *map, int fd);
int		color_line(t_map *map, char *s);
void	char_tolower(char *c);
void	get_min_max_z(t_map *map);
int		ft_isspace(int c);
void	ft_striter(char *s, void (*f)(char *));
int		mlx_main(t_map	*map);
int		initialise_vars(t_vars *vars, t_map *map);
void	reset_vars(t_vars *vars);
int		ft_max(int a, int b);
void	initialise_mlx(t_vars	*vars);
int		key_hook(int keycode, t_vars *vars);

#endif