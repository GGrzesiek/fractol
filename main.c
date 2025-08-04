#include <stdlib.h>
#include "mlx_linux/mlx.h"
#include "fractol.h"
#define WIDTH	400
#define HEIGHT	400
int	main()
{
	void	*mlx_conn;
	void	*mlx_window;
	t_data img;
	int i;

	i = 0;
	mlx_conn = mlx_init();
	if (NULL == mlx_conn)
		return (1);

	mlx_window = mlx_new_window(mlx_conn,HEIGHT,WIDTH,"My window");
	img.img = mlx_new_image(mlx_conn,1920,1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_len, &img.endian);
	while (i <100)
	{
		opt_mlx_pixel_put(&img,i,i,0x00FF0000);
		i++;
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
