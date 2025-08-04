/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkryszcz <gkryszcz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 14:36:41 by gkryszcz          #+#    #+#             */
/*   Updated: 2025/08/04 14:46:27 by gkryszcz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_linux/mlx.h"

typedef struct s_data
{
	void *img;
	char *addr;
	int	bits_per_pixel;
	int	line_len;
	int	endian;
}	t_data;	

void opt_mlx_pixel_put(t_data *data, int x, int y,int color)
{
	char *dst;

	dst = data->addr + (y * data->line_len + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}