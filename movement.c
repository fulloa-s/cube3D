/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fulloa-s <fulloa-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 13:56:11 by fulloa-s          #+#    #+#             */
/*   Updated: 2021/04/08 13:57:26 by fulloa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_up(t_win_data *win, double movespeed)
{
	if (win->map[(int)(win->rayc.posy + win->rayc.diry * movespeed)] \
	[(int)win->rayc.posx] == '0')
		win->rayc.posy += win->rayc.diry * movespeed;
	if (win->map[(int)(win->rayc.posy)] \
	[(int)(win->rayc.posx + win->rayc.dirx * movespeed)] == '0')
		win->rayc.posx += win->rayc.dirx * movespeed;
}

void	move_down(t_win_data *win, double movespeed)
{
	if (win->map[(int)(win->rayc.posy - win->rayc.diry * movespeed)] \
	[(int)(win->rayc.posx)] == '0')
		win->rayc.posy -= win->rayc.diry * movespeed;
	if (win->map[(int)(win->rayc.posy)] \
	[(int)(win->rayc.posx - win->rayc.dirx * movespeed)] == '0')
		win->rayc.posx -= win->rayc.dirx * movespeed;
}

void	move_left(t_win_data *win, double movespeed)
{
	if (win->map[(int)(win->rayc.posy)] \
	[(int)(win->rayc.posx + win->rayc.diry * movespeed)] == '0')
		win->rayc.posx += win->rayc.diry * movespeed;
	if (win->map[(int)(win->rayc.posy - win->rayc.dirx * movespeed)] \
	[(int)(win->rayc.posx)] == '0')
		win->rayc.posy -= win->rayc.dirx * movespeed;
}

void	move_right(t_win_data *win, double movespeed)
{
	if (win->map[(int)(win->rayc.posy)] \
	[(int)(win->rayc.posx - win->rayc.diry * movespeed)] == '0')
		win->rayc.posx -= win->rayc.diry * movespeed;
	if (win->map[(int)(win->rayc.posy + win->rayc.dirx * movespeed)] \
	[(int)(win->rayc.posx)] == '0')
		win->rayc.posy += win->rayc.dirx * movespeed;
}

void	player_move(t_win_data *win)
{
	double	movespeed;
	double	rotspeed;

	movespeed = 0.15;
	rotspeed = 0.05;
	if (win->keys[126] || win->keys[13])
		move_up(win, movespeed);
	if (win->keys[125] || win->keys[1])
		move_down(win, movespeed);
	if (win->keys[124])
		rotate_left(win, rotspeed);
	if (win->keys[123])
		rotate_right(win, rotspeed);
	if (win->keys[0])
		move_left(win, movespeed);
	if (win->keys[2])
		move_right(win, movespeed);
}
