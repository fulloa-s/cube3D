/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitmap_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fulloa-s <fulloa-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 14:00:41 by fulloa-s          #+#    #+#             */
/*   Updated: 2021/04/08 17:21:49 by fulloa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	bmp_print(t_win_data *win, int fd)
{
	int	x;
	int	y;
	int	dst;
	int	resx;
	int	resy;

	resx = (int)win->resx;
	resy = (int)win->resy;
	y = resy - 1;
	dst = 0;
	while (y >= 0)
	{
		x = 0;
		while (x < resx)
		{
			dst = (*(int *)(win->img.addr + \
			(y * win->img.line_length + (x * 4))));
			write(fd, &dst, 4);
			x++;
		}
		y--;
	}
}

void	bmp_header_2(t_win_data *win, int fd)
{
	int		plane;
	int		color;
	int		imgsize;
	int		resx;
	int		resy;

	plane = 1;
	color = 0;
	resx = (int)win->resx;
	resy = (int)win->resy;
	imgsize = resx * (resy - 1) * 4;
	write(fd, &plane, 2);
	write(fd, &win->img.bpp, 2);
	write(fd, "\0\0\0\0", 4);
	write(fd, &imgsize, 4);
	write(fd, &color, 4);
	write(fd, &color, 4);
	write(fd, &color, 4);
	write(fd, &color, 4);
}

void	bmp_header(t_win_data *win, int fd)
{
	int		filesize;
	int		offset;
	int		infoheader;
	int		resx;
	int		resy;

	offset = 54;
	infoheader = 40;
	resx = (int)win->resx;
	resy = (int)win->resy;
	filesize = resx * resy * 4 + 54;
	write(fd, "BM", 2);
	write(fd, &filesize, 4);
	write(fd, "\0\0\0\0", 4);
	write(fd, &offset, 4);
	write(fd, &infoheader, 4);
	write(fd, &resx, 4);
	write(fd, &resy, 4);
}

int	ft_bitmap(t_win_data *win)
{
	int	fd;

	fd = open("screenshot.bmp", O_CREAT | O_WRONLY, 00755);
	bmp_header(win, fd);
	bmp_header_2(win, fd);
	bmp_print(win, fd);
	close(fd);
	return (1);
}
