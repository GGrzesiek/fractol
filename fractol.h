/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkryszcz <gkryszcz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 14:36:41 by gkryszcz          #+#    #+#             */
/*   Updated: 2025/10/02 16:23:47 by gkryszcz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_linux/mlx.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_data
{
	void *img;
	char *addr;
	int	bits_per_pixel;
	int	line_len;
	int	endian;
}	t_data;	

typedef struct s_vars
{
	void *mlx;
	void *win;
}	t_vars;



void draw_circle(t_data img,int x, int y,int size);
void draw_square(t_data img,int x,int y,int size);
void draw_random_texture(t_data img);
int handle_keypress(int keycode, void *param);
void opt_mlx_pixel_put(t_data *data, int x, int y,int color);
int render_next_frame(t_data *image);