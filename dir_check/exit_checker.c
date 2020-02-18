/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarni <rmarni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 09:46:46 by rmarni            #+#    #+#             */
/*   Updated: 2019/11/28 16:55:41 by rmarni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_exit_checker(t_stack checker, int flag)
{
	if (flag)
		if (check_asc(checker.a_stack, checker.ac, 0) && checker.a_stack != 0)
		{
			if (checker.bonus)
				ft_bonus(checker, 0, 1);
			ft_printf(GREEN("OK\n"));
		}
		else
			ft_printf(RED("Error\n"));
	else
		ft_printf(RED("Error\n"));
	free(checker.a_stack);
	free(checker.b_stack);
	exit(0);
}

int		ft_arr_size_(t_stack checker, char stack)
{
	int	i;

	i = 0;
	if (stack == 'a')
		while (checker.a_stack[i] != EMPTY && i < checker.ac)
			i++;
	if (stack == 'b')
		while (checker.b_stack[i] != EMPTY && i < checker.ac)
			i++;
	return (i);
}

void	ft_bonus(t_stack checker, int i, int flag)
{
	if (!flag)
	{
		ft_printf("\n");
		ft_printf(YELLOW("   *** DEBUG OPTION ***"));
		ft_printf("\n");
		ft_print_stack(checker);
		ft_printf("Current command = ");
		ft_printf(RED("%6s"), checker.arr_cmd[i]);
		ft_printf("\n");
		sleep(1);
		ft_printf("\e[1;1H\e[2J");
	}
	if (flag)
	{
		ft_printf("\n");
		ft_printf(YELLOW("   *** SORTED LIST ***"));
		ft_printf("\n");
		ft_print_stack(checker);
		ft_printf("Total command used: ");
		ft_printf(GREEN("%4d,"), checker.cmd_count);
		ft_printf(" checker answer: ");
	}
}
