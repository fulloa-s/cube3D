/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_var2_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fulloa-s <fulloa-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 13:54:12 by fulloa-s          #+#    #+#             */
/*   Updated: 2021/04/08 17:22:04 by fulloa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	ft_checkres(t_parse *parsing, char *line, int i)
{
	if (parsing->check.resolution == 1)
		ft_error("Resolution Error: redefinition of res");
	while (line[i])
	{
		if (line[i] != ' ')
			ft_error("Resolution Error: problem with args");
		i++;
	}
	if (parsing->resx == 0 && parsing->resy == 0)
		ft_error("Resolution Error: both res are missing");
	if (parsing->resx == 0 || parsing->resy == 0)
		ft_error("Resolution Error: one res is missing");
	parsing->check.resolution = 1;
}

int	ft_checkpath(char *parsing, char *line, int check, int i)
{
	int	fd;

	if (check == 1)
		ft_error("Path Error: redefinition of some textures");
	ft_warning(line, i);
	fd = open(parsing, O_RDONLY);
	if (fd == -1)
		ft_error("Path Error: not valid file");
	close(fd);
	check = 1;
	return (check);
}
