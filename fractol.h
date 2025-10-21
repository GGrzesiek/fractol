/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrzesiek <ggrzesiek@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 14:36:41 by gkryszcz          #+#    #+#             */
/*   Updated: 2025/10/21 13:17:09 by ggrzesiek        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx_linux/mlx.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define WIDTH 800
# define HEIGHT 800
# define MAX_ITER 1000
# define MANDELBROT 1
# define JULIA 2
# define TRICORN 3
# define KEY_ESC 65307

typedef struct s_complex
{
	double		r;
	double		i;
}				t_complex;

typedef struct s_data
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_len;
	int			endian;
}				t_data;

typedef struct s_fractal
{
	void		*mlx;
	void		*win;
	t_data		img;
	int			type;
	t_complex	julia_c;
	double		zoom;
	double		offset_x;
	double		offset_y;
	int			max_iter;
	int			color_shift;
}				t_fractal;

void			init_fractal(t_fractal *f, int type);
int				parse_args(int argc, char **argv, t_fractal *f);
int				mandelbrot(t_complex c, int max_iter);
int				julia(t_complex z, t_complex c, int max_iter);
int				tricorn(t_complex c, int max_iter);
t_complex		map_pixel_to_complex(int x, int y, t_fractal *f);
void			render_fractal(t_fractal *f);
void			put_pixel(t_data *img, int x, int y, int color);
int				get_color(int iter, int max_iter, int shift);
int				create_trgb(int t, int r, int g, int b);
int				handle_key(int keycode, t_fractal *f);
int				handle_mouse(int button, int x, int y, t_fractal *f);
int				handle_close(t_fractal *f);
double			ft_atof(char *str);
void			cleanup(t_fractal *f);
void			ft_putstr_fd(char *s, int fd);
void			print_usage(void);
void			img_init(t_fractal *f);
#endif
