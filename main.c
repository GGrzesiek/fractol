/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkryszcz <gkryszcz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 12:37:32 by gkryszcz          #+#    #+#             */
/*   Updated: 2025/09/17 12:53:59 by gkryszcz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fractol.h"
#define WIDTH	1920
#define HEIGHT	1080

// int *fibb()
// {
	

// }
int	main()
{
	void	*mlx_conn;
	void	*mlx_window;
	t_data img;
	int i;
	int j;
	int lol;
	int middlex;
	int middley;
	int circle;
	int radius;
	// double PI = 3.1415926535;
	double x1,y1;

	i = 200;
	j = 0;
	lol = 0;
	circle = 0;
	radius = 100;
	mlx_conn = mlx_init();
	if (NULL == mlx_conn)
		return (1);

	mlx_window = mlx_new_window(mlx_conn,HEIGHT,WIDTH,"Fractol");
	img.img = mlx_new_image(mlx_conn,HEIGHT,WIDTH);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_len, &img.endian);
	// while (i <100)
	// {
	// 	opt_mlx_pixel_put(&img,i,j,0x00FF0000);
	// 	i++;
	// 	j++;
	// }
	// while(i >0)
	// {
	// 	opt_mlx_pixel_put(&img,i,j,0x000000FF);
	// 	i--;
	// 	j++;
	// }
	middley = 600;
	middlex = 400;

	while(lol < 600)
	{
			while(j < 500)
		{
			x1 = i;
			y1 = j;
			opt_mlx_pixel_put(&img,x1,y1,0x000000FF);
			i++;
			j++;
		}
		while(j > 0)
		{
			x1 = i;
			y1 = j;
			opt_mlx_pixel_put(&img,x1,y1,0x00FF0000);
			i++;
			j--;
		}
		lol++;
	}

	// if (NULL == mlx_window)
	// {
	// 	mlx_destroy_display(mlx_conn);
	// 	free(mlx_conn);
	// 	return(1);
	// }
	mlx_put_image_to_window(mlx_conn,mlx_window,img.img,0,0);
	mlx_loop(mlx_conn);
	mlx_destroy_display(mlx_conn);
	free(mlx_conn);
	return 0;
}
