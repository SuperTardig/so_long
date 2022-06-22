/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperron <bperron@student.42quebec.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 09:21:01 by bperron           #+#    #+#             */
/*   Updated: 2022/03/31 13:26:35 by bperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *restrict dst, const void *restrict src, size_t n)
{
	size_t	i;
	char	*src1;
	char	*dst1;

	if (dst == NULL && src == NULL)
		return (NULL);
	src1 = (char *) src;
	dst1 = (char *) dst;
	i = 0;
	if (dst1 > src1)
		while (i++ < n)
			dst1[n - i] = src1[n - i];
	else
	{
		while (n-- > 0)
		{
			dst1[i] = src1[i];
			i++;
		}
	}
	return (dst);
}
