/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrzesiek <ggrzesiek@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 12:37:32 by gkryszcz          #+#    #+#             */
/*   Updated: 2025/10/11 08:24:19 by ggrzesiek        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
/*
	./fractol mandelbrot
	./fractol julia -0.7 0.27015
	./fractol julia -0.4 0.6
	./fractol julia 0.285 0.01
*/
void init_fractal(t_fractal *f, int type)
{
	f->type = type;
	f->zoom = 1.0;
	f->offset_x = 0.0;
	f->offset_x = 0.0;
	f->max_iter = MAX_ITER;
	f->color_shift = 0;
	if(type == JULIA)
	{
		f->julia_c.r = -0.7;
		f->julia_c.i = 0.27015;
	}
}

void cleanup(t_fractal *f)
{
	if(f->img.img)
		mlx_destroy_image(f->mlx, f->img.img);
	if(f->win)
		mlx_destroy_window(f->mlx, f->win);
	if (f->mlx)
	{
		mlx_destroy_display(f->mlx);
		free(f->mlx);
	}
}

int handle_close(t_fractal *f)
{
	cleanup(f);
	exit(0);
	return(0);
}

int	main(int argc, char **argv)
{
	t_fractal f;
	if(!parse_args(argc,argv,&f))
	{
		print_usage();
		return(1);
	}
	f.mlx = mlx_init();
	if (!f.mlx)
		return(1);
	f.win = mlx_new_window(f.mlx, WIDTH, HEIGHT, "Fractol");
	if(!f.win)
	{
		mlx_destroy_display(f.mlx);
		free(f.win);
		return (1);
	}
	f.img.img = mlx_new_image(f.mlx,HEIGHT,WIDTH);
	f.img.addr = mlx_get_data_addr(f.img.img, &f.img.bits_per_pixel, &f.img.line_len, &f.img.endian);
	render_fractal(&f);
	mlx_put_image_to_window(f.mlx,f.win,f.img.img,0,0);
	mlx_hook(f.win, 2, (1L << 0), handle_key, &f);
	mlx_hook(f.win, 4, (1L << 2), handle_mouse, &f);
	mlx_hook(f.win, 17, 0, handle_close, &f);
	mlx_loop(f.mlx);
	return 0;
}
