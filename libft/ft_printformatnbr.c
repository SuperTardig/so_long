/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printformatnbr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperron <bperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 10:09:56 by bperron           #+#    #+#             */
/*   Updated: 2022/06/06 09:18:38 by bperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printfnbr(long nb, int i)
{
	int		ret;
	char	arr[12];

	ret = 0;
	if (nb == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
		i += 1;
	}
	while (nb > 0)
	{
		arr[ret] = nb % 10 + '0';
		nb /= 10;
		ret++;
	}
	i += ret;
	while (ret > 0)
		write (1, &arr[--ret], 1);
	return (i);
}

int	ft_printfu(unsigned int nb)
{
	int	ret;

	ret = 0;
	if (nb < 0)
		nb = 4294967295 - (nb - 1);
	ret = ft_printfnbr(nb, 0);
	return (ret);
}
