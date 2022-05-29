/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fulloa-s <fulloa-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 14:11:56 by fulloa-s          #+#    #+#             */
/*   Updated: 2021/04/08 14:07:06 by fulloa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	my_mlx_pixel_put(t_img_data *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

void	my_mlx_pixel_put2(t_img_data *img, int x, int y, int color)
{
	char	*dst;
	int		h;
	int		l;
	int		i;

	h = 0;
	l = 0;
	while (h < img->size_pixel)
	{
		l = 0;
		i = 0;
		while (l < img->size_pixel)
		{
			dst = img->addr + (y * img->line_length + (x + i) * (img->bpp / 8));
			*(unsigned int *)dst = color;
			i++;
			l++;
		}
		h++;
		y++;
	}	
}

void	draw_dot(t_win_data *win, int x, int y, int color)
{
	char	b;
	char	g;
	char	r;
	int		i;

	if (color == 256 * 256 * 256 + 256 * 256 + 256)
		return ;
	b = color % 256;
	g = (color / 256) % 256;
	r = (color / 256 / 256) % 256;
	i = (win->img.line_length * y) + (x * ((double)win->img.bpp / 8));
	win->img.addr[i] = b;
	win->img.addr[i + 1] = g;
	win->img.addr[i + 2] = r;
	win->img.addr[i + 3] = 0;
}
