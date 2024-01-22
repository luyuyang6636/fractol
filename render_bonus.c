/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luyang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:32:22 by luyang            #+#    #+#             */
/*   Updated: 2024/01/17 16:32:27 by luyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_pixel_put(int colour, int x, int y, t_img *img)
{
	int	offset;

	offset = (y * img->line_len) + (x * img->bpp / 8);
	*(unsigned int *)(img->pixels_ptr + offset) = colour;
}

void	complex_init(t_fractal *fractal, t_complex *z, t_complex *c)
{
	if (!ft_strncmp(fractal->name, "julia", 5))
	{
		c->r = fractal->julia_r;
		c->im = fractal->julia_im;
	}
	else
	{
		c->r = z->r;
		c->im = z->im;
	}
}

void	handle_pixel(t_fractal *fractal, int x, int y)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			colour;		

	i = 0;
	z.r = ft_map(x, fractal->x_max, fractal->x_min, WIDTH) + fractal->shift_x;
	z.im = ft_map(y, fractal->y_max, fractal->y_min, HEIGHT) + fractal->shift_y;
	complex_init(fractal, &z, &c);
	while (i < fractal->iteration_c)
	{
		z = ft_sum_complex(ft_square_complex(z, *fractal), c);
		if ((z.r * z.r + z.im * z.im) > fractal->escape_v)
		{
			colour = ft_map(i, fractal->colour1, fractal->colour2, ITERATION_C);
			my_pixel_put(colour, x, y, &fractal->img);
			return ;
		}
		i++;
	}
	my_pixel_put(MAGENTA_BURST, x, y, &fractal->img);
}

void	fractal_render(t_fractal *fractal)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			handle_pixel(fractal, x, y);
	}
	mlx_put_image_to_window(fractal->mlx_connection, fractal->mlx_window,
		fractal->img.img_ptr, 0, 0);
}
