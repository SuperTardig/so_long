/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperron <bperron@student.42quebec.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 10:28:46 by bperron           #+#    #+#             */
/*   Updated: 2022/04/05 13:36:31 by bperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;
	size_t			len1;
	size_t			len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	str1 = (unsigned char *) s1;
	str2 = (unsigned char *) s2;
	if (n == 0)
		return (0);
	i = 0;
	while (len1-- >= 0 && len2-- >= 0 && str1[i] == str2[i] && n - 1 > i)
		i++;
	return ((unsigned char) str1[i] - str2[i]);
}
