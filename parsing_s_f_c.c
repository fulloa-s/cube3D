/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_s_f_c.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fulloa-s <fulloa-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 14:35:08 by fulloa-s          #+#    #+#             */
/*   Updated: 2021/04/08 12:44:11 by fulloa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	set_texture_and_color_s(t_parse *parsing, char *line, int i)
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
	parsing->s = (char *)malloc(sizeof(char) * (c + 1));
	if (!(parsing->s))
		return (-1);
	c = 0;
	while (line[z] && line[z] != ' ')
	{
		parsing->s[c] = line[z];
		c++;
		z++;
	}
	parsing->s[c] = '\0';
	parsing->check.s = ft_checkpath(parsing->s, line, parsing->check.s, i);
	return (0);
}

int	set_texture_and_color_f(t_parse *parsing, char *line, int i)
{
	int	c;
	int	z;

	c = 0;
	i += 2;
	while (line[i] == ' ')
		i++;
	z = i;
	while (line[i++])
		c++;
	parsing->f = (char *)malloc(sizeof(char) * (c + 1));
	if (!(parsing->f))
		return (-1);
	c = 0;
	while (line[z])
	{
		parsing->f[c] = line[z];
		c++;
		z++;
	}
	parsing->f[c] = '\0';
	parsing->check.f = ft_checkcolor(parsing->f, parsing->f_color, \
	parsing->check.f);
	return (0);
}

int	set_texture_and_color_c(t_parse *parsing, char *line, int i)
{
	int	c;
	int	z;

	c = 0;
	i += 2;
	while (line[i] == ' ')
		i++;
	z = i;
	while (line[i++])
		c++;
	parsing->c = (char *)malloc(sizeof(char) * (c + 1));
	if (!(parsing->c))
		return (-1);
	c = 0;
	while (line[z])
	{
		parsing->c[c] = line[z];
		c++;
		z++;
	}
	parsing->c[c] = '\0';
	parsing->check.c = ft_checkcolor(parsing->c, parsing->c_color, \
	parsing->check.c);
	return (0);
}
