/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarni <rmarni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 13:32:39 by rmarni            #+#    #+#             */
/*   Updated: 2019/11/26 17:35:30 by rmarni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		ft_rotate(t_stack checker, char stack, int flag)
{
	long	tmp;
	int		i;

	if (stack == 'a' || stack == 'c')
		if (checker.a_stack[0] != EMPTY && checker.a_stack[1] != EMPTY)
		{
			tmp = checker.a_stack[0];
			i = ft_stack_up(checker, 'a');
			checker.a_stack[i] = tmp;
			if (!flag)
				ft_printf("ra\n");
		}
	if (stack == 'b' || stack == 'c')
		if (checker.b_stack[0] != EMPTY && checker.b_stack[1] != EMPTY)
		{
			tmp = checker.b_stack[0];
			i = ft_stack_up(checker, 'b');
			checker.b_stack[i] = tmp;
			if (!flag)
				ft_printf("rb\n");
		}
}

void		ft_rev_rotate(t_stack checker, char stack, int rrr)
{
	long	tmp;
	int		arr_size;

	if (stack == 'a' || stack == 'c')
		if (checker.a_stack[0] != EMPTY && checker.a_stack[1] != EMPTY)
		{
			arr_size = ft_arr_size_(checker, 'a');
			tmp = checker.a_stack[arr_size - 1];
			ft_stack_down(checker, 'a');
			checker.a_stack[0] = tmp;
			checker.a_stack[arr_size] = EMPTY;
			if (!rrr)
				ft_printf("rra\n");
		}
	if (stack == 'b' || stack == 'c')
		if (checker.b_stack[0] != EMPTY && checker.b_stack[1] != EMPTY)
		{
			tmp = checker.b_stack[ft_arr_size_(checker, 'b') - 1];
			ft_stack_down(checker, 'b');
			checker.b_stack[0] = tmp;
			checker.b_stack[ft_arr_size_(checker, 'b') - 1] = EMPTY;
			if (!rrr)
				ft_printf("rrb\n");
		}
}

void		ft_rev_rotate_c(t_stack checker)
{
	ft_rev_rotate(checker, 'a', 1);
	ft_rev_rotate(checker, 'b', 1);
	ft_printf("rrr\n");
}

void		ft_push(t_stack checker, char stack)
{
	if (stack == 'a')
		if (checker.b_stack[0] != EMPTY)
		{
			ft_stack_down(checker, 'a');
			checker.a_stack[0] = checker.b_stack[0];
			checker.b_stack[0] = EMPTY;
			ft_stack_up(checker, 'b');
			ft_printf("pa\n");
		}
	if (stack == 'b')
		if (checker.a_stack[0] != EMPTY)
		{
			ft_stack_down(checker, 'b');
			checker.b_stack[0] = checker.a_stack[0];
			checker.a_stack[0] = EMPTY;
			ft_stack_up(checker, 'a');
			ft_printf("pb\n");
		}
}

void		ft_cmd_works(char *str, t_stack checker)
{
	if (!ft_strcmp(str, "sa"))
		ft_check_swap(checker, 'a', 1);
	else if (!ft_strcmp(str, "sb"))
		ft_check_swap(checker, 'b', 1);
	else if (!ft_strcmp(str, "ss"))
		ft_swap_c(checker);
	else if (!ft_strcmp(str, "pa"))
		ft_push(checker, 'a');
	else if (!ft_strcmp(str, "pb"))
		ft_push(checker, 'b');
	else if (!ft_strcmp(str, "ra"))
		ft_rotate(checker, 'a', 0);
	else if (!ft_strcmp(str, "rb"))
		ft_rotate(checker, 'b', 0);
	else if (!ft_strcmp(str, "rr"))
		ft_rotate_c(checker);
	else if (!ft_strcmp(str, "rra"))
		ft_rev_rotate(checker, 'a', 0);
	else if (!ft_strcmp(str, "rrb"))
		ft_rev_rotate(checker, 'b', 0);
	else if (!ft_strcmp(str, "rrr"))
		ft_rev_rotate_c(checker);
}
