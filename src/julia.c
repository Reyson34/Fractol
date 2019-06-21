/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcottet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 17:25:57 by fcottet           #+#    #+#             */
/*   Updated: 2018/11/05 18:05:09 by fcottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

t_fract				*julia_init(t_fract *data)
{
	data->x1 = -1.5;
	data->x2 = 1;
	data->y1 = -1.2;
	data->y2 = 1.2;
	data->zoom = 400;
	data->imax = 150;
	if (!data->color)
		data->color = 0xFFFFFF;
	data->c_r = -0.772691322542185;
	data->c_i = 0.124281466072787;
	return (data);
}

void				put_julia(t_fract *data, int x, int y)
{
	int				i;

	i = 0;
	data->z_r = x / data->zoom + data->x1;
	data->z_i = y / data->zoom + data->y1;
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
		put_pxl_to_img(data, x, y, (data->color * i));
}

void				draw_julia(t_fract *data)
{
	int				x;
	int				y;

	mlx_hook(data->win, 6, 0, hook_mousemove, data);
	data->image_x = (data->x2 - data->x1) * data->zoom;
	data->image_y = (data->y2 - data->y1) * data->zoom;
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGH);
	data->img_adr = mlx_get_data_addr(data->img, &data->bit,
			&data->sizel, &data->endian);
	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGH)
		{
			put_julia(data, x, y);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
