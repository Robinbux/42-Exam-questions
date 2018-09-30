/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_capitalizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 18:53:53 by exam              #+#    #+#             */
/*   Updated: 2018/09/07 18:55:52 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

int main(int argc, char **argv)
{
    int i;
    int h;

    i = 1;
    while (i < argc)
    {
        h = 0;
        while (argv[i][h] != '\0')
        {
            if (argv[i][h] >= 'a' && argv[i][h] <= 'z' && ((argv[i][h - 1] == ' ' || argv[i][h - 1] == '\t') || h == 0))
            {
                argv[i][h] -= 32;
            }
            else if (argv[i][h] >= 'A' && argv[i][h] <= 'Z' && ((argv[i][h - 1] != ' ' && argv[i][h - 1] != '\t') && h != 0))
            {
                argv[i][h] += 32;
            }
            ft_putchar(argv[i][h]);
            h++;
        }
        i++;
        ft_putchar('\n');
    }

    if (argc == 1)
    {
        ft_putchar('\n');
    }

    return 0;
}
