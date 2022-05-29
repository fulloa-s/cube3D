/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_var.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fulloa-s <fulloa-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 10:26:47 by fulloa-s          #+#    #+#             */
/*   Updated: 2021/04/08 13:54:34 by fulloa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_checkcolor_norme(char *str, int i, int *color)
{
	int	x;

	x = 0;
	while (str[i])
	{
		if (str[i] && ft_isdigit(str[i]))
		{
			if (color[x] == 256)
				color[x] = 0;
			color[x] = (10 * color[x]) + (str[i] - '0');
		}
		else if (str[i] && !ft_isdigit(str[i]))
		{
			if (str[i] == ',')
				x++;
			else if (str[i] != ' ')
				ft_error("Color Error: not valid color");
		}
		i++;
	}
	return (x);
}

int	ft_checkcolor(char *str, int *color, int check)
{
	int	i;
	int	x;

	i = 0;
	if (!ft_isdigit(str[i]))
		ft_error("Color Error: not valid color");
	x = ft_checkcolor_norme(str, i, color);
	if (x != 2)
		ft_error("Color Error");
	check = ft_checkvalidcolor(color, check);
	return (check);
}

int	ft_checkvalidcolor(int *color, int check)
{
	int	i;

	i = 0;
	if (check == 1)
		ft_error("Color Error: redefinition of some color");
	while (i < 3)
	{
		if (color[i] > 255)
			ft_error("Color Error: not valid color range");
		i++;
	}
	check = 1;
	return (check);
}

void	ft_warning(char *line, int i)
{
	while (line[i])
	{
		if (line[i] != ' ')
			ft_error("Error: too many args");
		i++;
	}
}
