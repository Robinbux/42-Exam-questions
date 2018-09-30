/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 18:44:05 by exam              #+#    #+#             */
/*   Updated: 2018/08/31 19:18:20 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		get_array_size(int start, int end)
{
	if (start >= 0 && end >= 0)
	{
		if (start > end)
			return (start - end + 1);
		else
			return (end - start + 1);
	}
	if (start >= 0 && end < 0)
	{
		return (start - end + 1);
	}
	else if (start < 0 && end >= 0)
	{
		return (end - start + 1);		
	}
	else if (end > start)
		return ((-start) - (-end) + 1);
	else
		return ((-end) - (-start) + 1);
}

int		*ft_rrange(int start, int end)
{
	int *array;
	int array_size;
	int i;

	array_size = get_array_size(start, end);
	array = malloc(sizeof(int) * array_size);
	i = 0;
	while (end != start)
	{
		array[i] = end;
		if (end > start)
		{
			end--;
		}
		else
		{
			end++;
		}
		i++;	
	}
	array[i] = start;
	return (array);
}
