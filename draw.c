/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyathams <pyathams@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 18:49:04 by pyathams          #+#    #+#             */
/*   Updated: 2024/06/19 20:45:16 by pyathams         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_rectangle(t_vars *vars, int width, int height)
{
	int	i;
	int	j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			img_pixel_put(vars, j, i, 0xFFAA00);
			j++;
		}
		i++;
	}
}

void	draw_menu(t_vars *vars)
{
	int		y;
	void	*mlx;
	void	*win;

	mlx = vars->mlx_connection;
	win = vars->window;
	y = 0;
	draw_rectangle(vars, 175, 1280);
	mlx_string_put(mlx, win, 15, y += 15, BLACK, "Controls:");
	mlx_string_put(mlx, win, 15, y += 50, BLACK, "Reset: R");
	mlx_string_put(mlx, win, 15, y += 25, BLACK, "Move: W, A, S, D");
	mlx_string_put(mlx, win, 15, y += 25, BLACK, "Zoom: Arrows");
	mlx_string_put(mlx, win, 15, y += 25, BLACK, "Flattening: + / -");
	mlx_string_put(mlx, win, 15, y += 25, BLACK, "Rotate:");
	mlx_string_put(mlx, win, 30, y += 25, BLACK, "  x (+ / -): U / J");
	mlx_string_put(mlx, win, 30, y += 25, BLACK, "  y (+ / -): I / K");
	mlx_string_put(mlx, win, 30, y += 25, BLACK, "  z (+ / -): O / L");
	mlx_string_put(mlx, win, 15, y += 25, BLACK, "Toggle Perspective: P");
	mlx_string_put(mlx, win, 15, y += 25, BLACK, "(Isometric and Parallel)");
}

int	ft_abs(int a)
{
	if (a < 0)
		return (-(a));
	return (a);
}

void	initialise_bresenham(t_point *start, t_point *end,
	t_point *delta, t_point *sign)
{
	delta->x = ft_abs(end->x - start->x);
	delta->y = ft_abs(end->y - start->y);
	sign->x = -1;
	sign->y = -1;
	if (start->x < end->x)
		sign->x = 1;
	if (start->y < end->y)
		sign->y = 1;
}

void	bresenham(t_vars *vars, t_point start, t_point end)
{
	t_point	cur;
	t_point	sign;
	t_point	delta;
	int		line;
	int		tmp;

	initialise_bresenham(&start, &end, &delta, &sign);
	line = delta.x -delta.y;
	cur = start;
	while (cur.x != end.x || cur.y != end.y)
	{
		img_pixel_put(vars, cur.x, cur.y, get_color(cur, start, end, delta));
		tmp = line * 2;
		if (tmp > -delta.y)
		{
			line -= delta.y;
			cur.x += sign.x;
		}
		if (tmp < delta.x)
		{
			line += delta.x;
			cur.y += sign.y;
		}
	}
}

void	draw(t_vars *vars)
{
	int	x;
	int	y;

	ft_bzero(vars->img->addr, WIN_H * WIN_W * (vars->img->bpp / 8));
	if (vars->zoom)
	{
		y = -1;
		while (++y < vars->map->h)
		{
			x = -1;
			while (++x < vars->map->w)
			{
				if (x < vars->map->w - 1)
					bresenham(vars, get_coords(vars, new_point(x, y, vars)),
						get_coords(vars, new_point(x + 1, y, vars)));
				if (y < vars->map->h - 1)
					bresenham(vars, get_coords(vars, new_point(x, y, vars)),
						get_coords(vars, new_point(x, y + 1, vars)));
			}
		}
	}
	mlx_put_image_to_window(vars->mlx_connection,
		vars->window, vars->img->img, 0, 0);
	draw_menu(vars);
}
