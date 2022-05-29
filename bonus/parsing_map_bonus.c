/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fulloa-s <fulloa-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 10:53:26 by fulloa-s          #+#    #+#             */
/*   Updated: 2021/04/08 17:23:20 by fulloa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

char	**ft_realloc_tmp(t_parse *parsing)
{
	int		c;
	int		n_line;
	char	**tmp;
	int		i;

	c = 0;
	n_line = parsing->n_line;
	tmp = (char **)malloc(sizeof(char *) * (parsing->n_line + 1));
	if (!(tmp))
		return (NULL);
	parsing->map[parsing->n_line] = NULL;
	while (n_line--)
	{
		i = ft_strlen(parsing->map[c]);
		tmp[c] = (char *)malloc(sizeof(char) * (i + 1));
		if (!(tmp[c]))
			return (NULL);
		tmp[c] = ft_memcpy(tmp[c], parsing->map[c], i);
		tmp[c][i] = '\0';
		free(parsing->map[c++]);
	}
	free(parsing->map);
	return (tmp);
}

void	ft_reallocfinal(t_parse *parsing, char *line, int c, int i)
{
	i = ft_strlen(line);
	parsing->map[c] = (char *)malloc(sizeof(char) * (i + 1));
	if (!(parsing->map[c]))
		return ;
	parsing->map[c] = ft_memcpy(parsing->map[c], line, i);
	parsing->map[c][i] = '\0';
}

void	ft_realloc(t_parse *parsing, char *line)
{
	int		i;
	int		c;
	int		n_line;
	char	**tmp;

	tmp = ft_realloc_tmp(parsing);
	n_line = parsing->n_line;
	parsing->n_line++;
	parsing->map = malloc(sizeof(char *) * (parsing->n_line + 1));
	if (!(parsing->map))
		return ;
	parsing->map[parsing->n_line] = NULL;
	c = 0;
	while (n_line--)
	{
		i = ft_strlen(tmp[c]);
		parsing->map[c] = (char *)malloc(sizeof(char) * (i + 1));
		if (!(parsing->map[c]))
			return ;
		parsing->map[c] = ft_memcpy(parsing->map[c], tmp[c], i);
		parsing->map[c][i] = '\0';
		free(tmp[c++]);
	}
	free(tmp);
	ft_reallocfinal(parsing, line, c, i);
}

void	ft_map(t_parse *parsing, char *line)
{
	int	i;

	if (parsing->map == NULL)
	{
		parsing->map = (char **)malloc(sizeof(char *) * (2));
		if (!(parsing->map))
			return ;
		parsing->map[1] = NULL;
		i = ft_strlen(line);
		parsing->map[0] = (char *)malloc(sizeof(char) * (i + 1));
		if (!(parsing->map[0]))
			return ;
		parsing->map[0] = ft_memcpy(parsing->map[0], line, i);
		parsing->map[0][i] = '\0';
	}
	else
		ft_realloc(parsing, line);
}

void	ft_parsing_map(char **argv, t_parse *parsing)
{
	int		fd;
	char	*line;
	int		r;

	r = 1;
	line = NULL;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		ft_error("Error with .cub file");
	listinit(parsing);
	while (r)
	{
		r = get_next_line(fd, &line, parsing);
		if (check_emptyline(line, parsing) == 0)
			ft_map(parsing, line);
		else
			ft_checkparsing(parsing, line);
		free(line);
	}
	if (!check_var(parsing))
		ft_error("Map Error: missing some info");
	close(fd);
	ft_checkmap(parsing);
}
