/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 08:40:26 by rmarni            #+#    #+#             */
/*   Updated: 2019/11/28 17:05:33 by rmarni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		*ft_sort_long(long *arr, int arr_size)
{
	int		i;
	int		j;
	int		tmp;

	if (arr == NULL)
		return (NULL);
	tmp = 0;
	i = -1;
	j = arr_size;
	while (++i < arr_size)
	{
		while (--j)
		{
			if (arr[j] < arr[j - 1])
			{
				tmp = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = tmp;
			}
		}
		j = arr_size;
	}
	return (arr);
}

int			check_asc(long *arr, int num_elem, int i)
{
	while (num_elem-- > 1)
	{
		if (arr[i] >= arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void		ft_validate_stack(t_stack checker)
{
	int		i;
	int		b;
	long	*tmp_arr;

	b = -1;
	i = checker.ac;
	tmp_arr = (long *)malloc(sizeof(long) * checker.ac);
	while (++b < i)
		tmp_arr[b] = checker.a_stack[b];
	ft_sort_long(tmp_arr, checker.ac);
	if (!check_asc(tmp_arr, checker.ac, 0))
	{
		free(tmp_arr);
		ft_exit_checker(checker, 0);
	}
	free(tmp_arr);
}
