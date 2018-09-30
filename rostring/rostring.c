/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 19:52:57 by exam              #+#    #+#             */
/*   Updated: 2018/09/07 19:58:17 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

int ln_first_word(char **argv)
{
    int i;
    int ln;

    ln = 0;
    i = 0;
    while (argv[1][i] != '\0')
    {
        while (argv[1][i] == ' ' || argv[1][i] == '\t')
        {
            i++;
        }
        i++;
        ln++;
        if (argv[1][i] == ' ' || argv[1][i] == '\t' || argv[1][i] == '\0')
        {
            return (ln);
        }
    }
    return (-1);
}

int     main(int argc, char **argv)
{
	if (argc == 1)
	{
		ft_putchar('\n');
		return (0);
	}
    int i;
    int ln = ln_first_word(argv);
    int w_mark;
    char first_word_array[ln + 1];
    int one_word;
    int space;
    int h;
    int stop;;

    stop = 0;
    h = 0;
    i = 0;
    while (argv[1][i] != '\0' && !stop)
    {
        while (argv[1][i] == ' ' || argv[1][i] == '\t')
        {
            i++;
        }
        while (argv[1][i] != ' ' && argv[1][i] != '\t' && argv[1][i] != '\0')
        {
            first_word_array[h] = argv[1][i];
            i++;
            h++;
            stop = 1;
        }
    }
    first_word_array[h] = '\0';
    space = 0;
    one_word = 0;
    w_mark = 0;
    i = 0;
    while (argv[1][i] != '\0')
    {
        while (argv[1][i] == ' ' || argv[1][i] == '\t')
        {
            i++;
            space = 1;
        }
        if (w_mark != 0 && argv[1][i] != '\0' && one_word && space)
        {
            ft_putchar(' ');
        }
        if (w_mark == 0)
        {
            while (argv[1][i] != ' ' && argv[1][i] != '\t' && argv[1][i] != '\0')
            {
                i++;
            }
            w_mark = 1;
        }
        if (argv[1][i] != ' ' && argv[1][i] != '\t' && argv[1][i] != '\0')
        {
            ft_putchar(argv[1][i]);
            i++;
            one_word = 1;
        }
        space = 0;
    }
    if (one_word)
    {
        ft_putchar(' ');
    }
    i = 0;
    while(i < ln)
    {
        ft_putchar(first_word_array[i]);
        i++;
    }
    ft_putchar('\n');
}
