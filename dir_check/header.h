/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarni <rmarni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 14:12:37 by rmarni            #+#    #+#             */
/*   Updated: 2019/12/03 12:22:35 by rmarni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _HEADER_H
# define _HEADER_H
# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <wchar.h>
# include <stdlib.h>
# define EMPTY 2147483648
# define LINE_STACK "*------------**------------*\n"
# define BLACK(string)			"\x1b[30m" string "\x1b[0m"
# define RED(string)			"\x1b[31m" string "\x1b[0m"
# define GREEN(string)			"\x1b[32m" string "\x1b[0m"
# define YELLOW(string)			"\x1b[33m" string "\x1b[0m"
# define BLUE(string)			"\x1b[34m" string "\x1b[0m"
# define MAGENTA(string)		"\x1b[35m" string "\x1b[0m"
# define CYAN(string)			"\x1b[36m" string "\x1b[0m"
# define GREY(string)			"\x1b[37m" string "\x1b[0m"

typedef struct	s_stack
{
	long		*a_stack;
	long		*b_stack;
	int			ac;
	char		*cmd;
	char		*arr_cmd[INT16_MAX];
	int			cmd_count;
	int			bonus;
	char		*buf;
}				t_stack;

long			ft_atoi_long(const char *src, t_stack checker, int flag);
void			ft_exit_checker(t_stack checker, int flag);
void			ft_print_stack(t_stack checker);
void			ft_validate_stack(t_stack checker);
int				get_next_line(const int fd, char **line);
void			*ft_sort_long(long *arr, int arr_size);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_printf(const char *format, ...);
int				check_asc(long *arr, int num_elem, int i);
int				ft_cmd_works(t_stack checker, int i);
void			ft_the_end (t_stack checker);
void			ft_check_swap(t_stack checker, char stack);
int				ft_stack_up(t_stack checker, char chr);
void			ft_stack_down(t_stack checker, char chr);
int				ft_str_arg(char *str, t_stack checker, int flag);
void			fill_empy(t_stack checker);
void			ft_arg_line(t_stack checker, char *str, int ac, int i);
void			ft_valid_cmd(char *str, t_stack checker);
int				ft_arr_size_(t_stack checker, char stack);
void			ft_bonus(t_stack checker, int i, int flag);
void			ft_swap_c(t_stack checker);
void			ft_cmd_works_norma(t_stack checker, int i);
int				tmp_func(t_stack checker, char *str, int ac, int i);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strdup(const char *src);
int				ft_isdig(int c, int flag);

#endif
