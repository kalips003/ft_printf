/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallon <agallon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:06:44 by agallon           #+#    #+#             */
/*   Updated: 2023/12/08 14:51:07 by agallon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

////////////////////////////////////////////////////////////
///////////////////// %[# +-0][*0-9].[*0-9][scpiduxX%*bofeE]
//	#	INI STRUCT
void	f_ini_struct(t_flags *f)
{
	f->minus = 0;
	f->zero = 0;
	f->width = 0;
	f->plus = 0;
	f->space = 0;
	f->hash = 0;
	f->point = 0;
	f->preci = 0;
	f->flag = 0;
	f->error = 0;
	f->increment = 0;
}

////////////////////////////////////////////////////////////
//////////////////////////// %[#+- 0][width][.preci][format]
//	#	STRUCT CHECK ERROR
static void	f_small_clean(t_flags *f)
{
	f->zero = 0;
	f->plus = 0;
	f->space = 0;
	f->hash = 0;
}

void	f_error_check(t_flags *f)
{
	if (f->flag == 's' || f->flag == 'c')
		f_small_clean(f);
	if (f->flag == 'c' && !f->point)
		f->preci = 1;
	if (f->zero && f->point && f->flag != 'f')
		f->zero = 0;
	if (f->zero && f->minus)
		f->zero = 0;
	if (f->space && f->plus)
		f->space = 0;
	if (f->flag == 'u' || f->flag == 'x' || f->flag == 'X' || f->flag == 'b'
		|| f->flag == 'o')
	{
		f->plus = 0;
		f->space = 0;
	}
}

////////////////////////////////////////////////////////////
//	#	FILL STRUCT f
static void	f_fill_struct_help(const char *str, t_flags *f, int *i)
{
	while (wii(str[*i]) == -1)
	{
		if (str[*i] == '#')
			f->hash = 1;
		if (str[*i] == '-')
			f->minus = 1;
		if (str[*i] == '+')
			f->plus = 1;
		if (str[*i] == ' ')
			f->space = 1;
		if (str[*i] == '0')
			f->zero = 1;
		(*i)++;
	}
}

void	f_fill_struct(const char *str, t_flags *f, va_list args)
{
	int	i;

	i = 0;
	f_fill_struct_help(str, f, &i);
	if (wii(str[i]) == -3 || str[i] == '*')
		i += atoi_pos(&str[i], &f->width, f, args);
	if (wii(str[i]) == -2)
	{
		f->point = 1;
		i++;
		i += atoi_pos(&str[i], &f->preci, f, args);
	}
	if (wii(str[i]) > 0)
		f->flag = str[i];
	else
		f->error = 1;
	f->increment = i + 2;
}
