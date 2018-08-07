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
}

int		which_frac(t_frac *frac, char *s)
{
	if (!ft_strcmp(s, "julia") || !ft_strcmp(s, "Julia"))
		frac->id = 1;
	else if (!ft_strcmp(s, "mandelbrot") || !ft_strcmp(s, "Mandelbrot"))
		frac->id = 2;
	// else if if (!ft_strcmp(s, "bonus") || !ft_strcmp(s, "Bonus"))
	// 		run_jula(frac);
	else
		return (0);
	return (1);
	
}

int		main(int argc, char **argv)
{
	t_frac	frac;

	ft_bzero(&frac, sizeof(t_frac));
	if (argc == 2 && (which_frac(&frac, argv[1])))
	{
		init_frac(&frac, argv[1]);
    	create_frac(&frac);
		// init_hooks(view);
		mlx_loop(frac.mlx.init);
	}
	else
		frac_error();
	return (0);
}
