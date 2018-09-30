/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 21:34:22 by exam              #+#    #+#             */
/*   Updated: 2018/09/07 21:34:33 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

long int     pow (int nbr, int power)
{
    int i;
    int origin;
    long int long_nbr;

    if (power == 0)
        return (1);
    long_nbr = nbr;
    origin = nbr;
    i = 1;
    while (i < power)
    {
        long_nbr *= origin;
        i++;
    }
    return (long_nbr);
}

int     find_pow(long int value, int base)
{
    int pow_val;
    long int long_val;

    long_val = value;
    pow_val = 0;
    while (pow(base, pow_val) <= long_val)
    {
        pow_val++;
    }
    return (pow_val - 1);
}

char    convert_to_base(int nbr)
{
    if (nbr == 10)
        return ('A');
    else if (nbr == 11)
        return ('B');
    else if (nbr == 12)
        return ('C');
    else if (nbr == 13)
        return ('D');
    else if (nbr == 14)
        return ('E');
    else if (nbr == 15)
        return ('F');
    else
        return (nbr + '0');
}

char    *ft_itoa_base(int value, int base)
{
    char *str_nbr;
    char *start;
    long int long_val;
    int power;
    int i;
    int negative;

    if (value < 0 && base == 10)
        negative = 1;
    else
        negative = 0;
    long_val = value;
    if (negative)
    {
        long_val = -long_val;
    }
    if (value == 0)
    {
        str_nbr = malloc(sizeof(char) * 2);
        *str_nbr = '0';
        str_nbr++;
        *str_nbr = '\0';
        return (str_nbr - 1);
    }
    power = find_pow(long_val, base);
    str_nbr = malloc(sizeof(char) * (power + 1 + negative));
    start = str_nbr;
    if (negative)
    {
        *str_nbr = '-';
        str_nbr++;
    }

    while(power >= 0)
    {
        i = 0;
        while (i * pow(base, power) <= long_val)
        {
            i++;
        }
        i--;
        *str_nbr = convert_to_base(i);
        long_val -= pow(base, power) * i;
        power--;
        str_nbr++;
    }
    *str_nbr = '\0';
    return (start);
}
