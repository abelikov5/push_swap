/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 14:37:27 by rmarni            #+#    #+#             */
/*   Updated: 2019/12/03 13:09:38 by rmarni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static long				ft_return_long(int i, unsigned char *str,
t_stack checker)
{
	int					minus;
	unsigned long long	base;

	minus = 0;
	base = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i + 1] < '0' || str[i + 1] > '9')
			ft_exit_checker(checker, 0);
		if (str[i] == '-')
			minus = 1;
		i++;
	}
	base = base + (str[i] - '0');
	i++;
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		base = base * 10 + (str[i] - '0');
		i++;
	}
	if ((base > INT32_MAX && !minus) || (base > 2147483648 && minus))
		ft_exit_checker(checker, 0);
	return (minus == 1 ? base * (-1) : base);
}

void					ft_atoi_validate(unsigned char *str,
t_stack checker)
{
	int i;

	i = 0;
	if (str == NULL)
		ft_exit_checker(checker, 0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			ft_exit_checker(checker, 0);
		i++;
	}
}

void					ft_overload_int(unsigned char *str, t_stack checker)
{
	int					i;

	i = 0;
	while (i < 11)
	{
		if (!ft_isdig(str[i], 0))
			return ;
		i++;
	}
	ft_exit_checker(checker, 0);
}

long					ft_atoi_long(const char *src, t_stack checker,
int flag)
{
	int					i;
	unsigned char		*str;

	str = ((unsigned char *)src);
	if (flag)
		ft_atoi_validate(str, checker);
	else
		ft_overload_int(str, checker);
	i = 0;
	while ((str[i] != '\0'))
	{
		if ((str[i] >= '0' && str[i] <= '9') || (str[i] == '-')
		|| (str[i] == '+'))
			return (ft_return_long(i, str, checker));
		i++;
	}
	return (0);
}

int						tmp_func(t_stack checker, char *str, int ac, int i)
{
	ft_arg_line(checker, str, ac, i);
	return (0);
}
