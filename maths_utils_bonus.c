/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luyang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:32:48 by luyang            #+#    #+#             */
/*   Updated: 2024/01/17 16:32:50 by luyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

long double	ft_map(double originaln, double new_max, double new_min, double len)
{
	return (originaln * (new_max - new_min) / len + new_min);
}

long double	ft_atoi_fractol(char *str)
{
	int			sign;
	long double	ret;

	sign = 1;
	ret = 0;
	while ((*str > 8 && *str < 14) || *str == 32)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		ret = ret * 10 + *str - 48;
		str++;
	}
	return (ret);
}

long double	ft_atodbl(char *str)
{
	long double	decimal_part;
	long double	pwr;
	long double	integer_part;

	if (!str)
		ft_handle_error("null pointer in atodbl!");
	decimal_part = 0;
	pwr = 1;
	integer_part = ft_atoi_fractol(str);
	while (*str && *str != '.')
		str++;
	if (*str++ == '.')
	{
		while (*str >= '0' && *str <= '9')
		{
			pwr /= 10;
			decimal_part += (*str - 48) * pwr;
			str++;
		}
	}
	if (integer_part < 0)
		return (integer_part - decimal_part);
	return (integer_part + decimal_part);
}

t_complex	ft_square_complex(t_complex z, t_fractal fractal)
{
	t_complex	ret;

	if (!ft_strncmp(fractal.name, "burning ship", 12))
	{
		z.im = fabsl(z.im);
		z.r = fabsl(z.r);
	}
	ret.r = (z.r * z.r) - (z.im * z.im);
	ret.im = 2 * z.r * z.im;
	return (ret);
}

t_complex	ft_sum_complex(t_complex z, t_complex c)
{
	z.im += c.im;
	z.r += c.r;
	return (z);
}
