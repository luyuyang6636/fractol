#include "fractal.h"

long double	ft_map(int originaln, int new_max, int new_min, int len)
{
	return (originaln * (new_max - new_min) / len + new_min);
}

long double	ft_atoi_fractol(char *str)
{
	int	sign;
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
	return (ret)
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