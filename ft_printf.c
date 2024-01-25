/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallon <agallon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:06:22 by agallon           #+#    #+#             */
/*   Updated: 2023/12/08 14:41:07 by agallon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

////////////////////////////////////////////////////////////
t_func		g_function_pointer[] = {NULL,
	ft_string,
	ft_char,
	ft_pointer,
	ft_int,
	ft_int,
	ft_unsigned,
	ft_hexa,
	ft_hexa,
	ft_percent,
	ft_binary,
	ft_octal,
	ft_float,
	ft_scientific,
	ft_scientific,
	NULL};

////////////////////////////////////////////////////////////
//	#	RETURN INT != 0 IF IN SET
int	wii(char c)
{
	char	*char_set;
	int		i;

	char_set = "0# -+.123456789scpiduxX%bofeE";
	i = 0;
	while (char_set[i])
	{
		if (char_set[i] == c)
			break ;
		i++;
	}
	if (i < 5)
		return (-1);
	if (i == 5)
		return (-2);
	if (i < 15)
		return (-3);
	if (i < ft_strlen(char_set))
		return (i - 14);
	return (0);
}

////////////////////////////////////////////////////////////
//	#	CREATE STRUCT
int	f_1(const char *str, int *i, va_list args)
{
	t_flags	f;
	int		rtrn;

	f_ini_struct(&f);
	f_fill_struct(&str[*i + 1], &f, args);
	f_error_check(&f);
	if (f.error)
	{
		if (f.error == -2)
			return (-1);
		*i += write(1, "%", 1);
		return (1);
	}
	rtrn = g_function_pointer[wii(f.flag)](args, &f);
	*i += f.increment;
	return (rtrn);
}

////////////////////////////////////////////////////////////
//	#
int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		sum;
	int		r;

	va_start(args, str);
	i = 0;
	sum = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			r = f_1(str, &i, args);
			if (r < 0)
				return (-1);
			sum += r;
		}
		else
			sum += write(1, &str[i++], 1);
	}
	va_end(args);
	return (sum);
}
////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////

// #include <limits.h>

// int	main(void)
// {
// 	int				orig;
// 	int				mine;

// 	mine = ft_printf("MINE =%.*c=\n", 45, 'c');
// 	orig =    printf("ORIG =%.10c=\n", 'c');
// 	printf("MINE =%d; ORIG = %d", mine - 8, orig - 8);
// 	return (0);
// }
