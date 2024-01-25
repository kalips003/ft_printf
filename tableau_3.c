/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tableau_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:35:59 by agallon           #+#    #+#             */
/*   Updated: 2023/12/08 16:36:00 by agallon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//////////////////////////////////////////////////////////// (%e)(%E)
int	ft_scientific(va_list args, t_flags *f)
{
	double	exp;
	int		size;
	int		num_size;

	exp = va_arg(args, double);
	num_size = size_exp(f);
	size = 0;
	if (!f->minus)
		size += f_spacing(f, num_size + size_format_num(exp, f, num_size));
	size += f_format_num(f, exp, num_size);
	size += ft_put_science(exp, f);
	if (f->minus)
		size += f_spacing(f, num_size + size_format_num(exp, f, num_size));
	return (size);
}
