/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 18:09:46 by exam              #+#    #+#             */
/*   Updated: 2018/09/07 18:20:57 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		main(int argc, char**argv)
{
	int i;
	int j;

	i = 0;
	if (argc != 2)
	{
		ft_putchar('\n');
		return (0);
	}
	while (argv[1][i] != '\0')
	{
		j = 0;
		if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
		{
			while (j < argv[1][i] - 'a' + 1)
			{
				ft_putchar(argv[1][i]);
				j++;
			}
		}
		else if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
		{
			while (j < argv[1][i] - 'A' + 1)
			{
				ft_putchar(argv[1][i]);
				j++;
			}
		}
		else
		{
			ft_putchar(argv[1][i]);
		}
		i++;
	}
	ft_putchar('\n');

	return (0);
}
