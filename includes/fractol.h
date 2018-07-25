/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 12:24:48 by nwang             #+#    #+#             */
/*   Updated: 2018/06/01 16:34:09 by nwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <dirent.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include <pthread.h>
# include <mlx.h>
# include "../libft/includes/ft_printf.h"
# define C_RED		"\x1b[31m"
# define C_GRN		"\x1b[32m"
# define C_YEL		"\x1b[33m"
# define C_BLU		"\x1b[34m"
# define C_MAG		"\x1b[35m"
# define C_CYN		"\x1b[36m"
# define C_WHT		"\x1b[37m"
# define C_RESET	"\x1b[0m"

# define WINWID			(1280)
# define WINHGT			(720)

typedef struct		s_mlx
{
	void			*init;
	void    		*win;
	void    		*img;
}               	t_mlx;

typedef struct  	s_img
{
	char    		*data;
	int             size;
	int             end;
	int             bpp;
}                   t_img;

typedef struct  	s_color
{
	int             red;
	int             grn;
	int             blu;
}                   t_color;

typedef struct		s_map
{
	int				type;
	int				depth;
	int				iteration;
	double			width;
	double			height;
	// double			scale;
	// double			limit;
	// double			xr;
	// double			yi;
}					t_map;

typedef struct  	s_frac
{
	t_mlx   		mlx;
	t_img   		img;
	t_color 		color;
	t_map   		map;
	char			*fracname;
}                   t_frac;

void        		run_julia(t_frac *frac, char *s);
void        		run_mandelbrot(t_frac *frac, char *s);
void				init_frac(t_frac *frac, char *s);

#endif
