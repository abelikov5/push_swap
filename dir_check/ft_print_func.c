/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_func.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarni <rmarni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 18:04:28 by rmarni            #+#    #+#             */
/*   Updated: 2019/12/02 17:17:10 by rmarni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		ft_the_end(t_stack checker)
{
	if (checker.bonus)
		ft_bonus(checker, 0, 1);
	if (checker.b_stack[0] == EMPTY)
		check_asc(checker.a_stack, checker.ac, 0) ? ft_printf(GREEN("OK\n"))
		: ft_printf(RED("KO\n"));
	else
		ft_printf(RED("KO\n"));
}

void		ft_print_stack(t_stack checker)
{
	int		b;

	b = -1;
	ft_printf(LINE_STACK);
	ft_printf("|  stack \"A\" ||  stack \"B\" |\n");
	ft_printf(LINE_STACK);
	while (++b < checker.ac)
	{
		if (checker.a_stack[b] == EMPTY)
			ft_printf("|% -12c|", 0);
		else
			ft_printf("|% -12ld|", checker.a_stack[b]);
		if (checker.b_stack[b] == EMPTY)
			ft_printf("|% -12c|\n", 0);
		else
			ft_printf("|% -12ld|\n", checker.b_stack[b]);
	}
	ft_printf(LINE_STACK);
}

void		fill_empy(t_stack checker)
{
	int		i;

	i = -1;
	while (++i < checker.ac)
		checker.b_stack[i] = EMPTY;
}

void		ft_valid_cmd(char *str, t_stack checker)
{
	int		i;
	char	*valid_cmd[12];

	i = -1;
	valid_cmd[0] = "sa";
	valid_cmd[1] = "sb";
	valid_cmd[2] = "ss";
	valid_cmd[3] = "pa";
	valid_cmd[4] = "pb";
	valid_cmd[5] = "ra";
	valid_cmd[6] = "rb";
	valid_cmd[7] = "rr";
	valid_cmd[8] = "rra";
	valid_cmd[9] = "rrb";
	valid_cmd[10] = "rrr";
	while (++i < 11)
		if (!ft_strcmp(str, valid_cmd[i]))
			return ;
	ft_exit_checker(checker, 0);
}

void		ft_swap_c(t_stack checker)
{
	ft_check_swap(checker, 'a');
	ft_check_swap(checker, 'b');
}
