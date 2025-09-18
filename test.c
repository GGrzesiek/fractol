#include "fractol.h"

int key_hook(int keycode, t_vars *vars)
{
	(void)keycode;
	printf("Hello :) ");
	return (0);
}

int close(int keycode, t_vars *vars)
{
	printf("%d",keycode);
	// (void)keycode;
	mlx_destroy_window(vars->mlx,vars->win);
	return (0);
}

int main(void)
{
	t_vars vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx,640,480,"img");
	// mlx_key_hook(vars.win, key_hook, &vars);
	mlx_hook(vars.win,2, 1L<<0, close, &vars);
	mlx_loop(vars.mlx);
}