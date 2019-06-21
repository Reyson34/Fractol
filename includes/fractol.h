/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcottet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 10:35:20 by fcottet           #+#    #+#             */
/*   Updated: 2018/11/05 17:57:04 by fcottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "../libft/libft.h"
# include <stdlib.h>
# include <mlx.h>
# include <math.h>
# define WIDTH 1200
# define HEIGH 950

typedef struct	s_fract
{
	int			fract;
	void		*mlx;
	void		*win;
	double		x1;
	double		y1;
	int			imax;
	int			ymax;
	double		x2;
	double		y2;
	double		zoom;
	double		c_r;
	double		c_i;
	double		z_r;
	double		z_i;
	double		tmp;
	int			color;
	void		*img;
	char		*img_adr;
	int			bit;
	int			sizel;
	int			endian;
	double		image_x;
	double		image_y;
	int			ctrl;
}				t_fract;

typedef struct	s_co
{
	int			x;
	int			y;
}				t_co;

t_fract			*burning_init(t_fract *data);
void			draw_burning(t_fract *data);
t_fract			*julia_init(t_fract *data);
void			draw_julia(t_fract *data);
void			put_pxl_to_img(t_fract *data, int x, int y, int color);
void			put_pixel_img(t_fract *par, int x, int y, int color);
t_fract			*mandelbrot_init(t_fract *data);
int				deal_mouse(int button, int x, int y, void *par);
int				deal_key(int key, void *par);
void			draw_mandelbrot(t_fract *par);
int				hook_mousemove(int x, int y, void *data);
int				hook_mouseup(int x, int y, void *data);
int				hook_mousedown(int x, int y, void *data);
int				check_color(char *str);
int				get_color(char *str);
int				expose_hook(t_fract *data);

#endif
