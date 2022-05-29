/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_orientation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fulloa-s <fulloa-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 14:02:52 by fulloa-s          #+#    #+#             */
/*   Updated: 2021/04/08 14:03:22 by fulloa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	look_north(t_win_data *win, int y, int x)
{
	win->rayc.posx = x + 0.49;
	win->rayc.posy = y + 0.49;
	win->rayc.dirx = 0;
	win->rayc.diry = -1;
	win->rayc.planex = 0.66;
	win->rayc.planey = 0;
	win->map[y][x] = '0';
}

void	look_west(t_win_data *win, int y, int x)
{
	win->rayc.posx = x + 0.49;
	win->rayc.posy = y + 0.49;
	win->rayc.dirx = -1;
	win->rayc.diry = 0;
	win->rayc.planex = 0;
	win->rayc.planey = -0.66;
	win->map[y][x] = '0';
}

void	look_east(t_win_data *win, int y, int x)
{
	win->rayc.posx = x + 0.49;
	win->rayc.posy = y + 0.49;
	win->rayc.dirx = 1;
	win->rayc.diry = 0;
	win->rayc.planex = 0;
	win->rayc.planey = 0.66;
	win->map[y][x] = '0';
}

void	look_south(t_win_data *win, int y, int x)
{
	win->rayc.posx = x + 0.49;
	win->rayc.posy = y + 0.49;
	win->rayc.dirx = 0;
	win->rayc.diry = 1;
	win->rayc.planex = -0.66;
	win->rayc.planey = 0;
	win->map[y][x] = '0';
}

void	ft_findplayer(t_win_data *win)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (win->map[y])
	{
		x = 0;
		while (win->map[y][x])
		{
			if (win->map[y][x] == 'N')
				look_north(win, y, x);
			if (win->map[y][x] == 'W')
				look_west(win, y, x);
			if (win->map[y][x] == 'E')
				look_east(win, y, x);
			if (win->map[y][x] == 'S')
				look_south(win, y, x);
			if (win->map[y][x] == '2')
				win->countsprite++;
			x++;
		}
		y++;
	}
}
