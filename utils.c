/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkryszcz <gkryszcz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 14:15:49 by ggrzesiek         #+#    #+#             */
/*   Updated: 2025/10/11 10:52:53 by gkryszcz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_putstr_fd(char *s, int fd)
{
	ssize_t	ret;
	int		i;

	i = 0;
	while (s[i])
	{
		ret = write(fd, &s[i], 1);
		if (ret == -1)
			return ;
		i++;
	}
}

int	is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r');
}

double	ft_atof(char *str)
{
	double	res;
	double	fract;
	int		sgn;

	res = 0.0;
	fract = 0.1;
	sgn = 1;
	while (is_space(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sgn = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
		res = res * 10.0 + (*str++ - '0');
	if (*str == '.')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		res += (*str++ - '0') * fract;
		fract *= 0.1;
	}
	return (res * sgn);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

int	parse_args(int argc, char **argv, t_fractal *f)
{
	if (argc < 2)
		return (0);
	if (ft_strcmp(argv[1], "mandelbrot") == 0)
	{
		if (argc != 2)
			return (0);
		init_fractal(f, MANDELBROT);
		return (1);
	}
	if (ft_strcmp(argv[1], "julia") == 0)
	{
		if (argc != 4)
			return (0);
		init_fractal(f, JULIA);
		f->julia_c.r = ft_atof(argv[2]);
		f->julia_c.i = ft_atof(argv[3]);
		return (1);
	}
	return (0);
}
