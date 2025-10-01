/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkryszcz <gkryszcz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 12:37:32 by gkryszcz          #+#    #+#             */
/*   Updated: 2025/10/01 12:42:46 by gkryszcz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fractol.h"
#define WIDTH	1920
#define HEIGHT	1080

// int *fibb()
// {
	

// }

// void draw_triangle(int center, int side_len)
// {
	
// }

// int close(int keycode, t_data *wind)
// {
// 	mlx_destroy_window(wind->mlx, )
// }
// bad implementation, but works
void draw_circle(t_data img,int x, int y,int size)
{
	int i;
	int j;
	// int distx;
	// int disty;
	
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

// void draw_full_circle(t_data img,int x, int y, int size)
// {
	
// }

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
		printf("%c",'\n');
		while(j < y + size)
		{
			opt_mlx_pixel_put(&img,i,j,0x000000FF);
			j++;
		}
		printf("%c",'\n');
		while(i > x)
		{
			opt_mlx_pixel_put(&img,i,j,0x00FF0000);
			i--;
		}
		printf("%c",'\n');
		while(j > y)
		{
			opt_mlx_pixel_put(&img,i,j,0x00FFFFFF);
			j--;
		}
		printf("%c",'\n');
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
int handle_keypress(int keycode, void *param)
{
    t_vars *vars = (t_vars *)param;
    (void)vars;
    // printf("Key pressed: %d\n", keycode);
    /* Escape on X11 is 65307 */
    if (keycode == 65307)
    {
        mlx_destroy_window(vars->mlx, vars->win);
        exit(0);
    }
    return (0);
}
int	main()
{
	// void	*mlx_conn;
	// void	*mlx_window;
	t_vars vars;
	t_data img;

	int middlex;
	int middley;
	int circle;
	int radius;
	// double PI = 3.1415926535;

	
	circle = 0;
	radius = 100;
	vars.mlx = mlx_init();
	if (NULL == vars.mlx)
		return (1);

	vars.win = mlx_new_window(vars.mlx,HEIGHT,WIDTH,"Fractol");
	if(!vars.win)
		return (1);
	
	img.img = mlx_new_image(vars.mlx,HEIGHT,WIDTH);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_len, &img.endian);
	
	middley = 600;
	middlex = 400;

	draw_random_texture(img);
	// draw_square(img,100,100, 50);
	// draw_circle(img,500,500,100);
	// if (NULL == mlx_window)
	// {
	// 	mlx_destroy_display(mlx_conn);
	// 	free(mlx_conn);
	// 	return(1);
	// }
	mlx_put_image_to_window(vars.mlx,vars.win,img.img,0,0);
	// mlx_hook(vars.win,2, 1L<<0,close,&vars);
	mlx_hook(vars.win, 2, (1L << 0), handle_keypress, &vars);
	mlx_loop(vars.mlx);
	mlx_destroy_display(vars.mlx);
	free(vars.mlx);
	return 0;
}
