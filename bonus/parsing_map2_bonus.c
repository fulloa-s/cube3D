/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map2_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fulloa-s <fulloa-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 14:15:11 by fulloa-s          #+#    #+#             */
/*   Updated: 2021/04/08 17:23:24 by fulloa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	ft_checkparsing(t_parse *parsing, char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ')
		i++;
	if (line[i] == 'R')
		set_res(parsing, line, i);
	else if (line[i] == 'N' && line[i + 1] == 'O')
		set_texture_and_color_no(parsing, line, i);
	else if (line[i] == 'S' && line[i + 1] == 'O')
		set_texture_and_color_so(parsing, line, i);
	else if (line[i] == 'W' && line[i + 1] == 'E')
		set_texture_and_color_we(parsing, line, i);
	else if (line[i] == 'E' && line[i + 1] == 'A')
		set_texture_and_color_ea(parsing, line, i);
	else if (line[i] == 'S' && line[i + 1] == ' ')
		set_texture_and_color_s(parsing, line, i);
	else if (line[i] == 'F' && line[i + 1] == ' ')
		set_texture_and_color_f(parsing, line, i);
	else if (line[i] == 'C' && line[i + 1] == ' ')
		set_texture_and_color_c(parsing, line, i);
	else if (line[i] != ' ' && line[i] != '\0')
		ft_error("Parsing Error");
}

int	check_var(t_parse *parsing)
{
	if (parsing->resx != 0 && parsing->resy != 0 \
	 && parsing->no != NULL && parsing->so != NULL \
	 && parsing->we != NULL && parsing->ea != NULL \
	 && parsing->s != NULL && parsing->f != NULL \
	 && parsing->c != NULL)
		return (1);
	else
		return (0);
}

int	check_emptyline(char *line, t_parse *parsing)
{
	if (parsing->map != NULL)
		return (0);
	if (line[0] == '\0')
		return (1);
	while (*line == ' ')
		line++;
	if (*line == '1' || *line == '0')
		return (0);
	return (1);
}
