/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drum_alg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarni <rmarni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 08:26:47 by rmarni            #+#    #+#             */
/*   Updated: 2019/11/29 08:11:32 by rmarni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_does_it_min_max(t_stack checker, int pos_b)
{
	if (checker.b_stack[pos_b] < ft_three_min(checker,
		ft_num_of_elem(checker, 'a'), 'a'))
		return (1);
	if (checker.b_stack[pos_b] > ft_three_max(checker,
		ft_num_of_elem(checker, 'a'), 'a'))
		return (2);
	return (0);
}

void	ft_sort_cicle(t_stack checker)
{
	if (checker.a_stack[0] < checker.a_stack[1] && checker.a_stack[0]
	< checker.a_stack[2])
	{
		if (checker.a_stack[1] > checker.a_stack[2])
			ft_cmd_works("sa", checker);
	}
	else if (checker.a_stack[0] > checker.a_stack[1] && checker.a_stack[0]
	< checker.a_stack[2])
		ft_cmd_works("sa", checker);
	else if (checker.a_stack[0] > checker.a_stack[1] && checker.a_stack[0]
	> checker.a_stack[2])
	{
		if (checker.a_stack[1] > checker.a_stack[2])
			ft_cmd_works("sa", checker);
	}
}

int		ft_midl_(t_stack checker, long mid)
{
	int	num_elem;
	int	i;

	i = 0;
	num_elem = ft_num_of_elem(checker, 'a');
	if (num_elem > 3)
		while (i < num_elem)
		{
			if (checker.a_stack[i] >= mid)
				return (1);
			i++;
		}
	return (0);
}

void	ft_push_b_(t_stack checker, long mid, long mid_b, int i)
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
			i++;
		}
		mid /= 2;
		mid_b = mid + mid / 2;
	}
}

void	ft_drum_alg(t_stack checker)
{
	int up;
	int btm;

	ft_push_b_(checker, checker.mid, checker.mid_b, 0);
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
