#ifndef FRACTOL_H
#define FRACTOL_H

# include "libft/libft.h"
# include "minilibx-linux/mlx.h"

typedef struct s_img
{
	void	*img_ptr;
	char	*pixels_ptr;
	int		bpp;
	int		endian;
	int		line_len;
	
} 	_img;

typedef struct s_fractol
{
	char	*name;
	void	*mlx_connection;
	void	*mlx_window;
	t_img	img;
	int	escape_v;
	int	iteration_c;
	long double	julia_r;
	long double	julia_im;
}	t_fractal;

typedef struct s_complex
{
	long double	r;
	long double	im;
}	t_complex;

# define WIDTH	800;
# define HEIGHT	800;
# define ESCAPE_V	4;
# define ITERATION_C	42;

void	fractal_input_hint(void);
void	fractal_init(t_fractal *fractal);
void	data_init(t_fractal *fractal);
void	fractal_render(t_fractal *fractal);
void	handle_pixel(t_fractal *fractal, int x, int y);
void	complex_init(t_fractal *fractal, t_complex *z, t_complex *c);
long double	ft_map(int originaln, int new_max, int new_min, int len);
long double	ft_atodbl(char *str);
long double	ft_atoi_fractol(char *str);

#endif