/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 16:08:40 by ebennace          #+#    #+#             */
/*   Updated: 2021/10/22 14:27:25 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t elementCount, size_t elementSize)
{
	char	*str;
	int		i;

	i = 0;
	str = malloc(elementCount * elementSize);
	if (str == NULL)
		return (NULL);
	while (i < ((int)elementSize * (int)elementCount))
	{
		str[i] = 0;
		i++;
	}
	return ((void *)str);
}
/*
int main ()
{
	int elementCount = 4;
	int elementSize = 5;
	char *str = ft_calloc(elementCount, elementSize);
	char *str1 = calloc(elementCount, elementSize);
	printf("%s\n",str);
	printf("%s\n",str1);
}
*/
