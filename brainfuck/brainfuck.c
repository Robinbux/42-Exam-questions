/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brainfuck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 21:44:42 by exam              #+#    #+#             */
/*   Updated: 2018/08/31 21:48:15 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

int		main(int argc, char **argv)
{
    char array[2048] = {0};
    char *current_byte = array;
    int i;
    int j;
    int passed_brackets;

	if (argc == 1)
	{
		ft_putchar('\n');
	}

    passed_brackets = 0;
    j = 0;
    i = 0;
    while (argv[1][i] != '\0')
    {
        if (argv[1][i] == '>')
        {
            j++;
        }
        if (argv[1][i] == '<')
        {
            j--;
        }
        if (argv[1][i] == '+')
        {
            current_byte[j]++;
        }
        if (argv[1][i] == '-')
        {
            current_byte[j]--;
        }
        if (argv[1][i] == '.')
        {
            ft_putchar(current_byte[j]);
        }
        if (argv[1][i] == '[' && current_byte[j] == 0)
        {
            while (1)
            {
                i++;
                if (argv[1][i] == '[')
                {
                    passed_brackets++;
                }
                if (argv[1][i] == ']' && passed_brackets == 0)
                {
                    passed_brackets = 0;
                    break;
                }
                if (argv[1][i] == ']')
                {
                    passed_brackets--;
                }
            }

        }
        if (argv[1][i] == ']' && current_byte[j] != 0)
        {
            while (1)
            {
                i--;
                if (argv[1][i] == ']')
                {
                    passed_brackets++;
                }
                if (argv[1][i] == '[' && passed_brackets == 0)
                {
                    passed_brackets = 0;
                    break;
                }
                if (argv[1][i] == '[')
                {
                    passed_brackets--;
                }
            }
        }
        i++;
    }
    return 0;
}
