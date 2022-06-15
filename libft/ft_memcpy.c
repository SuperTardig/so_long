/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperron <bperron@student.42quebec.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 11:20:44 by bperron           #+#    #+#             */
/*   Updated: 2022/03/31 13:25:23 by bperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	size_t	i;
	char	*s;
	char	*d;

	if (src == NULL && dst == NULL)
		return (NULL);
	d = (char *) dst;
	s = (char *) src;
	i = 0;
	while (n-- > 0)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}
