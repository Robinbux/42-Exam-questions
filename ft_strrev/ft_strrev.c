/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 18:24:07 by exam              #+#    #+#             */
/*   Updated: 2018/09/07 18:35:31 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char *ft_strrev(char *str)
{
    int ln;
    int i;
    char tmp;
    char *start;

    i = 0;
    ln = 0;
    start = str;
    while (*str)
    {
        ln++;
        str++;
    }
    str -= ln;

    while (i < ln/2)
    {
        tmp = str[i];
        str[i] = str[ln - i - 1];
        str[ln - i - 1] = tmp;
        i++;
    }
    return (start);
}
