/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkryszcz <gkryszcz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 14:46:47 by gkryszcz          #+#    #+#             */
/*   Updated: 2025/10/21 13:23:46 by gkryszcz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_pixel(t_data *img, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		dst = img->addr + (y * img->line_len + x * (img->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

void	render_fractal(t_fractal *f)
{
	int			x;
	int			y;
	int			iter;
	t_complex	c;
	int			color;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			c = map_pixel_to_complex(x, y, f);
			if (f->type == MANDELBROT)
				iter = mandelbrot(c, f->max_iter);
			else if (f->type == JULIA)
				iter = julia(c, f->julia_c, f->max_iter);
			else if (f->type == TRICORN)
				iter = tricorn(c, f->max_iter);
			else
				iter = 0;
			color = get_color(iter, f->max_iter, f->color_shift);
			put_pixel(&f->img, x, y, color);
		}
	}
}

void	img_init(t_fractal *f)
{
	f->img.img = mlx_new_image(f->mlx, HEIGHT, WIDTH);
	f->img.addr = mlx_get_data_addr(f->img.img, &f->img.bits_per_pixel,
			&f->img.line_len, &f->img.endian);
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	get_color(int iter, int max_iter, int shift)
{
	double	t;
	int		r;
	int		g;
	int		b;

	if (iter == max_iter)
		return (0x00000000);
	t = (double)iter / max_iter;
	r = (int)(9 * (1 - t) * t * t * t * 255);
	g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	r = (r + shift) % 256;
	g = (g + shift) % 256;
	b = (b + shift) % 256;
	return (create_trgb(0, r, g, b));
}
