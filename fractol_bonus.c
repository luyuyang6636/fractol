/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luyang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:32:14 by luyang            #+#    #+#             */
/*   Updated: 2024/01/17 16:32:16 by luyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fractal_input_hint(void)
{
	ft_putstr_fd("You have input the wrong arguments!\n", STDERR_FILENO);
	ft_putstr_fd("Please enter the following options:\n", STDERR_FILENO);
	ft_putstr_fd("mandelbrot\n", STDERR_FILENO);
	ft_putstr_fd("julia [real] [imaginary]\n", STDERR_FILENO);
	ft_putstr_fd("burning ship\n", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_fractal	fractal;

	if ((argc == 2 && (!ft_strncmp("mandelbrot", argv[1], 10)
				|| !ft_strncmp("burning ship", argv[1], 12)))
		|| (argc == 4 && !ft_strncmp("julia", argv[1], 5)))
	{
		fractal.name = argv[1];
		if (!ft_strncmp("julia", argv[1], 5))
		{
			fractal.julia_r = ft_atodbl(argv[2]);
			fractal.julia_im = ft_atodbl(argv[3]);
		}
		fractal_init(&fractal);
		fractal_render(&fractal);
		mlx_loop(fractal.mlx_connection);
	}
	else
	{
		fractal_input_hint();
	}
}
