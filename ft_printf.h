/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallon <agallon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:38:31 by agallon           #+#    #+#             */
/*   Updated: 2023/12/08 14:41:58 by agallon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stddef.h>
# include <stdio.h>
# include <unistd.h>

////////////////////////////////////////////////////////////
//	#	STRUCT
typedef struct s_flag
{
	int			minus;
	int			zero;
	int			width;
	int			plus;
	int			space;
	int			hash;
	int			point;
	int			preci;
	char		flag;
	char		error;
	int			increment;
}				t_flags;

typedef int		(*t_func)(va_list, t_flags *);
////////////////////////////////////////////////////////////
//	#	PRINTF
int		f_1(const char *str, int *i, va_list args);
int		ft_printf(const char *str, ...);
int		wii(char c);
////////////////////////////////////////////////////////////
//	#	STRUCT
void	f_ini_struct(t_flags *flags);
void	f_error_check(t_flags *flags);
void	f_fill_struct(const char *str, t_flags *f, va_list args);
////////////////////////////////////////////////////////////
//	#	TOOLS
int		ft_strlen(const char *str);
int		atoi_pos(const char *str, int *preci_width, t_flags *f,	va_list args);
int		size_num_base(long long num, int base);
int		size_float(double nbr, t_flags *flags);
int		size_exp(t_flags *f);
////////////////////////////////////////////////////////////
//	#	TOOLS PRINT
int		f_format_num(t_flags *f, long long num, int size_num);
int		size_format_num(long long num, t_flags *flags, int num_size);
int		f_spacing(t_flags *flags, int size);
////////////////////////////////////////////////////////////
int		ft_putnbr_base(long long nbr, char *base);
int		ft_put_float(double nbr, t_flags *flags);
int		ft_put_science(double nbr, t_flags *f);
////////////////////////////////////////////////////////////
//	#	TOOLS UNSIGNED
int		size_format_num_un(unsigned long num, t_flags *f, int num_size);
int		size_num_base_un(unsigned long num, int base);
int		f_format_num_un(t_flags *f, unsigned long num, int size_num);
int		ft_putnbr_base_un(unsigned long nbr, char *base);
////////////////////////////////////////////////////////////
//	#	TABLEAU
int		ft_string(va_list args, t_flags *flags);
int		ft_char(va_list args, t_flags *flags);
int		ft_pointer(va_list args, t_flags *flags);
int		ft_int(va_list args, t_flags *flags);
int		ft_unsigned(va_list args, t_flags *flags);
////////////////////////////////////////////////////////////
int		ft_hexa(va_list args, t_flags *flags);
int		ft_percent(va_list args, t_flags *flags);
int		ft_binary(va_list args, t_flags *flags);
int		ft_octal(va_list args, t_flags *flags);
int		ft_float(va_list args, t_flags *flags);
////////////////////////////////////////////////////////////
int		ft_scientific(va_list args, t_flags *flags);
////////////////////////////////////////////////////////////

#endif
