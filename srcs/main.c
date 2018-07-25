/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 12:25:11 by nwang             #+#    #+#             */
/*   Updated: 2018/07/21 13:56:19 by nwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	frac_error(void)
{
	ft_putstr("Usg: ./fractol <fractal name>.\n");
	ft_putstr("Fractals: Julia, Mandelbrot, TEMP, TEMP\n");
	ft_putstr("Controls: TEMP\n");
	exit(1);
}
void	init_frac(t_frac *frac, char *s)
{
	frac->mlx.init = mlx_init();
	frac->mlx.win = mlx_new_window(frac->mlx.init, WINWID,
		WINHGT, s);
	frac->mlx.img = mlx_new_image(frac->mlx.init, WINWID, WINHGT);
	frac->img.data = mlx_get_data_addr(frac->mlx.img,
		&frac->img.bpp, &frac->img.size, &frac->img.end);
}

void	which_frac(t_frac *frac, char *s)
{
	if (!ft_strcmp(s, "julia") || !ft_strcmp(s, "Julia"))
		run_julia(frac, s);
	else if (!ft_strcmp(s, "mandelbrot") || !ft_strcmp(s, "Mandelbrot"))
		run_mandelbrot(frac, s);
	// else if if (!ft_strcmp(s, "bonus") || !ft_strcmp(s, "Bonus"))
	// 		run_jula(frac);
	else
		frac_error();
}

int		main(int argc, char **argv)
{
	t_frac	frac;

	ft_bzero(&frac, sizeof(t_frac));
	if (argc == 2)
		which_frac(&frac, argv[1]);
	else
		frac_error();
	return (0);
}
