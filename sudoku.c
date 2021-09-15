/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epfennig <epfennig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 11:09:11 by epfennig          #+#    #+#             */
/*   Updated: 2021/09/15 15:15:56 by epfennig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

void	print_map(char cpymap[9][9])
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y < 9)
	{
		while (x < 9)
		{
			if (x > 0)
				write(1, " ", 1);
			write(1, &cpymap[y][x], 1);
			x++;
		}
		write(1, "\n", 1);
		x = 0;
		y++;
	}
}

void	copy_map(char map[9][9], char cpymap[9][9])
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < 9)
	{
		while (x < 9)
		{
			cpymap[y][x] = map[y][x];
			x++;
		}
		x = 0;
		y++;
	}
}

int		fill_curr_case(int x, int y, char cpymap[9][9])
{
	int		value;

	value = '1';
	while (value <= '9')
	{
		if (check_line_row(x, y, value, cpymap))
		{
			cpymap[y][x] = value;
			// print_map(cpymap);
			// system("clear");
			if (check_3x3(x, y, value, cpymap))
				if ((resolve_map(cpymap)))
					return (1);
		}
		value++;
	}
	return (0);
}

int		resolve_map(char map[9][9])
{
	char	cpymap[9][9];
	int		x;
	int		y;

	copy_map(map, cpymap);
	x = 0;
	y = 0;
	while (y < 9)
	{
		while (x < 9)
		{
			if (cpymap[y][x] == '0')
				return (fill_curr_case(x, y, cpymap));
			x++;
		}
		x = 0;
		y++;
	}
	print_map(cpymap);
	return (1);
}
