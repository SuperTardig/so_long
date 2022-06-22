/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperron <bperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 09:24:21 by bperron           #+#    #+#             */
/*   Updated: 2022/06/06 09:19:51 by bperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strchri(const char *s, int c)
{
	char	*str;
	int		i;
	size_t	len;

	str = (char *) s;
	len = ft_strlen(s);
	i = 0;
	if (!s)
		return (0);
	while (len-- > 0)
	{
		if (str[i] == (char) c)
			return (1);
		i++;
	}
	return (0);
}
