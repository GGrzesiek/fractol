/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkryszcz <gkryszcz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 14:52:56 by ggrzesiek         #+#    #+#             */
/*   Updated: 2025/10/11 12:28:25 by gkryszcz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot(t_complex c, int max_iter)
{
	t_complex	z;
	double		temp;
	int			i;

	z.r = 0;
	z.i = 0;
	i = 0;
	while (i < max_iter)
	{
		if (z.r * z.r + z.i * z.i > 4.0)
			return (i);
		temp = z.r * z.r - z.i * z.i + c.r;
		z.i = 2.0 * z.r * z.i + c.i;
		z.r = temp;
		i++;
	}
	return (max_iter);
}

int	julia(t_complex z, t_complex c, int max_iter)
{
	double	temp;
	int		i;

	i = 0;
	while (i < max_iter)
	{
		if (z.r * z.r + z.i * z.i > 4.0)
			return (i);
		temp = z.r * z.r - z.i * z.i + c.r;
		z.i = 2.0 * z.r * z.i + c.i;
		z.r = temp;
		i++;
	}
	return (max_iter);
}

t_complex	map_pixel_to_complex(int x, int y, t_fractal *f)
{
	t_complex	c;

	c.r = (x - WIDTH / 2.0) / (0.5 * f->zoom * WIDTH) + f->offset_x;
	c.i = (y - HEIGHT / 2.0) / (0.5 * f->zoom * HEIGHT) + f->offset_y;
	return (c);
}
