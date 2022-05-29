/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fulloa-s <fulloa-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 14:09:26 by fulloa-s          #+#    #+#             */
/*   Updated: 2021/04/08 14:09:54 by fulloa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_minimap(t_win_data *win)
{
	int	y;
	int	x;

	y = 0;
	while (win->resolution.x_max * win->img.size_pixel > win->resx)
		win->img.size_pixel--;
	while (win->resolution.n_line * win->img.size_pixel > win->resy)
		win->img.size_pixel--;
	while (win->map[y])
	{
		x = 0;
		while (win->map[y][x])
		{
			if (win->map[y][x] == '1')
				my_mlx_pixel_put2(&win->img, x * win->img.size_pixel, \
				y * win->img.size_pixel, 0x00FFFFFF);
			if (win->map[y][x] == '2')
				my_mlx_pixel_put2(&win->img, x * win->img.size_pixel, \
				y * win->img.size_pixel, 0x00FF0000);
			x++;
		}
		y++;
	}
	my_mlx_pixel_put2(&win->img, (int)win->rayc.posx * win->img.size_pixel, \
	(int)win->rayc.posy * win->img.size_pixel, 0x00FF00FF);
}
