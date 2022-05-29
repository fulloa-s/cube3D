/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fulloa-s <fulloa-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 14:04:26 by fulloa-s          #+#    #+#             */
/*   Updated: 2021/04/08 14:05:17 by fulloa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_keyinit(t_win_data *win)
{
	int	i;

	i = 0;
	while (i < 128)
		win->keys[i++] = 0;
}

int	ft_keypress(int keycode, t_win_data *win)
{
	if (keycode == 53)
		ft_exit(win);
	if (keycode == 126 || keycode == 13)
		win->keys[keycode] = 1;
	if (keycode == 125 || keycode == 1)
		win->keys[keycode] = 1;
	if (keycode == 124)
		win->keys[keycode] = 1;
	if (keycode == 123)
		win->keys[keycode] = 1;
	if (keycode == 0)
		win->keys[keycode] = 1;
	if (keycode == 2)
		win->keys[keycode] = 1;
	if (keycode == 46)
		win->keys[keycode] = 1;
	return (0);
}

int	ft_keyrelease(int keycode, t_win_data *win)
{
	if (keycode == 126 || keycode == 13)
		win->keys[keycode] = 0;
	if (keycode == 125 || keycode == 1)
		win->keys[keycode] = 0;
	if (keycode == 124)
		win->keys[keycode] = 0;
	if (keycode == 123)
		win->keys[keycode] = 0;
	if (keycode == 0)
		win->keys[keycode] = 0;
	if (keycode == 2)
		win->keys[keycode] = 0;
	if (keycode == 46)
		win->keys[keycode] = 0;
	return (0);
}
