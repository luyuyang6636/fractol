/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luyang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 21:18:34 by luyang            #+#    #+#             */
/*   Updated: 2024/01/17 21:20:13 by luyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_key_handler_1(int keysym, t_fractal *fractal)
{
	if (keysym == XK_0)
		data_init(fractal);
	else if (keysym == XK_b)
		fractal->name = "burning ship";
	else if (keysym == XK_m)
		fractal->name = "mandelbrot";
	else if (keysym == XK_1)
	{
		fractal->colour1 = PSYCHEDELIC_PURPLE;
		fractal->colour2 = LIME_SHOCK;
	}
	else if (keysym == XK_2)
	{
		fractal->colour1 = NEON_ORANGE;
		fractal->colour2 = PSYCHEDELIC_PURPLE;
	}
	else if (keysym == XK_3)
	{
		fractal->colour1 = MAGENTA_BURST;
		fractal->colour2 = AQUA_DREAM;
	}
}

int	ft_close_handler(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_connection, fractal->img.img_ptr);
	mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
	mlx_destroy_display(fractal->mlx_connection);
	free(fractal->mlx_connection);
	exit (EXIT_SUCCESS);
}

int	ft_key_handler(int keysym, t_fractal *fractal)
{
	if (keysym == XK_Escape)
		ft_close_handler(fractal);
	if (keysym == XK_Left)
		fractal->shift_x += 0.5 * fractal->zoom;
	else if (keysym == XK_Right)
		fractal->shift_x -= 0.5 * fractal->zoom;
	else if (keysym == XK_Up)
		fractal->shift_y -= 0.5 * fractal->zoom;
	else if (keysym == XK_Down)
		fractal->shift_y += 0.5 * fractal->zoom;
	else if (keysym == XK_equal)
		fractal->iteration_c += 10;
	else if (keysym == XK_minus && fractal->iteration_c > 10)
		fractal->iteration_c -= 10;
	else if (keysym == XK_j)
	{
		fractal->name = "julia";
		fractal->julia_r = -0.8696;
		fractal->julia_im = 0.26;
	}
	ft_key_handler_1(keysym, fractal);
	fractal_render(fractal);
	return (0);
}

int	ft_mouse_handler(int button, int x, int y, t_fractal *fractal)
{
	long double	new_x;
	long double	new_y;

	if (button == Button4)
		fractal->zoom = 0.95;
	else if (button == Button5)
		fractal->zoom = 1.05;
	new_x = ft_map(x, fractal->x_max, fractal->x_min, WIDTH);
	new_y = ft_map(y, fractal->y_max, fractal->y_min, HEIGHT);
	fractal->x_max = (fractal->x_max - new_x) * fractal->zoom + new_x;
	fractal->x_min = (fractal->x_min - new_x) * fractal->zoom + new_x;
	fractal->y_max = (fractal->y_max - new_y) * fractal->zoom + new_y;
	fractal->y_min = (fractal->y_min - new_y) * fractal->zoom + new_y;
	if (!ft_strncmp("julia", fractal->name, 5))
	{
		if (button == Button1)
		{
			fractal->julia_r = ft_map(x, fractal->x_max, fractal->x_min, WIDTH);
			fractal->julia_im = ft_map(y, fractal->y_max,
					fractal->y_min, HEIGHT);
		}
	}
	fractal_render(fractal);
	return (0);
}
