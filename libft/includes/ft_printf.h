/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 15:40:20 by nwang             #+#    #+#             */
/*   Updated: 2018/02/21 15:44:40 by nwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <string.h>
# include <fcntl.h>
# include <stdio.h>
# include <wchar.h>
# include "../libft/srcs/libft.h"

typedef struct		s_flag
{
	int				hash;
	int				zero;
	int				minus;
	int				pos;
	int				neg;
	int				sp;
	int				prec;
	char			cha;
	int				mod;
	int				ilen;
	int				dot;
	int				width;
	int				mwidth;
	int				star;
	int				starw;
	int				starp;
}					t_flag;

int					ft_printf(const char *format, ...);
int					check_spec(char c);
int					check_flag(char c);
int					check_lspec(char c);
int					which_flag(const char *f, int i, int x, t_flag *pf);
int					valid_char(const char *f, int i, t_flag *pf);
int					which_mods(const char *f, int i, t_flag *pf);
int					output(va_list ap, t_flag *pf);
int					letters(va_list ap, t_flag *pf);
int					digits(va_list ap, t_flag *pf, int i);
int					udigits(va_list ap, t_flag *pf);
int					pad(int i, t_flag pf);
int					zppad(uintmax_t z, int i, int x, t_flag *pf);
int					minpad(uintmax_t z, int i, int x, t_flag *pf);
char				*unbase(uintmax_t z, int base);
int					baselen(uintmax_t z, int base);
char				*hexbase(uintmax_t z, int y);
int					d_len(intmax_t i);
int					oct(uintmax_t i, int len, t_flag *pf);
int					hex(uintmax_t i, t_flag *pf);
int					unint(uintmax_t i, t_flag *pf);
int					pwstring(va_list ap, int i, int z, t_flag *pf);
int					wstr(va_list ap, int i, int x, t_flag *pf);

#endif
