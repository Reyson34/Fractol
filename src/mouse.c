/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcottet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 13:25:37 by fcottet           #+#    #+#             */
/*   Updated: 2018/11/05 17:37:48 by fcottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int					hook_mousemove(int x, int y, void *data)
{
	static t_co		xy;
	t_co			prev;

	if (xy.x)
		prev = xy;
	xy.x = x;
	xy.y = y;
	if (((t_fract *)data)->ctrl > 0)
	{
		if (prev.x < xy.x)
			((t_fract *)data)->c_r += 0.05;
		if (prev.x > xy.x)
			((t_fract *)data)->c_r -= 0.05;
		if (prev.y > xy.y)
			((t_fract *)data)->c_i += 0.05;
		if (prev.y < xy.y)
			((t_fract *)data)->c_i -= 0.05;
	}
	mlx_clear_window(((t_fract *)data)->mlx, ((t_fract *)data)->win);
	draw_julia(data);
	return (0);
}

void				get_zoom(t_fract *data, int button, int x, int y)
{
	if (button == 4 || button == 1)
	{
		if (data->fract < 3)
		{
			data->zoom += 160;
			data->imax += 10;
		}
		if (data->fract == 3)
			data->zoom += 50;
		data->x1 += (((double)x - (WIDTH / 2)) / data->zoom);
		data->y1 += (((double)y - (HEIGH / 2)) / data->zoom);
	}
	if (button == 5 || button == 2)
	{
		if (data->zoom > 200)
		{
			data->zoom -= 160;
			if (data->imax > 50)
				data->imax -= 10;
		}
	}
}

int					deal_mouse(int button, int x, int y, void *data)
{
	if (button == 4 || button == 1 || button == 5 || button == 2)
		get_zoom(data, button, x, y);
	mlx_clear_window(((t_fract *)data)->mlx, ((t_fract *)data)->win);
	if (((t_fract *)data)->fract == 1)
		draw_mandelbrot(data);
	else if (((t_fract *)data)->fract == 2)
		draw_julia(data);
	else if (((t_fract *)data)->fract == 3)
		draw_burning(data);
	return (0);
}
