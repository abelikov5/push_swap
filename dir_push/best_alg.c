/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_alg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarni <rmarni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 18:09:37 by rmarni            #+#    #+#             */
/*   Updated: 2019/12/03 12:17:04 by rmarni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

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

void		ft_push_best_b(t_stack checker, long mid, long mid_b, int i)
{
	while (checker.a_stack[3] != EMPTY)
	{
		i = 0;
		while (ft_midl_(checker, mid))
		{
			if (checker.a_stack[0] >= mid && checker.a_stack[0] != EMPTY)
				ft_cmd_works("pb", checker);
			else if (checker.a_stack[0] < mid)
			{
				if (checker.b_stack[0] >= mid_b)
					ft_cmd_works("rr", checker);
				else
					ft_cmd_works("ra", checker);
			}
			if (checker.b_stack[0] >= mid_b)
				ft_cmd_works("rb", checker);
			i++;
		}
		mid /= 2;
		mid_b = checker.max;
	}
}

void		ft_best_alg(t_stack checker)
{
	int		up;
	int		btm;

	ft_push_best_b(checker, checker.mid, checker.mid_b, 0);
	ft_sort_cicle(checker);
	while (checker.b_stack[0] != EMPTY)
	{
		ft_choose_index(checker);
		up = ft_stack_a(checker, 0);
		btm = ft_num_of_elem(checker, 'a') - up;
		if (up <= btm)
			while (up-- != 0 && up >= 0)
				ft_cmd_works("ra", checker);
		else if (up > btm)
			while (btm-- != 0 && btm >= 0)
				ft_cmd_works("rra", checker);
		ft_cmd_works("pa", checker);
	}
	ft_final_func(checker, checker.min);
}
