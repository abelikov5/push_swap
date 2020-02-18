/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarni <rmarni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 13:32:39 by rmarni            #+#    #+#             */
/*   Updated: 2019/12/02 17:36:05 by rmarni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		ft_rotate(t_stack checker, char stack)
{
	long	tmp;
	int		i;

	if (stack == 'a')
		if (checker.a_stack[0] != EMPTY && checker.a_stack[1] != EMPTY)
		{
			tmp = checker.a_stack[0];
			i = ft_stack_up(checker, 'a');
			checker.a_stack[i] = tmp;
		}
	if (stack == 'b')
		if (checker.b_stack[0] != EMPTY && checker.b_stack[1] != EMPTY)
		{
			tmp = checker.b_stack[0];
			i = ft_stack_up(checker, 'b');
			checker.b_stack[i] = tmp;
		}
	if (stack == 'c')
	{
		ft_rotate(checker, 'a');
		ft_rotate(checker, 'b');
	}
}

void		ft_rev_rotate(t_stack checker, char stack)
{
	long	tmp;
	int		arr_size;

	arr_size = ft_arr_size_(checker, stack);
	if (stack == 'a')
		if (checker.a_stack[0] != EMPTY && checker.a_stack[1] != EMPTY)
		{
			tmp = checker.a_stack[arr_size - 1];
			ft_stack_down(checker, 'a');
			checker.a_stack[0] = tmp;
			checker.a_stack[arr_size] = EMPTY;
		}
	if (stack == 'b')
		if (checker.b_stack[0] != EMPTY && checker.b_stack[1] != EMPTY)
		{
			tmp = checker.b_stack[arr_size - 1];
			ft_stack_down(checker, 'b');
			checker.b_stack[0] = tmp;
			checker.b_stack[arr_size] = EMPTY;
		}
	if (stack == 'c')
	{
		ft_rev_rotate(checker, 'a');
		ft_rev_rotate(checker, 'b');
	}
}

void		ft_push(t_stack checker, char stack)
{
	if (stack == 'a')
		if (checker.a_stack[0] != EMPTY)
		{
			ft_stack_down(checker, 'b');
			checker.b_stack[0] = checker.a_stack[0];
			checker.a_stack[0] = EMPTY;
			ft_stack_up(checker, 'a');
		}
	if (stack == 'b')
		if (checker.b_stack[0] != EMPTY)
		{
			ft_stack_down(checker, 'a');
			checker.a_stack[0] = checker.b_stack[0];
			checker.b_stack[0] = EMPTY;
			ft_stack_up(checker, 'b');
		}
}

int			ft_cmd_works(t_stack checker, int i)
{
	while (i < checker.cmd_count)
	{
		ft_cmd_works_norma(checker, i);
		if (checker.bonus)
			ft_bonus(checker, i, 0);
		if (!ft_strcmp(checker.arr_cmd[i], "sa"))
			ft_check_swap(checker, 'a');
		else if (!ft_strcmp(checker.arr_cmd[i], "pa"))
			ft_push(checker, 'b');
		else if (!ft_strcmp(checker.arr_cmd[i], "ra"))
			ft_rotate(checker, 'a');
		else if (!ft_strcmp(checker.arr_cmd[i], "rb"))
			ft_rotate(checker, 'b');
		else if (!ft_strcmp(checker.arr_cmd[i], "rr"))
			ft_rotate(checker, 'c');
		else if (!ft_strcmp(checker.arr_cmd[i], "rra"))
			ft_rev_rotate(checker, 'a');
		else if (!ft_strcmp(checker.arr_cmd[i], "rrb"))
			ft_rev_rotate(checker, 'b');
		else if (!ft_strcmp(checker.arr_cmd[i], "rrr"))
			ft_rev_rotate(checker, 'c');
		i++;
	}
	ft_the_end(checker);
	return (0);
}

void		ft_cmd_works_norma(t_stack checker, int i)
{
	if (!ft_strcmp(checker.arr_cmd[i], "sb"))
		ft_check_swap(checker, 'b');
	else if (!ft_strcmp(checker.arr_cmd[i], "ss"))
		ft_swap_c(checker);
	else if (!ft_strcmp(checker.arr_cmd[i], "pb"))
		ft_push(checker, 'a');
}
