#include "fractol.h"

void	data_init(t_fractal *fractal)
{
	fractal->escape_v = ESCAPE_V;
	fractal->iteration_c = ITERATION_C;
	
}

void	fractal_init(t_fractal *fractal)
{
	fractal->mlx_connection = mlx_init();
	if (!fractal->mlx_connection)
		ft_handle_error("malloc error!");
	fractal->mlx_window = mlx_new_window(fractal->mlx_connection,
		WIDTH, HEIGHT, fractal->name);
	if (!fractal->mlx_window)
	{
		mlx_destroy_display(fractal->mlx_connection);
		free (fractal->mlx_connection);
		ft_handle_error("malloc error!");
	}
	fractal->img.img_ptr = mlx_new_image(fractal->mlx_connection,
		WIDTH, HEIGHT);
	if (!fractal->img.img_ptr)
	{
		mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
		mlx_destroy_display(fractal->mlx_connection);
		free (fractal->mlx_connection)
		ft_handle_error("malloc error!")
	}
	fractal->img.pixels_ptr = mlx_get_data_addr(fractal->img.img_ptr,
	&fractal->img.bpp, &fractal->img.line_len, &fractal->img.endian);
	data_init(&fractal);
}
