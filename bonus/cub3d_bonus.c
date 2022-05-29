/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fulloa-s <fulloa-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 11:20:03 by fulloa-s          #+#    #+#             */
/*   Updated: 2021/04/08 17:22:08 by fulloa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	ft_rendering(t_win_data *win)
{
	ft_raycasting(win);
	if (win->save == 0)
	{
		player_move(win);
		if (win->keys[46])
			ft_minimap(win);
		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img.img, 0, 0);
		mlx_do_sync(win->mlx_ptr);
	}
	return (0);
}

void	init_save(t_win_data *win, t_parse *parsing, char **argv)
{
	ft_parsing_map(argv, parsing);
	init_window(win, parsing);
	init_textures(win);
	ft_findplayer(win);
	malloc_sprite(win);
	ft_keyinit(win);
	ft_rendering(win);
	ft_bitmap(win);
}

void	init_rayc(t_win_data *win, t_parse *parsing, char **argv)
{
	ft_parsing_map(argv, parsing);
	init_window(win, parsing);
	init_textures(win);
	ft_findplayer(win);
	malloc_sprite(win);
	system("afplay ./soundtracks/western.mp3 &");
	ft_keyinit(win);
	mlx_loop_hook(win->mlx_ptr, ft_rendering, win);
	mlx_hook(win->win_ptr, 17, 1L, ft_exit, win);
	mlx_hook(win->win_ptr, 2, 1L << 0, ft_keypress, win);
	mlx_hook(win->win_ptr, 3, 1L << 1, ft_keyrelease, win);
	mlx_loop(win->mlx_ptr);
}

int	save_check(char *arg, char *save)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (arg[i] == save[i])
			i++;
		else
			return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_parse		parsing;
	t_win_data	win;

	if (argc == 3 && (ft_strnstr(argv[1], ".cub") == 1) \
	 && (ft_strlen(argv[2]) == 6 && \
	(ft_strnstr(argv[2], "--save") == 1)))
	{
		win.save = 1;
		init_save(&win, &parsing, argv);
	}
	else if (argc == 2 && (ft_strnstr(argv[1], ".cub") == 1))
	{
		win.save = 0;
		init_rayc(&win, &parsing, argv);
	}
	else
		printf("Error\n");
}
