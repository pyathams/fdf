/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyathams <pyathams@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 14:10:33 by pyathams          #+#    #+#             */
/*   Updated: 2024/06/16 17:49:29 by pyathams         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <stdlib.h>
# include <fcntl.h>
# include "libft/inc/libft.h"
# include "libft/inc/get_next_line.h"
# include "libft/inc/ft_printf.h"
# include <unistd.h>
# include <stdio.h>
# include <ctype.h>

#define LHEX "0123456789ABCDEF"
# define WHITE 0xFFFFFF

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

#endif