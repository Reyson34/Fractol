/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcottet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 10:40:30 by fcottet           #+#    #+#             */
/*   Updated: 2018/11/05 16:23:09 by fcottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

t_fract			*mandelbrot_init(t_fract *data)
{
	data->zoom = 400;
	data->imax = 50;
	if (!data->color)
		data->color = 0x0000FF;
	data->x1 = -2.1;
	data->x2 = 0.6;
	data->y1 = -1.2;
	data->y2 = 1.2;
	return (data);
}

void			put_mandelbrot(t_fract *data, int x, int y)
{
	int			i;

	i = 0;
	while ((data->z_r * data->z_r + data->z_i * data->z_i) < 4
		&& i < data->imax)
	{
		data->tmp = data->z_r;
		data->z_r = (data->z_r * data->z_r -
		data->z_i * data->z_i + data->c_r);
		data->z_i = (2 * data->z_i * data->tmp + data->c_i);
		i++;
	}
	if (i == data->imax)
		put_pxl_to_img(data, x, y, 0x000000);
	else
		put_pxl_to_img(data, x, y, (data->color * i / data->imax));
}

void			draw_mandelbrot(t_fract *data)
{
	int			x;
	int			y;

	data->img = mlx_new_image(data->mlx, WIDTH, HEIGH);
	data->img_adr = mlx_get_data_addr(data->img, &data->bit,
			&data->sizel, &data->endian);
	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGH)
		{
			data->c_r = (x / data->zoom + data->x1);
			data->c_i = (y / data->zoom + data->y1);
			data->z_r = 0;
			data->z_i = 0;
			put_mandelbrot(data, x, y);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
