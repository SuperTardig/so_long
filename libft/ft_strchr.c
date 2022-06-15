/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperron <bperron@student.42quebec.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 09:07:57 by bperron           #+#    #+#             */
/*   Updated: 2022/04/05 13:38:37 by bperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;
	int		i;
	size_t	len;

	str = (char *) s;
	len = ft_strlen(s);
	if (c == '\0')
		return (str + len);
	i = 0;
	if (!s)
		return (NULL);
	while (len-- > 0)
	{
		if (str[i] == (char) c)
			return (str + i);
		i++;
	}
	return (NULL);
}
