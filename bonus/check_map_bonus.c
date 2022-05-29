/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fulloa-s <fulloa-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 15:59:17 by fulloa-s          #+#    #+#             */
/*   Updated: 2021/04/08 17:21:53 by fulloa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	ft_crosscheck(t_parse *parsing)
{
	int	x;
	int	y;

	y = 1;
	while (parsing->map[y])
	{
		x = 1;
		while (parsing->map[y][x])
		{
			if (ft_checkchar(parsing->map[y][x]))
			{
				ft_checkline(parsing, y, x);
				if (ft_isvalidchar(parsing->map[y][x - 1]) == 0 \
				 || ft_isvalidchar(parsing->map[y][x + 1]) == 0 \
				 || ft_isvalidchar(parsing->map[y - 1][x]) == 0 \
				 || ft_isvalidchar(parsing->map[y + 1][x]) == 0)
				{
					printf("Map error: Invalid around [%d,%d]\n", y, x);
					exit(0);
				}
			}
			x++;
		}
		y++;
	}
}

void	ft_checkplayer(t_parse *parsing)
{
	int	x;
	int	y;
	int	c;

	y = 0;
	c = 0;
	while (parsing->map[y])
	{
		x = 0;
		while (parsing->map[y][x])
		{
			if (parsing->map[y][x] == 'N' \
			 || parsing->map[y][x] == 'S' \
			 || parsing->map[y][x] == 'W' \
			 || parsing->map[y][x] == 'E')
				c++;
			x++;
		}
		y++;
	}
	if (c != 1)
		ft_error("Error with player");
}

void	ft_checkminimap(t_parse *parsing)
{
	int	y;
	int	min;

	y = 0;
	parsing->x_max = 0;
	while (y < parsing->n_line)
	{
		min = ft_strlen(parsing->map[y]);
		if (min > parsing->x_max)
			parsing->x_max = min;
		y++;
	}
}

void	ft_checkline(t_parse *parsing, int y, int x)
{
	int	l;

	l = (ft_strlen(parsing->map[y - 1]) - 1);
	if (x > l)
		ft_error("Error: Invalid map");
	l = (ft_strlen(parsing->map[y + 1]) - 1);
	if (x > l)
		ft_error("Error: Invalid map");
}

void	ft_checkmap(t_parse *parsing)
{
	if (parsing->map == NULL)
		ft_error("Error: Invalid map");
	ft_checkfirstlast(parsing);
	ft_checkborder(parsing);
	ft_crosscheck(parsing);
	ft_checkplayer(parsing);
	ft_checkminimap(parsing);
}
