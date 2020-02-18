/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarni <rmarni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 17:12:17 by rmarni            #+#    #+#             */
/*   Updated: 2019/12/02 17:03:25 by rmarni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		ft_stack_down(t_stack checker, char chr)
{
	int		i;

	i = checker.ac - 1;
	if (chr == 'b')
	{
		while (checker.b_stack[i] == EMPTY && i >= 0)
			i--;
		while (i >= 0)
		{
			checker.b_stack[i + 1] = checker.b_stack[i];
			i--;
		}
	}
	if (chr == 'a')
	{
		while (checker.a_stack[i] == EMPTY && i >= 0)
			i--;
		while (i >= 0)
		{
			checker.a_stack[i + 1] = checker.a_stack[i];
			i--;
		}
	}
}

int			ft_stack_up(t_stack checker, char chr)
{
	int		i;

	i = 1;
	if (chr == 'a')
	{
		while (checker.a_stack[i] != EMPTY && i < checker.ac)
		{
			checker.a_stack[i - 1] = checker.a_stack[i];
			i++;
		}
		checker.a_stack[i - 1] = EMPTY;
	}
	if (chr == 'b')
	{
		while (checker.b_stack[i] != EMPTY && i < checker.ac)
		{
			checker.b_stack[i - 1] = checker.b_stack[i];
			i++;
		}
		checker.b_stack[i - 1] = EMPTY;
	}
	return (i - 1);
}

void		ft_check_swap(t_stack checker, char stack)
{
	long	tmp;

	if (stack == 'a')
	{
		if (checker.a_stack[0] != EMPTY && checker.a_stack[1] != EMPTY)
		{
			tmp = checker.a_stack[0];
			checker.a_stack[0] = checker.a_stack[1];
			checker.a_stack[1] = tmp;
		}
	}
	if (stack == 'b')
	{
		if (checker.b_stack[0] != EMPTY && checker.b_stack[1] != EMPTY)
		{
			tmp = checker.b_stack[0];
			checker.b_stack[0] = checker.b_stack[1];
			checker.b_stack[1] = tmp;
		}
	}
	if (stack == 'c')
	{
		ft_check_swap(checker, 'a');
		ft_check_swap(checker, 'b');
	}
}

t_stack		ft_prep_bonus(t_stack checker, int ac, int i, char **av)
{
	int		j;
	int		b;

	b = 1;
	j = -1;
	if (ac <= 2)
		exit(tmp_func(checker, av[1], ac, -1));
	if (!ft_strcmp(av[1], "-v"))
	{
		checker.bonus = 1;
		i++;
		b = 2;
	}
	else
		checker.bonus = 0;
	checker.a_stack = (long *)malloc(sizeof(long) * ac);
	checker.b_stack = (long *)malloc(sizeof(long) * ac);
	checker.ac = ac - b;
	checker.cmd_count = 0;
	while (++i < ac - 1)
		checker.a_stack[++j] = ft_atoi_long(av[i + 1], checker, 1);
	ft_validate_stack(checker);
	fill_empy(checker);
	return (checker);
}

int			main(int ac, char **av)
{
	int		i;
	t_stack	checker;

	i = -1;
	checker.cmd_count = 0;
	checker = ft_prep_bonus(checker, ac, -1, av);
	while (get_next_line(0, &checker.buf))
	{
		ft_valid_cmd(checker.buf, checker);
		checker.arr_cmd[checker.cmd_count] = ft_strdup(checker.buf);
		checker.cmd_count++;
		free(checker.buf);
	}
	if (!checker.arr_cmd[0])
		ft_exit_checker(checker, 1);
	if (checker.bonus)
		ft_printf("\e[1;1H\e[2J");
	ft_cmd_works(checker, 0);
	while (++i < checker.cmd_count)
		free(checker.arr_cmd[i]);
	free(checker.a_stack);
	free(checker.b_stack);
	return (0);
}
