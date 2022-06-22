/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperron <bperron@student.42quebec.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 15:04:58 by bperron           #+#    #+#             */
/*   Updated: 2022/04/04 11:34:30 by bperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	getsize(long int n)
{
	int	i;
	int	j;

	j = 10;
	i = 1;
	if (n < 0)
		n *= -1;
	while (n > 0)
	{
		i++;
		n = n / 10;
	}
	i++;
	return (i);
}

char	*ft_itoa(int n)
{
	char		*str;
	long int	nb;
	int			size;

	nb = n;
	size = getsize(nb) - 3;
	str = ft_calloc(getsize(nb), sizeof(char));
	if (!str)
		return (NULL);
	if (nb == 0)
		str[0] = '0';
	else if (nb < 0)
	{
		nb *= -1;
		str[0] = '-';
		size++;
	}
	while (nb > 0)
	{
		str[size--] = nb % 10 + '0';
		nb /= 10;
	}
	return (str);
}
