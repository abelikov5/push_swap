/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 12:35:20 by rmarni            #+#    #+#             */
/*   Updated: 2019/11/30 19:30:40 by rmarni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_count_words(char const *s, char dem)
{
	int		i;
	int		g;

	i = 0;
	g = 0;
	while (s[i] != '\0')
	{
		if (s[i] != dem)
		{
			g++;
			while (s[i] != dem && s[i + 1] != '\0')
				i++;
		}
		i++;
	}
	return (g);
}
