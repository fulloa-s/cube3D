/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fulloa-s <fulloa-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 10:12:31 by fulloa-s          #+#    #+#             */
/*   Updated: 2021/04/08 14:27:38 by fulloa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	wall_casting(t_win_data *win, double *zbuffer)
{
	win->rayc.x = 0;
	while (win->rayc.x < win->resx)
	{
		ray_calculations(win);
		perform_dda(win);
		pre_draw_calculations(win);
		win->rayc.y = win->rayc.drawstart;
		while (win->rayc.y < win->rayc.drawend)
		{
			win->rayc.texy = (int)win->rayc.texpos & \
			(win->text[win->rayc.i].h - 1);
			win->rayc.texpos += win->rayc.step;
			win->rayc.color = (unsigned int)win->text[win->rayc.i].addr \
			[win->text[win->rayc.i].h * win->rayc.texy + win->rayc.texx];
			draw_dot(win, win->rayc.x, win->rayc.y, win->rayc.color);
			win->rayc.y++;
		}
		zbuffer[win->rayc.x] = win->rayc.pwd;
		win->rayc.x++;
	}
}

void	sprite_position(t_win_data *win)
{
	win->rayc.spritex = win->spr[win->rayc.i].posx - win->rayc.posx;
	win->rayc.spritey = win->spr[win->rayc.i].posy - win->rayc.posy;
	win->rayc.invdet = 1.0 / \
	(win->rayc.planex * win->rayc.diry - win->rayc.dirx * win->rayc.planey);
	win->rayc.transformx = win->rayc.invdet * \
	(win->rayc.diry * win->rayc.spritex - win->rayc.dirx * win->rayc.spritey);
	win->rayc.transformy = win->rayc.invdet * \
	((-win->rayc.planey) * win->rayc.spritex + \
	win->rayc.planex * win->rayc.spritey);
	win->rayc.sprscrx = (int)((win->resx / 2) * \
	(1 + win->rayc.transformx / win->rayc.transformy));
}

void	sprite_calculations(t_win_data *win)
{
	sprite_position(win);
	win->rayc.sprh = (abs((int)(win->resy / win->rayc.transformy)));
	win->rayc.drawstarty = -win->rayc.sprh / 2 + win->resy / 2;
	if (win->rayc.drawstarty < 0)
		win->rayc.drawstarty = 0;
	win->rayc.drawendy = win->rayc.sprh / 2 + win->resy / 2;
	if (win->rayc.drawendy >= win->resy)
		win->rayc.drawendy = win->resy - 1;
	win->rayc.sprw = (abs((int)(win->resy / win->rayc.transformy)));
	win->rayc.drawstartx = -win->rayc.sprw / 2 + win->rayc.sprscrx;
	if (win->rayc.drawstartx < 0)
		win->rayc.drawstartx = 0;
	win->rayc.drawendx = win->rayc.sprw / 2 + win->rayc.sprscrx;
	if (win->rayc.drawendx >= win->resx)
		win->rayc.drawendx = win->resx - 1;
	win->rayc.stripe = win->rayc.drawstartx;
}

void	draw_sprites(t_win_data *win, double *zbuffer)
{
	win->rayc.i = 0;
	while (win->rayc.i < win->countsprite)
	{
		sprite_calculations(win);
		while (win->rayc.stripe < win->rayc.drawendx)
		{
			win->rayc.texx = (int)(256 * (win->rayc.stripe - \
			(-win->rayc.sprw / 2 + win->rayc.sprscrx)) \
			 * win->text[4].w / win->rayc.sprw) / 256;
			if (win->rayc.transformy > 0 && win->rayc.stripe > 0 && \
			win->rayc.stripe < win->resx && \
			win->rayc.transformy < zbuffer[win->rayc.stripe])
			{
				win->rayc.y = win->rayc.drawstarty;
				while (win->rayc.y < win->rayc.drawendy)
				{
					win->rayc.d = (win->rayc.y) * 256 - win->resy * 128 \
					 + win->rayc.sprh * 128;
					win->rayc.texy = ((win->rayc.d * win->text[4].h) / \
					win->rayc.sprh) / 256;
					win->rayc.color = (unsigned int)win->spr[win->rayc.i].addr \
					[win->text[4].w * win->rayc.texy + win->rayc.texx];
					if ((win->rayc.color & 0x00FFFFFF) != 0)
						draw_dot(win, win->rayc.stripe, win->rayc.y, \
						win->rayc.color);
					win->rayc.y++;
				}
			}
			win->rayc.stripe++;
		}
		win->rayc.i++;
	}
}

void	ft_raycasting(t_win_data *win)
{
	double	*zbuffer;

	zbuffer = malloc(sizeof(double) * win->resx + 1);
	floor_ceiling(win);
	wall_casting(win, zbuffer);
	sort_sprites(win);
	draw_sprites(win, zbuffer);
	free(zbuffer);
}
