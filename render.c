#include "fractol.h"

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
	t_fractal	z;
	t_fractal	c;
	int		i;

	i = 0;
	z.x = ft_map(x, 2, -2, WIDTH);
	z.y = ft_map(y, -2, 2, HEIGHT);
	complex_init(fractal, &z, &c);
	while (i++ < fractal->escape_v)
	{
		z
	}
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
}
