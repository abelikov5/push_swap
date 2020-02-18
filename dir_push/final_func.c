/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarni <rmarni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 17:15:54 by rmarni            #+#    #+#             */
/*   Updated: 2019/11/26 17:22:01 by rmarni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void			ft_final_func(t_stack checker, long min)
{
	int			i;

	i = 0;
	while (checker.a_stack[i] != min)
		i++;
	if (i <= checker.ac - i)
		while (i--)
			ft_cmd_works("ra", checker);
	else
	{
		i = checker.ac - i;
		while (i--)
			ft_cmd_works("rra", checker);
	}
}

int				ft_num_of_elem(t_stack checker, char stack)
{
	int			num_elem;

	num_elem = 0;
	if (stack == 'a')
		while (checker.a_stack[num_elem] != EMPTY && num_elem < checker.ac)
			num_elem++;
	if (stack == 'b')
		while (checker.b_stack[num_elem] != EMPTY && num_elem < checker.ac)
			num_elem++;
	return (num_elem);
}

t_ch			ft_num_oper(t_ch ch_t)
{
	ch_t.main_oper = ch_t.num_opert;
	ch_t.main_ind = ch_t.i;
	return (ch_t);
}

int				ft_stack_a(t_stack checker, int i)
{
	t_stack_a	stack_a;

	stack_a.pos_up = 0;
	stack_a.last = ft_num_of_elem(checker, 'a');
	stack_a.min_max = ft_does_it_min_max(checker, i);
	return (ft_stack_a_norma_(checker, stack_a, i));
}

int				ft_choose_index(t_stack checker)
{
	t_ch ch_t;

	ch_t.q_a = ft_num_of_elem(checker, 'a');
	ch_t.q_b = ft_num_of_elem(checker, 'b');
	ch_t.i = 0;
	ch_t.pos_stack_a = 0;
	ch_t.btm_up_a = ch_t.q_a - (ch_t.q_a / 2);
	ch_t.btm_up_b = ch_t.q_b - (ch_t.q_b / 2);
	ch_t.num_opert = 0;
	ch_t.main_oper = 99;
	ch_t.main_ind = 0;
	return (ft_choose_norma(checker, ch_t));
}
