/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrzesiek <ggrzesiek@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 17:21:15 by gkryszcz          #+#    #+#             */
/*   Updated: 2025/10/07 14:46:26 by ggrzesiek        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	create_trgb(int t, int r, int g, int b)
{
	return(t << 24 | r << 16 | g << 8 | b);
}

// int get_t(int trgb)
// {
// 	return ((trgb >> 24) & 0xFF);
// }

// int get_r(int trgb)
// {
// 	return((trgb >> 16) & 0xFF);
// }

// int get_g(int trgb)
// {
// 	return((trgb >> 8) & 0xFF);
// }

// int get_b(int trgb)
// {
// 	return (trgb & 0xFF);
// }

int get_color(int iter, int max_iter, int shift)
{
	double t;
	int	r;
	int	g;
	int b;
	if(iter == max_iter)
		return(0x00000000);
	t = (double)iter / max_iter;
	r = (int)(9 * (1 - t) * t *t *t * 255);
	g = (int)(15 * (1 -t) * (1 -t) * t *t *255 );
	b = (int)(8.5 * (1 -t ) * (1 -t) * (1 -t) *t * 255);
	r = (r +shift) & 256;
	g = (g +shift) % 256;
	b = (b + shift) % 256;
	return (create_trgb(0,r,g,b));
}