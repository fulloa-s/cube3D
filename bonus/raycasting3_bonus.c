/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting3_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fulloa-s <fulloa-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 14:26:49 by fulloa-s          #+#    #+#             */
/*   Updated: 2021/04/08 17:24:06 by fulloa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	set_directions(t_win_data *win)
{
	if (win->rayc.side == 0 && win->rayc.raydirx < 0)
		win->rayc.i = 0;
	if (win->rayc.side == 0 && win->rayc.raydirx > 0)
		win->rayc.i = 1;
	if (win->rayc.side == 1 && win->rayc.raydiry < 0)
		win->rayc.i = 2;
	if (win->rayc.side == 1 && win->rayc.raydiry > 0)
		win->rayc.i = 3;
}

void	set_text_variables(t_win_data *win)
{
	if (win->rayc.side == 0)
		win->rayc.wallx = win->rayc.posy + win->rayc.pwd * win->rayc.raydiry;
	else
		win->rayc.wallx = win->rayc.posx + win->rayc.pwd * win->rayc.raydirx;
	win->rayc.wallx -= floor((win->rayc.wallx));
	win->rayc.texx = (int)(win->rayc.wallx * (double)win->text[win->rayc.i].w);
	if (win->rayc.side == 0 && win->rayc.raydirx > 0)
		win->rayc.texx = win->text[win->rayc.i].w - win->rayc.texx - 1;
	if (win->rayc.side == 1 && win->rayc.raydiry < 0)
		win->rayc.texx = win->text[win->rayc.i].w - win->rayc.texx - 1;
	win->rayc.step = 1.0 * win->text[win->rayc.i].h / win->rayc.lineh;
	win->rayc.texpos = (win->rayc.drawstart - win->resy / 2 + \
	win->rayc.lineh / 2) * win->rayc.step;
}

void	pre_draw_calculations(t_win_data *win)
{
	if (win->rayc.side == 0)
		win->rayc.pwd = (win->rayc.mapx - win->rayc.posx + \
		(1 - win->rayc.stepx) / 2) / win->rayc.raydirx;
	else
		win->rayc.pwd = (win->rayc.mapy - win->rayc.posy + \
		(1 - win->rayc.stepy) / 2) / win->rayc.raydiry;
	win->rayc.lineh = (int)(win->resy / win->rayc.pwd);
	win->rayc.drawstart = win->resy / 2 - win->rayc.lineh / 2;
	if (win->rayc.drawstart < 0)
		win->rayc.drawstart = 0;
	win->rayc.drawend = win->rayc.lineh / 2 + win->resy / 2;
	if (win->rayc.drawend >= win->resy)
		win->rayc.drawend = win->resy - 1;
	set_directions(win);
	set_text_variables(win);
}
