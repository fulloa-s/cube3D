/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fulloa-s <fulloa-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 10:56:50 by fulloa-s          #+#    #+#             */
/*   Updated: 2021/04/09 12:26:00 by fulloa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dst && !src)
		return (NULL);
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dst);
}

int	ft_strnstr(const char *hay, const char *ndl)
{
	size_t	i;
	size_t	j;

	if (*ndl == '\0')
		return (0);
	i = 0;
	while (*(hay + i) != '\0')
	{
		j = 0;
		while (*(hay + i + j) == *(ndl + j))
		{
			if (*(ndl + j + 1) == '\0')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_exit(t_win_data *win)
{
	mlx_destroy_image(win->mlx_ptr, win->text[0].img);
	mlx_destroy_image(win->mlx_ptr, win->text[1].img);
	mlx_destroy_image(win->mlx_ptr, win->text[2].img);
	mlx_destroy_image(win->mlx_ptr, win->text[3].img);
	mlx_destroy_image(win->mlx_ptr, win->text[4].img);
	mlx_destroy_image(win->mlx_ptr, win->text[5].img);
	mlx_destroy_image(win->mlx_ptr, win->text[6].img);
	mlx_destroy_image(win->mlx_ptr, win->img.img);
	mlx_destroy_window(win->mlx_ptr, win->win_ptr);
	system("killall afplay");
	exit(0);
	return (0);
}

void	ft_screensize(t_win_data *win)
{
	win->img.size_pixel = 7;
	mlx_get_screen_size(win->mlx_ptr,
	&win->resolution.sizex, &win->resolution.sizey);
	if (win->resx > win->resolution.sizex)
		win->resx = win->resolution.sizex;
	if (win->resx < 800)
		win->resx = 800;
	if (win->resy > win->resolution.sizey)
		win->resy = win->resolution.sizey;
	if (win->resy < 600)
		win->resy = 600;
}
