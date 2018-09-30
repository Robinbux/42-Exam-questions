/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 19:22:24 by exam              #+#    #+#             */
/*   Updated: 2018/08/31 20:38:01 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int get_pow(int i)
{
    int pow;
    int j;

    j = 0;
    pow = 10;
    while (j < i)
    {
        pow *= 10;
        j++;
    }
    return (pow);
}

char	*ft_itoa(int nbr)
{
    int size;
    int is_negative;
    int nb_copy;
    char *array;
    int result;
    int i;
    int substractor;
    int long_nb;

    long_nb = 0;
    substractor = 1;
    i = 0;
    size = 0;
    is_negative = 0;
    if (nbr == 0)
    {
        array = malloc(sizeof(char) * (2));
        array[0] = '0';
        array[1] = '\0';
        return (array);
    }
    if (nbr == -2147483648)
    {
        array = malloc(sizeof(char) * (12));
        array[0] = '-';
        array[1] = '2';
        array[2] = '1';
        array[3] = '4';
        array[4] = '7';
        array[5] = '4';
        array[6] = '8';
        array[7] = '3';
        array[8] = '6';
        array[9] = '4';
        array[10] = '8';
        array[11] = '\0';
        return (array);
    }
    if (nbr < 0)
    {
        nbr = -nbr;
        size++;
        is_negative = 1;
        substractor = 0;
    }
    nb_copy = nbr;
    while (nb_copy > 0)
    {
        nb_copy /= 10;
        size++;
    }
    array = malloc(sizeof(char) * (size + 1));
    if (is_negative)
    {
        array[0] = '-';
        size--;
    }

    if (nbr >= 1000000000)
    {
        long_nb = (nbr / 1000000000) + '0';
        nbr %= 1000000000;
    }
    while (i < size)
    {
        result = (nbr % get_pow(i)) / ((get_pow(i) / 10));
        array[size - i - substractor] = result + '0';
        i++;
    }
    array[i + is_negative] = '\0';
    if (long_nb > 0)
        array[is_negative] = long_nb;
    return (array);
}
