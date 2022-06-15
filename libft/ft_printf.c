/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperron <bperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 13:01:24 by bperron           #+#    #+#             */
/*   Updated: 2022/06/06 09:18:14 by bperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_format(char format, va_list args)
{
	int	ret;

	ret = 0;
	if (format == 'c')
		ret = ft_printfc(va_arg(args, int));
	else if (format == 's')
		ret = ft_printfs(va_arg(args, char *));
	else if (format == 'p')
		ret = ft_printfp(va_arg(args, unsigned long));
	else if (format == 'd' || format == 'i')
		ret = ft_printfnbr((long) va_arg(args, int), 0);
	else if (format == 'u')
		ret = ft_printfu((unsigned int) va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		ret = ft_printfhex(format, va_arg(args, unsigned int));
	else if (format == '%')
	{
		write (1, "%", 1);
		ret = 1;
	}
	return (ret);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		ret;
	va_list	args;

	if (!format)
		return (0);
	va_start(args, format);
	i = -1;
	ret = 0;
	while (format[++i])
	{
		if (format[i] != '%')
		{
			write(1, &format[i], 1);
			ret++;
		}
		else
		{
			ret += ft_format(format[++i], args);
		}
	}
	va_end(args);
	return (ret);
}
