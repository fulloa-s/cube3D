/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fulloa-s <fulloa-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 10:27:08 by fulloa-s          #+#    #+#             */
/*   Updated: 2021/04/08 12:42:17 by fulloa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*fill_line(char *memory, char *line)
{
	int	i;
	int	y;

	i = 0;
	if (!memory)
		return (NULL);
	while (memory[i] != '\n' && memory[i])
		i++;
	line = (char *)malloc(sizeof(char) * (i + 1));
	if (!(line))
		return (NULL);
	y = 0;
	while (y < i)
	{
		line[y] = memory[y];
		y++;
	}
	line[y] = '\0';
	return (line);
}

char	*clean_memory(char *memory)
{
	int		i;
	char	*cleanedmem;
	int		y;

	i = 0;
	if (!memory)
		return (NULL);
	y = ft_strlen(memory);
	while (memory[i] && memory[i] != '\n')
		i++;
	cleanedmem = (char *)malloc(sizeof(char) * (y - i + 1));
	if (!(cleanedmem))
		return (NULL);
	y = 0;
	while (memory[i])
	{
		i++;
		cleanedmem[y] = memory[i];
		y++;
	}
	cleanedmem[y] = '\0';
	free(memory);
	return (cleanedmem);
}

int	tofree(char *buff)
{
	free(buff);
	return (-1);
}

int	defr(char **line, int fd)
{
	int	r;

	if (!line || BUFFER_SIZE <= 0 || fd < 0)
		r = -1;
	else
		r = 1;
	return (r);
}

int	get_next_line(int fd, char **line, t_parse *parsing)
{
	char			*buff;
	static char		*memory;

	parsing->r = defr(line, fd);
	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (parsing->r == -1 || !(buff))
		return (-1);
	while (!ft_strchr(memory, '\n') && parsing->r != 0)
	{
		parsing->r = read(fd, buff, BUFFER_SIZE);
		if (parsing->r == -1)
			return (tofree(buff));
		buff[parsing->r] = '\0';
		memory = ft_strjoin(memory, buff);
	}
	free(buff);
	*line = fill_line(memory, *line);
	memory = clean_memory(memory);
	if (parsing->r == 0)
	{
		free(memory);
		memory = NULL;
		return (0);
	}
	return (1);
}
