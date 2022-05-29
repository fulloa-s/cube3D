/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fulloa-s <fulloa-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 14:25:57 by fulloa-s          #+#    #+#             */
/*   Updated: 2021/04/08 14:26:28 by fulloa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_textured_floorceiling(t_win_data *win)
{
	win->rayc.raydirx0 = win->rayc.dirx - win->rayc.planex;
	win->rayc.raydiry0 = win->rayc.diry - win->rayc.planey;
	win->rayc.raydirx1 = win->rayc.dirx + win->rayc.planex;
	win->rayc.raydiry1 = win->rayc.diry + win->rayc.planey;
	win->rayc.posz = 0.5 * win->resy;
	win->rayc.rowdistance = win->rayc.posz / (win->rayc.y - win->resy / 2);
	win->rayc.floorstepx = win->rayc.rowdistance * \
	(win->rayc.raydirx1 - win->rayc.raydirx0) / win->resx;
	win->rayc.floorstepy = win->rayc.rowdistance * \
	(win->rayc.raydiry1 - win->rayc.raydiry0) / win->resx;
	win->rayc.floorx = win->rayc.posx + win->rayc.rowdistance * \
	win->rayc.raydirx0;
	win->rayc.floory = win->rayc.posy + win->rayc.rowdistance * \
	win->rayc.raydiry0;
}

void	floor_ceiling(t_win_data *win)
{
	win->rayc.y = win->resy / 2 + 1;
	while (win->rayc.y < win->resy)
	{
		set_textured_floorceiling(win);
		win->rayc.x = 0;
		while (win->rayc.x < win->resx)
		{
			win->rayc.cellx = (int)(win->rayc.floorx);
			win->rayc.celly = (int)(win->rayc.floory);
			win->rayc.tx = (int)(win->text[0].w * \
			(win->rayc.floorx - win->rayc.cellx)) & (win->text[0].w - 1);
			win->rayc.ty = (int)(win->text[0].h * \
			(win->rayc.floory - win->rayc.celly)) & (win->text[0].h - 1);
			win->rayc.floorx += win->rayc.floorstepx;
			win->rayc.floory += win->rayc.floorstepy;
			win->rayc.color = win->color[0];
			draw_dot(win, win->rayc.x, win->rayc.y, win->rayc.color);
			win->rayc.color = win->color[1];
			draw_dot(win, win->rayc.x, win->resy - \
			win->rayc.y - 1, win->rayc.color);
			++win->rayc.x;
		}
		++win->rayc.y;
	}
}

void	ray_calculations_2(t_win_data *win)
{
	win->rayc.camerax = 2 * win->rayc.x / (double)win->resx - 1;
	win->rayc.raydirx = win->rayc.dirx + win->rayc.planex * win->rayc.camerax;
	win->rayc.raydiry = win->rayc.diry + win->rayc.planey * win->rayc.camerax;
	win->rayc.mapx = (int)win->rayc.posx;
	win->rayc.mapy = (int)win->rayc.posy;
	win->rayc.ddx = fabs(1 / win->rayc.raydirx);
	win->rayc.ddy = fabs(1 / win->rayc.raydiry);
	win->rayc.hit = 0;
}

void	ray_calculations(t_win_data *win)
{
	ray_calculations_2(win);
	if (win->rayc.raydirx < 0)
	{
		win->rayc.stepx = -1;
		win->rayc.sdx = (win->rayc.posx - win->rayc.mapx) * win->rayc.ddx;
	}
	else
	{
		win->rayc.stepx = 1;
		win->rayc.sdx = (win->rayc.mapx + 1.0 - win->rayc.posx) * win->rayc.ddx;
	}
	if (win->rayc.raydiry < 0)
	{
		win->rayc.stepy = -1;
		win->rayc.sdy = (win->rayc.posy - win->rayc.mapy) * win->rayc.ddy;
	}
	else
	{
		win->rayc.stepy = 1;
		win->rayc.sdy = (win->rayc.mapy + 1.0 - win->rayc.posy) * win->rayc.ddy;
	}
}

void	perform_dda(t_win_data *win)
{
	while (win->rayc.hit == 0)
	{
		if (win->rayc.sdx < win->rayc.sdy)
		{
			win->rayc.sdx += win->rayc.ddx;
			win->rayc.mapx += win->rayc.stepx;
			win->rayc.side = 0;
		}
		else
		{
			win->rayc.sdy += win->rayc.ddy;
			win->rayc.mapy += win->rayc.stepy;
			win->rayc.side = 1;
		}
		if (win->map[win->rayc.mapy][win->rayc.mapx] == '1')
			win->rayc.hit = 1;
	}
}
