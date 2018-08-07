/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 13:29:27 by nwang             #+#    #+#             */
/*   Updated: 2018/07/21 13:29:50 by nwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void        draw_julia(t_frac *frac, int y)
{
    (void)y;
    (void)frac;
    ft_putstr("Julia\n");
}

void        draw_mandelbrot(t_frac *frac, int y)
{
    (void)y;
    (void)frac;
    ft_putstr("Mandelfuck\n");
}