/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fulloa-s <fulloa-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 14:05:53 by fulloa-s          #+#    #+#             */
/*   Updated: 2021/04/08 17:24:17 by fulloa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	rotate_left(t_win_data *win, double rotspeed)
{
	win->rayc.olddirx = win->rayc.dirx;
	win->rayc.dirx = win->rayc.dirx * cos(rotspeed) \
	 - win->rayc.diry * sin(rotspeed);
	win->rayc.diry = win->rayc.olddirx * sin(rotspeed) \
	 + win->rayc.diry * cos(rotspeed);
	win->rayc.oldplanex = win->rayc.planex;
	win->rayc.planex = win->rayc.planex * cos(rotspeed) \
	 - win->rayc.planey * sin(rotspeed);
	win->rayc.planey = win->rayc.oldplanex * sin(rotspeed) \
	 + win->rayc.planey * cos(rotspeed);
}

void	rotate_right(t_win_data *win, double rotspeed)
{
	win->rayc.olddirx = win->rayc.dirx;
	win->rayc.dirx = win->rayc.dirx * cos(-rotspeed) \
	 - win->rayc.diry * sin(-rotspeed);
	win->rayc.diry = win->rayc.olddirx * sin(-rotspeed) \
	 + win->rayc.diry * cos(-rotspeed);
	win->rayc.oldplanex = win->rayc.planex;
	win->rayc.planex = win->rayc.planex * cos(-rotspeed) \
	 - win->rayc.planey * sin(-rotspeed);
	win->rayc.planey = win->rayc.oldplanex * sin(-rotspeed) \
	 + win->rayc.planey * cos(-rotspeed);
}
