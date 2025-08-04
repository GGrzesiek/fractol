#include <stdlib.h>
#include "mlx_linux/mlx.h"

#define WIDTH	400
#define HEIGHT	400
int	main()
{
	void	*mlx_conn;
	void	*mlx_window;
	
	mlx_conn = mlx_init();
	if (NULL == mlx_conn)
		return (1);

	mlx_window = mlx_new_window(mlx_conn,HEIGHT,WIDTH,"My window");

	if (NULL == mlx_window)
	{
		mlx_destroy_display(mlx_conn);
		free(mlx_conn);
		return(1);
	}

	mlx_loop(mlx_conn);
	mlx_destroy_display(mlx_conn);
	free(mlx_conn);
	return 0;
}