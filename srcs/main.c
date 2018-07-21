/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 12:25:11 by nwang             #+#    #+#             */
/*   Updated: 2018/06/01 16:33:17 by nwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	frac_error(void)
{
	ft_putstr("Usage: ./fractol <fractal name>.\n");
	ft_putstr("Fractals: Julia, Mandelbrot, TEMP, TEMP\n");
	ft_putstr("Controls: TEMP\n");
	exit(1);
}

void	which_frac(char *s)
{
	if (!ft_strcmp(argv[1], "julia") || !ft_strcmp(argv[1], "Julia"))
			//julia
	else if (!ft_strcmp(argv[1], "mandelbrot") || !ft_strcmp(argv[1], "Mandelbrot"))
			//mandelbrot
	else if if (!ft_strcmp(argv[1], "bonus") || !ft_strcmp(argv[1], "Bonus"))
			//bonus
	else
		frac_error();
}

int		main(int argc, char **argv)
{
	t_frac	frac;

	ft_bzero(&frac, sizeof(t_frac));
	if (argc == 2)
	{
		frac->mlx.init = mlx_init();
		frac->mlx.win = mlx_new_window(frac->mlx.init, WINWID, \
			WHGT, argv[1]);
		frac->mlx.img = mlx_new_image(frac->mlx.init, WINWID, WHGT);
		frac->image.data = mlx_get_data_addr(frac->mlx.img, \
			&frac->image.bpp, &frac->image.size, &frac->image.endian);
		which_fractal(argv[1];)
		
	}
	else
		frac_error();
	return (0);
}
