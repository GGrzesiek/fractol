/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrzesiek <ggrzesiek@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 14:46:47 by ggrzesiek         #+#    #+#             */
/*   Updated: 2025/10/07 15:13:27 by ggrzesiek        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void put_pixel(t_data *img, int x, int y, int color)
{
	char *dst;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		dst = img->addr + (y * img->line_len + x * (img->bits_per_pixel /8));
		*(unsigned int *)dst = color;
	}
}

void render_fractal(t_fractal *f)
{
	int x;
	int y;
	int iter;
	t_complex c;
	int color;

	y = 0;
	while(y< HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			c = map_pixel_to_complex(x, y, f);
			if(f->type == MANDELBROT)
				iter =mandelbrot(c, f->max_iter);
			else if(f->type == JULIA)
				iter = julia(c,f->julia_c,f->max_iter);
			else
				iter = 0;
			color = get_color(iter, f->max_iter, f->color_shift);
			put_pixel(&f->img,x,y,color);
			x++;			
		}
		y++;
	}
}
