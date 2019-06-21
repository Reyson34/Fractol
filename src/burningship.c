/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcottet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 15:44:56 by fcottet           #+#    #+#             */
/*   Updated: 2018/11/05 17:36:28 by fcottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

t_fract		*burning_init(t_fract *data)
{
	data->x1 = -2.0;
	data->y1 = -2.5;
	data->zoom = 220;
	data->imax = 25;
	if (!data->color)
		data->color = 0xFF0000;
	return (data);
}

void		burningship(t_fract *data, int x, int y)
{
	int		i;

	i = 0;
	data->z_r = 0;
	data->z_i = 0;
	data->c_r = x / data->zoom + data->x1;
	data->c_i = y / data->zoom + data->y1;
	while (data->z_r * data->z_r + data->z_i * data->z_i < 4
						&& i < data->imax)
	{
		data->tmp = data->z_r * data->z_r - data->z_i * data->z_i + data->c_r;
		data->z_i = fabs(2 * data->z_r * data->z_i) + data->c_i;
		data->z_r = data->tmp;
		i++;
	}
	if (i == data->imax)
		put_pxl_to_img(data, x, y, data->color);
	else
		put_pxl_to_img(data, x, y, i * 0x070000);
}

void		draw_burning(t_fract *data)
{
	int		x;
	int		y;

	x = 0;
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGH);
	data->img_adr = mlx_get_data_addr(data->img, &data->bit,
		&data->sizel, &data->endian);
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGH)
		{
			burningship(data, x, y);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
