/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperron <bperron@student.42quebec.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 11:55:57 by bperron           #+#    #+#             */
/*   Updated: 2022/03/28 12:22:37 by bperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;	
	char	*str;

	str = (char *) b;
	i = 0;
	while (i < len)
	{
		str[i] = (char) c;
		i++;
	}
	return ((void *) str);
}
