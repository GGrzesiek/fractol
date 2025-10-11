/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkryszcz <gkryszcz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 14:15:47 by ggrzesiek         #+#    #+#             */
/*   Updated: 2025/10/11 12:28:06 by gkryszcz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	handle_key(int keycode, t_fractal *f)
{
	if (keycode == KEY_ESC)
		handle_close(f);
	else if (keycode == 65361)
		f->offset_x -= 0.1 / f->zoom;
	else if (keycode == 65363)
		f->offset_x += 0.1 / f->zoom;
	else if (keycode == 65362)
		f->offset_y -= 0.1 / f->zoom;
	else if (keycode == 65364)
		f->offset_y += 0.1 / f->zoom;
	else if (keycode == 99)
		f->color_shift = (f->color_shift + 10) % 256;
	else
		return (0);
	render_fractal(f);
	mlx_put_image_to_window(f->mlx, f->win, f->img.img, 0, 0);
	return (0);
}

int	handle_mouse(int button, int x, int y, t_fractal *f)
{
	t_complex	mouse_pos;
	double		zoom_factor;

	mouse_pos = map_pixel_to_complex(x, y, f);
	if (button == 4)
		zoom_factor = 1.1;
	else if (button == 5)
		zoom_factor = 0.9;
	else
		return (0);
	f->offset_x = mouse_pos.r + (f->offset_x - mouse_pos.r) / zoom_factor;
	f->offset_y = mouse_pos.i + (f->offset_y - mouse_pos.i) / zoom_factor;
	f->zoom *= zoom_factor;
	render_fractal(f);
	mlx_put_image_to_window(f->mlx, f->win, f->img.img, 0, 0);
	return (0);
}

void	print_usage(void)
{
	ft_putstr_fd("Usage:\n", 1);
	ft_putstr_fd(" ./fractol mandelbrot\n", 1);
	ft_putstr_fd(" ./fractol julia <real> <imaginary>\n", 1);
}
