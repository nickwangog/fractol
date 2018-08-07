/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 11:59:11 by nwang             #+#    #+#             */
/*   Updated: 2018/08/06 12:08:04 by nwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_image(t_frac *frac)
{
	mlx_put_image_to_window(frac->mlx.init, frac->mlx.win, frac->mlx.img, 0, 0);
	mlx_destroy_image(frac->mlx.init, frac->mlx.img);
}

void	create_image(t_frac *frac)
{
    frac->mlx.img = mlx_new_image(frac->mlx.init, WINWID, WINHGT);
	frac->img.data = mlx_get_data_addr(frac->mlx.img,
		&frac->img.bpp, &frac->img.size, &frac->img.end);
}

void	*draw_frac(void *arg)
{
	t_thread	*thread;
	t_frac		*frac;
	int			y;
	int			height;

	thread = (t_thread*)arg;
	frac = thread->frac;
	height = (thread->i * 300) + 300;
	y = 300 * thread->i;
	while (y < height)
	{
	    if (frac->id == 1)
            draw_julia(frac, y);
			// julia_draw(frac, frac->mouse_x, frac->mouse_y, y);
		else if (frac->id == 2)
            draw_mandelbrot(frac, y);
			// mandelbrot_draw(frac, y);
		y++;
	}
	return (frac);
}

int		create_frac(t_frac *frac)
{
	int			i;
	t_thread	*thread;
	pthread_t	tid[4];

	i = -1;
	if (!(thread = ft_memalloc(sizeof(t_thread) * 4)))
    {
        ft_printf("Failed to malloc\n");
        exit(1);
    }
	while (++i < 4)
	{
		thread[i].frac = frac;
		thread[i].i = i;
		pthread_create(&tid[i], NULL, draw_frac, &thread[i]);
	}
	i = -1;
	while (++i < 4)
	{
		pthread_join(tid[i], NULL);
	}
	create_image(frac);
	put_image(frac);
	free(thread);
	return (0);
}

