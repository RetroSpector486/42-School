/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbolzon <kbolzon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 09:42:41 by kbolzon           #+#    #+#             */
/*   Updated: 2022/02/28 13:52:01 by kbolzon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (src == NULL || src[0] == '\0')
		return ((char *)dest);
	while (dest[i] != '\0' && i < n)
	{
		if (dest[i] == src[j])
		{
			while (dest[i + j] == src[j] && i + j < n)
			{
				if (src[j + 1] == '\0')
					return ((char *)dest + i);
				j++;
			}
			j = 0;
		}
		i++;
	}
	return (NULL);
}
