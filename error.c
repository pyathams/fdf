/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyathams <pyathams@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 14:30:47 by pyathams          #+#    #+#             */
/*   Updated: 2024/06/16 15:48:10 by pyathams         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	error_exit(void)
{
	write(2, "ERROR INVALID ARGUMENTS", 24);
	exit(EXIT_FAILURE);
}

void	perror_exit(const char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}