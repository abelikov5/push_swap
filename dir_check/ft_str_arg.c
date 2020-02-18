/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarni <rmarni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 07:28:44 by rmarni            #+#    #+#             */
/*   Updated: 2019/12/03 12:53:55 by rmarni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/*
** Current file make validation in case int ARG passed as string;
** ft_count_ac: count all int ARG and fill arr;
** ft_validate: make validation if it DIGIT;
*/

int			ft_isdig(int c, int flag)
{
	if (flag)
	{
		if ((c >= '0' && c <= '9') || (c == '+' || c == '-'))
			return (1);
	}
	else
	{
		if (c >= '0' && c <= '9')
			return (1);
	}
	return (0);
}

int			ft_count_ac(char *str, t_stack checker, int flag)
{
	int		i;
	int		ac;

	ac = 0;
	i = 0;
	if (ft_isdig(str[i], 1))
	{
		ac++;
		if (flag)
			checker.a_stack[ac - 1] = ft_atoi_long(str, checker, 0);
	}
	while (str[i])
	{
		while (str[i] != ' ' && str[i])
			i++;
		if (ft_isdig(str[i + 1], 1))
		{
			ac++;
			if (flag)
				checker.a_stack[ac - 1] = ft_atoi_long(str + (i + 1),
				checker, 0);
		}
		i++;
	}
	return (ac);
}

void		ft_validate(char *str, t_stack checker)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdig(str[i], 0) && (str[i] != '+'
		&& str[i] != '-' && str[i] != ' '))
			ft_exit_checker(checker, 0);
		if ((str[i] == '+' || str[i] == '-') && !ft_isdig(str[i + 1], 0))
		{
			if (i > 0 && (str[i - 1] != ' '))
				ft_exit_checker(checker, 0);
			ft_exit_checker(checker, 0);
		}
		i++;
	}
}

int			ft_str_arg(char *str, t_stack checker, int flag)
{
	ft_validate(str, checker);
	ft_count_ac(str, checker, flag);
	if (flag)
		fill_empy(checker);
	return (ft_count_ac(str, checker, flag));
}

void		ft_arg_line(t_stack checker, char *str, int ac, int i)
{
	if (str == NULL)
		exit(0);
	checker.ac = ft_str_arg(str, checker, 0);
	if (ac == 1 || checker.ac == 0)
		exit(0);
	ac = checker.ac + 1;
	checker.a_stack = (long *)malloc(sizeof(long) * ac);
	checker.b_stack = (long *)malloc(sizeof(long) * ac);
	checker.cmd_count = 0;
	ft_str_arg(str, checker, 1);
	while (get_next_line(0, &checker.buf))
	{
		ft_valid_cmd(checker.buf, checker);
		checker.arr_cmd[checker.cmd_count] = ft_strdup(checker.buf);
		checker.cmd_count++;
		free(checker.buf);
	}
	if (!checker.arr_cmd[0])
		ft_exit_checker(checker, 1);
	ft_cmd_works(checker, 0);
	while (++i < checker.cmd_count)
		free(checker.arr_cmd[i]);
	free(checker.a_stack);
	free(checker.b_stack);
}
