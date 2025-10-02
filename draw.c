/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkryszcz <gkryszcz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 15:25:49 by gkryszcz          #+#    #+#             */
/*   Updated: 2025/10/02 17:14:40 by gkryszcz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void draw_circle(t_data img,int x, int y,int size)
{
	int i;
	int j;
	
	i = 0;
	while (i <= size * 2)
	{
		j = 0;
		while (j <= size * 2)
		{
			int dist = sqrt((i - size) * (i - size) + (j - size) * (j - size));
			if (dist < size)
			{
				opt_mlx_pixel_put(&img, i + x, j + y, 0x00FF0000);
			}
			j++;
		}
		i++;
	}
}

void draw_square(t_data img,int x,int y,int size)
{
	int i;
	int j;
	
	i = x;
	j = y;
		while(i < x + size)
		{
			opt_mlx_pixel_put(&img,i,j,0x0000FF00);
			i++;
		}
		while(j < y + size)
		{
			opt_mlx_pixel_put(&img,i,j,0x000000FF);
			j++;
		}
		while(i > x)
		{
			opt_mlx_pixel_put(&img,i,j,0x00FF0000);
			i--;
		}
		while(j > y)
		{
			opt_mlx_pixel_put(&img,i,j,0x00FFFFFF);
			j--;
		}
}

void draw_random_texture(t_data img)
{
	int i;
	int j;
	int lol;
	
	i = 200;
	j = 0;
	lol = 0;

	while(lol < 600)
	{
		while(j < 500)
		{
			opt_mlx_pixel_put(&img,i,j,0x0000FF00+i);
			i++;
			j++;
		}
		while(j > 0)
		{
			opt_mlx_pixel_put(&img,i,j,0x00FF0000+i);
			i++;
			j--;
		}
		lol++;
	}
}

int render_next_frame(t_data *image)
{
	static int x;
	static int y;

	x = 0;
	y = 0;
	while(x<1000)
	{
		draw_circle(*image,x,y,30);
		x++;
		y++;
	}
	return(0);
}

int	rainbow_string(t_vars *mlx)
{
	mlx_string_put(mlx->mlx,mlx->win,150,150,0x00FF0000,"Hello");
	
	return(0);
}