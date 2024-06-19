/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyathams <pyathams@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 14:10:13 by pyathams          #+#    #+#             */
/*   Updated: 2024/06/19 20:29:32 by pyathams         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_map	*map;
	// int	i;
	// int z;

	map = NULL;
	args_handle(&map, argc, argv);
	mlx_main(map);
	// ft_printf("%d %d \n", map->h, map->w);
	// // i = -1;
	// // while (++i < map->h)
	// // {
	// // 	z = -1;
	// // 	while (++z < map->w)
	// // 	{
	// // 		ft_printf("%d ", map->zdir_mt[i][z]);
	// // 	}
	// // 	ft_printf("\n");
	// // }
	// // i = -1;
	// // while (++i < map->h)
	// // {
	// // 	z = -1;
	// // 	while (++z < map->w)
	// // 	{
	// // 		ft_printf("%d ", map->clrs[i][z]);
	// // 	}
	// // 	ft_printf("\n");
	// // }
	free_map(map);
	return (0);
}
