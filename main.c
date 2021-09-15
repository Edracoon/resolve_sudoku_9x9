/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epfennig <epfennig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 11:09:11 by epfennig          #+#    #+#             */
/*   Updated: 2021/09/15 12:36:30 by epfennig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

int				check_map(char *pathname, char map[9][9])
{
	int		fd;
	int		r;
	char	c;
	int		x = 0;
	int		y = 0;

	if ((fd = open(pathname, O_DIRECTORY)) > 0)
		return (-1);
	if ((fd = open(pathname, O_RDONLY)) == -1)
		return (-1);
	while (y < 9 && (r = read(fd, &c, 1)))
	{
		if (!(c >= '0' && c <= '9') && c != '\n')
			return (-1);
		if (c != '\n')
			map[y][x++] = c;
		else
		{
			x = 0;
			y++;
		}
	}
	return (0);
}

int				main(int ac, char **av)
{
	int			i;
	char		map[9][9];

	i = 0;
	if (ac != 2)
	{
		write(STDOUT_FILENO, "Error : [./sudoku] [map]\n", 28);
		return (0);
	}
	if ((check_map(av[1], map)) == -1)
	{
		write(STDERR_FILENO, "Error : map file invalid\n", 28);
		return (0);
	}
	// int x = 0; int y = 0;
	// while (y < 9)
	// {
	// 	x = 0;
	// 	while (x < 9)
	// 		printf("%c", map[y][x++]);
	// 	y++;
	// 	printf("\n");
	// }
	if (!(resolve_map(map)))
		write(1, "Error : No Solve\n", 17);
	return (0);
}
