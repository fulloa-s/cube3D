/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fulloa-s <fulloa-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 13:52:03 by fulloa-s          #+#    #+#             */
/*   Updated: 2021/04/08 13:53:27 by fulloa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_checkfirstlast(t_parse *parsing)
{
	int	x;

	x = 0;
	while (parsing->map[0][x])
	{
		if (parsing->map[0][x] != ' ' && parsing->map[0][x] != '1')
			ft_error("Map error: problem in first line");
		x++;
	}
	x = 0;
	while (parsing->map[parsing->n_line - 1][x])
	{
		if (parsing->map[parsing->n_line - 1][x] != ' ' \
		 && parsing->map[parsing->n_line - 1][x] != '1')
			ft_error("Map error: problem in last line");
		x++;
	}
}

int	ft_isvalidchar(char c)
{
	if (c == '1' || c == '0' || c == '2' || c == 'N'
		|| c == 'S' || c == 'W' || c == 'E')
		return (1);
	return (0);
}

void	ft_checkborder(t_parse *parsing)
{
	int	x;
	int	y;

	y = 0;
	while (y < parsing->n_line)
	{
		x = ft_strlen(parsing->map[y]);
		if (parsing->map[y][0] != '1' && parsing->map[y][0] != ' ')
		{
			printf("Map border error: problem on the %d line\n", y);
			exit(0);
		}
		if (parsing->map[y][x - 1] != '1' && parsing->map[y][x - 1] != ' ')
		{
			printf("Map border error: problem on the %d line\n", y);
			exit(0);
		}
		y++;
	}
}

int	ft_checkchar(char c)
{
	if (c == '0' || c == '2' || c == 'N'
		|| c == 'S' || c == 'W' || c == 'E')
		return (1);
	return (0);
}
