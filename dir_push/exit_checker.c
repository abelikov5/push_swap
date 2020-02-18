/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarni <rmarni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 09:46:46 by rmarni            #+#    #+#             */
/*   Updated: 2019/11/26 18:05:02 by rmarni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_exit_checker(t_stack checker, int flag)
{
	checker.mid_b = 0;
	if (flag)
		exit(0);
	else
		ft_printf(RED("Error\n"));
	exit(1);
}

int		ft_arr_size_(t_stack checker, char stack)
{
	int i;

	i = 0;
	if (stack == 'a')
		while (checker.a_stack[i] != EMPTY && i < checker.ac)
			i++;
	if (stack == 'b')
		while (checker.b_stack[i] != EMPTY && i < checker.ac)
			i++;
	return (i);
}
