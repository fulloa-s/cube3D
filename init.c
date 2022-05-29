/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fulloa-s <fulloa-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 13:58:51 by fulloa-s          #+#    #+#             */
/*   Updated: 2021/04/08 16:26:48 by fulloa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	*ft_colorinit(int *color)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		color[i] = 256;
		i++;
	}
	return (color);
}

void	listinit(t_parse *parsing)
{
	parsing->resx = 0;
	parsing->resy = 0;
	parsing->no = NULL;
	parsing->so = NULL;
	parsing->we = NULL;
	parsing->ea = NULL;
	parsing->s = NULL;
	parsing->f = NULL;
	parsing->c = NULL;
	ft_colorinit(parsing->f_color);
	ft_colorinit(parsing->c_color);
	parsing->map = NULL;
	parsing->n_line = 1;
	parsing->check.resolution = 0;
	parsing->check.no = 0;
	parsing->check.so = 0;
	parsing->check.we = 0;
	parsing->check.ea = 0;
	parsing->check.s = 0;
	parsing->check.f = 0;
	parsing->check.c = 0;
	parsing->r = 1;
}

void	init_textures(t_win_data *win)
{
	int	i;

	i = 0;
	while (i <= 4)
	{
		ft_checkxpm(win, i);
		i++;
	}
	i = 0;
	while (i <= 4)
	{
		if (win->text[i].xpm == 1)
			win->text[i].img = mlx_xpm_file_to_image(win->mlx_ptr, \
			win->text[i].relative_path, &win->text[i].w, &win->text[i].h);
		else
			win->text[i].img = mlx_png_file_to_image(win->mlx_ptr, \
			win->text[i].relative_path, &win->text[i].w, &win->text[i].h);
		win->text[i].addr = (int *)mlx_get_data_addr(win->text[i].img, \
		&win->text[i].bpp, &win->text[i].line_length, &win->text[i].end);
		i++;
	}
}

void	init_window(t_win_data *win, t_parse *parsing)
{
	win->map = parsing->map;
	win->resx = parsing->resx;
	win->resy = parsing->resy;
	win->resolution.x_max = parsing->x_max;
	win->resolution.n_line = parsing->n_line;
	win->text[0].relative_path = parsing->we;
	win->text[1].relative_path = parsing->ea;
	win->text[2].relative_path = parsing->no;
	win->text[3].relative_path = parsing->so;
	win->text[4].relative_path = parsing->s;
	win->color[0] = create_trgb(0, parsing->f_color[0], \
	parsing->f_color[1], parsing->f_color[2]);
	win->color[1] = create_trgb(0, parsing->c_color[0], \
	parsing->c_color[1], parsing->c_color[2]);
	win->countsprite = 0;
	win->mlx_ptr = mlx_init();
	ft_screensize(win);
	win->img.img = mlx_new_image(win->mlx_ptr, win->resx, win->resy);
	win->img.addr = mlx_get_data_addr(win->img.img, \
	&win->img.bpp, &win->img.line_length, &win->img.endian);
	if (win->save == 0)
	{
		win->win_ptr = mlx_new_window(win->mlx_ptr, \
		win->resx, win->resy, "cub3D");
	}
}

void	ft_checkxpm(t_win_data *win, int i)
{
	int	j;

	j = ft_strlen(win->text[i].relative_path);
	if (win->text[i].relative_path[j - 1] == 'm')
		win->text[i].xpm = 1;
	else
		win->text[i].xpm = 0;
}
