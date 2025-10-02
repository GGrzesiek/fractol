/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkryszcz <gkryszcz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 12:37:32 by gkryszcz          #+#    #+#             */
/*   Updated: 2025/10/02 17:14:14 by gkryszcz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#define WIDTH	1920
#define HEIGHT	1080

// int *fibb()
// {
	

// }

// int close(int keycode, t_data *wind)
// {
// 	mlx_destroy_window(wind->mlx, )
// }
// bad implementation, but works

void opt_mlx_pixel_put(t_data *data, int x, int y,int color)
{
	char *dst;

	dst = data->addr + (y * data->line_len + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
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
	t_vars vars;
	t_data img;

	int middlex;
	int middley;
	int radius;
	// double PI = 3.1415926535;

	radius = 100;
	vars.mlx = mlx_init();
	if (NULL == vars.mlx)
		return (1);

	vars.win = mlx_new_window(vars.mlx,HEIGHT,WIDTH,"Fractol");
	if(!vars.win)
	{
		mlx_destroy_display(vars.mlx);
		free(vars.win);
		return (1);
	}
	
	img.img = mlx_new_image(vars.mlx,HEIGHT,WIDTH);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_len, &img.endian);
	
	middley = 600;
	middlex = 400;

	// draw_random_texture(img);
	draw_square(img,middlex+200,middley, radius);
	// draw_circle(img,middlex+200,middley,radius);
	// if (NULL == mlx_window)
	// {
	// 	mlx_destroy_display(mlx_conn);
	// 	free(mlx_conn);
	// 	return(1);
	// }
	// mlx_hook(vars.win,2, 1L<<0,close,&vars);
	mlx_hook(vars.win, 2, (1L << 0), handle_keypress, &vars);
	
	mlx_loop_hook(vars.mlx, render_next_frame, &img);
	mlx_put_image_to_window(vars.mlx,vars.win,img.img,0,0);
	mlx_loop(vars.mlx);
	mlx_destroy_window(vars.mlx, vars.win);
	mlx_destroy_display(vars.mlx);
	free(vars.mlx);
	return 0;
}
