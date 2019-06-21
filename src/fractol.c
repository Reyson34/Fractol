/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcottet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 10:35:12 by fcottet           #+#    #+#             */
/*   Updated: 2018/11/05 17:50:51 by fcottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void				init_fract(t_fract *par)
{
	if (par->fract == 1)
	{
		par = mandelbrot_init(par);
		draw_mandelbrot(par);
	}
	if (par->fract == 2)
	{
		par = julia_init(par);
		par->ctrl = 1;
		draw_julia(par);
	}
	if (par->fract == 3)
	{
		par = burning_init(par);
		draw_burning(par);
	}
}

t_fract				*init_window(t_fract *par)
{
	par->mlx = mlx_init();
	par->win = mlx_new_window(par->mlx, WIDTH, HEIGH, "Fractol");
	init_fract(par);
	mlx_mouse_hook(par->win, deal_mouse, par);
	mlx_key_hook(par->win, deal_key, par);
	mlx_expose_hook(par->win, expose_hook, par);
	mlx_loop(par->mlx);
	return (par);
}

int					check_av(char *str)
{
	int				i;

	i = 0;
	if (ft_strcmp(str, "mandelbrot") == 0)
		i = 1;
	else if (ft_strcmp(str, "julia") == 0)
		i = 2;
	else if (ft_strcmp(str, "burningship") == 0)
		i = 3;
	return (i);
}

int					main(int ac, char **av)
{
	static t_fract	*par;
	char			*str;

	str = "usage: ./fractol [mandelbrot | julia | burningship] [0xRRGGBB]";
	if ((ac != 2 && ac != 3) || check_av(av[1]) == 0)
	{
		ft_putendl(str);
		return (0);
	}
	par = malloc(sizeof(t_fract));
	if (av[2])
	{
		if (check_color(av[2]) == 1)
			par->color = get_color(av[2]);
		else
		{
			ft_putendl(str);
			return (0);
		}
	}
	par->fract = check_av(av[1]);
	par = init_window(par);
	return (0);
}
