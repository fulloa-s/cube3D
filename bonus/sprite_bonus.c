/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fulloa-s <fulloa-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 14:07:23 by fulloa-s          #+#    #+#             */
/*   Updated: 2021/04/08 17:24:22 by fulloa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	malloc_sprite(t_win_data *win)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	x = 0;
	y = 0;
	win->spr = malloc(sizeof(t_sprite) * (win->countsprite + 1));
	while (win->map[y])
	{
		x = 0;
		while (win->map[y][x])
		{
			if (win->map[y][x] == '2')
			{
				win->spr[i].posx = x + 0.5;
				win->spr[i].posy = y + 0.5;
				win->spr[i].addr = win->text[4].addr;
				i++;
			}
			x++;
		}
		y++;
	}
}

void	count_sprites(t_win_data *win)
{
	win->rayc.i = 0;
	while (win->rayc.i++ < win->countsprite)
		win->spr[win->rayc.i].sprdis = \
		((win->rayc.posx - win->spr[win->rayc.i].posx) \
		 * (win->rayc.posx - win->spr[win->rayc.i].posx) + \
		(win->rayc.posy - win->spr[win->rayc.i].posy) \
		 * (win->rayc.posy - win->spr[win->rayc.i].posy));
}

void	sort_sprites(t_win_data *win)
{
	t_sprite	tmp;
	int			i;
	int			j;
	int			c;

	c = win->countsprite - 1;
	j = 0;
	count_sprites(win);
	while (j < c)
	{
		i = c - 1;
		while (i >= j)
		{
			if (win->spr[i].sprdis < win->spr[i + 1].sprdis)
			{
				tmp = win->spr[i];
				win->spr[i] = win->spr[i + 1];
				win->spr[i + 1] = tmp;
			}
			i--;
		}
		j++;
	}
}
