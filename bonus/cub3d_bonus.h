/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fulloa-s <fulloa-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 11:21:25 by fulloa-s          #+#    #+#             */
/*   Updated: 2021/04/09 10:58:26 by fulloa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdlib.h>
# include "../mlx/mlx.h"
# include <math.h>

# define BUFFER_SIZE 1024

typedef struct s_img_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
	int		size_pixel;
}				t_img_data;

typedef struct s_engine
{
	double			posx;
	double			posy;
	double			dirx;
	double			diry;
	double			planex;
	double			planey;
	double			camerax;
	double			raydirx;
	double			raydiry;
	double			sdx;
	double			sdy;
	double			ddx;
	double			ddy;
	int				mapx;
	int				mapy;
	int				stepx;
	int				stepy;
	int				hit;
	int				side;
	double			pwd;
	int				drawstart;
	int				drawend;
	int				lineh;
	double			olddirx;
	double			oldplanex;
	float			raydirx0;
	float			raydirx1;
	float			raydiry0;
	float			raydiry1;
	float			posz;
	float			rowdistance;
	float			floorstepx;
	float			floorstepy;
	float			floorx;
	float			floory;
	int				cellx;
	int				celly;
	int				tx;
	int				ty;
	double			wallx;
	int				texx;
	double			step;
	double			texpos;
	int				texy;
	double			spritex;
	double			spritey;
	double			invdet;
	double			transformx;
	double			transformy;
	int				sprscrx;
	int				sprh;
	int				drawstarty;
	int				drawendy;
	int				sprw;
	int				drawstartx;
	int				drawendx;
	int				stripe;
	int				d;
	unsigned int	color;
	int				x;
	int				y;
	int				i;
}				t_engine;

typedef struct s_texture
{
	void	*img;
	int		*addr;
	char	*relative_path;
	int		w;
	int		h;
	int		bpp;
	int		line_length;
	int		end;
	int		xpm;
}				t_texture;

typedef struct s_sprite
{
	double	posx;
	double	posy;
	double	sprdis;
	int		*addr;
}				t_sprite;

typedef struct s_resolution
{
	int		sizex;
	int		sizey;
	int		x_max;
	int		n_line;
}				t_res;

typedef struct s_win_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img_data	img;
	t_img_data	minimap;
	t_texture	text[7];
	char		**map;
	t_engine	rayc;
	int			resx;
	int			resy;
	char		keys[128];
	int			color[2];
	int			countsprite;
	t_sprite	*spr;
	t_res		resolution;
	int			save;
}				t_win_data;

typedef struct s_check
{
	int	resolution;
	int	no;
	int	so;
	int	we;
	int	ea;
	int	s;
	int	f;
	int	c;
}				t_check;

typedef struct s_parse
{
	int		resx;
	int		resy;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*s;
	char	*f;
	char	*c;
	char	**map;
	int		n_line;
	int		x_max;
	t_check	check;
	int		r;
}				t_parse;

void	my_mlx_pixel_put2(t_img_data *img, int x, int y, int color);
void	my_mlx_pixel_put(t_img_data *img, int x, int y, int color);
void	ft_crosscheck(t_parse *parsing);
int		create_trgb(int t, int r, int g, int b);
int		get_next_line(int fd, char **line, t_parse *parsing);
char	*fill_line(char *memory, char *line);
char	*clean_memory(char *memory);
int		tofree(char *buff);
int		defr(char **line, int fd);
int		ft_strlen(char *line);
int		ft_strchr(char *line, char c);
char	*ft_strjoin(char *s1, char *s2);
void	ft_parsing_map(char **argv, t_parse *list);
int		ft_isdigit(int c);
void	ft_checkparsing(t_parse *list, char *line);
void	listinit(t_parse *list);
void	set_res(t_parse *list, char *line, int i);
int		set_texture_and_color_no(t_parse *list, char *line, int i);
int		set_texture_and_color_so(t_parse *list, char *line, int i);
int		set_texture_and_color_we(t_parse *list, char *line, int i);
int		set_texture_and_color_ea(t_parse *list, char *line, int i);
int		set_texture_and_color_s(t_parse *list, char *line, int i);
int		set_texture_and_color_f(t_parse *list, char *line, int i);
int		set_texture_and_color_c(t_parse *list, char *line, int i);
int		check_var(t_parse *list);
int		check_emptyline(char *line, t_parse *list);
void	ft_map(t_parse *list, char *line);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	ft_checkres(t_parse *list, char *line, int i);
int		ft_checkpath(char *list, char *line, int check, int i);
int		*ft_colorinit(int *color);
int		ft_checkcolor(char *str, int *color, int check);
int		ft_checkvalidcolor(int *color, int check);
void	ft_warning(char *line, int i);
void	ft_checkmap(t_parse *list);
int		ft_keyhook(int keycode, t_win_data *win);
int		ft_rendering(t_win_data *win);
void	ft_pavicielo(t_win_data *win);
void	ft_minimap(t_win_data *win);
void	malloc_sprite(t_win_data *win);
void	ft_checkfirstlast(t_parse *parsing);
void	ft_checkborder(t_parse *parsing);
void	ft_checkplayer(t_parse *parsing);
void	ft_screensize(t_win_data *win);
void	ft_checkminimap(t_parse *parsing);
void	draw_dot(t_win_data *win, int x, int y, int color);
void	count_sprites(t_win_data *win);
void	sort_sprites(t_win_data *win);
int		ft_strnstr(const char *hay, const char *ndl);
void	ft_error(char *errormsg);
void	ft_checkline(t_parse *parsing, int y, int x);
int		ft_exit(t_win_data *win);
int		ft_keypress(int keycode, t_win_data *win);
int		ft_keyrelease(int keycode, t_win_data *win);
int		ft_isvalidchar(char c);
int		ft_checkchar(char c);
void	rotate_left(t_win_data *win, double rotspeed);
void	rotate_right(t_win_data *win, double rotspeed);
void	init_textures(t_win_data *win);
void	init_window(t_win_data *win, t_parse *parsing);
void	ft_checkxpm(t_win_data *win, int i);
void	ft_keyinit(t_win_data *win);
void	look_north(t_win_data *win, int y, int x);
void	look_west(t_win_data *win, int y, int x);
void	look_south(t_win_data *win, int y, int x);
void	look_east(t_win_data *win, int y, int x);
void	ft_findplayer(t_win_data *win);
void	bmp_print(t_win_data *win, int fd);
void	bmp_header_2(t_win_data *win, int fd);
void	bmp_header(t_win_data *win, int fd);
int		ft_bitmap(t_win_data *win);
void	player_move(t_win_data *win);
void	move_right(t_win_data *win, double movespeed);
void	move_left(t_win_data *win, double movespeed);
void	move_down(t_win_data *win, double movespeed);
void	move_up(t_win_data *win, double movespeed);
void	wall_casting(t_win_data *win, double *zbuffer);
void	sprite_position(t_win_data *win);
void	sprite_calculations(t_win_data *win);
void	draw_sprites(t_win_data *win, double *zbuffer);
void	ft_raycasting(t_win_data *win);
void	set_textured_floorceiling(t_win_data *win);
void	floor_ceiling(t_win_data *win);
void	ray_calculations_2(t_win_data *win);
void	ray_calculations(t_win_data *win);
void	perform_dda(t_win_data *win);
void	set_directions(t_win_data *win);
void	set_text_variables(t_win_data *win);
void	pre_draw_calculations(t_win_data *win);
int		ft_checkcolor_norme(char *str, int i, int *color);
void	init_save(t_win_data *win, t_parse *parsing, char **argv);
void	init_rayc(t_win_data *win, t_parse *parsing, char **argv);
int		save_check(char *arg, char *save);
char	**ft_realloc_tmp(t_parse *parsing);
void	ft_reallocfinal(t_parse *parsing, char *line, int c, int i);
void	ft_realloc(t_parse *parsing, char *line);

#endif