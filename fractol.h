/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luyang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:32:02 by luyang            #+#    #+#             */
/*   Updated: 2024/01/17 16:32:10 by luyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>

typedef struct s_img
{
	void	*img_ptr;
	char	*pixels_ptr;
	int		bpp;
	int		endian;
	int		line_len;
}	t_img;

typedef struct s_fractal
{
	char		*name;
	void		*mlx_connection;
	void		*mlx_window;
	t_img		img;
	int			escape_v;
	int			iteration_c;
	long double	julia_r;
	long double	julia_im;
	double		shift_x;
	double		shift_y;
	double		zoom;
	long double	x_min;
	long double	x_max;
	long double	y_min;
	long double	y_max;
	int			colour1;
	int			colour2;
}	t_fractal;

typedef struct s_complex
{
	long double	r;
	long double	im;
}	t_complex;

# define WIDTH	800
# define HEIGHT	800
# define ESCAPE_V	4
# define ITERATION_C	42
# define MAGENTA_BURST   0xFF00FF  // A vibrant magenta
# define LIME_SHOCK      0xCCFF00  // A blinding lime
# define NEON_ORANGE     0xFF6600  // A blazing neon orange
# define PSYCHEDELIC_PURPLE 0x660066  // A deep purple
# define AQUA_DREAM      0x33CCCC  // A bright turquoise
# define HOT_PINK        0xFF66B2  // As the name suggests!
# define ELECTRIC_BLUE   0x0066FF  // A radiant blue
# define LAVA_RED        0xFF3300  // A bright, molten red
# define X_MIN	-2
# define X_MAX	2
# define Y_MIN	2
# define Y_MAX	-2

void		fractal_input_hint(void);
void		fractal_init(t_fractal *fractal);
void		data_init(t_fractal *fractal);
void		fractal_render(t_fractal *fractal);
void		handle_pixel(t_fractal *fractal, int x, int y);
void		complex_init(t_fractal *fractal, t_complex *z, t_complex *c);
long double	ft_map(double originaln,
				double new_max, double new_min, double len);
long double	ft_atodbl(char *str);
long double	ft_atoi_fractol(char *str);
t_complex	ft_square_complex(t_complex z, t_fractal fractal);
t_complex	ft_sum_complex(t_complex z, t_complex c);
void		my_pixel_put(int colour, int x, int y, t_img *img);
int			ft_key_handler(int keysym, t_fractal *fractal);
int			ft_mouse_handler(int button, int x, int y, t_fractal *fractal);
int			ft_close_handler(t_fractal *fractal);
void		ft_key_handler_1(int keysym, t_fractal *fractal);

#endif
