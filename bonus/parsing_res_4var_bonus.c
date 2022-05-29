/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_res_4var_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fulloa-s <fulloa-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 11:10:50 by fulloa-s          #+#    #+#             */
/*   Updated: 2021/04/08 17:23:46 by fulloa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	set_res(t_parse *parsing, char *line, int i)
{
	i++;
	while (line[i] == ' ')
		i++;
	while (ft_isdigit(line[i]))
	{
		parsing->resx = (10 * parsing->resx) + (line[i] - '0');
		i++;
	}
	while (line[i] == ' ')
		i++;
	while (ft_isdigit(line[i]))
	{
		parsing->resy = (10 * parsing->resy) + (line[i] - '0');
		i++;
	}
	ft_checkres(parsing, line, i);
}

int	set_texture_and_color_no(t_parse *parsing, char *line, int i)
{
	int	c;
	int	z;

	c = 0;
	i += 2;
	while (line[i] == ' ')
		i++;
	z = i;
	while (line[i] && line[i++] != ' ')
		c++;
	parsing->no = (char *)malloc(sizeof(char) * (c + 1));
	if (!(parsing->no))
		return (-1);
	c = 0;
	while (line[z] && line[z] != ' ')
	{
		parsing->no[c] = line[z];
		c++;
		z++;
	}
	parsing->no[c] = '\0';
	parsing->check.no = ft_checkpath(parsing->no, line, parsing->check.no, i);
	return (0);
}

int	set_texture_and_color_so(t_parse *parsing, char *line, int i)
{
	int	c;
	int	z;

	c = 0;
	i += 2;
	while (line[i] == ' ')
		i++;
	z = i;
	while (line[i] && line[i++] != ' ')
		c++;
	parsing->so = (char *)malloc(sizeof(char) * (c + 1));
	if (!(parsing->so))
		return (-1);
	c = 0;
	while (line[z] && line[z] != ' ')
	{
		parsing->so[c] = line[z];
		c++;
		z++;
	}
	parsing->so[c] = '\0';
	parsing->check.so = ft_checkpath(parsing->so, line, parsing->check.so, i);
	return (0);
}

int	set_texture_and_color_we(t_parse *parsing, char *line, int i)
{
	int	c;
	int	z;

	c = 0;
	i += 2;
	while (line[i] == ' ')
		i++;
	z = i;
	while (line[i] && line[i++] != ' ')
		c++;
	parsing->we = (char *)malloc(sizeof(char) * (c + 1));
	if (!(parsing->we))
		return (-1);
	c = 0;
	while (line[z] && line[z] != ' ')
	{
		parsing->we[c] = line[z];
		c++;
		z++;
	}
	parsing->we[c] = '\0';
	parsing->check.we = ft_checkpath(parsing->we, line, parsing->check.we, i);
	return (0);
}

int	set_texture_and_color_ea(t_parse *parsing, char *line, int i)
{
	int	c;
	int	z;

	c = 0;
	i += 2;
	while (line[i] == ' ')
		i++;
	z = i;
	while (line[i] && line[i++] != ' ')
		c++;
	parsing->ea = (char *)malloc(sizeof(char) * (c + 1));
	if (!(parsing->ea))
		return (-1);
	c = 0;
	while (line[z] && line[z] != ' ')
	{
		parsing->ea[c] = line[z];
		c++;
		z++;
	}
	parsing->ea[c] = '\0';
	parsing->check.ea = ft_checkpath(parsing->ea, line, parsing->check.ea, i);
	return (0);
}
