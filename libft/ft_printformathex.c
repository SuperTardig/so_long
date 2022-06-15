/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printformathex.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperron <bperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 13:21:12 by bperron           #+#    #+#             */
/*   Updated: 2022/06/06 09:18:32 by bperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printptr(unsigned long ptr, int *ret)
{
	if (ptr >= 16)
		ft_printptr((ptr / 16), ret);
	write(1, &"0123456789abcdef"[ptr % 16], 1);
	*ret += 1;
}

int	ft_printfp(unsigned long ptr)
{
	int	ret;

	ret = 2;
	write (1, "0x", 2);
	ft_printptr(ptr, &ret);
	return (ret);
}

int	ft_hexlen(unsigned long nb)
{
	int	i;

	i = 1;
	while (nb >= 16)
	{
		nb /= 16;
		i++;
	}
	return (i);
}

int	ft_printfhex(char format, unsigned int nb)
{
	char	*hexbase;

	if (format == 'x')
		hexbase = "0123456789abcdef";
	else if (format == 'X')
		hexbase = "0123456789ABCDEF";
	if (nb >= 16)
	{
		ft_printfhex(format, (nb / 16));
		ft_printfhex(format, (nb % 16));
	}
	else
		write (1, &hexbase[nb], 1);
	return (ft_hexlen(nb));
}
